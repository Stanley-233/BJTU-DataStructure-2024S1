//
// Created by stanl on 24-11-1.
//

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <QMap>

class HuffmanTree {
    struct Node {
        unsigned char ch;
        unsigned int weight;
        Node* left;
        Node* right;
        Node(const unsigned char ch, const unsigned int weight): ch(ch), weight(weight), left(nullptr), right(nullptr) {}
        Node(const unsigned char ch, const unsigned int weight, Node* left, Node* right): ch(ch), weight(weight), left(left), right(right) {}
    };
    Node* root;
    void deleteTree(Node* node);
    Node* buildTree(std::vector<Node*>& nodes);
    void generateCodes(Node* node, const QString& currentCode, QMap<unsigned char, QString>& codes);

public:
    HuffmanTree() = default;
    explicit HuffmanTree(const QMap<unsigned char, unsigned int>& map);
    ~HuffmanTree() {
        deleteTree(root);
    }
    QMap<unsigned char, QString> getHuffmanCodes();
};



#endif //HUFFMANTREE_H
