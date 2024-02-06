
#include <algorithm>
#include <stdio.h>
#include <limits.h>
#include "dynamicArray.h"

DynamicArray::DynamicArray() : DynamicArray(INITIAL_SIZE) {
}

DynamicArray::DynamicArray(int size) {
    m_ary.resize(size, INT_MAX);
}

void DynamicArray::set(const int idx, const int val) {
    _resize(idx);
    m_ary[idx] = val;
    m_count = idx + 1;
    m_isEmpty = false;
    return;
}

int DynamicArray::get(const int idx) {
    if((m_isEmpty == true) || (idx > (m_count - 1))) {
        printf("out of bounds - throw here\n");
        return 0;
    }
    return m_ary[idx];
}

void DynamicArray::_resize(const int idx) {
    size_t sz = m_ary.size();
    if(idx > sz) {
        m_ary.resize((sz + INCREMENT_SIZE), INT_MAX);
    }
}

void DynamicArray::sort() {
    std::sort(m_ary.begin(), m_ary.begin() + m_count);
}

double DynamicArray::getMedianValue() {
    std::sort(m_ary.begin(), m_ary.end());
    if(m_count == 0) {
        return -1;
    }

    if(m_count == 1) {
        return m_ary[0];
    }

    int rem = m_count % 2;
    if(rem == 1) {
        // odd
        // 1 3 5 7 8 12 16
        // ans 7
        return m_ary[m_count/2];
    } else {
        // even
        // 1 3 5 7 8 12
        // l 5
        // r 7
        // ans 6
        double left = m_ary[(m_count/2) - 1];
        double right = m_ary[(m_count/2)];
        return (left + right) / 2;
    }
}

