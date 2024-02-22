#pragma once

typedef struct _corners {
    int tl[2];
    int tr[2];
    int bl[2];
    int br[2];
} rc_corners;

#define rccRow 0
#define rccCol 1

class Spiral {
public:
    Spiral(int rows, int cols);
    Spiral() = default;
    ~Spiral() = default;

    void fill();
    void print();
    void fillRowRight(int, rc_corners);
    void fillRowLeft(int, rc_corners);
    void fillColUp(int, rc_corners);
    void fillColDown(int, rc_corners);
private: 
    void _initRow(int);
    void _printRow(int);
    int m_rows{0};
    int m_cols{0};
    int m_val{1};
    int** m_ary;

};
