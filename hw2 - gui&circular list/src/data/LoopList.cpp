//
// Created by stanl on 24-9-9.
//

#include "LoopList.h"

#include <iostream>

LoopList::LoopList(int size) {
    this->size = size;
    head = new Node(1,head);
    auto p = head;
    for (int i = 2; i <= size; i++) {
        p->next = new Node(i,head);
        p = p->next;
    }
}

int LoopList::solveRing(int key, int ret[]) {
    auto p = head;
    memset(ret,-1,sizeof(int)*size);
    int count = 1,i = 0;
    while (p != p->next) {
        if (key == 1) {
            for (int j = 0; j < size; j++) {
                ret[j] = j+1;
            }
            return size;
        }
        if (count == key - 1) {
            Node* q = p->next;
            ret[i] = q->data;
            i++;
            p->next = q->next;
            delete(q);
            count = 0;
        }
        p = p->next;
        count++;
    }
    head = p;
    return head->data;
}
