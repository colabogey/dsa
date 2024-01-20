
#pragma once

class SptInfo {
  public:
    SptInfo() = default;
    SptInfo(int start, int dest, std::deque<int>& costs, std::deque<int>& parents) {
        m_start = start;
        m_dest = dest;
        m_costs(costs.begin(), costs.end());
        m_parents(parents.begin(), parents.end());
    };

    ~SptInfo() = default;

    int getStart() { return m_start; };
    int getDest() { return m_dest; };

  private:
    int m_start{-1};
    int m_dest{-1};
    std::deque<int> m_costs;
    std::deque<int> m_parents;
};
