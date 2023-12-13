#pragma once

#include <deque>

class ArrayShifter
{
public:
    ArrayShifter() = default;
    ~ArrayShifter() = default;
    ArrayShifter& operator=(ArrayShifter& other) {return *this;};
    ArrayShifter(ArrayShifter& other) {};

    void Initz();

    void Init(int[], int);
    void InitOs(int);
    void InitInPlace(int);
    void ShiftRight(int);
    void ShiftRightOs(int[], int);
    void ShiftRightInPlace(int[], int);
    void ShiftLeftInPlace(int[], int);
    void ShiftLeft(int);
    void ShiftLeftOs(int[], int);
    void MakeNewArray(int[]);

private:
    void _shiftRight();
    void _shiftLeft();
    void _shiftRightOs(int[]);
    void _shiftLeftOs(int[]);
    void _makeShiftRightTargetIndexAry(int[], int);  
    void _makeShiftLeftTargetIndexAry(int[], int);  

    std::deque<int> m_ary;
    int m_numElems{ 0 };
};
