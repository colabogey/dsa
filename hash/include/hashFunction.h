#pragma once

#include <string>

class HashFunction
{
public:
    HashFunction();
    virtual ~HashFunction();
    HashFunction& operator=(HashFunction& other) {return *this;};
    HashFunction(HashFunction& other) {};

    int hash(const std::string&);

private:

};
