#pragma once

#include "hashValues.h"
#include "hashTableItem.h"
#include <memory>
#include <string>

class HashTable
{
public:
    HashTable();
    ~HashTable() = default;
    HashTable& operator=(HashTable& other) {return *this;};
    HashTable(HashTable& other) {};
    void insert(int idx, pHashTableItem);
    pHashTableItem remove(int idx);
    pHashTableItem find(int idx);

private:
    pHashTableItem m_hashTable[BUCKETS];

};
