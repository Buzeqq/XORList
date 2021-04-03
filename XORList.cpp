//
// Created by Milosz Chojnacki on 31.03.2021.
//
#include "XORList.h"

XORList::XORList() {
    begin = nullptr;
    end = nullptr;
    actual = nullptr;
    next = nullptr;
    prev = nullptr;
}

Node* XORList::Begin() const {
    return begin;
}

Node* XORList::End() const {
    return end;
}

Node* XORList::GetActual() const {
    return actual;
}

Node* XORList::GetNext() const {
    return next;
}

Node* XORList::GetPrev() const {
    return prev;
}

bool XORList::isEmpty() const {
    if (begin == nullptr) return true;
    else return false;
}

void XORList::PushFront(int key) {
    if (isEmpty()) {
        begin = new Node(key);
        begin->SetXOR(nullptr, nullptr);
        end = actual = begin;
    } else {
        auto* tmp = new Node(key);
        tmp->SetXOR(nullptr, begin);
        if (begin == actual) prev = tmp;
        begin->SetXOR(tmp, begin->GetNext(nullptr));
        begin = tmp;
    }
}

void XORList::PushBack(int key) {
    if (isEmpty()) {
        begin = new Node(key);
        begin->SetXOR(nullptr, nullptr);
        end = actual = begin;
    } else {
        auto* tmp = new Node(key);
        tmp->SetXOR(end, nullptr);
        if (end == actual) next = tmp;
        end->SetXOR(end->GetPrev(nullptr), tmp);
        end = tmp;
    }
}

void XORList::AddBeforeActual(int key) {

}

void XORList::Print() const {
    Node* actualTmp = begin, *prevTmp = nullptr;
    while (actualTmp != nullptr) { // if you can move actualTmp and prevTmp to the right
        std::cout << actualTmp->key << " ";
        Node* tmp = actualTmp;
        actualTmp = actualTmp->GetNext(prevTmp);
        prevTmp = tmp;
    }
}

void XORList::PrintBackward() const {
    Node* actualTmp = end, *nextTmp = nullptr;
    while (actualTmp != nullptr) {
        std::cout << actualTmp->key << " ";
        Node* tmp = actualTmp;
        actualTmp = actualTmp->GetPrev(nextTmp);
        nextTmp = tmp;
    }
}