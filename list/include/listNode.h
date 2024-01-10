#pragma once
#include <string>
#include <memory>

class ListNode
{
public:
    ListNode() = default;
    ListNode(std::string data) { m_data = data ;};
    ~ListNode() = default;
    std::string getData() { return m_data; };
    void setData(std::string data) { m_data = data; };
    std::shared_ptr<ListNode> getNext() { return m_next; };
    void setNext(std::shared_ptr<ListNode> next) { m_next = next; };
    std::shared_ptr<ListNode> getPrev() { return m_prev; };
    void setPrev(std::shared_ptr<ListNode> prev) { m_prev = prev; };

private:
    std::string m_data{""};
    std::shared_ptr<ListNode> m_next{nullptr};
    std::shared_ptr<ListNode> m_prev{nullptr};

};

typedef std::shared_ptr<ListNode> pListNode;
