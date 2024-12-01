//
// Created by stanl on 24-11-1.
//

#include "HuffmanTree.h"

#include <stack>

void HuffmanTree::deleteTree(Node *node) { // NOLINT
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

HuffmanTree::Node* HuffmanTree::buildTree(std::vector<Node*> &nodes) {// NOLINT
    if (nodes.size() == 1) {
        return nodes.front();
    }
    std::sort(nodes.begin(), nodes.end(), [](const Node *a, const Node *b) {
        return a->weight < b->weight;
    });
    // WPL第一和第二小子树
    Node* left = nodes.front();
    nodes.erase(nodes.begin());
    Node* right = nodes.front();
    nodes.erase(nodes.begin());
    const auto parent = new Node('\0', left->weight+right->weight, left, right);
    nodes.push_back(parent);
    return buildTree(nodes);
}

HuffmanTree::HuffmanTree(const QMap<unsigned char, unsigned int> &map) {
    std::vector<Node*> nodes;
    for (auto it = map.begin(); it != map.end(); ++it) {
        nodes.push_back(new Node(it.key(),it.value()));
    }
    root = buildTree(nodes);
}

QMap<unsigned char, QString> HuffmanTree::getHuffmanCodes() {
    QMap<unsigned char, QString> codes; //char,code
    QString currentCode = ""; // 当前编码
    generateCodes(root, currentCode, codes); // 递归生成编码
    return codes;
}

void HuffmanTree::generateCodes(Node* node, const QString& currentCode, QMap<unsigned char, QString>& codes) {
    if (!node) return;
    if (!node->left && !node->right) {
        codes[node->ch] = currentCode;
    } else {
        // 向左子树递归，添加 '0'
        generateCodes(node->left,currentCode + '0', codes);
        // 向右子树递归，添加 '1'
        generateCodes(node->right, currentCode + '1', codes);
    }
}
