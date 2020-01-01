//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_DATABASE_H
#define RELATIONALDATABASE_DATABASE_H

#include <algorithm>
#include <fstream>
#include "Relation.h"
#include "Parser.h"
#include "Predicate.h"

using namespace std;

class Database {
private:
    Parser mParser;
    vector<Predicate> mSchemes;
    vector<Predicate> mFacts;
    vector<Predicate> mQueries;
    map<string, Relation> mRelations;
    ofstream os;

public:
    Database(char *, char *);

    void initRelations();

    void readSchemes();

    void setRelationScheme(Relation&, unsigned int);

    void readFacts();

    void setTupleAttributes(Tuple&, unsigned int);

    void solveQueries();

    void toString();

    void queryToString(unsigned int, unsigned int);

};


#endif //RELATIONALDATABASE_DATABASE_H
