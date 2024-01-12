
#pragma once

#include <string>

class IHashFunction
{
public:
    virtual ~IHashFunction(){};
    virtual int hash(const std::string&) = 0;
};
