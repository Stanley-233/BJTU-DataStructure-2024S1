//
// Created by stanl on 24-9-20.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class Stack {
    typedef struct Node {
        T data;
        Node* next;
        Node(T data, Node *next) : data(data), next(next) {}
    }Node;
    Node* top;
    int size;

public:
    explicit Stack() {
        top = nullptr;
        size = 0;
    }

    void push(T data) {
        // 头插法链表
        auto newNode = new Node(data,top);
        top = newNode;
        size++;
    }

    T pop() {
        if (size == 0) {
            throw std::exception("Stack is empty");
        }
        auto ret = top->data;
        auto preTop = top;
        top = top->next;
        free(preTop);
        size--;
        return ret;
    }

    T getTop() {
        return top->data;
    }

    [[nodiscard]] int getSize() const {
        return size;
    }

    [[nodiscard]] bool isEmpty() const {
        return size == 0;
    }
};

#endif //STACK_H
