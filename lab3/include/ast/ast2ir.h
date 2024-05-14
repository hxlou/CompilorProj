#include "ast/ast.h"
#include "accsys/include/ir/ir.h"
#include "accsys/include/ir/type.h"
#include "ast/symbolTable.h"
#include <vector>
#include <map>

std::vector<std::map<std::string, Value*>> IDValueTable;
Module* CompMod;

// translate expression to a value
Value* translate_expr(TreeExpr* expr, BasicBlock* bb) {
    // Lval -> var or array, just do nothing
    if (auto *lval = expr->as<TreeLVal*>()) {
        // var or array
        // it must be declear before, and table should has it

    }
    // int
    else if (auto *cint = expr->as<TreeIntegerLiteral*>()) {
        Value *res = ConstantInt::Create(cint->value);
        return res;
    }
    // Binary
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
    // Unary --> (-a) or (foo(a, b))
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
Value* translate_expr(TreeLvalEqStmt* expr, BasicBlock* bb) {

}

// var declear 
// if it is in a function, it should use alloc and store, and store to the IDValueTable
// if it is a global, it should be store to module and IDValueTable
Value* translate_expr(TreeVarDecl* decl, BasicBlock* bb) {

}

Value* translate_expr(TreeFuncDef* fdef, BasicBlock* bb) {

}

BasicBlock* translate_stmt(TreeStmt* stmt, BasicBlock* bb) {

}

// return a new module
// call when into a CompUnit
Module* newModule() {

}




