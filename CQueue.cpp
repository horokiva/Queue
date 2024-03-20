#include "CQueue.h"

void CQueue::push(int x) {
    Node* node = new Node();
    node->data = x;
    node->next = nullptr;
    if (m_size == 0)
    {
        m_front = node;
        m_back = node;
    } else {
        m_back->next = node;
        m_back = node;
    }

    m_size++;
}

int CQueue::pop() {
    Node* node = m_front;
    m_front = node->next;
    int result = node->data;
    delete node;
    return result;
}

bool CQueue::isEmpty() const {
    return m_size == 0;
}

int CQueue::size() const {
    return m_size;
}

const int &CQueue::front() const {
    return m_front->data;
}

const int &CQueue::back() const {
    return m_back->data;
}

CQueue::CQueue() : m_front(nullptr), m_back(nullptr), m_size(0) {}

CQueue::~CQueue() {
    while(m_size != 0) {
        pop();
    }
}

CQueue::CQueue(const CQueue& other) : CQueue() {
    Node* node = other.m_front;
    while(node != nullptr) {
        push(node->data);
        node = node->next;
    }
}

CQueue& CQueue::operator=(const CQueue &other) {
    if(this == &other) {
        return *this;
    }
    clear();
    pushAll();
    return *this;
}

void CQueue::pushAll(const CQueue &other) {
    Node *node = other.m_front;
    while (node != nullptr) {
        push(node->data);
        node = node->next;
    }
}

void CQueue::clear() {
    while(m_size != 0) {
        pop();
    }
}