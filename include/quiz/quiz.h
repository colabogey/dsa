#pragma once

#include <memory>
#include <string>
#include <unordered_set>
#include <list>

class Quiz {
  public:
    Quiz(std::string[], int);
    Quiz() = default;
    ~Quiz() = default;
    Quiz &operator=(Quiz &other) { return *this; };
    Quiz(Quiz &other){};
    bool findItem(std::string);
    bool findAllItems(std::string);

  private:
    void _findItem(std::string, int, int);
    std::unordered_set<std::string> m_items;
    std::unordered_set<std::string> m_found;
    std::list<std::string> m_allStrings;
};
