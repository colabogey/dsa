#pragma once

#include <memory>

class Merger {
  public:
    Merger() = default;
    ~Merger() = default;
    Merger &operator=(Merger &other) { return *this; };
    Merger(Merger &other){};

    void mergeSort(int[], int const, int const);
    void merge(int[], int const, int const, int const);
    void printArray(int[], int);

  private:
};
