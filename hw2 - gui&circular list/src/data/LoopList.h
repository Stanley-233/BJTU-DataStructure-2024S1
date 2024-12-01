//
// Created by stanl on 24-9-9.
//

#ifndef LOOPLIST_H
#define LOOPLIST_H

class LoopList {
    typedef struct Node {
        int data;
        Node *next;
        Node(int data, Node *next): data(data), next(next) {}
    } Node;
    int size = 0;
    Node *head = nullptr;
    public:
    LoopList(int size);
    ~LoopList() = default;
    int solveRing(int key, int[]);
};

#endif //LOOPLIST_H
