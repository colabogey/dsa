#include "shifterWithIndex.h"
#include <algorithm>
#include <limits.h>
#include <cstdio>

ShifterWithIndex::ShifterWithIndex(int ary[], int sz, int shift) {
    m_ary = &ary[0];
    m_sz = sz;
    m_shift = shift;
    m_store.resize(sz, INT_MAX);
}

void ShifterWithIndex::ShiftRight() {
    m_shift = m_shift % m_sz;
    if (m_shift == 0 || m_sz <= 1) {
        return;
    }
    _shiftRight();
    _storeToAry();
    m_store.clear();
    return;
}

void ShifterWithIndex::ShiftLeft() {
    m_shift = m_shift % m_sz;
    if (m_shift == 0 || m_sz <= 1) {
        return;
    }
    _shiftLeft();
    _storeToAry();
    m_store.clear();
    return;
}

void ShifterWithIndex::_storeToAry() {
    for(int i = 0; i < m_sz; i++) {
        m_ary[i] = m_store[i];
    }
}

/*
    values from nshift = 4
    1 2 3 4 5 6
    3 4 5 6 1 2
    index values
    0 1 2 3 4 5
    2 3 4 5 0 1

    target = idx + nShift
              0      4
    if target >= m_numelems subtract m_numelems

    or
    new = (((2 * max_idx) + shift + idx) % max_idx) -1

*/
void ShifterWithIndex::_shiftRight() {
    for (int i = 0; i < m_sz; i++) {
        int targetIdx = (i + m_shift);
        if (targetIdx >= m_sz) {
            targetIdx -= m_sz;
        }
        m_store[targetIdx] = m_ary[i];
    }
}

/*
    values from nshift = 4
    1 2 3 4 5 6
    5 6 1 2 3 4
    index values
    0 1 2 3 4 5
    4 5 0 1 2 3

    start at the back
    target = idx - nShift
    if target < 0 add m_sz
              5      4  =  1
              1      4  = -3   3
              3      4  = -1   5

    or
    new = (((2 * max_idx) - shift + idx) % max_idx) +1

*/
void ShifterWithIndex::_shiftLeft() {
    for (int i = 0; i < m_sz; i++) {
        int targetIdx = (i - m_shift);
        if (targetIdx < 0) {
            targetIdx += m_sz;
        }
        m_store[targetIdx] = m_ary[i];
    }
}
