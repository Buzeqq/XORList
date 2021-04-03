//
// Created by Milosz Chojnacki on 31.03.2021.
//
#include "XORList.h"

XORList::XORList(): begin(nullptr), end(nullptr), actual(nullptr), next(nullptr), prev(nullptr) {}

XORList::Node* XORList::Begin() const {
    return begin;
}

XORList::Node* XORList::End() const {
    return end;
}

XORList::Node* XORList::Actual() const {
    return actual;
}

XORList::Node* XORList::GetNext() const {
    return next;
}

XORList::Node* XORList::GetPrev() const {
    return prev;
}

bool XORList::isEmpty() const {
    if (begin == nullptr) return true;
    else return false;
}

void XORList::PushFront(int key) {
    if (isEmpty()) {
        begin = new Node(key, nullptr, nullptr);
        end = actual = begin;
    } else {
        auto* newNode = new Node(key, nullptr, begin);
        if (begin == actual) prev = newNode; // if actual is begin set next
        begin->SetXOR(newNode, begin->GetNext(nullptr));
        begin = newNode;
    }
}

void XORList::PushBack(int key) {
    if (isEmpty()) {
        begin = new Node(key, nullptr, nullptr);
        end = actual = begin;
    } else {
        auto* newNode = new Node(key, end, nullptr);
        if (end == actual) next = newNode; // if actual is also end set next
        end->SetXOR(end->GetPrev(nullptr), newNode);
        end = newNode;
    }
}

void XORList::AddBeforeActual(int key) {
    if (!actual) std::cerr << "XORList::AddBeforeActual(int key), actual was nullptr." << std::endl;
    else {
        if (prev) { // if there's predecessor for actual
            auto* newNode = new Node(key, prev, actual);
            prev->SetXOR(prev->GetPrev(actual), newNode); // setting new XOR for old prev
            actual->SetXOR(newNode, actual->GetNext(prev)); // setting new XOR for actual
            prev = newNode; // finally setting new prev
        } else { // actual is also begin
            PushFront(key);
        }
    }
}

XORList::Node* XORList::Next() {
    if (!actual) return nullptr; // if there's no actual
    if (actual == end) { // if actual is also end
        prev = nullptr;
        actual = begin;
        next = begin->GetNext(nullptr);
    } else {
        Node* tmp = actual;
        next = next->GetNext(actual); // move next to right
        actual = actual->GetNext(prev); // move actual to right (actual = old next)
        prev = tmp; // set prev as old actual
    }
    return actual;
}

XORList::Node* XORList::Previous() {
    if (!actual) return nullptr; // if there's no actual
    if (actual == begin) { // if actual is also begin
        next = nullptr;
        actual = end;
        prev = end->GetPrev(nullptr);
    } else {
        Node* tmp = actual;
        prev = prev->GetPrev(actual); // move prev to left
        actual = actual->GetPrev(next); // move actual to left (actual = old prev)
        next = tmp; // set next as old actual
    }
    return actual;
}

void XORList::PopFront() {
    if (isEmpty()) return;
    Node* tmp = begin;
    if (begin == end) { // if there's only one node
        delete begin;
        begin = end = actual = prev = next = nullptr; // set all pointers to nullptr
        return;
    }
    begin = begin->GetNext(nullptr); // set begin as successor of old begin
    begin->SetXOR(nullptr, begin->GetNext(tmp)); // set XOR of new begin
    Node* nextTmp = begin->GetNext(nullptr); // pointer for successor of new begin
    if (nextTmp) { // if there's successor of new begin
        nextTmp->SetXOR(begin, nextTmp->GetNext(begin)); // set XOR of successor of new begin
    }
    delete tmp; // finally delete old begin
}

void XORList::Print() const {
    Node* actualTmp = begin, *prevTmp = nullptr;
    while (actualTmp != nullptr) { // if you can, move actualTmp and prevTmp to the right
        std::cout << actualTmp->GetKey() << " ";
        Node* tmp = actualTmp;
        actualTmp = actualTmp->GetNext(prevTmp);
        prevTmp = tmp;
    }
}

void XORList::PrintBackward() const {
    Node* actualTmp = end, *nextTmp = nullptr;
    while (actualTmp != nullptr) {
        std::cout << actualTmp->GetKey() << " ";
        Node* tmp = actualTmp;
        actualTmp = actualTmp->GetPrev(nextTmp);
        nextTmp = tmp;
    }
}

XORList::~XORList() {
    Node* actualTmp = begin, *prevTmp = nullptr;
    while (actualTmp != nullptr) {
        Node* tmp = actualTmp;
        actualTmp = actualTmp->GetPrev(prevTmp);
        delete prevTmp; // deleting nullptr has no effect
        prevTmp = tmp;
    }
    delete end; // in order to free all memory we have to do also this
}