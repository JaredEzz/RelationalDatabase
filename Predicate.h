//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_PREDICATE_H
#define RELATIONALDATABASE_PREDICATE_H

#include "Parameter.h"

#include <vector>

using namespace std;

class Predicate {
private:
    string mIdentity;
    vector<Parameter> mParameterList;
public:
    void setIdentity(string);
    void addParameter(Parameter);
    void cleanPredicate();
    string getIdentity() const { return mIdentity; }
    vector<Parameter> getParameterList() const { return mParameterList; }
    string toString();
};


#endif //RELATIONALDATABASE_PREDICATE_H
