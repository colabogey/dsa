#pragma once

#include <deque>

class ArrayShifter
{
public:
    ArrayShifter() = default;
    ~ArrayShifter() = default;

    void Initz();

    void Init(int[], int);
    void InitOs(int);
    void ShiftRight(int);
    void ShiftRightOs(int[], int);
    void ShiftLeft(int);
    void ShiftLeftOs(int[], int);
    void MakeNewArray(int[]);

private:
    void _shiftRight();
    void _shiftLeft();
    void _shiftRightOs(int[]);
    void _shiftLeftOs(int[]);
    std::deque<int> m_ary;
    int m_numElems{ 0 };
};
