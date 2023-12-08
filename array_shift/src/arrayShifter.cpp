

#include "arrayShifter.h"
#include <cstdio>

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

