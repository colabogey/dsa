#include <string>
#include "hashTableItem.h"

HashTableItem::~HashTableItem()
{
    m_list.clear();
}

bool HashTableItem::isDuplicate(pHashTableItem item) {
    if(item->getKey() == m_key) {
        return true;
    }
    for(pHashTableItem listItem : m_list) {
        if(listItem->getKey() == item->getKey()) {
            return true;
        }
    }
    return false;
}

void HashTableItem::handleInsertCollision(pHashTableItem item)
{
    m_list.push_back(item);
}

void HashTableItem::removeListItem(std::string key) {
    for (auto it = m_list.begin(); it != m_list.end(); it++) {
        pHashTableItem tableItem = *it;
        if(tableItem->getKey() == key) {
            m_list.erase(it);
            break;
        }
    }
}

void HashTableItem::promoteListItem() {
    if(m_list.size() > 0) {
        pHashTableItem listItem = m_list.front();
        m_list.pop_front();
        m_key = listItem->getKey();
        m_value = listItem->getValue();
        m_list = listItem->m_list;
        listItem->clear();
    }
}

pHashTableItem HashTableItem::findListItem(std::string key) {
    for(pHashTableItem listItem : m_list) {
        if(listItem->getKey() == key) {
            return listItem;
        }
    }
    return nullptr;
}
void HashTableItem::clear() {
    m_key = "";
    m_value = "";
    m_list.clear();
}