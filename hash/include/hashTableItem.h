#pragma once
#include <string>
#include <memory>

class HashTableItem
{
public:
    HashTableItem() = default;
    ~HashTableItem() = default;
    HashTableItem(std::string key, std::string value) 
    {
        m_key = key;
        m_value = value;
    }
     
    std::string getKey() { return m_key; };
    std::string getValue() { return m_value; };

private:
    std::string m_key;
    std::string m_value;

};

typedef std::unique_ptr<HashTableItem> pHashTableItem;
