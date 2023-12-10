#pragma once

#include "hashValues.h"
#include "hashTableItem.h"
#include "hashFunction.h"
#include <memory>
#include <string>

class HashMap
{
public:
    HashMap();
    ~HashMap() = default;
    HashMap& operator=(HashMap& other) {return *this;};
    HashMap(HashMap& other) {};
    void insert(std::string key, std::string value);
    pHashTableItem remove(std::string key);
    pHashTableItem find(std::string key);
    pHashTableItem create(std::string key, std::string value);

private:
    std::unique_ptr<HashTable> m_pHashTable;
    std::unique_ptr<IHashFunction> m_pHashFunction;
};
