#pragma once
#include <cstdint>
#include <type_traits>
#include <string>
#include <vector>

enum OpType {                           // this is enum for op( +-*/ and so on)
#define OpcodeDefine(x, s) x,
#include "common/common.def"
};

enum NodeType {                         // this is enum for NodeType
#define TreeNodeDefine(x) x,
#include "common/common.def"
};

struct Node;
using NodePtr = Node*;
struct TreeExpr;
using ExprPtr = TreeExpr*;
struct TreeType;

struct Node;
struct TreeStmt;
struct CompUnit;
struct TreeType;
struct TreeIdent;
struct TreeLvalEqStmt;
struct TreeReturnStmt;
struct TreeIfStmt;
struct TreeWhileStmt;
struct TreeBreakStmt;
struct TreeContinueStmt;
struct TreeBlock;
struct TreeVarDecl;
struct TreeVarDef;
struct TreeFuncDef;
struct TreeFuncRParams;
struct TreeFuncParams;
struct TreeFuncParam;
struct TreeExpr;
struct TreeBinaryExpr;
struct TreeUnaryExpr;
struct TreeIntegerLiteral;
struct TreeLVal;


struct Node {                                                               // paser base struct Node
    NodeType node_type;                         // NodeType
    
    Node(NodeType type) : node_type(type) {}    // construct
    virtual ~Node() {};

    template <typename T> bool is() {           // is NodeType
        return node_type == std::remove_pointer_t<T>::this_type;
    }
    template <typename T> T as() {              // change this to T if OK
        if (is<T>())
            return static_cast<T>(this);
        return nullptr;
    }
    template <typename T> T as_unchecked() {    // change this to T without check
        return static_cast<T>(this); 
    }     

};

struct TreeStmt : public Node {

    TreeStmt(NodeType type) : Node(type) {};
    virtual ~TreeStmt() {};
};

struct TreeExpr : public TreeStmt {                                             // Tree Exoression
    TreeExpr(NodeType type) : TreeStmt(type) {}
    virtual ~TreeExpr() {};
};

struct CompUnit :public Node {
    constexpr static NodeType this_type = ND_CompUnit;

    std::vector<TreeStmt* > * child;

    CompUnit(std::vector<TreeStmt* > * ch) :
        Node(this_type), child(ch) {};
    virtual ~CompUnit() {};
};

struct TreeType : public Node {
    // type node include void and int
    constexpr static NodeType this_type = ND_Type;
    // 0    void
    // 1    int
    // 2    float
    // ...  so on
    unsigned int type;

    TreeType(unsigned int type) : 
        Node(this_type), type(type) {};
    virtual ~TreeType() {};
};

struct TreeIdent : public TreeExpr {
    constexpr static NodeType this_type = ND_Ident;
    std::string IdentName;
    
    TreeIdent(std::string name) : TreeExpr(this_type) , IdentName(name){};
    virtual ~TreeIdent() {};
};

struct TreeLvalEqStmt : public TreeStmt {
    constexpr static NodeType this_type = ND_LvalEqStmt;

    TreeExpr *lval, *exp;

    TreeLvalEqStmt(TreeExpr* l, TreeExpr* e): 
        TreeStmt(this_type), lval(l), exp(e) {};

};

struct TreeReturnStmt : public TreeStmt {
    constexpr static NodeType this_type = ND_Return;

    TreeExpr* expr;

    TreeReturnStmt(TreeExpr* e) :
        TreeStmt(this_type), expr(e) {};
    virtual ~TreeReturnStmt() {};
};

struct TreeIfStmt : public TreeStmt {
    constexpr static NodeType this_type = ND_If;
    // "if" "(" Exp ")" Stmt ["else" Stmt]
    struct TreeExpr* exp;
    struct TreeStmt* stmtIf;
    struct TreeStmt* stmtElse;
    bool hasElse = false;

    TreeIfStmt(TreeExpr* e, TreeStmt* s1, TreeStmt* s2, bool has = false) : 
         TreeStmt(this_type), exp(e), stmtIf(s1), stmtElse(s2), hasElse(has) {};
    virtual ~TreeIfStmt() {};
};

struct TreeWhileStmt : public TreeStmt {
    constexpr static NodeType this_type = ND_While;
    // "while" "(" Exp ")" Stmt
    TreeExpr* exp;
    TreeStmt* stmt;

    TreeWhileStmt(TreeExpr* exp, TreeStmt* stmt) :
         TreeStmt(this_type), exp(exp), stmt(stmt) {};
    virtual ~TreeWhileStmt() {};
};

struct TreeBreakStmt : public TreeStmt {
    constexpr static NodeType this_type = ND_Break;

    TreeBreakStmt() : TreeStmt(this_type) {};
    virtual ~TreeBreakStmt() {};
};

struct TreeContinueStmt : public TreeStmt {
    constexpr static NodeType this_type = ND_Continue;

    TreeContinueStmt() : TreeStmt(this_type) {};
    virtual ~TreeContinueStmt() {};
};

struct TreeBlock : public TreeStmt {
    constexpr static NodeType this_type = ND_Block;
    // "{" {BlockItem} "}";
    std::vector<TreeStmt* >  * child;

    TreeBlock() : TreeStmt(this_type) {};
    TreeBlock(std::vector<TreeStmt* > * ch) :TreeStmt(this_type), child(ch) {};
    virtual ~TreeBlock() {};
};

// struct TreeBlockItem : public TreeStmt {
//     constexpr static NodeType this_type = ND_BlockItem;
//     // BlockItem     ::= Decl | Stmt;
//     TreeStmt* stmt;
//     TreeBlockItem(TreeStmt* s) :
//         stmt(s), TreeStmt(this_type) {};
//     virtual ~TreeBlockItem() {};
// };

struct TreeVarDecl : public TreeStmt {
    constexpr static NodeType this_type = ND_VarDecl;
    // VarDecl       ::= BType VarDef {"," VarDef} ";";
    TreeType* type;
    std::vector<TreeVarDef* > * varDef;

    TreeVarDecl(TreeType* t, std::vector<TreeVarDef* > * defs) :
        TreeStmt(this_type), type(t), varDef(defs) {};
    virtual ~TreeVarDecl() {};
};

struct TreeVarDef : public TreeStmt {
    constexpr static NodeType this_type = ND_VarDef;
    // VarDef        ::= IDENT "=" InitVal
    //                 | IDENT {"[" INT_CONST "]"};
    TreeIdent* ident;
    bool isArry = false;
    std::vector<TreeIntegerLiteral* > * child;
    TreeExpr* initVal;

    TreeVarDef (TreeIdent* i, bool is, std::vector<TreeIntegerLiteral* > * ch, TreeExpr* expr) :
        TreeStmt(this_type), ident(i), isArry(is), child(ch), initVal(expr) {};
    virtual ~TreeVarDef () {};
};

struct TreeFuncDef : public TreeStmt {
    constexpr static NodeType this_type = ND_FuncDef;// FuncDef       ::= FuncType IDENT "(" [FuncFParams] ")" Block;
    TreeType* type;
    TreeIdent* ident;
    TreeFuncParams* params;
    TreeStmt* block;
    TreeFuncDef(TreeType* t, TreeIdent* i, TreeFuncParams* param, TreeStmt* b) : 
        TreeStmt(this_type), type(t), ident(i), params(param), block(b) {};
    virtual ~TreeFuncDef() {};
};

struct TreeFuncParams : public TreeStmt {
    constexpr static NodeType this_type = ND_FuncParams;
    // FuncFParams   ::= FuncFParam {"," FuncFParam};
    std::vector<TreeFuncParam*>* child;

    TreeFuncParams(std::vector<TreeFuncParam*>* ch) :
         TreeStmt(this_type) , child(ch) {};
    virtual ~TreeFuncParams() {};
};

struct TreeFuncParam : public TreeStmt {
    constexpr static NodeType this_type = ND_FuncParam;
    // FuncFParam    ::= BType IDENT ["[" "]" {"[" INT_CONST "]"}];
    TreeType*  type;
    TreeIdent* ident;
    bool isArry;
    std::vector<TreeIntegerLiteral * > * child;

    TreeFuncParam(TreeType* t, TreeIdent* ident, bool is, std::vector<TreeIntegerLiteral* > * ch) :
         TreeStmt(this_type), type(t), ident(ident), isArry(is), child(ch) {};
    virtual ~TreeFuncParam() {};
};

struct TreeFuncRParams : public TreeExpr {
    constexpr static NodeType this_type = ND_FuncRParams;

    std::vector<TreeExpr* > * child;

    TreeFuncRParams(std::vector<TreeExpr* > * ch) : 
        TreeExpr(this_type), child(ch)  {};
};

struct TreeBinaryExpr : public TreeExpr {                                   // Tree Expression
    constexpr static NodeType this_type = ND_BinaryExpr;
    OpType op;
    ExprPtr lhs, rhs;
    TreeBinaryExpr(OpType op, ExprPtr lhs, ExprPtr rhs)
        : TreeExpr(this_type), op(op), lhs(lhs), rhs(rhs) {
    }
    virtual ~TreeBinaryExpr() {};
};

struct TreeUnaryExpr : public TreeExpr {                                    // Tree Expression Node
    constexpr static NodeType this_type = ND_UnaryExpr;
    OpType op;
    ExprPtr operand;
    TreeIdent* id;
    TreeUnaryExpr(OpType op, ExprPtr operand, TreeIdent* i = nullptr)
        : TreeExpr(this_type), op(op), operand(operand),id(i) {
    }
    virtual ~TreeUnaryExpr() {};
};

struct TreeIntegerLiteral : public TreeExpr {                               // use to store uint_64(int)
    constexpr static NodeType this_type = ND_IntegerLiteral;
    int64_t value;
    TreeIntegerLiteral(int64_t value) : TreeExpr(this_type), value(value) {}
    virtual ~TreeIntegerLiteral() {};
};

struct TreeLVal : public TreeExpr {
    constexpr static NodeType this_type = ND_LVal;

    TreeIdent* ident;
    bool hasExpress;
    std::vector<TreeExpr* > * exprs;

    TreeLVal    (TreeIdent* i, std::vector<TreeExpr* > * exprs) :
        TreeExpr(this_type), ident(i), exprs(exprs)  {
            if (exprs != nullptr) hasExpress = exprs->size();
            else hasExpress = false;
        };
};



/// A possible helper function dipatch based on the type of `TreeExpr`
void print_tree(Node* node, std::string prefix = "", bool isfunctiondef = false);

/**
 * Node(base)
 *  -> CompUnit
 *  -> Type
 *  -> Stmt
 *      -> IfStmt
 *      -> WhileStmt
 *      -> BreakStmt
 *      -> ContinueStmt
 *      -> Block
 *      -> BlockItem
 *      -> VarDecl
 *      -> VarDef
 *      -> FuncParams
 *      -> FuncDef
 *      -> Expr
 *          -> Ident
 *          -> Binary
 *          -> Unary
 *          -> Integer
 *          -> LVal
 *          -> PrimaryExp
 *          -> FuncRParams
*/



// struct TreePirvateExpr : public TreeExpr {
//     constexpr static NodeType this_type = ND_PrimaryExp;

//     int index;
//     TreeExpr* expr;
//     TreeLVal* lval;
//     TreeIntegerLiteral* num;

//     TreePirvateExpr(int index, TreeExpr* e, TreeLVal* l, TreeIntegerLiteral* num) :
//          TreeExpr(this_type), index(index), expr(e), lval(l), num(num) {};
//     virtual ~TreePirvateExpr() {};
// };