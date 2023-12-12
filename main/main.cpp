#include <iostream>

#include "../TQueue/TQueue.h"

void main() {
    PQueue<int> q(10);
    q.push(1,1);
    q.push(2,0);
    q.push(3,1);
    q.print();
    q.popmin();
    q.print();
}
