//
// Created by stanl on 24-9-6.
//

#include "Polynomial.h"

#include <ios>
#include <stdexcept>

Polynomial::Polynomial(int length, const int inputs[]) {
    this->length = length;
    this->head = new Node(0,0,nullptr);
    Node* head = this->head;
    Node* now = head;
    for (int i = 0; i < length*2; i+=2) {
        int coef = inputs[i];
        int exponent = inputs[i+1];
        // 尾插，降序排列
        now->next = new Node(coef, exponent, nullptr);
        now = now->next;
    }
}

void Polynomial::append(int coef, int exp) const {
    auto now = this->head;
    if (now == nullptr) {
        now = new Node(0,0,nullptr);
    }
    while (now->next != nullptr) {
        now = now->next;
    }
    now->next = new Node(coef,exp,nullptr);
}

void Polynomial::append(const Node* node) const {
    auto now = this->head;
    while (now->next != nullptr) {
        now = now->next;
    }
    now->next = node->next;
}

Polynomial::Node *Polynomial::get(int location) const {
    if (location <= 0 || location > this->length) {
        throw std::out_of_range("Polynomial::get");
    }
    Node *now = this->head;
    for (int i = 0; i < location; i++) {
        now = now->next;
    }
    return now;
}

void Polynomial::insert(int location, int coef, int exp) const {
    if (location <= 0 || location >= this->length) {
        throw std::out_of_range("Polynomial::insert");
    }
    Node *now = this->head;
    for (int i = 0; i < location; i++) {
        now = now->next;
    }
    // location 后插入
    auto newNode = new Node(coef, exp,now->next);
    now->next = newNode;
}


void Polynomial::edit(int location, int coef, int exp) const {
    auto now = get(location);
    now = new Node(coef,exp,nullptr);
}

Polynomial Polynomial::operator+(const Polynomial &rhs) {
    Polynomial result;
    if (this->head == nullptr) {
        result.head = new Node(0,0,rhs.head->next);
        result.length = rhs.length;
    } else {
        Node *left_now = this->head->next;
        Node *right_now = rhs.head->next;
        while (left_now != nullptr && right_now != nullptr) {
            int left_exp = left_now->exponent;
            int right_exp = right_now->exponent;
            // 创建新节点，加入新的链表中
            if (left_exp > right_exp) {
                result.append(left_now->coefficient,left_now->exponent);
                left_now = left_now->next;
            } else if (left_exp < right_exp) {
                result.append(right_now->coefficient,right_now->exponent);
                right_now = right_now->next;
            } else {
                int sum = left_now->coefficient + right_now->coefficient;
                if (sum != 0) {
                    result.append(sum,left_now->exponent);
                    left_now = left_now->next;
                    right_now = right_now->next;
                }
            }
            result.length++;
        }
        if (left_now != nullptr) {
            result.append(left_now->coefficient,left_now->exponent);
            result.length++;
        } else if (right_now != nullptr) {
            result.append(right_now->coefficient,right_now->exponent);
            result.length++;
        }
    }
    return result;
}

Polynomial Polynomial::operator*(const Polynomial &rhs) {
    Polynomial result;
    result.length = 0;
    result.head = nullptr;
    auto right_now = rhs.head->next;
    auto left_now = this->head->next;
    while (right_now != nullptr) {
        Polynomial now;
        while (left_now != nullptr) {
            now.append(left_now->coefficient * right_now->coefficient,left_now->exponent + right_now->exponent);
            now.length++;
            left_now = left_now->next;
        }
        result = result + now;
        right_now = right_now->next;
        left_now = this->head->next;
    }
    return result;
}
