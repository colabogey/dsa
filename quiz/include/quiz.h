#pragma once

#include <memory>
#include <string>
#include <unordered_set>

class Quiz {
  public:
    Quiz(std::string[], int);
    Quiz() = default;
    ~Quiz() = default;
    Quiz &operator=(Quiz &other) { return *this; };
    Quiz(Quiz &other){};

    bool findItem(std::string);

  private:
    bool _findItem(std::string, int, int);
    std::unordered_set<std::string> m_items;
};
