
#pragma once
#include <deque>

typedef std::tuple<int, int, std::deque<int>> SPT_PATH_ITEM;

class SptData {
  public:
    SptData() = default;
    ~SptData() = default;

    void setSrc(int src) { m_src = src; };
    void addSptItem(SPT_PATH_ITEM);
    void show();

  private:
    int m_src{-1};
    std::deque<SPT_PATH_ITEM> m_spt_path_items;
};
