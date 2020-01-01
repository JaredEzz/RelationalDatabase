//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_PARSER_H
#define RELATIONALDATABASE_PARSER_H

#include <fstream>
#include "Rule.h"
#include "Datalog.h"
#include "Scanner.h"
#include "Token.h"

class Parser {
private:
    Datalog mDatalogParser;
    Rule mRule;
    Predicate mPredicate;
    Parameter mParameter;
    Scanner mScanner;
    Token mToken;

    void parseSchemeList();
    void parseScheme();
    void parseFactList();
    void parseFact();
    void parseRuleList();
    void parseRule();
    void parseQueryList();
    void parseQuery();
    void parsePredicateList();
    void parsePredicate();
    void parseParameterList();
    void parseParameter();
    void match(tokenType);
    void error(Token);

public:
    Parser(char*, char*);
    void parseDatalog();
    Datalog getDatalog() const { return mDatalogParser; }
    Rule getRule() const { return mRule; }
    Predicate getPredicate() const { return mPredicate; }
    Parameter getParameter() const { return mParameter; }
    string errorToString();
    string toString();
};


#endif //RELATIONALDATABASE_PARSER_H
