//
// Created by Jared Hasson on 2019-03-11.
//

#include "Tuple.h"

using namespace std;

void Tuple::addAttributeValue(string val)
{
    push_back(val);
}

string const Tuple::getTupleValue(unsigned int i)
{
    return at(i);
}