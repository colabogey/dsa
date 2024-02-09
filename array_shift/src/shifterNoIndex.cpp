#include "shifterNoIndex.h"
#include <algorithm>
#include <cstdio>

ShifterNoIndex::ShifterNoIndex(int ary[], int sz, int shift) {
    m_ary = &ary[0];
    m_sz = sz;
    m_shift = shift;
}

void ShifterNoIndex::_shiftRight() {
    for(int i = 0; i < (m_sz - m_shift); i++) {
        m_store.push_back(m_ary[i]);
    }

    for(int i = (m_sz - 1); i >= (m_sz - m_shift); i--) {
        m_store.push_front(m_ary[i]);
    }
}

void ShifterNoIndex::_shiftLeft() {
    for(int i = (m_sz - 1); i >= m_shift; i--) {
        m_store.push_front(m_ary[i]);
    }

    for(int i = 0; i < m_shift; i++) {
        m_store.push_back(m_ary[i]);
    }
}

void ShifterNoIndex::ShiftRight() {
    m_shift = m_shift % m_sz;
    if (m_shift == 0 || m_sz <= 1) {
        return;
    }
    _shiftRight();
    _storeToAry();
    m_store.clear();
    return;
}

void ShifterNoIndex::ShiftLeft() {
    m_shift = m_shift % m_sz;
    if (m_shift == 0 || m_sz <= 1) {
        return;
    }
    _shiftLeft();
    _storeToAry();
    m_store.clear();
    return;
}

void ShifterNoIndex::_storeToAry() {
    for(int i = 0; i < m_sz; i++) {
        m_ary[i] = m_store[i];
    }
}
