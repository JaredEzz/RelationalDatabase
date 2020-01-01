//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_RELATION_H
#define RELATIONALDATABASE_RELATION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include "Tuple.h"
#include "Scheme.h"

using namespace std;
class Relation {

private:
    string mName;
    Scheme mScheme;
    set<Tuple> mTuples;

public:
    Relation();

    Relation(string);

    void setName(string);

    void setScheme(Scheme);

    void addSchemeAttribute(string);

    void addTuple(Tuple);

    Tuple getTuple(unsigned int);

    string getName() const {
        return mName; }

    Scheme getScheme() const {
        return mScheme; }

    set <Tuple> getTuples() const {
        return mTuples; }

    void clearTuples();

    void clearRelation();

    void select(unsigned int, string);

    void select(unsigned int, unsigned int);

    void project(map<unsigned int, string> &);

    void rename(map<unsigned int, string> &);

    void toString(ofstream &);
};


#endif //RELATIONALDATABASE_RELATION_H
