#include "ast/symbolTable.h"

int isInLoop = 0;
FuncTypeNode* nowFunc = nullptr;
std::vector<std::map<std::string, IdentTypeNode>> IDSymbolTable {};
std::vector<std::map<std::string, FuncTypeNode>> FuncSymbolTable {};


bool check (TreeLvalEqStmt* leq) {
    DeType left = check_type(leq->lval);
    DeType right = check_type(leq->exp);
    if (left == right && right == DeType::INT) {
        return true;
    }
    else {
        throw("The lval assignment is fail\n");
    }
    return false;
}

bool check (TreeReturnStmt* ret) {
    // check the return type is weather equal to now function
    if (nowFunc == nullptr) {
        throw("Now has not in a function but has a return statement\n");
    }
    else if (nowFunc->type == DeType::FUNC_VOID && ret->expr != nullptr) {
        throw("Function should return nothing(void), but actually return something\n");
    }
    else if (nowFunc->type == DeType::FUNC_INT && ret->expr == nullptr) {
        throw("Function should return INT but actually return nothing\n");
    }
    else if (nowFunc->type == DeType::FUNC_INT && check_type(ret->expr) == DeType::INT) {
        // its OK
        return true;
    }
    else if (nowFunc->type == DeType::FUNC_VOID && ret->expr == nullptr) {
        // is OK
        return true;
    }
    else {
        throw("Return error type\n");
    }
    return false;

}

bool check (TreeIfStmt* iff) {
    // check if condition
    if (iff->exp == nullptr) {
        throw("If need confition express\n");
    }
    if (check_type(iff->exp) != DeType::INT) {
        throw("Invalid for the condition express for if\n");
    }
    return true;
}

bool check (TreeWhileStmt* wh) {
    if (check_type(wh->exp) != DeType::INT) {
        throw("Invalid for the condition express for while\n");
    }
    return true;
}

/**
 * @param expr The expression to find the type
 * @return The type of expression
*/
DeType check_type (TreeExpr* expr) {
    // Lval
    if (auto *lval = expr->as<TreeLVal*>()) {
        // Ident or array
        // first check the ident is define
        IdentTypeNode *tmp = checkIdDefine(lval->ident);
        if (tmp == nullptr) {
            throw("Use undefine Ident\n");
        }
        else if ((tmp->dimension == 0) && (lval->hasExpress)) {
            throw("The Ident can't be used as array\n");
        }
        // array
        if (tmp->type == DeType::ARRAY_INT) {
            // all child should be INT but not void
            // check all child and expect 
            if (lval->exprs->size() > (unsigned int)tmp->dimension) {
                throw("Array has too many params\n");
            }
            for (unsigned int i = 0; i < lval->exprs->size(); ++i) {
                DeType child = check_type(lval->exprs->at(i));
                if (child == DeType::VOID) {
                    throw("The index of array can't be void\n");
                }
                else if (child != DeType::INT) {
                    throw("The index of array is not INT\n");
                }
            }
            if (lval->exprs->size() == (unsigned int)tmp->dimension) {
                return DeType::INT;
            }
            else {
                return (DeType)((DeType::ARRAY_INT) + (tmp->dimension - lval->exprs->size()));
            }
        }
        // INT
        else if (tmp->type == DeType::INT) {
            return DeType::INT;
        }
    }
    // int
    else if ([[maybe_unused]]auto *inte = expr->as<TreeIntegerLiteral*>()) {
        return DeType::INT;
    }
    // Unary
    else if (auto *una = expr->as<TreeUnaryExpr*>()) {
        // maybe (-a)  or (foo(a,b))
        // func call
        if (una->op == OpType::OP_Func) {
            // check that the func has defined
            FuncTypeNode* functmp = checkFuncDefine(una->id);
            if (functmp == nullptr) {
                throw("The function used is not defined\n");
            }
            // first check the RParams is equal to the Params
            if (una->operand != nullptr) {
                auto* rParams = una->operand->as<TreeFuncRParams*>();
                int rnum = rParams->child->size();
                int num = functmp->funcParams.size();
                if (rnum > num) {
                    throw("Function call with too many params\n");
                }
                else if (rnum < num) {
                    throw("Function call with less params\n");
                }
                for (int i = 0; i < num; ++i) {
                    // i means the ith child of funccall
                    DeType rtype = check_type(rParams->child->at(i));
                    if (rtype != (DeType)(functmp->funcParams[i].type +functmp->funcParams[i].dimension)) {
                        // throw("Function call with error real param at " + std::to_string(i) + "\n");
                        throw("Function call with error real param\n");
                    }
                    else if (rtype > DeType::ARRAY_INT) {
                        // check the domain size is weather same
                        IdentTypeNode* iden = checkIdDefine(rParams->child->at(i)->as<TreeLVal*>()->ident);
                        int rdomainNum = (int)(rtype - DeType::ARRAY_INT) - 1;
                        int rn = iden->domainSize.size() - 1, ln = functmp->funcParams[i].domainSize.size() - 1;
                        for (int ii = 0; ii < rdomainNum; ++ii) {
                            if (iden->domainSize[rn--] != functmp->funcParams[i].domainSize[ln--]) {
                                throw("Function call with invalid domain size\n");
                            }
                        }
                    }
                }
            }
            else {
                // Func call with no param
                if (functmp->funcParams.size() != 0) {
                    throw("Funcion call with less params\n");
                }
            }
            // then return the type of func
            if (functmp->type == DeType::FUNC_INT) {
                return DeType::INT;
            }
            else {
                return DeType::VOID;
            }

        }
        // just number
        else {
            return check_type(una->operand);
        }

    }
    // Binary
    else if (auto *bina = expr->as<TreeBinaryExpr*>()) {
        DeType left, right;
        left = check_type(bina->lhs);
        right = check_type(bina->rhs);
        if (left == right && left != DeType::VOID) {
            return left;
        }
        else {
            throw("Binary expression with invalid type of left or right\n");
        }
    }
    return DeType::ERROR;
};

/**
 * find the ident of id
*/
IdentTypeNode* checkIdDefine(TreeIdent* ident) {
    // bool find = false;
    int n = IDSymbolTable.size();
    for (int i = n - 1; i >= 0; --i) {
        auto mp = IDSymbolTable[i];
        auto it = mp.find(ident->IdentName);
        if (it != mp.end()) {
            return &(IDSymbolTable[i][ident->IdentName]);
        }
    }
    return nullptr;
}

/**
 * 
*/
FuncTypeNode* checkFuncDefine(TreeIdent* ident) {
    // bool find = false;
    // int n = FuncSymbolTable.size();
    
    for (int i = 0; i >= 0; --i) {
        auto mp = FuncSymbolTable[i];
        auto it = mp.find(ident->IdentName);
        if (it != mp.end()) {
            return &(FuncSymbolTable[0][ident->IdentName]);
        }
    }
    return nullptr;
}

/**
 * Insert into SymbolTable functions
 * Insert into func and ID
*/

/**
 * @param node The node that include series of var def
 * @return is success insert
 * check first, and then insert one, check one
 * TODO
*/
bool addToIDSymbolTable (TreeVarDecl* node) {
    int n = IDSymbolTable.size();
    if (n == 0) {
        throw("There is no domain to add\n");
    }
    for (unsigned int i = 0; i < node->varDef->size(); ++i) {
        TreeVarDef* var = node->varDef->at(i);
        // check if it has been defined
        if (IDSymbolTable[n-1].find(var->ident->IdentName) != IDSymbolTable[n-1].end()) {
            throw("This var has defined in this domain before\n");
        }
        // add it to table
        IdentTypeNode idNode;
        if (var->isArry) {
            // array's params are all int_const, cannot error
            idNode.type = DeType::ARRAY_INT;
            idNode.dimension = var->child->size();
            for (unsigned int ii = 0; ii < var->child->size(); ++ii) {
                idNode.domainSize.push_back((int)var->child->at(ii)->value);
            }
        }
        else {
            // check the expr's type first
            DeType rightExpr = check_type(var->initVal);
            if (rightExpr != DeType::INT) {
                throw("Error right value when define a lval\n");
            }
            idNode.type = DeType::INT;
            idNode.dimension = 0;
        }
        IDSymbolTable[n-1][var->ident->IdentName] = idNode;
    }
    return true;
};

/**
 * @param node The node that include series of var def
 * @return is success insert
 * check first and insert then
*/
FuncTypeNode* addToFuncSymbolTable (TreeFuncDef* node) {
    int n = IDSymbolTable.size();
    if (n == 0) {
        throw("There is no domain to add\n");
    }
    else if (n >= 2) {
        throw("Function can only define in the gloable domain\n");
    }
    // check
    if (FuncSymbolTable[0].find(node->ident->IdentName) != FuncSymbolTable[0].end()) {
        throw("There has defined thhis function\n");
    }
    // add
    unsigned int type = node->type->type;
    FuncTypeNode* funcnode = new FuncTypeNode;
    funcnode->type = (type) ? DeType::FUNC_INT : DeType::FUNC_VOID;
    // add params  the params also need to add to the new doamin
    TreeFuncParams* params = node->params;
    if (params != nullptr) {
        for (unsigned int i = 0; i < params->child->size(); ++i) {
            IdentTypeNode idnode;
            TreeFuncParam* param = params->child->at(i);
            if (param->isArry) {
                idnode.type = DeType::ARRAY_INT;
                idnode.dimension = param->child->size() + 1;
                idnode.domainSize.push_back(0);
                for (unsigned int ii = 0; ii < param->child->size(); ++ii) {
                    idnode.domainSize.push_back((int)param->child->at(ii)->value);
                }
            }
            else {
                idnode.type = DeType::INT;
                idnode.dimension = 0;
            }
            funcnode->funcParams.push_back(idnode);
        }
    }
    FuncSymbolTable[0][node->ident->IdentName] = *funcnode;
    return funcnode;
}

void addFuncParamsToTable(TreeFuncDef* node) {
    // the domain must be empty just insert
    int n = IDSymbolTable.size();
    TreeFuncParams* params = node->params;
    if (params == nullptr) {
        return;
    }
    for (unsigned int i = 0; i < params->child->size(); ++i) {
        TreeFuncParam* param = params->child->at(i);
        // check
        auto it = IDSymbolTable[n-1].find(param->ident->IdentName);
        if (it != IDSymbolTable[n-1].end()) {
            throw("Function define with same param\n");
        }
        else {
            IdentTypeNode nn;
            if (param->isArry) {
                nn.type = DeType::ARRAY_INT;
                nn.dimension = param->child->size() + 1;
                nn.domainSize.push_back(0);
                for (unsigned int ii = 0; ii < param->child->size(); ++ii) {
                    nn.domainSize.push_back((int)param->child->at(ii)->value);
                }
            }
            else {
                nn.type = DeType::INT;
                nn.dimension = 0;
            }
            IDSymbolTable[n-1][param->ident->IdentName] = nn;
        }
    }
}

/**
 * @return is successful add a new domain, which means into a new block {}
 * add empty map to vector
*/
void newDomain () {
    std::map<std::string, IdentTypeNode> idMap {};
    std::map<std::string, FuncTypeNode> funcMap {};
    IDSymbolTable.push_back(idMap);
    FuncSymbolTable.push_back(funcMap);
}

/**
 * Like stack, just 'pop' the top map
*/
void deleteDomain () {
    // IDSymbolTable.erase(IDSymbolTable.begin() + IDSymbolTable.size() - 1);
    // FuncSymbolTable.erase(FuncSymbolTable.begin() + FuncSymbolTable.size() - 1);
    if (!IDSymbolTable.empty()) IDSymbolTable.pop_back();
    if (!FuncSymbolTable.empty()) FuncSymbolTable.pop_back();
}

void addRunTimeFunc() {
    // getint getch getarray
    FuncTypeNode *getInt = new FuncTypeNode, *getCh = new FuncTypeNode, *getArray = new FuncTypeNode;
    getInt->type = DeType::FUNC_INT;
    getCh->type = DeType::FUNC_INT;
    getArray->type = DeType::FUNC_INT;
    getArray->funcParams.push_back({DeType::ARRAY_INT, 1});
    FuncSymbolTable[0]["getint"] = *getInt;
    FuncSymbolTable[0]["getch"] = *getCh;
    FuncSymbolTable[0]["getarray"] = *getArray;
    // putint putch putarray
    FuncTypeNode *putInt = new FuncTypeNode, *putCh = new FuncTypeNode, *putArray = new FuncTypeNode;
    putInt->type = DeType::FUNC_VOID;
    putInt->funcParams.push_back({DeType::INT, 0});
    putCh->type = DeType::FUNC_VOID;
    putCh->funcParams.push_back({DeType::INT, 0});
    putArray->type = DeType::FUNC_VOID;
    putArray->funcParams.push_back({DeType::INT, 0});
    putArray->funcParams.push_back({DeType::ARRAY_INT, 1});
    FuncSymbolTable[0]["putint"] = *putInt;
    FuncSymbolTable[0]["putch"] = *putCh;
    FuncSymbolTable[0]["putarray"] = *putArray;
    // starttime stoptime
    FuncTypeNode *startT = new FuncTypeNode, *stopT = new FuncTypeNode;
    startT->type = DeType::VOID;
    stopT->type = DeType::VOID;
    FuncSymbolTable[0]["starttime"] = *startT;
    FuncSymbolTable[0]["stoptime"] = *stopT;
}