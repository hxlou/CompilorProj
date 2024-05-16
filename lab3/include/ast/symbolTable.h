#pragma once
#include <vector>
#include <map>
#include <string>
#include <ast/ast.h>
#include <iostream>

enum DeType {
    ERROR,
    INT,
    VOID,
    FUNC_INT,
    FUNC_VOID,
    POINTER,
    ARRAY_INT
};

struct IdentTypeNode {
    DeType type;
    // for array
    int dimension;
    std::vector<int> domainSize {};
    // IdentTypeNode::IdentTypeNode() : type(DeType::ERROR), dimension(0) {};
    // IdentTypeNode::IdentTypeNode(DeType t, int d) : type(t), dimension(d) {};
};

struct FuncTypeNode {
    DeType type;
    // for funcDef
    std::vector<IdentTypeNode> funcParams {};

    // FuncTypeNode::FuncTypeNode(DeType t) : type(t) {
    //     funcParams.clear();
    // };
};

extern int isInLoop;
extern FuncTypeNode* nowFunc;
extern std::vector<std::map<std::string, IdentTypeNode>> IDSymbolTable;
extern std::vector<std::map<std::string, FuncTypeNode>> FuncSymbolTable;

// pre declear
bool check (TreeLvalEqStmt* leq);

bool check (TreeReturnStmt* ret);

bool check (TreeIfStmt* iff);

bool check (TreeWhileStmt* wh);

DeType check_type(TreeExpr* expr);

IdentTypeNode* checkIdDefine(TreeIdent* ident);

FuncTypeNode* checkFuncDefine(TreeIdent* ident);

bool addToIDSymbolTable (TreeVarDecl* node);

FuncTypeNode* addToFuncSymbolTable (TreeFuncDef* node);

void addFuncParamsToTable(TreeFuncDef* node);

void newDomain();

void deleteDomain();

void addRunTimeFunc();

