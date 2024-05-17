#pragma once
#include "ast/ast.h"
#include "../../accsys/include/ir/ir.h"
#include "../../accsys/include/ir/type.h"
#include "ast/symbolTable.h"

#include <vector>
#include <map>

extern int isIRinLoop;
extern BasicBlock* loopExit;
extern BasicBlock* loopEntry;
extern BasicBlock* funcEntry;
extern bool isIRInFunc;
extern std::vector<TreeVarDef*> globalVarBinding;
extern std::vector<std::pair<BasicBlock*, BasicBlock*>> allLoops;

extern std::vector<std::map<std::string, Value*>> IDValueTable;
extern std::vector<std::map<std::string, Function*>> FuncValueTable;
extern Module* CompMod;

// function pre declear
Value* translate_expr(TreeExpr* expr, BasicBlock* bb);

void translate_expr(TreeLvalEqStmt* expr, BasicBlock* bb);

void translate_expr(TreeVarDecl* decl, BasicBlock* bb);

Value* translate_expr(TreeFuncDef* fdef, BasicBlock* bb = nullptr);

BasicBlock* translate_stmt(TreeStmt* stmt, BasicBlock* bb, bool fromFunc = false);

Module* newModule();

Value* findValue(std::string ss, bool& isGlobal);

void newValueDomain();

void deleteValueDomain();

void clearSynbolTable();

void addRuntimeFuncValue();

void addToNewDomain (Value* ret, TreeFuncDef* fdef, Function* ff);

void doGlobalVarBinding(std::vector<TreeVarDef*>& defs, BasicBlock* bb);

std::string transName (std::string name);

std::string getTranstedName (std::string name);

std::string getPrefix (std::string name);

void clearNameNumTable();

Module* translate_root (Node* node);

