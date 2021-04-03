//
// Created by Milosz Chojnacki on 31.03.2021.
//
#include "XORList.h"

XORList::Node::Node(int key) {
    this->key = key;
    addressXOR = nullptr;
}

void XORList::Node::SetXOR(Node* predecessor, Node* successor) { // probably should be moved to the constructor
    addressXOR = (Node*)((unsigned long)predecessor ^ (unsigned long)successor);
}

XORList::Node* XORList::Node::GetNext(XORList::Node* predecessor) const {   // this function is same as GetPrev function
    return (Node*)((unsigned long)addressXOR ^ (unsigned long)predecessor); // and I did it to make code more clear if
}                                                                           // I want to go to prev or next

XORList::Node* XORList::Node::GetPrev(XORList::Node* successor) const { // for the comment look up at line 15
    return (Node*)((unsigned long)addressXOR ^ (unsigned long)successor);
}