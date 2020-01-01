//
// Created by Jared Hasson on 2019-03-11.
//

#include "Scheme.h"

using namespace std;

void Scheme::addAttribute(string attr)
{
    mAttributeNames.push_back(attr);
}

void Scheme::setAttribute(unsigned int pos, string val)
{
    mAttributeNames.at(pos) = val;
}

void Scheme::clearAttributes()
{
    mAttributeNames.clear();
}