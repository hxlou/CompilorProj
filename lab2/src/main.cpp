#include "ast/ast.h"
#include <fmt/core.h>

extern int yyparse();
extern FILE* yyin;

NodePtr root;

int main(int argc, char **argv) {
    // read in from file
    if(argc > 1) {
        for(int i=1; i<argc; i++) {
            if(!(yyin = fopen(argv[i], "r"))) {
                perror(argv[1]);
                return 1;
            }
            root = nullptr;
            yyparse();
            try{    
                print_tree(root);       //?root存在内存泄漏
            }
            catch (const char *s) {
                fmt::print("\033[31m[ERROR] :\033[0m {}", s);
                return 1;
            }
        }
    }
    else {
        yyparse();
        try{    
            print_tree(root);       //?root存在内存泄漏
        }
        catch (const char *s) {
            fmt::print("\033[31m[ERROR] :\033[0m {}", s);
            return 1;
        }
    }
    
    fmt::print("[***]Hello, World!\n");
    
    return 0;
}
