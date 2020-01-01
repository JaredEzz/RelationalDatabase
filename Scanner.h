//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_SCANNER_H
#define RELATIONALDATABASE_SCANNER_H
#include "Token.h"

#include <queue>

using namespace std;

class Scanner {
private:
    int line;
    bool error;
    queue<char> code;
    queue<Token> tokens;
    void readFile(char*);
    void readTokens();
    void scanColon();
    void scanString();
    void scanError();
    void scanIdentity();
    void scanComment();
    void scanNewline();

public:
    Scanner(char*);
    Scanner(){}
    Token getToken();
    string tokensToString();
};


#endif //RELATIONALDATABASE_SCANNER_H
