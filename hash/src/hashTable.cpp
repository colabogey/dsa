
#include <string>
#include <stdexcept>
#include "hashTable.h"

HashTable::HashTable(std::shared_ptr<IHashFunction> spHashFunction)
{
    m_spHashFunction = spHashFunction;
}

void HashTable::insert(HashTableItem)
{
}

spHashTableItem HashTable::remove(std::string key)
{
    return nullptr;
}

spHashTableItem HashTable::find(std::string key)
{
    return nullptr;
}

spHashTableItem HashTable::create(std::string key, std::string value)
{
    return nullptr;
}


