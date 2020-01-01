//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_PARAMETER_H
#define RELATIONALDATABASE_PARAMETER_H

#include <sstream>
#include <string>

using namespace std;

class Parameter {
private:
    string mValue;

public:
    Parameter(){}
    void setValue(string);
    string getValue() const { return mValue; }
    string toString();
};


#endif //RELATIONALDATABASE_PARAMETER_H
