#pragma once
#include <vector>
#include <map>
#include <string>

enum IdType {
    INT,
    VOID,
    ARRAY_INT,
    FUNC_INT,
    FUNC_VOID
};

std::vector<std::map<std::string, IdType>> IDSymbolTable {};
std::vector<std::map<std::string, IdType>> FuncSymbolTable {};

/**
 * 语义分析具体要求：
 * 1. 符号表相关
 *      调用未定义函数 使用未定义变量
 *      重复定义函数 同一个作用域内重复定义变量
 * 2. 类型检查
 *      变量定义或赋值中左右表达式类型不匹配
 *      操作数类型不匹配 操作数与操作符不匹配
 *      return 返回类型与定义类型不同
 *      函数调用参数个数不匹配
 *      非数组使用[]操作符
 *      非函数使用()操作符
*/