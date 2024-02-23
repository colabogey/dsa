
#include "spiral.h"
#include <cstdio>

/*

    1 2 3
    8 9 4
    7 6 5

*/

Spiral::Spiral(int rows, int cols) {
    m_rows = rows;
    m_cols = cols;
    m_ary = new int *[m_rows * m_cols];
    for (int i = 0; i < m_rows; i++) {
        m_ary[i] = new int[m_cols];
        _initRow(i);
    }
}

void Spiral::_initRow(int r) {
    for (int i = 0; i < m_cols; i++) {
        m_ary[r][i] = 0;
    }
}

void Spiral::fill() {
    // go right
    // go down
    // go left
    // go up

    // recalculate rectangle

    rc_corners rcc = {
        {0, 0}, {0, m_cols - 1}, {m_rows - 1}, {m_rows - 1, m_cols - 1}};

    // while(rcc.tr[rccCol] >= 0) {
    while (validCorners(rcc)) {
        fillRowRight(rcc.tl[rccRow], rcc);

        // col, row top, row bot
        fillColDown(rcc.tr[rccCol], rcc);

        // row, col begin, col end
        fillRowLeft(rcc.br[rccRow], rcc);

        // col, row top, row bot
        fillColUp(rcc.bl[rccCol], rcc);

        rcc.tl[rccRow] = rcc.tl[rccRow] + 1;
        rcc.tl[rccCol] = rcc.tl[rccCol] + 1;
        rcc.tr[rccRow] = rcc.tr[rccRow] + 1;
        rcc.tr[rccCol] = rcc.tr[rccCol] - 1;
        rcc.bl[rccRow] = rcc.bl[rccRow] - 1;
        rcc.bl[rccCol] = rcc.bl[rccCol] + 1;
        rcc.br[rccRow] = rcc.br[rccRow] - 1;
        rcc.br[rccCol] = rcc.br[rccCol] - 1;
    }
}

bool Spiral::validCorners(rc_corners rcc) {
    bool ans = true;
    if((rcc.tl[rccRow] == -1) ||
        (rcc.tl[rccCol] == -1) ||
        (rcc.tr[rccRow] == -1) ||
        (rcc.tr[rccCol] == -1) ||
        (rcc.bl[rccRow] == -1) ||
        (rcc.bl[rccCol] == -1) ||
        (rcc.br[rccRow] == -1) ||
        (rcc.br[rccCol] == -1)) { 
            ans = false;
        }
    return ans;
}
void Spiral::fillRowRight(int row, rc_corners rcc) {
    for (int i = rcc.tl[rccCol]; i <= rcc.tr[rccCol]; i++) {
        if(m_ary[row][i] == 0) {
            m_ary[row][i] = m_val;
            m_val++;
        }
    }
}

void Spiral::fillRowLeft(int row, rc_corners rcc) {
    for (int i = (rcc.br[rccCol] - 1); i >= rcc.bl[rccCol]; i--) {
        if(m_ary[row][i] ==0) {
            m_ary[row][i] = m_val;
            m_val++;
        }
    }
}

void Spiral::fillColDown(int col, rc_corners rcc) {
    for (int i = (rcc.tr[rccRow] + 1); i <= rcc.br[rccRow]; i++) {
        if (m_ary[i][col] == 0) {
            m_ary[i][col] = m_val;
            m_val++;
        }
    }
}

void Spiral::fillColUp(int col, rc_corners rcc) {
    for (int i = (rcc.bl[rccRow] - 1); i >= (rcc.tl[rccRow] + 1); i--) {
        if (m_ary[i][col] == 0) {
            m_ary[i][col] = m_val;
            m_val++;
        }
    }
}

void Spiral::print() {
    for (int i = 0; i < m_rows; i++) {
        _printRow(i);
    }
}

void Spiral::_printRow(int r) {
    for (int i = 0; i < m_cols; i++) {
        printf("(%.2d) ", m_ary[r][i]);
    }
    printf("\n");
}
