/* 
COMPILER PROJECT
Following: https://www.youtube.com/watch?v=vcSijrRsrY0&list=PLUDlas_Zy_qC7c5tCgTMYq2idyyT241qs
*/

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

enum class TokenType {
    _return,
    int_lit,
    semi
};

struct Token {
    TokenType type;
    std::string value {};
};

std::vector<Token> tokenize(const std::string &contents) {
    std::vector<Token> tokens;
    std::string buf;

    for (int i = 0; i < contents.length(); i++) {
        char c = contents.at(i);
        if (std::isalpha(c)) {
            buf.push_back(c);
            i++;
            while (std::isalnum(contents.at(i))) {
                buf.push_back(contents.at(i));
                i++;
            }
            i--;

            if (buf == "return") {
                tokens.push_back({ TokenType::_return, "" });
                buf.clear();
                continue;
            } else {
                std::cerr << "unknown token: " << buf << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    return std::vector<Token>();
}

int main(int argc, char *argv[]) {

    // arguments check
    if (argc != 2) {
        std::cerr << "usage: ./build/hydro <file>" << std::endl;
        return 1;
    }

    // reading a file
    std::string contents;
    {
        std::stringstream contents_stream;
        std::ifstream file(argv[1]);
        contents_stream << file.rdbuf();
        contents = contents_stream.str();
    }

    std::vector<Token> tokens = tokenize(contents);
    for (const Token &token : tokens) {
        std::cout << "token found" << std::endl;
    }

    return 0;
}