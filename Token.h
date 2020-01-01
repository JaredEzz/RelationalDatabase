//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_TOKEN_H
#define RELATIONALDATABASE_TOKEN_H
#include "TokenType.h"

#include <iostream>

using namespace std;

class Token {
private:
    tokenType mType;
    string mValue;
    int mLine;

public:
    Token(tokenType, string, int);
    int getLine() const { return mLine; }
    string getValue() const { return mValue; }
    tokenType getType() const { return mType; }
    string toString() const;
};


#endif //RELATIONALDATABASE_TOKEN_H
