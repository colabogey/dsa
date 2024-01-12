
#include <memory>
#include "IHashFunction.h"
#include "hashFunction.h"
#include "hashFunctionFactory.h"

std::shared_ptr<IHashFunction> HashFunctionFactory::create()
{
    std::shared_ptr<IHashFunction> hf = std::make_shared<HashFunction>();
    return(hf);
}

