#pragma once

class ShifterWithIndex {
  public:
    ShifterWithIndex() = default;
    ShifterWithIndex(int ary[], int sz, int shift);
    ~ShifterWithIndex() = default;
    ShifterWithIndex &operator=(ShifterWithIndex &other) { return *this; };
    ShifterWithIndex(ShifterWithIndex &other){};

    void ShiftRight();
    void ShiftRightOs(int[], int);
    void ShiftRightInPlace(int[], int);
    void ShiftLeftInPlace(int[], int);
    void ShiftLeft();
    void ShiftLeftOs(int[], int);
    void MakeNewArray(int[]);

  private:
    void _shiftRight();
    void _shiftLeft();
    void _storeToAry();

    void _shiftRightOs(int[]);
    void _shiftLeftOs(int[]);
    void _makeShiftRightTargetIndexAry(int[], int);
    void _makeShiftLeftTargetIndexAry(int[], int);

    std::deque<int> m_store;
    int m_sz{0};
    int m_shift{0};
    int* m_ary;
};
