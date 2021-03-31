//
// Created by Milosz Chojnacki on 31.03.2021.
//

#include "XORList.h"

template<class T>
Node<T>::Node(T key) {
    this->key = key;
    addressXOR = nullptr;
}