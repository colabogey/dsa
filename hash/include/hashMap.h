#pragma once

#include "hashValues.h"
#include "hashTable.h"
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
    void remove(std::string key);
    std::string find(std::string key);
    pHashTableItem create(std::string key, std::string value);

private:
    std::shared_ptr<HashTable> m_pHashTable;
    std::shared_ptr<IHashFunction> m_pHashFunction;
};
