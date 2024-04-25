/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_LLL_MYC_ACCIPIT_MAIN_LAB1_BUILD_SYSY_TAB_HH_INCLUDED
# define YY_YY_HOME_LLL_MYC_ACCIPIT_MAIN_LAB1_BUILD_SYSY_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    VOID = 259,                    /* VOID  */
    NUM = 260,                     /* NUM  */
    ADD = 261,                     /* ADD  */
    SUB = 262,                     /* SUB  */
    MUL = 263,                     /* MUL  */
    DIV = 264,                     /* DIV  */
    AND = 265,                     /* AND  */
    NOT = 266,                     /* NOT  */
    OR = 267,                      /* OR  */
    MOD = 268,                     /* MOD  */
    RP = 269,                      /* RP  */
    LP = 270,                      /* LP  */
    RB = 271,                      /* RB  */
    LB = 272,                      /* LB  */
    RC = 273,                      /* RC  */
    LC = 274,                      /* LC  */
    SEMI = 275,                    /* SEMI  */
    COMMA = 276,                   /* COMMA  */
    IF = 277,                      /* IF  */
    ELSE = 278,                    /* ELSE  */
    WHILE = 279,                   /* WHILE  */
    BREAK = 280,                   /* BREAK  */
    CONTINUE = 281,                /* CONTINUE  */
    RETURN = 282,                  /* RETURN  */
    LT = 283,                      /* LT  */
    LE = 284,                      /* LE  */
    GT = 285,                      /* GT  */
    GE = 286,                      /* GE  */
    EQ = 287,                      /* EQ  */
    NE = 288,                      /* NE  */
    ASSIGNOP = 289,                /* ASSIGNOP  */
    IDENT = 290,                   /* IDENT  */
    comment = 291                  /* comment  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "/home/lll/MyC/accipit-main/lab1/src/sysy.y"

    int ival;                       // value
    // std::string     name;           // ident name
    OpType          op;             // operation
    
    std::vector<int>*                   vecInt;     // array_int
    std::vector<TreeIntegerLiteral*>*   vecTreeInt;
    std::vector<TreeVarDef*>*           vecTreeVarDef; 
    std::vector<TreeExpr*>*             vecTreeExpr;
    std::vector<TreeStmt*>*             vecStmt;
    std::vector<TreeFuncParam*>*        vecFuncParam;

    TreeExpr*       expr;           // expression
    TreeStmt*       stmt;           // statement
    TreeType*       type;           // type
    TreeIdent*      ident;          // ident 
    TreeIntegerLiteral* integer;    // 
    TreeVarDef*     varDef;         // var def
    TreeVarDecl*    varDecl;        // var decl
    TreeLVal*       lVal;           // left value
    TreeFuncRParams* funcRP;        // func call's params
    TreeFuncParam*  funcP;          // func's param
    TreeFuncParams* funcPs;         // 
    CompUnit*       comp;           // 
    Node*           nptr;           // node
    

#line 128 "/home/lll/MyC/accipit-main/lab1/build/sysy.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_LLL_MYC_ACCIPIT_MAIN_LAB1_BUILD_SYSY_TAB_HH_INCLUDED  */
