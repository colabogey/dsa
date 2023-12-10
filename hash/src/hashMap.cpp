
#include <string>
#include "hashTable.h"
#include "hashMap.h"
#include "hashFunction.h"
#include "hashFunctionFactory.h"

HashMap::HashMap()
{
    std::unique_ptr<HashFunctionFactory> hff = std::make_unique<HashFunctionFactory>();
    m_pHashFunction = hff->create();
    m_pHashTable = std::make_unique<HashTable>();
    /*
    make a hash func
    make a hash table
    methods are like insert, remove, find, 
    hashTable create is part of this guys remove

    hash TABLE has NO USE for the hashFunction

    maybe call this thing unordered set

    get the IHashFunction from a factory
    or forget the fanciness

    */
}

void HashMap::insert(std::string key, std::string value)
{
    pHashTableItem pI = std::make_unique<HashTableItem>(key, value);
    int idx = m_pHashFunction->hash(key);
    m_pHashTable->insert(idx, std::move(pI));
}

pHashTableItem HashMap::remove(std::string key)
{
    int idx = m_pHashFunction->hash(key);
    pHashTableItem item = m_pHashTable->remove(idx);
    return item;
}

pHashTableItem HashMap::find(std::string key)
{
    int idx = m_pHashFunction->hash(key);
    pHashTableItem item = m_pHashTable->find(idx);
    return item;
}

