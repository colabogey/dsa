

#include "arrayShifter.h"
#include <cstdio>

void ArrayShifter::InitInPlace(int numElems)
{
    m_numElems = numElems;
    return;
}

void ArrayShifter::Init(int ary[], int numElems)
{
    for(int i = 0; i < numElems; i++)
    {
        m_ary.push_back(ary[i]);
    }
    return;
}

void ArrayShifter::InitOs(int numElems)
{
    m_numElems = numElems;
    return;
}

void ArrayShifter::_shiftRight()
{

    for(int i = m_ary.size(); i ; i--)
    {
        int item = m_ary.back();
        m_ary.pop_back();
        m_ary.push_front(item);
    return;
    }
}

void ArrayShifter::_shiftLeft()
{
    for(int i = m_ary.size(); i ; i--)
    {
        int item = m_ary.front();
        m_ary.pop_front();
        m_ary.push_back(item);
    return;
    }
}

void ArrayShifter::ShiftRight(int nShift)
{
    int numToShift = nShift % m_ary.size();
    
    if(numToShift == 0 || m_numElems == 1)
    {
        return;
    }

    for(int i = 0; i < nShift; i++)
    {
        _shiftRight();
    }
    return;
}

void ArrayShifter::ShiftLeft(int nShift)
{
    int numToShift = nShift % m_ary.size();
    
    if(numToShift == 0 || m_numElems == 1)
    {
        return;
    }

    for(int i = 0; i < nShift; i++)
    {
        _shiftLeft();
    }
    return;
}

void ArrayShifter::ShiftRightInPlace(int ary[], int nShift)
{
    int numToShift = nShift % m_numElems;
    
    if(numToShift == 0 || m_numElems <= 1)
    {
        return;
    }
    
    int aryCopy[m_numElems];
    for(int i = 0; i < m_numElems; i++)
    {
        aryCopy[i] = ary[i];
    }

    int aryTargetIndex[m_numElems];
    _makeShiftRightTargetIndexAry(aryTargetIndex, nShift);

    for(int i = 0; i < m_numElems; i++)
    {
        ary[aryTargetIndex[i]] = aryCopy[i];
    }
    return;
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

*/
void ArrayShifter::_makeShiftRightTargetIndexAry(int aryTargetIndex[], int nShift)
{
    for(int i = 0; i < m_numElems; i++)
    {
        int targetIdx = (i + nShift);
        if(targetIdx >= m_numElems)
        {
            targetIdx -= m_numElems;
        }
        aryTargetIndex[i] = targetIdx;
    }
}

void ArrayShifter::ShiftLeftInPlace(int ary[], int nShift)
{
    int numToShift = nShift % m_numElems;
    
    if(numToShift == 0 || m_numElems <= 1)
    {
        return;
    }
    
    int aryCopy[m_numElems];
    for(int i = 0; i < m_numElems; i++)
    {
        aryCopy[i] = ary[i];
    }

    int aryTargetIndex[m_numElems];
    _makeShiftLeftTargetIndexAry(aryTargetIndex, nShift);

    for(int i = 0; i < m_numElems; i++)
    {
        ary[aryTargetIndex[i]] = aryCopy[i];
    }
    return;
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
    if target < 0 add m_numElems
              5      4  =  1
              1      4  = -3   3
              3      4  = -1   5

*/
void ArrayShifter::_makeShiftLeftTargetIndexAry(int aryTargetIndex[], int nShift)
{
    for(int i = 0; i < m_numElems; i++)
    {
        int targetIdx = (i - nShift);
        if(targetIdx < 0)
        {
            targetIdx += m_numElems;
        }
        aryTargetIndex[i] = targetIdx;
    }
}


void ArrayShifter::ShiftRightOs(int ary[], int nShift)
{
    int numToShift = nShift % m_numElems;
    
    if(numToShift == 0 || m_numElems == 1)
    {
        return;
    }

    for(int i = 0; i < numToShift; i++)
    {
        int item = ary[m_numElems - 1];
        _shiftRightOs(ary);
        ary[0] = item;
    }
    return;
}

void ArrayShifter::_shiftRightOs(int ary[])
{
/*
 1 2 3 4 5

 1 1 2 3 4

*/

    for( int i = m_numElems - 1; i > 0; i--)
    {
        ary[i] = ary[i - 1];
    }
}

void ArrayShifter::_shiftLeftOs(int ary[])
{
/*
 1 2 3 4 5

 2 3 4 5 5

*/

    for( int i = 0; i < m_numElems - 2; i++)
    {
        ary[i] = ary[i + 1];
    }
}

void ArrayShifter::ShiftLeftOs(int ary[], int nShift)
{
    int numToShift = nShift % m_numElems;
    
    if(numToShift == 0 || m_numElems == 1)
    {
        return;
    }

    for(int i = 0; i < numToShift; i++)
    {
        int item = ary[0];
        _shiftLeftOs(ary);
        ary[m_numElems - 1] = item;
    }
    return;
}

void ArrayShifter::MakeNewArray(int ary[])
{
    int i = 0;
    for(int e : m_ary)
    {
        ary[i] = e;
        i++;
    }
}

