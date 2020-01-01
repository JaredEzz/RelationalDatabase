//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_RULE_H
#define RELATIONALDATABASE_RULE_H

#include "Predicate.h"

class Rule {
private:
    Predicate mHead;
    vector<Predicate> mPredicateList;
public:
    void setHead(Predicate);
    void addPredicate(Predicate);
    void cleanRule();
    Predicate getHead() const { return mHead; }
    vector<Predicate> getPredList() const { return mPredicateList; }
    string toString();
};


#endif //RELATIONALDATABASE_RULE_H
