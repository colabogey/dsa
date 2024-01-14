#pragma once

class GraphVertex {
  public:
    GraphVertex() = default;
    GraphVertex(int vtx, int weight) {
        m_vtx = vtx;
        m_weight = weight;
    };
    ~GraphVertex() = default;

    int getVtx() { return m_vtx; };
    int getWeight() { return m_weight; };

  private:
    int m_vtx{-1};
    int m_weight{-1};
};
