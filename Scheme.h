//
// Created by Jared Hasson on 2019-03-11.
//

#ifndef RELATIONALDATABASE_SCHEME_H
#define RELATIONALDATABASE_SCHEME_H

#include <vector>
#include <string>

using namespace std;

class Scheme {
private:
    vector<string> mAttributeNames;
public:
    Scheme(){};

    void addAttribute(string);

    void setAttribute(unsigned int, string);

    vector<string> getAttributeNames() const { return mAttributeNames; }

    void clearAttributes();
};


#endif //RELATIONALDATABASE_SCHEME_H
