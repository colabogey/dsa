#pragma once

#include <deque>

class ShifterWithIndex {
  public:
    ShifterWithIndex() = default;
    ShifterWithIndex(int ary[], int sz, int shift);
    ~ShifterWithIndex() = default;
    ShifterWithIndex &operator=(ShifterWithIndex &other) { return *this; };
    ShifterWithIndex(ShifterWithIndex &other){};

    void ShiftRight();
    void ShiftLeft();

  private:
    void _shiftRight();
    void _shiftLeft();
    void _storeToAry();
    std::deque<int> m_store;
    int m_sz{0};
    int m_shift{0};
    int* m_ary;
};
