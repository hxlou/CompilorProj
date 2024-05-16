#include "ast/ast2ir.h"
#include "ast/symbolTable.h"

#include <fmt/core.h>
#include <iostream>
#include <cassert>

int isIRinLoop = 0;
BasicBlock* loopExit = nullptr;
BasicBlock* loopEntry = nullptr;
BasicBlock* funcEntry = nullptr;
bool isIRInFunc = false;
std::vector<TreeVarDef*> globalVarBinding {};
std::vector<std::pair<BasicBlock*, BasicBlock*>> allLoops {};

std::vector<std::map<std::string, Value*>> IDValueTable {};
std::vector<std::map<std::string, Function*>> FuncValueTable {};
Module* CompMod = nullptr;

extern std::vector<std::map<std::string, IdentTypeNode>> IDSymbolTable;
extern std::vector<std::map<std::string, FuncTypeNode>> FuncSymbolTable;

// translate expression to a value
Value* translate_expr(TreeExpr* expr, BasicBlock* bb) {
    // OK Lval -> var or array, just do nothing
    if (auto *lval = expr->as<TreeLVal*>()) {
        // var or array
        // array a[x1][x2][x3]
        if (lval->hasExpress) {
            // array and need to cal the index(values) and BoundList
            // use offset to cal address 
            // use load to get the value if it is jvbu
            // global var can use directly
            std::vector<Value*> v;
            std::vector <std::optional<std::size_t>> BoundList;
            // check IDSymbolTable to get the BoundList
            IdentTypeNode* IdType = checkIdDefine(lval->ident);
            for (int i = 0; i < IdType->dimension; ++i) {
                if (IdType->domainSize[i] == 0) {
                    if (i != 0) {
                        throw("Func's Array Param's index(1,2,3,...) can't be 0 expect index(0)\n");
                    }
                    BoundList.push_back(std::nullopt);
                }
                else {
                    BoundList.push_back(IdType->domainSize[i]);
                }
            }
            // get the values
            for (unsigned int i = 0; i < lval->exprs->size(); ++i) {
                v.push_back(translate_expr(lval->exprs->at(i), bb));
            }
            // ptr
            bool isG = false;
            Value* ptr = findValue(lval->ident->IdentName, isG);
            // offset and load
            Value* offset = OffsetInst::Create(Type::getIntegerTy(), ptr, v, BoundList, bb);
            Value* load = LoadInst::Create(offset, bb);
            return load;
        }
        // just number(ID)
        else {
            // just number and load is ok
            bool isG = false;
            Value* ptr = findValue(lval->ident->IdentName, isG);
            Value* load = LoadInst::Create(ptr, bb);
            return load;
        }
    }
    // OK int
    else if (auto *cint = expr->as<TreeIntegerLiteral*>()) {
        Value *res = ConstantInt::Create(cint->value);
        return res;
    }
    // OK Binary
    else if (auto *bop = expr->as<TreeBinaryExpr*>()) {
        Value* lhs = translate_expr(bop->lhs, bb);
        Value* rhs = translate_expr(bop->rhs, bb);
        Type* ty = nullptr;
        if (check_type(bop->lhs) == DeType::INT) {
            ty = Type::getIntegerTy();
        }
        else {
            ty = Type::getUnitTy();
        }
        Value* res = nullptr;
        switch (bop->op)
        {
        case OpType::OP_Add:
            res = BinaryInst::CreateAdd(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Sub:
            res = BinaryInst::CreateSub(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Mul:
            res = BinaryInst::CreateMul(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Div:
            res = BinaryInst::CreateDiv(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Mod:
            res = BinaryInst::CreateMod(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Land:
            res = BinaryInst::CreateAnd(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Lor:
            res = BinaryInst::CreateOr(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Lxor:
            res = BinaryInst::CreateXor(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Lt:
            res = BinaryInst::CreateLt(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Gt:
            res = BinaryInst::CreateGt(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Le:
            res = BinaryInst::CreateLe(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Ge:
            res = BinaryInst::CreateGe(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Eq:
            res = BinaryInst::CreateMul(lhs, rhs, ty, bb);
            break;
        case OpType::OP_Ne:
            res = BinaryInst::CreateNe(lhs, rhs, ty, bb);
            break;
        default:
            break;
        }
        return res;
    }
    // OK Unary --> (-a) or (foo(a, b)) 
    else if (auto *uop = expr->as<TreeUnaryExpr*>()) {
        // function call
        if (uop->op == OpType::OP_Func) {
            Function* f = CompMod->getFunction(uop->id->IdentName);
            std::vector<Value*> Args {};
            auto* rparams = uop->operand->as<TreeFuncRParams*>();
            for (unsigned int i = 0; i < rparams->child->size(); ++i) {
                Args.push_back(translate_expr(rparams->child->at(i), bb));
            }
            Value* res = CallInst::Create(f, Args, bb);
            return res;
        }
        // just calculate
        else {
            Value* res = nullptr;
            if (uop->op == OpType::OP_Lnot) {
                // logical not can change to : eq src 0
                Value* z = ConstantInt::Create(0);
                Value* src = translate_expr(uop->operand, bb);
                res = BinaryInst::CreateEq(src, z, Type::getIntegerTy(), bb);
            }
            else if (uop->op == OpType::OP_Neg) {
                // -a
                Value* z = ConstantInt::Create(0);
                Value* src = translate_expr(uop->operand, bb);
                res = BinaryInst::CreateSub(z, src, Type::getIntegerTy(), bb);
            }
            else if (uop->op == OpType::OP_Lnot) {
                Value* c = ConstantInt::Create(0xffffffff);
                Value* src = translate_expr(uop->operand, bb);
                res = BinaryInst::CreateXor(c, src, Type::getIntegerTy(), bb);
            }
            return res;
        }
    }

    return nullptr;
}

// left value assigment
// change the table, means that a symbol's value is change to the newest
void translate_expr(TreeLvalEqStmt* expr, BasicBlock* bb) {
    // Lval: global or jvbu
    // if global, just change and update table
    // if jvbu, get address + store + update table
    TreeLVal* lval = expr->lval->as<TreeLVal*>();
    TreeExpr* rexp = expr->exp;
    Value* r = translate_expr(rexp, bb);
    bool isG = false;
    Value* ptr = findValue(lval->ident->IdentName, isG);
    // OK array
    if (lval->hasExpress) {
        // offset and load and store and update
        // boundlist
        std::vector<Value*> v;
        std::vector<std::optional<std::size_t>> BoundList;
        auto* IdType = checkIdDefine(lval->ident);
        for (int i = 0; i < IdType->dimension; ++i) {
            if (IdType->domainSize[i] == 0) {
                if (i != 0) {
                    throw("Finc's Array Param's error\n");
                }
                BoundList.push_back(std::nullopt);
            }
            else {
                BoundList.push_back(IdType->domainSize[i]);
            }
        }
        // value*
        for (unsigned int i = 0; i < lval->exprs->size(); ++i) {
            v.push_back(translate_expr(lval->exprs->at(i), bb));
        }
        // store
        Value* offset = OffsetInst::Create(Type::getIntegerTy(), ptr, v, BoundList, bb);
        Value* store = StoreInst::Create(r, offset, bb);
    }
    // OK just like a = b + 1, and a store is enough
    else {
        // get ptr and store is OK
        Value* store = StoreInst::Create(r, ptr, bb);
    }

    return ;
};

// var declear 
// if it is in a function, it should use alloc and store, and store to the IDValueTable
// if it is a global, it should be store to module and IDValueTable
void translate_expr(TreeVarDecl* decl, BasicBlock* bb) {
    // if size == 1 for gloable var
    if (IDValueTable.size() == 1) {
        // gloable
        // 1. create GlobalVariable
        // 2. if is a num, store the def waiting for the binding
        // 3. update the 2 tables
        Type* ty = nullptr;
        if (decl->type->type == 1) {
            ty = Type::getIntegerTy();
        }
        for (unsigned int i = 0; i < decl->varDef->size(); ++i) {
            // 
            TreeVarDef* def = decl->varDef->at(i);   
            GlobalVariable *gvar = nullptr;
            IdentTypeNode idTypeNode;
            
            // array
            if (def->isArry) {
                int arraySize = 1;
                for (unsigned int j = 0; j < def->child->size(); ++j) {
                    arraySize *= def->child->at(j)->value;
                    idTypeNode.domainSize.push_back(def->child->at(j)->value);
                }
                gvar = GlobalVariable::Create(ty, arraySize, false, def->ident->IdentName, CompMod);
                // id type node
                idTypeNode.type = DeType::ARRAY_INT;
                idTypeNode.dimension = def->child->size();
            }
            else {
                idTypeNode.type = DeType::INT;
                idTypeNode.dimension = 0;
                gvar = GlobalVariable::Create(ty, 1, false, def->ident->IdentName, CompMod);
                globalVarBinding.push_back(def);
            }
            // update the table
            IDValueTable[0][def->ident->IdentName] = gvar;
            IDSymbolTable[0][def->ident->IdentName] = idTypeNode;
        }
    }
    else {
        // jvbu var
        Function* pp = bb->getParent();
        BasicBlock* fentry = &pp->getEntryBlock();
        Type* ty = nullptr;
        if (decl->type->type == 1) {
            ty = Type::getIntegerTy();
        }
        for (unsigned int i = 0; i < decl->varDef->size(); ++i) {
            IdentTypeNode idTypeNode;
            idTypeNode.type = DeType::INT, idTypeNode.dimension = 0;
            TreeVarDef* def = decl->varDef->at(i);
            int arraySize = 1;
            if (def->isArry) {
                idTypeNode.type = DeType::ARRAY_INT;
                idTypeNode.dimension = def->child->size();
                for (unsigned int j = 0; j < def->child->size(); ++j) {
                    arraySize *= def->child->at(j)->value;
                    idTypeNode.domainSize.push_back(def->child->at(j)->value);
                }
            }
            Value* talloc = AllocaInst::Create(ty, arraySize, fentry);
            if (!def->isArry) {
                // if not array, we need to store the true value to it
                Value* trueValue = translate_expr(def->initVal, fentry);
                Value* trueValueStore = StoreInst::Create(trueValue, talloc, fentry);
            }
            // update table
            IDValueTable[IDValueTable.size() - 1][def->ident->IdentName] = talloc;
            IDSymbolTable[IDSymbolTable.size() - 1][def->ident->IdentName] = idTypeNode;
        }
    }
}

Value* translate_expr(TreeFuncDef* fdef, BasicBlock* bb) {
    // function declear
    // static Function *Create(FunctionType *FTy, bool ExternalLinkage = false,
    //                     std::string_view Name = "", Module *M = nullptr);
    // construct the result
    Type* res = nullptr;
    std::vector<Type*> params {};
    if (fdef->type->type == 0) res = Type::getUnitTy();
    else res = Type::getIntegerTy();
    // construct the params
    if (fdef->params != nullptr) {
        auto* v = fdef->params->child;
        for (unsigned int i = 0; i < v->size(); ++i) {
            if (v->at(i)->isArry) {
                params.push_back(PointerType::get(Type::getIntegerTy()));
            }
            else {
                params.push_back(Type::getIntegerTy());
            }
        }
    }
    // construct the function type
    FunctionType* fty = FunctionType::get(res, params);
    // create funciton
    Function* fun = Function::Create(fty, false, fdef->ident->IdentName, CompMod);
    FuncValueTable[0][fdef->ident->IdentName] = fun;
    // create extry exit returnvalue
    BasicBlock* fentryBB = BasicBlock::Create(fun);
    fentryBB->setName("FuncEntry");
    BasicBlock* fbodyBB = BasicBlock::Create(fun);
    fbodyBB->setName("FuncBody");
    BasicBlock* fretBB = BasicBlock::Create(fun);
    fretBB->setName("FuncRet");
    // %ret and add to params table
    Value* fret = nullptr;
    if (fdef->type->type == 1) {
        fret = AllocaInst::Create(Type::getIntegerTy(), 1, fentryBB);
    }
    else {
        // fret = AllocaInst::Create(Type::getUnitTy(), 1, fentryBB);
    }
    // fill retBB
    if (fdef->type->type == 0) {
        // ret nothing
        Value* resI = RetInst::Create(ConstantUnit::Create(), fretBB);
    }
    else {
        // get the return value from table use load
        Value* load = LoadInst::Create(fret, fretBB);
        Value* retI = RetInst::Create(load, fretBB);
    }
    // if main, need to do binding

    // ret and jvbu need to add to new domain
    // translate the body of function
    newDomain();
    newValueDomain();
    isIRInFunc = 1;
    
    addToNewDomain(fret, fdef, fun);
    BasicBlock* fBodyRet = translate_stmt(fdef->block, fbodyBB, true);

    isIRInFunc = 0;
    deleteValueDomain();
    deleteDomain();
    // fentryBB jump to func's body
    Value* bodyRet2exit = JumpInst::Create(fretBB, fBodyRet);
    Value* j2body = JumpInst::Create(fbodyBB, fentryBB);
}

BasicBlock* translate_stmt(TreeStmt* stmt, BasicBlock* bb, bool fromFunc) {
    // if while break return block continue
    // OK if
    if (auto* If = stmt->as<TreeIfStmt*>()) { 
        Value* condValue = translate_expr(If->exp, bb);
        BasicBlock *isT, *isF, *exit;
        if (If->hasElse) {
            isT = BasicBlock::Create(bb->getParent(), bb);
            isF = BasicBlock::Create(bb->getParent(), bb);
            exit = BasicBlock::Create(bb->getParent(), bb);
            Value* branch = BranchInst::Create(isT, isF, condValue, bb);
            BasicBlock* isTret = translate_stmt(If->stmtIf, isT);            // return ?
            Value* tjmp = JumpInst::Create(exit, isTret);
            BasicBlock* isFret = translate_stmt(If->stmtElse, isF);
            Value* fjmp = JumpInst::Create(exit, isFret);
            return exit;
        }
        else {
            isT = BasicBlock::Create(bb->getParent(), bb);
            exit = BasicBlock::Create(bb->getParent(), bb);
            Value* branch = BranchInst::Create(isT, exit, condValue, bb);
            BasicBlock* isTret = translate_stmt(If->stmtIf, isT);
            Value* tjmp = JumpInst::Create(exit, isTret);
            return exit;
        }
    }
    // OK while
    else if (auto* While = stmt->as<TreeWhileStmt*>()) {
        BasicBlock *entry, *body, *exit;
        entry = BasicBlock::Create(bb->getParent(), bb);
        body = BasicBlock::Create(bb->getParent(), bb);
        exit = BasicBlock::Create(bb->getParent(), bb);
        Value* j2en = JumpInst::Create(entry, bb);
        Value* condValue = translate_expr(While->exp, entry);
        Value* branch = BranchInst::Create(body, exit, condValue, entry);

        isIRinLoop++;
        loopExit = exit;
        loopEntry = entry;
        allLoops.push_back({entry, exit});
        BasicBlock* bodyExit = translate_stmt(While->stmt, body);
        allLoops.pop_back();
        loopEntry = nullptr;
        loopExit = nullptr;
        isIRinLoop--;

        Value* j2exit = JumpInst::Create(exit, bodyExit);

        return exit;
    }
    // OK break
    else if (auto* Break = stmt->as<TreeBreakStmt*>()) {
        // break out from the minmun loop, for and while
        if (!isIRinLoop) {
            throw("Break but not in loop\n");
        }
        Value* jmp = JumpInst::Create(allLoops.end()->second, bb);
        return bb;
    }
    // OK continue
    else if (auto* Continue = stmt->as<TreeContinueStmt*>()) {
        if (!isIRinLoop) {
            throw("Continue but not in loop\n");
        }
        Value* jmp = JumpInst::Create(allLoops.end()->first, bb);
        return bb;
    }
    // OK return
    else if (auto* Ret = stmt->as<TreeReturnStmt*>()) {
        BasicBlock* retBB = &bb->getParent()->end().operator*();
        bool isG = false;
        Value* ptr = findValue("return", isG);
        // return something
        if (Ret->expr) {
            Value* retValue = translate_expr(Ret->expr, bb);
            Value* storeRet = StoreInst::Create(retValue, ptr, bb);
            Value* j2RetBB = JumpInst::Create(retBB, bb);
        }
        // return nothing
        else {
            Value* j2RetBB = JumpInst::Create(retBB, bb);
        }
        // normally, ret should be a bb's last inst, return nullptr
        // but if there's some insts after retInst, the func should return bb
        return bb;
    }
    // OK FuncDef
    else if (auto* fdef = stmt->as<TreeFuncDef*>()) {
        translate_expr(fdef, bb);
        return bb;
    }
    // OK VarDecl
    else if (auto* vdecl = stmt->as<TreeVarDecl*>()) {
        translate_expr(vdecl, bb);
        return bb;
    }
    // OK LvalEqStmt
    else if (auto* leq = stmt->as<TreeLvalEqStmt*>()) {
        translate_expr(leq, bb);
        return bb;
    }
    // OK Block
    else if (auto* Block = stmt->as<TreeBlock*>()) {
        BasicBlock* now = bb;
        newValueDomain();
        // if func
        if (fromFunc) {
            int n = IDValueTable.size();
            IDValueTable[n-1] = IDValueTable[n-2];
        }

        for (unsigned int i = 0; i < Block->child->size(); ++i) {
            TreeStmt* tmp = Block->child->at(i);
            // if 
            now = translate_stmt(tmp, now);
        }

        deleteValueDomain();
        return now;
    }
    // OK else translate_expr don't need to new bb or else
    else {
        TreeExpr* expr = dynamic_cast<TreeExpr*>(stmt);
        if (expr) {
            translate_expr(expr, bb);
        }
        return bb;
    }

    return bb;
}

// return a new module
// call when into a CompUnit
Module* newModule() {
    CompMod = new Module();
    return CompMod;
}

// OK!!
Value* findValue(std::string ss, bool& isGlobal) {
    // 
    isGlobal = false;
    int size = IDValueTable.size();
    for (int i = size; i >= 0; --i) {
        auto it = IDValueTable[i].find(ss);
        if (it != IDValueTable[i].end()) {
            if (i == 0) {
                isGlobal = true;
            }
            return it->second;
        }
    }
    // not find
    return nullptr;
}

void newValueDomain () {
    std::map<std::string, Value*> tid;
    IDValueTable.push_back(tid);
    std::map<std::string, Function*> tfunc;
    FuncValueTable.push_back(tfunc);
}

void deleteValueDomain () {
    IDValueTable.pop_back();
    FuncValueTable.pop_back();
}

void clearSynbolTable () {
    IDSymbolTable.clear();
    FuncSymbolTable.clear();
}

void addRuntimeFuncValue () {
    Type* res;
    std::vector<Type*> params;
    FunctionType* fty;
    Function* f;
    // int getint()
    res = Type::getIntegerTy();
    params.clear();
    fty = FunctionType::get(res, params);
    f = Function::Create(fty, false, "getint", CompMod);
    FuncValueTable[0]["getint"] = f;
    // int getch()
    f = Function::Create(fty, false, "getch", CompMod);
    FuncValueTable[0]["getch"] = f;
    // int getarray(int a[])
    res = Type::getIntegerTy();
    params.clear();
    params.push_back(PointerType::get(Type::getIntegerTy()));
    fty = FunctionType::get(res, params);
    f = Function::Create(fty, false, "getarray", CompMod);
    FuncValueTable[0]["getarray"] = f;
    // void putint(int a)
    res = Type::getUnitTy();
    params.clear();
    params.push_back(Type::getIntegerTy());
    fty = FunctionType::get(res, params);
    f = Function::Create(fty, false, "putint", CompMod);
    FuncValueTable[0]["putint"] = f;
    // void putch(char ch)
    f = Function::Create(fty, false, "putch", CompMod);
    FuncValueTable[0]["putint"] = f;
    // void putarray(int, int [])
    params.push_back(PointerType::get(Type::getIntegerTy()));
    fty = FunctionType::get(res, params);
    f = Function::Create(fty, false, "putarray", CompMod);
    FuncValueTable[0]["putarray"] = f;
    // void starttime()
    res = Type::getUnitTy();
    params.clear();
    fty = FunctionType::get(res, params);
    f = Function::Create(fty, false, "starttime", CompMod);
    FuncValueTable[0]["starttime"] = f;
    // void stoptime()
    f = Function::Create(fty, false, "stoptime", CompMod);
    FuncValueTable[0]["stoptime"] = f;
}

void addToNewDomain (Value* ret, TreeFuncDef* fdef, Function* ff) {
    int index = IDValueTable.size() - 1;
    if (!ret) IDValueTable[index]["return"] = ret;
    // symbol table use lab2's code
    addFuncParamsToTable(fdef);
    // from ff get the arguments value
    for (int i = 0; i < ff->arg_size(); ++i) {
        IDValueTable[index][fdef->params->child->at(i)->ident->IdentName] = ff->getArg(i);
    }
    // add func to funcTable
    auto it = FuncValueTable[0].find(fdef->ident->IdentName);
    if (it == FuncValueTable[0].end()) {
        FuncValueTable[0][fdef->ident->IdentName] = ff;
    }
}

// TODO
void doGlobalVarBinding(std::vector<TreeVarDef*>& defs, BasicBlock* bb) {
    // TODO
}

void translate_root (Node* node) {
    // translate the root to the ir
    // new domain, and 
    auto* cmp = node->as<CompUnit*>();
    newValueDomain();
    clearSynbolTable();
    newDomain();
    // new compMod
    CompMod = new Module();
    // value need to add the runtime function
    addRuntimeFuncValue();
    addRunTimeFunc();
    // translate
    for (unsigned int i = 0; i < cmp->child->size(); ++i) {
        translate_stmt(cmp->child->at(i), nullptr);
    }
}

