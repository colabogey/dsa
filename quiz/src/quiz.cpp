
#include "quiz.h"

Quiz::Quiz(std::string sAry[], int size)
{
    for(int i = 0; i < size; i++)
    {
        m_items.insert(sAry[i]);
    }
}

bool Quiz::findItem(std::string s) {
    return _findItem(s, 0, s.length() -1);
}

bool Quiz::_findItem(std::string s, int begin, int end) {
    if(begin > end) {
        return(false);
    } 
    
    std::string sSub = s.substr(0, begin + 1);
    auto search = m_items.find(sSub);
    if(search != m_items.end()) {
        std::string sFound = *search;
        return true;
        //return _findItem(s, (begin + sSub.length()) -1, end);
     } else {
        return _findItem(s, begin + 1, end); 
    }
}

