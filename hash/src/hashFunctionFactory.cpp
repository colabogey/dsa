
#include <memory>
#include "hashFunction.h"
#include "hashFunctionFactory.h"

std::unique_ptr<HashFunction> HashFunctionFactory::create()
{
    std::unique_ptr<HashFunction> hf = std::make_unique<HashFunction>();
    return(hf);
}

