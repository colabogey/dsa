#include "hashFunction.h"
#include "hashValues.h"
#include <cstdio>

HashFunction::HashFunction()
{
}

HashFunction::~HashFunction()
{
}

int HashFunction::hash(const std::string& str)
{
    unsigned long hash = 0;
    for(int i = 0; i < str.length(); i++)
    {
        hash += str[i];
    }
    return hash % BUCKETS;
}

