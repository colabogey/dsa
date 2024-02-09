#pragma once

#include <deque>
#include <memory>

class ShifterNoIndex {
  public:
    ShifterNoIndex() = default;
    ShifterNoIndex(int ary[], int sz, int shift);
    virtual ~ShifterNoIndex() = default;
    ShifterNoIndex &operator=(ShifterNoIndex &other) { return *this; };
    ShifterNoIndex(ShifterNoIndex &other){};

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
