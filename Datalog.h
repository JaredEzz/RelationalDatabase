//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_DATALOG_H
#define RELATIONALDATABASE_DATALOG_H

#include <set>
#include "Rule.h"

class Datalog {
private:
    vector<Predicate> mSchemes;
    vector<Predicate> mFacts;
    vector<Predicate> mQueries;
    vector<Rule> mRules;
    set<string> mValues;

public:
    Datalog(){};
    void addScheme(Predicate);
    void addFact(Predicate);
    void addQuery(Predicate);
    void addRule(Rule);
    void addValue(string);
    vector<Predicate> getSchemes() const { return mSchemes; }
    vector<Predicate> getFacts() const { return mFacts; }
    vector<Predicate> getQueries() const { return mQueries; }
    vector<Rule> getRules() const { return mRules; }
    string toString();
};


#endif //RELATIONALDATABASE_DATALOG_H
