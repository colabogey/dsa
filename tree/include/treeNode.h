#pragma once
#include <memory>

class TreeNode
{
public:
    TreeNode() = default;
    TreeNode(int data) { m_data = data ;};
    ~TreeNode() = default;
    int getData() { return m_data; };
    void setData(int data) { m_data = data; };

    std::shared_ptr<TreeNode> getLeft() { return m_left; };
    void setLeft(std::shared_ptr<TreeNode> left) { m_left = left; };

    std::shared_ptr<TreeNode> getRight() { return m_right; };
    void setRight(std::shared_ptr<TreeNode> right) { m_right = right; };

private:
    int m_data{0};
    std::shared_ptr<TreeNode> m_left{nullptr};
    std::shared_ptr<TreeNode> m_right{nullptr};
};

typedef std::shared_ptr<TreeNode> pTreeNode;
