#pragma once
#include <memory>

class TreeNode {
  public:
    TreeNode() = default;
    TreeNode(int data) { m_data = data; };
    ~TreeNode() = default;
    int getData() { return m_data; };
    void setData(int data) { m_data = data; };

    std::shared_ptr<TreeNode> getLeft() { return m_left; };
    void setLeft(std::shared_ptr<TreeNode> left) { m_left = left; };

    std::shared_ptr<TreeNode> getRight() { return m_right; };
    void setRight(std::shared_ptr<TreeNode> right) { m_right = right; };

    std::shared_ptr<TreeNode> getParent() { return m_parent; };
    void setParent(std::shared_ptr<TreeNode> parent) { m_parent = parent; };

  private:
    int m_data{0};
    std::shared_ptr<TreeNode> m_left{nullptr};
    std::shared_ptr<TreeNode> m_right{nullptr};
    std::shared_ptr<TreeNode> m_parent{nullptr};
};

typedef std::shared_ptr<TreeNode> pTreeNode;
