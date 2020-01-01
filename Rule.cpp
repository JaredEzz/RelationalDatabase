//
// Created by Jared Hasson on 2019-03-11.
//

#include "Rule.h"

using namespace std;

void Rule::setHead(Predicate p)
{
    mHead = p;
}

void Rule::addPredicate(Predicate p)
{
    mPredicateList.push_back(p);
}

void Rule::cleanRule()
{
    mPredicateList.clear();
}

string Rule::toString()
{
    stringstream out;
    out << mHead.toString() << " :- ";

    for (unsigned i = 0; i < mPredicateList.size(); i++)
    {
        out << mPredicateList[i].toString();

        if (i < mPredicateList.size()-1)
        {
            out << ",";
        }
    }

    return out.str();
}