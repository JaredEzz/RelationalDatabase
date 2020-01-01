//
// Created by Jared Hasson on 2019-03-11.
//

#include "Parser.h"

using namespace std;

Parser::Parser(char* arg1, char* arg2) : mScanner(arg1), mToken(mScanner.getToken())
{
    try
    {
        parseDatalog();
    }

    catch(Token t)
    {
        ofstream out;
        out.open(arg2);
        out << errorToString();
    }
}

void Parser::parseDatalog()
{
    match(SCHEMES);
    match(COLON);

    if (mToken.getType() == FACTS)
    {
        error(mToken);
    }

    parseSchemeList();
    match(FACTS);
    match(COLON);

    if (mToken.getType() == ID)
    {
        parseFactList();
    }

    match(RULES);
    match(COLON);

    if (mToken.getType() == ID)
    {
        parseRuleList();
    }

    match(QUERIES);
    match(COLON);
    parseQueryList();
}

void Parser::parseSchemeList()
{
    mPredicate.cleanPredicate();
    parseScheme();
    mDatalogParser.addScheme(mPredicate);

    if (mToken.getType() == FACTS)
    {
        return;
    }
    else if (mToken.getType() == ID)
    {
        parseSchemeList();
    }
    else
    {
        error(mToken);
    }
}

void Parser::parseScheme()
{
    parsePredicate();
}

void Parser::parseFactList()
{
    mPredicate.cleanPredicate();
    parseFact();
    mDatalogParser.addFact(mPredicate);

    if(mToken.getType() == RULES)
    {
        return;
    }
    else if(mToken.getType() == ID)
    {
        parseFactList();
    }
    else
    {
        error(mToken);
    }
}

void Parser::parseFact()
{
    parsePredicate();
    match(PERIOD);
}

void Parser::parseRuleList()
{
    mRule.cleanRule();
    parseRule();
    mDatalogParser.addRule(mRule);

    if (mToken.getType() == QUERIES)
    {
        return;
    }
    else if (mToken.getType() == ID)
    {
        parseRuleList();
    }
    else
    {
        error(mToken);
    }
}

void Parser::parseRule()
{
    mPredicate.cleanPredicate();
    parsePredicate();
    mRule.setHead(mPredicate);
    match(COLON_DASH);
    parsePredicateList();
    match(PERIOD);
}

void Parser::parseQueryList()
{
    mPredicate.cleanPredicate();
    parseQuery();
    mDatalogParser.addQuery(mPredicate);
    match(Q_MARK);

    if (mToken.getType() == ID)
    {
        parseQueryList();
    }
    else if (mToken.getType() == END)
    {
        return;
    }
    else
    {
        error(mToken);
    }
}

void Parser::parseQuery()
{
    parsePredicate();
}

void Parser::parsePredicateList()
{
    mPredicate.cleanPredicate();
    parsePredicate();
    mRule.addPredicate(mPredicate);

    if (mToken.getType() == COMMA)
    {
        match(COMMA);
        parsePredicateList();
    }
}

void Parser::parsePredicate()
{
    mPredicate.setIdentity(mToken.getValue());
    match(ID);
    match(LEFT_PAREN);
    parseParameterList();
    match(RIGHT_PAREN);
}

void Parser::parseParameterList()
{
    parseParameter();
    mPredicate.addParameter(mParameter);

    if (mToken.getType() == COMMA)
    {
        match(COMMA);
        parseParameterList();
    }
}

void Parser::parseParameter()
{
    if (mToken.getType() == STRING)
    {
        mParameter.setValue("\'" + mToken.getValue() + "\'");
        mDatalogParser.addValue(mToken.getValue());
        match(STRING);
    }
    else if (mToken.getType() == ID)
    {
        mParameter.setValue(mToken.getValue());
        match(ID);
    }
    else
    {
        error(mToken);
    }
}

void Parser::match(tokenType k)
{
    if (mToken.getType() == k)
    {
        mToken = mScanner.getToken();
    }
    else
    {
        error(mToken);
    }
}

void Parser::error(Token t)
{
    throw t;
}

string Parser::errorToString()
{
    stringstream out;
    out << "Failure!\n" << "  " << mToken.toString();
    return out.str();
}

string Parser::toString()
{
    stringstream out;
    out << "Success!\n" << mDatalogParser.toString();
    return out.str();
}