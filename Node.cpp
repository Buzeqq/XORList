//
// Created by Milosz Chojnacki on 31.03.2021.
//
#include "XORList.h"

Node::Node(int key) {
    this->key = key;
    addressXOR = nullptr;
}

void Node::SetXOR(Node* predecessor, Node* successor) {
    addressXOR = (Node*)((unsigned long)predecessor ^ (unsigned long)successor);
}

Node* Node::GetNext(Node* predecessor) const {
    return (Node*)((unsigned long)addressXOR ^ (unsigned long)predecessor);
}

Node* Node::GetPrev(Node* successor) const {
    return (Node*)((unsigned long)addressXOR ^ (unsigned long)successor);
}