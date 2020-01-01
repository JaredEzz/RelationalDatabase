//
// Created by Jared Hasson on 2019-03-11.
//

#include "Predicate.h"

using namespace std;

void Predicate::setIdentity(string s)
{
    mIdentity = s;
}

void Predicate::addParameter(Parameter p)
{
    mParameterList.push_back(p);
}

void Predicate::cleanPredicate()
{
    mParameterList.clear();
}

string Predicate::toString()
{
    stringstream out;
    out << mIdentity << "(";

    for (unsigned i = 0; i < mParameterList.size(); i++)
    {
        out << mParameterList[i].getValue();

        if(i < mParameterList.size()-1)
        {
            out << ",";
        }
    }

    out << ")";

    return out.str();
}