//
// Created by stanl on 24-9-6.
//

#ifndef POLYNODE_H
#define POLYNODE_H

class Polynomial {
    // 子节点
    typedef struct Node {
        int coefficient;
        int exponent;
        Node* next = nullptr;
        Node() = default;
        Node(int coef, int exponent) {
            coefficient = coef;
            this->exponent = exponent;
        }
        Node(int coef, int exponent, Node* next) {
            coefficient = coef;
            this->exponent = exponent;
            this->next = next;
        }
    } Node;
    int length = 0;
    Node *head = nullptr;
public:
    Polynomial() {
        length = 0;
        head = new Node(0,0,nullptr);
    };
    Polynomial(int length, const int inputs[]);
    ~Polynomial() = default;
    void append(int coef, int exp) const;
    void append(const Node* node) const;
    void insert(int location, int coef, int exp) const;
    void edit(int location, int coef, int exp) const;
    Node* get(int location) const;
    Polynomial operator+(const Polynomial& rhs);
    Polynomial operator*(const Polynomial& rhs);
    [[nodiscard]] int getLength() const {
        return length;
    }
};

#endif //POLYNODE_H
