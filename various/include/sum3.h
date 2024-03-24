#pragma once

#include <unordered_map>
#include <vector>

class Sum3ToZero {
  public:
    Sum3ToZero() = default;
    ~Sum3ToZero() = default;
    bool canThreeSumToZero(std::vector<int> &);

  private:
    bool _findTwo(std::unordered_map<int, int> &, std::vector<int> &, int, int);
};
