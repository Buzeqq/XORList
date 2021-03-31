//
// Created by Milosz Chojnacki on 31.03.2021.
//

#define Template template<class T>

#include "XORList.h"

Template
XORList<T>::XORList() {
    begin = nullptr;
    end = nullptr;
    actual = nullptr;
}

Template
Node<T>* XORList<T>::Begin() const {
    return begin;
}

Template
Node<T>* XORList<T>::End() const {
    return end;
}

Template
Node<T>* XORList<T>::GetActual() const {
    return actual;
}

Template
Node<T>* XORList<T>::Create(Node<T> *ptr, T key) {
    ptr = new Node(key);
    return ptr;
}

Template
bool XORList<T>::isEmpty() const {
    if (begin == nullptr) return true;
    else return false;
}

Template
void XORList<T>::PushFront() {
    if (isEmpty()) {

    }
}