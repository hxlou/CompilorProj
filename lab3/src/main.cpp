#include "ast/ast.h"
#include "ast/ast2ir.h"
#include "../accsys/include/ir/ir_write.h"

#include <fmt/core.h>
#include <fstream>

extern int yyparse();
extern FILE* yyin;

NodePtr root;

int main(int argc, char **argv) {
    // read in from file
    if(argc > 1) {
        for(int i=1; i<argc; i+=2) {
            std::string src_filename(argv[i]);
            std::string dest_filename(argv[i+1]);

            std::ofstream outfile(dest_filename);

            if(!(yyin = fopen(src_filename.c_str(), "r"))) {
                perror(src_filename.c_str());
                return 1;
            }
            root = nullptr;
            yyparse();
            try{    
                print_tree(root);
                Module* mm = translate_root(root);
                fmt::print("************************************\n");
            
                mm->print(outfile, false);
            }
            catch (const char *s) {
                fmt::print("\033[31m[ERROR] :\033[0m {}", s);
                return 1;
            }
            outfile.close();
        }
    }
    else {
        std::ofstream outfile("tmp.acc");
        yyparse();
        try{    
            print_tree(root);       
            Module* mm = translate_root(root);
            fmt::print("************************************\n");
            mm->print(outfile, false);
        }
        catch (const char *s) {
            fmt::print("\033[31m[ERROR] :\033[0m {}", s);
            return 1;
        }
        outfile.close();
    }
    
    fmt::print("[***]Hello, World!\n");
    
    return 0;
}
