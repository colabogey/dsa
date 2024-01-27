
#pragma once
#include <memory>

class AvlTreeNode {
  public:
    AvlTreeNode() = default;
    AvlTreeNode(int data) { m_data = data; };
    virtual ~AvlTreeNode() = default;
    int getData() { return m_data; };
    void setData(int data) { m_data = data; };
    int getHeight() { return m_height; };
    void setHeight(int height) { m_height = height; };

    std::shared_ptr<AvlTreeNode> getLeft() { return m_left; };
    void setLeft(std::shared_ptr<AvlTreeNode> left) { m_left = left; };

    std::shared_ptr<AvlTreeNode> getRight() { return m_right; };
    void setRight(std::shared_ptr<AvlTreeNode> right) { m_right = right; };

    std::shared_ptr<AvlTreeNode> getParent() { return m_parent; };
    void setParent(std::shared_ptr<AvlTreeNode> parent) { m_parent = parent; };

  private:
    int m_data{0};
    int m_height{1};
    std::shared_ptr<AvlTreeNode> m_left{nullptr};
    std::shared_ptr<AvlTreeNode> m_right{nullptr};
    std::shared_ptr<AvlTreeNode> m_parent{nullptr};
};

typedef std::shared_ptr<AvlTreeNode> pAvlTreeNode;
