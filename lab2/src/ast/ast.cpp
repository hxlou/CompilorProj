#include "ast/ast.h"

#include <fmt/core.h>
#include <cassert>

static std::string op_str(OpType op_type) {
    switch (op_type) {
#define OpcodeDefine(x, s)     \
        case x: return s;
#include "common/common.def"
    default:
        return "<unknown>";
    }
}

void print_tree(Node* node, std::string prefix) {
    assert(node != nullptr);
    fmt::print(prefix);


    if (auto *comp = node->as<CompUnit*>()) {
        fmt::print("CompUnit\n");
        for (unsigned int i = 0; i < comp->child->size(); ++i) {
            print_tree(comp->child->at(i), prefix+"    ");
        }
    }

    if (auto *type = node->as<TreeType*>()) {
        switch (type->type)
        {
        case 0:
            fmt::print("Type VOID\n");
            break;
        case 1:
            fmt::print("Type INT\n");
        default:
            break;
        }
    }

    if (auto *id = node->as<TreeIdent*>()) {
        fmt::print("Ident {}\n", id->IdentName);
    }

    if (auto *les = node->as<TreeLvalEqStmt*>()) {
        fmt::print("BinOp Assign\n");
        print_tree(les->lval, prefix + "    ");
        print_tree(les->exp, prefix + "    ");
    }

    if (auto *ret = node->as<TreeReturnStmt*>()) {
        if (ret->expr != nullptr) {
            fmt::print("Return\n");
            print_tree(ret->expr, prefix + "    ");
        }
        else {
            fmt::print("Return Nothing\n");
        }
    }

    if (auto *ifel = node->as<TreeIfStmt*>()) {
        fmt::print("If\n");
        fmt::print(prefix);
        fmt::print("IF Condition\n");
        print_tree(ifel->exp, prefix + "    ");
        fmt::print(prefix);
        fmt::print("If Block\n");
        print_tree(ifel->stmtIf, prefix+"    ");
        if (ifel->hasElse) {
            fmt::print(prefix);
            fmt::print("Else Block\n");
            print_tree(ifel->stmtElse, prefix + "    ");
        }
    }

    if (auto *whil = node->as<TreeWhileStmt*>()) {
        fmt::print("While\n");
        fmt::print(prefix);
        fmt::print("While Condition Express\n");
        print_tree(whil->exp, prefix + "    ");
        fmt::print(prefix);
        fmt::print("While Body\n");
        print_tree(whil->stmt, prefix + "    ");
    }

    if ([[maybe_unused]]auto *bre = node->as<TreeBreakStmt*>()) {
        fmt::print("Break\n");
    }

    if ([[maybe_unused]]auto *conti = node->as<TreeContinueStmt*>()) {
        fmt::print("Continue\n");
    }

    if (auto *block = node->as<TreeBlock*>()) {
        fmt::print("Block\n");
        for (unsigned int i = 0; i < block->child->size(); ++i) {
            print_tree(block->child->at(i), prefix + "    ");
        }
    }

    if (auto *varDecl = node->as<TreeVarDecl*>()) {
        std::string type = varDecl->type->type == 0 ? "VOID" : "INT"; 
        fmt::print("Var Declear {}\n", type);
        for (unsigned int i = 0; i < varDecl->varDef->size(); ++i) {
            print_tree(varDecl->varDef->at(i), prefix + "    ");
        }
    }

    if (auto *varDef = node->as<TreeVarDef*>()) {
        if (varDef -> isArry) {
            fmt::print("Var Define {}", varDef->ident->IdentName);
            for (unsigned int i = 0; i < varDef->child->size(); ++i) {
                fmt::print("[{}]", varDef->child->at(i)->value);
            }
            fmt::print("\n");
        }
        else {
            fmt::print("Var Define And Init {}\n",varDef->ident->IdentName);
            print_tree(varDef->initVal, prefix + "    ");
        }
    }

    if (auto *funcDef = node->as<TreeFuncDef*>()) {
        std::string type = funcDef->type->type == 0 ? "VOID" : "INT";
        fmt::print("Func Def {} {}\n", type, funcDef->ident->IdentName);
        // params
        if (funcDef->params != nullptr) {
            fmt::print(prefix);
            fmt::print("Func Params\n");
            print_tree(funcDef->params, prefix + "    ");
        }
        // block
        print_tree(funcDef->block, prefix + "    ");
    }

    if (auto *funcPs = node->as<TreeFuncParams*>()) {
        for (unsigned int i = 0; i < funcPs->child->size();++i) {
            if (i != 0) fmt::print(prefix);
            fmt::print("Func Param {}\n", i);
            print_tree(funcPs->child->at(i), prefix+"    ");
        }
    }

    if (auto *funcP = node->as<TreeFuncParam*>()) {
        std::string type = funcP->type->type == 0 ? "VOID" : "INT";
        fmt::print("Func Param {} {}",type, funcP->ident->IdentName);
        if (funcP->isArry) {
            fmt::print("[]");
            for (unsigned int i = 0; i < funcP->child->size(); ++i) {
                fmt::print("[{}]", funcP->child->at(i)->value);
            }
        }
        fmt::print("\n");
    }

    if (auto *funcRP = node->as<TreeFuncRParams*>()) {
        for (unsigned int i = 0; i < funcRP->child->size(); ++i) {
            if (i != 0) fmt::print(prefix);
            fmt::print("RealParam{}\n",i);
            print_tree(funcRP->child->at(i), prefix + "    ");
        }
    }

    if (auto *lval = node->as<TreeLVal *>()) {                   // left value
        if (lval->exprs != nullptr && lval->exprs->size() >= 1) {
            // first line cout name
            fmt::print("LeftArrayValue {}\n", lval->ident->IdentName); 
            // then cout the exprs
            for (unsigned int i = 0; i < lval->exprs->size(); ++i) {
                print_tree(lval->exprs->at(i), prefix + "    ");
            }
        }
        else {
            fmt::print("LeftValue {}\n", lval->ident->IdentName);
        }
    }

    if (auto *bin_op = node->as<TreeBinaryExpr *>()) {           // could change into Binary
        fmt::print("BinOp \"{}\"\n", op_str(bin_op->op));
        print_tree(bin_op->lhs, prefix + "    ");
        print_tree(bin_op->rhs, prefix + "    ");
    }

    if (auto *un_op = node->as<TreeUnaryExpr *>()) {             // could change into Unary
        if (un_op->id == nullptr) { // Unary Expression
            fmt::print("UnOp \"{}\"\n", op_str(un_op->op));
            print_tree(un_op->operand, prefix + "    ");
        }
        else {                      // function call
            fmt::print("Funcion Call {}\n", un_op->id->IdentName);
            if (un_op->operand != nullptr)
                print_tree(un_op->operand, prefix + "    ");
        }
    }

    if (auto* lit = node->as < TreeIntegerLiteral *>()) {        // could achange into int
        fmt::print("Int {}\n", lit->value);
    }
    
}