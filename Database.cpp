//
// Created by Jared Hasson on 2019-03-11.
//

#include "Database.h"

using namespace std;

string printd(vector<string> vec)
{
    stringstream out;

    for (unsigned int i = 0; i < vec.size(); i++)
    {
        out << "(" << vec.at(i) << ")" << " ";
    }

    return out.str();
}

Database::Database(char* arg1, char* arg2) : mParser(arg1, arg2)
{
    mSchemes = mParser.getDatalog().getSchemes();
    mFacts = mParser.getDatalog().getFacts();
    mQueries = mParser.getDatalog().getQueries();
    os.open(arg2);
    initRelations();
    //toString();
    solveQueries();
    os.close();
}

void Database::initRelations()
{
    readSchemes();
    readFacts();
}

void Database::readSchemes(){
    Relation relation;

    for (unsigned int i = 0; i < mSchemes.size(); i++)
    {
        relation.setName(mSchemes.at(i).getIdentity());
        setRelationScheme(relation, i);
        mRelations.insert(pair<string, Relation>(relation.getName(), relation));
        relation.clearRelation();
    }
}

void Database::setRelationScheme(Relation& r, unsigned int i)
{
    for (unsigned int j = 0; j < mSchemes.at(i).getParameterList().size(); j++)
    {
        r.addSchemeAttribute(mParser.getDatalog().getSchemes().at(i).getParameterList().at(j).getValue());
    }
}

void Database::readFacts(){
    Tuple t;

    for (unsigned int i = 0; i < mFacts.size(); i++)
    {
        if (mRelations.count(mFacts.at(i).getIdentity()))
        {
            setTupleAttributes(t, i);
            mRelations.at(mFacts.at(i).getIdentity()).addTuple(t);
            t.clear();
        }
    }
}

void Database::setTupleAttributes(Tuple& t, unsigned int i)
{
    for(unsigned int j = 0; j < mFacts.at(i).getParameterList().size(); j++)
    {
        t.addAttributeValue(mFacts.at(i).getParameterList().at(j).getValue());
    }
}

bool compare (const Relation& r1, const Relation& r2)
{
    return r1.getName() < r2.getName();
}

void Database::solveQueries()
{
    Relation r;
    map<string, unsigned int> variables;
    map<unsigned int, string> variablePos;

    for (unsigned int i = 0; i < mQueries.size(); i++)
    {
        if (mRelations.count(mQueries.at(i).getIdentity()))
        {
            r = mRelations.at(mQueries.at(i).getIdentity());

            for (unsigned int j = 0; j < mQueries.at(i).getParameterList().size(); j++)
            {
                string value = mQueries.at(i).getParameterList().at(j).getValue();

                if (value.at(0) == '\'')
                {
                    r.select(j, value);
                }
                else
                {
                    if (variables.count(value) > 0)
                    {
                        r.select(j, variables.at(value));
                    }

                    variables.insert(pair<string, unsigned int>(value, j));

                    if (variables.size() > variablePos.size())
                    {
                        variablePos.insert(pair<unsigned int, string>(j, value));
                    }
                }

                r.setName("select");
            }
        }

        queryToString(i ,r.getTuples().size());

        if (r.getTuples().size() > 0)
        {
            //r.toString(out);
            r.project(variablePos);
            //r.toString(out);
            r.rename(variablePos);
            r.toString(os);
            cout << endl;
        }

        variables.clear();
        variablePos.clear();
    }
}

void Database::toString()
{
    for (auto& rel : mRelations)
    {
        rel.second.toString(os);
        cout << endl;
    }
}

void Database::queryToString(unsigned int i, unsigned int numMatches)
{
    cout << mQueries.at(i).toString() << "? ";

    if (numMatches > 0)
    {
        cout << "Yes(" << numMatches << ")";
    }
    else
    {
        cout << "No" << endl;
    }
}

