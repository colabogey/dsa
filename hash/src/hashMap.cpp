
#include <string>
#include "hashTable.h"
#include "hashMap.h"
#include "hashFunction.h"
#include "hashFunctionFactory.h"

HashMap::HashMap()
{
    std::shared_ptr<HashFunctionFactory> hff = std::make_shared<HashFunctionFactory>();
    m_pHashFunction = hff->create();
    m_pHashTable = std::make_shared<HashTable>();
}

void HashMap::insert(std::string key, std::string value)
{
    pHashTableItem pI = std::make_shared<HashTableItem>(key, value);
    int idx = m_pHashFunction->hash(key);
    m_pHashTable->insert(idx, pI);
}

void HashMap::remove(std::string key)
{
    int idx = m_pHashFunction->hash(key);
    m_pHashTable->remove(key, idx);
    return;
}

std::string HashMap::find(std::string key)
{
    std::string rVal = "";
    int idx = m_pHashFunction->hash(key);
    pHashTableItem item = m_pHashTable->find(key, idx);
    item != nullptr ? rVal = item->getValue() : rVal = "";
    return rVal;
}

void HashMap::dump() {
    m_pHashTable->dump();
}
