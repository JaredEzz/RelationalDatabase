//
// Created by Jared Hasson on 2019-03-11.
//

#include "Relation.h"

#include <fstream>

using namespace std;

Relation::Relation(string n) : mName(n)
{
    // Empty but necessary constructor
}

string print(vector<string> vec)
{
    stringstream out;

    for (unsigned int i = 0; i < vec.size(); i++)
    {
        cout << "(" << vec.at(i) << ")" << " ";
    }

    return out.str();
}

void Relation::setName(string n)
{
    mName = n;
}

void Relation::setScheme(Scheme schm)
{
    mScheme = schm;
}

void Relation::addSchemeAttribute(string attr)
{
    mScheme.addAttribute(attr);
}

void Relation::addTuple(Tuple t)
{
    mTuples.insert(t);
}

Tuple Relation::getTuple(unsigned int i)
{
    return *next(mTuples.begin(), i);
}

void Relation::clearTuples()
{
    mTuples.clear();
}

void Relation::clearRelation()
{
    mName = "";
    mScheme.clearAttributes();
    mTuples.clear();
}

void Relation::select(unsigned int pos, string val)
{
    set<Tuple> newTups;

    for (auto& t : mTuples)
    {
        if (t.at(pos) == val)
        {
            newTups.insert(t);
        }
    }

    mTuples = newTups;
    setName("select");
}

void Relation::select(unsigned int pos1, unsigned int pos2)
{
    set<Tuple> newTups;

    for (auto& t : mTuples)
    {
        if (t.at(pos1) == t.at(pos2))
        {
            newTups.insert(t);
        }
    }

    mTuples = newTups;
    setName("select");
}

void Relation::project(map<unsigned int, string>& variables)
{
    set<Tuple> newTups;
    Scheme newScheme;
    Tuple t;

    for (auto& v : variables)
    {
        newScheme.addAttribute(mScheme.getAttributeNames().at(v.first));
    }

    for (auto& tup : mTuples)
    {
        for (auto& v : variables)
        {
            t.addAttributeValue(tup.at(v.first));
        }

        if(variables.size() > 0)
        {
            newTups.insert(t);
            t.clear();
        }
    }

    mTuples = newTups;
    mScheme = newScheme;
    setName("project");
}

void Relation::rename(map<unsigned int, string>& variables)
{
    Scheme newScheme;

    for (auto& v : variables)
    {
        newScheme.addAttribute(v.second);
    }

    mScheme = newScheme;
    setName("rename");
}

void Relation::toString(ofstream& out)
{
    //out << name << endl;

    if (mTuples.size() == 0)
    {
        return;
    }
//
    cout << endl;

    for (unsigned int i = 0; i < mTuples.size(); i++)
    {
        cout << " ";

        for (unsigned int j = 0; j < mScheme.getAttributeNames().size(); j++)
        {
            cout << " " << mScheme.getAttributeNames().at(j) << "=" << getTuple(i).getTupleValue(j);
            if (j+1 < mScheme.getAttributeNames().size())
            {
                cout << ",";
            }
        }

        if (i+1 < mTuples.size()) {
            cout << endl;
        }
    }
}
