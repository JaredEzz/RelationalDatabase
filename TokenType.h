//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_TOKENTYPE_H
#define RELATIONALDATABASE_TOKENTYPE_H
#include <map>
#include <string>

using namespace std;

enum tokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    ERROR,
    END
};


#endif //RELATIONALDATABASE_TOKENTYPE_H
