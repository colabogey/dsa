
#include <string>
#include "hashTable.h"
#include "hashTableItem.h"

void HashTable::insert(int idx, pHashTableItem item)
{
    m_hashTable[idx] = std::move(item);
}

pHashTableItem HashTable::remove(int idx)
{
    pHashTableItem item = std::move(m_hashTable[idx]);
    m_hashTable[idx] = nullptr;
    return item;
}

pHashTableItem HashTable::find(int idx)
{
    pHashTableItem item = std::move(m_hashTable[idx]);
    return item;
}



