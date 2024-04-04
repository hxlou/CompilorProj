%option noinput
%option nounput
%option noyywrap

/* defination */
%{
    #include <ast/ast.h>
    #include "sysy.tab.hh"
    #include <fmt/core.h>
%}

%x COMMENT_STATE

blank   [ \t\n\r\v]

/* NUM */
ADD     "+"
SUB     "-"
MUL     "*"
DIV     "/"
MOD     "%"
AND     "&&"
NOT     "!"
OR      "||"

LP      "("
RP      ")"
LB      "["
RB      "]"
LC      "{"
RC      "}"

SEMI    ";"
COMMA   ","
DOT     "."

IF      "if"
ELSE    "else"
WHILE   "while"
BREAK   "break"
CONTINUE    "continue"
RETURN  "return"

LT      "<"
LE      "<="
GT      ">"
GE      ">="
EQ      "=="
NE      "!=" 
ASSIGNOP    "="

INT     "int"
VOID    "void"
NUM     0|[1-9][0-9]*
IDENT   [A-Za-z_][A-Za-z0-9_]*
%%
{ASSIGNOP}          {return ASSIGNOP;}     
{blank}             {}
{LT}                {return LT;}
{LE}                {return LE;}
{GT}                {return GT;}
{GE}                {return GE;}
{EQ}                {return EQ;}
{NE}                {return NE;}
{INT}               {yylval.type = new TreeType(1); return INT;}
{VOID}              {yylval.type = new TreeType(0); return VOID;}
{ADD}               {return ADD;}
{SUB}               {return SUB;}
{MUL}               {return MUL;}
{DIV}               {return DIV;}
{MOD}               {return MOD;}
{AND}               {return AND;}
{NOT}               {return NOT;}
{OR}                {return OR;}
{LP}                {return LP;}
{RP}                {return RP;}
{LB}                {return LB;}
{RB}                {return RB;}
{LC}                {return LC;}
{RC}                {return RC;}
{SEMI}              {return SEMI;}
{COMMA}             {return COMMA;}
{IF}                {return IF;}
{ELSE}              {return ELSE;}
{WHILE}             {return WHILE;}
{BREAK}             {return BREAK;}
{CONTINUE}          {return CONTINUE;}
{RETURN}            {return RETURN;}
{NUM}               {yylval.integer = new TreeIntegerLiteral(atoi(yytext)); return NUM;}
{IDENT}             {yylval.ident = new TreeIdent(yytext); return IDENT;}

"//"[^"\n"]*        { /* ignore */ }
"/*"                { BEGIN(COMMENT_STATE); }
<COMMENT_STATE>"*/" { BEGIN(INITIAL); }
<COMMENT_STATE>.    { /* Ignore */ }
<COMMENT_STATE>\n   { /* Ignore */ }
%%

/* user code */