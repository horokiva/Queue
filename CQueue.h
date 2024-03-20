#pragma once

struct Node {
    int data;
    Node* next;
};

class CQueue {
public:
    CQueue();

    ~CQueue();

    CQueue(const CQueue& other); //= delete; // zakazano vytvoreni implicitnitho kopirovaciho konstruktoru

    CQueue& operator=(const CQueue& other);

    void push(int x);

    int pop();

    bool isEmpty() const;

    int size() const;

    const int & front() const;

    const int & back() const;

private:
    Node* m_front;
    Node* m_back;
    int m_size;

    void clear();
    void pushAll(const CQueue& other);
};