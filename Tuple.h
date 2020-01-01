//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_TUPLE_H
#define RELATIONALDATABASE_TUPLE_H

#include <string>
#include <vector>

using namespace std;

class Tuple : public vector<string> {
public:
    void addAttributeValue(string);

    string const getTupleValue(unsigned int);
};


#endif //RELATIONALDATABASE_TUPLE_H
