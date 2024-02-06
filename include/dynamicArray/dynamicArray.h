#pragma once
#include <deque>

#define INITIAL_SIZE 128
#define INCREMENT_SIZE 4096

class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(int);
    ~DynamicArray() = default;
    DynamicArray& operator=(DynamicArray& other) {return *this;};
    DynamicArray(DynamicArray& other) {};
    void set(const int, const int idx);
    int get(const int idx);
    void sort();
    double getMedianValue();

private:
    void _resize(const int idx);
    int m_count{-1};
    bool m_isEmpty{true};
    std::deque<int> m_ary;
};

