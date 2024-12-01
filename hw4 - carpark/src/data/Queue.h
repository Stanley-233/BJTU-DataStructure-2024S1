//
// Created by stanl on 24-9-30.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <exception>
#include <stdexcept>

template <typename T>
class Queue{
    struct Node{
      T data;
      Node* next;
        Node() {next = nullptr;}
      Node(T data, Node* next) : data(data), next(next) {}
    };
    Node* head = nullptr;
    int size = 0;
    int capacity = Qt::MaximumSize;
public:
    Queue(int cap) : capacity(cap) {}
    void enque(T data) {
        if (size == capacity) {
            throw std::out_of_range("QUEUE::FULL");
        }
        if (head == nullptr) {
            head = new Node(data,nullptr);
        } else {
            auto tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = new Node(data,nullptr);
        }
        size++;
    }
    T deque() {
        if (head == nullptr) throw std::out_of_range("QUEUE::EMPTY");
        auto ret = head->data;
        auto p = head;
        head = head->next;
        delete p;
        size--;
        return ret;
    }
    T front() {
        if (head == nullptr) throw std::out_of_range("QUEUE::EMPTY");
        return head->data;
    }
    [[nodiscard]] int getSize() const {
        return size;
    }
    bool empty() const {
        return head == nullptr;
    }
};

#endif //QUEUE_H
