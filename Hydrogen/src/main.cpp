/* 
COMPILER PROJECT
Following: https://www.youtube.com/watch?v=vcSijrRsrY0&list=PLUDlas_Zy_qC7c5tCgTMYq2idyyT241qs
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {

    // arguments check
    if (argc != 2) {
        std::cerr << "usage: ./build/hydro <file>" << std::endl;
        return 1;
    }

    // file open
    std::ifstream file(argv[1]);
    if (file.is_open()) {
        std::string line;
        
        // parse for return
        std::string ret = "return";
        if (line.find(ret) != std::string::npos) {
            std::cout << ".global _start" << std::endl;
            std::cout << "_start:" << std::endl;
            std::cout << "mov rax, 60" << std::endl;
            std::cout << "mov rdi, " << line.substr(line.find("return") + 6) << std::endl;
            std::cout << "syscall" << std::endl;
        } else {
            std::cerr << "No return statement found" << std::endl;
        }

    } else {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    return 0;
}