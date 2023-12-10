#pragma once

#include "hashValues.h"
#include "IhashFunction.h"
#include <memory>
#include <string>

typedef struct hashTableItem
{
    std::string key;
    std::string value;
} HashTableItem;

typedef std::unique_ptr<hashTableItem> spHashTableItem;


class HashTable
{
public:
    HashTable() = default;
    HashTable(std::shared_ptr<IHashFunction>);
    ~HashTable() = default;
    HashTable& operator=(HashTable& other) {return *this;};
    HashTable(HashTable& other) {};
    void insert(HashTableItem);
    spHashTableItem remove(std::string key);
    spHashTableItem find(std::string key);
    spHashTableItem create(std::string key, std::string value);

private:
    spHashTableItem m_hashTable[BUCKETS];
    std::shared_ptr<IHashFunction> m_spHashFunction;

};
