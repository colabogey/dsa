#pragma once

#include <memory>

class MergerIt {
  public:
    MergerIt() = default;
    MergerIt(int size) { m_size = size; };
    ~MergerIt() = default;
    MergerIt &operator=(MergerIt &other) { return *this; };
    MergerIt(MergerIt &other){};

    void mergeSort(int[], int[], int, int);
    void merge(int[], int[], int from, int mid, int to);
    void printArray(int[]);
    int min(int x, int y) {return (x < y) ? x : y;};

  private:
    int m_size {0};
};
