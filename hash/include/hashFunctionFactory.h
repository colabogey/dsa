#pragma once

#include "hashFunction.h"
#include <memory>

class HashFunctionFactory
{
public:
    HashFunctionFactory() = default;
    ~HashFunctionFactory() = default;
    HashFunctionFactory& operator=(HashFunctionFactory& other) {return *this;};
    HashFunctionFactory(HashFunctionFactory& other) {};
    std::shared_ptr<IHashFunction> create();

private:

};
