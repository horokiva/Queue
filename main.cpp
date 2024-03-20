#include <iostream>
#include <cassert>
#include "CQueue.h"

int main() {
    CQueue queue;
    assert(queue.isEmpty());
    assert(queue.size() == 0);

    queue.push(1);
    assert(queue.size() == 1);

    queue.push(2);
    queue.push(3);
    assert(!queue.isEmpty());
    assert(queue.size() == 3);
    assert(queue.front() == 1);
    assert(queue.back() == 3);

    assert(queue.pop() == 1);
    assert(queue.size() == 2);
    assert(queue.front() == 2);
    assert(queue.back() == 3);

    queue.push(4);
    assert(queue.back() == 4);

    assert(queue.pop() == 2);
    assert(queue.pop() == 3);
    assert(queue.pop() == 4);
    assert(queue.isEmpty());
    assert(queue.size() == 0);

    queue.push(5);
    assert(queue.size() == 1);
    return 0;
}

