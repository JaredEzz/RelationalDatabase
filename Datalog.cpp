//
// Created by Jared Hasson on 2019-03-11.
//

#include "Datalog.h"

using namespace std;

void Datalog::addScheme(Predicate s)
{
    mSchemes.push_back(s);
}

void Datalog::addFact(Predicate f)
{
    mFacts.push_back(f);
}

void Datalog::addQuery(Predicate q)
{
    mQueries.push_back(q);
}

void Datalog::addRule(Rule r) {
    mRules.push_back(r);
}

void Datalog::addValue(string str)
{
    mValues.insert(str);
}

string Datalog::toString()
{
    stringstream out;
    out << "Schemes(" << mSchemes.size() << "):\n";

    for (unsigned i = 0; i < mSchemes.size(); i++)
    {
        out << "  " << mSchemes[i].toString() << endl;
    }

    out << "Facts(" << mFacts.size() << "):\n";

    for (unsigned i = 0; i < mFacts.size(); i++)
    {
        out << "  " << mFacts[i].toString() << endl;
    }

    out << "Rules(" << mRules.size() << "):\n";

    for (unsigned i = 0; i < mRules.size(); i++)
    {
        out << "  " << mRules[i].toString() << endl;
    }

    out << "Queries(" << mQueries.size() << "):\n";

    for (unsigned i = 0; i < mQueries.size(); i++)
    {
        out << "  " << mQueries[i].toString() << endl;
    }

    out << "Domain(" << mValues.size() << "):";
    set<string>::iterator it;

    for (it = mValues.begin(); it != mValues.end(); it++)
    {
        string s = *it;
        out << endl << "  \'" << s << "\'";
    }

    return out.str();
}