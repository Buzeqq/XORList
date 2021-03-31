//
// Created by Milosz Chojnacki on 31.03.2021.
//

#ifndef XORLIST_XORLIST_H
#define XORLIST_XORLIST_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

template<class T>
class XORList {

private:
    struct Node {
        T key;
        T* addressXOR;

        Node(T key);
    };

    Node* root; // root of the list
    Node* actual; // pointer


public:
    XORList(Node node); // constructor
    Node* GetRoot() const; // getter for root
    Node* GetActual() const; // getter for actual

    void Next() const; // print next element in list and change actual
    void Previous() const; //print previous element in list and change actual

    void PushFront(); // adding node at front
    void PushBack(); // adding node at back
    void AddBeforeActual(); // adding node before actual

    void PopFront(); // deleting node at front
    void PopBack(); // deleting node at back
    void DeleteValues(T n); // deleting all nodes with key n
    void DeleteActual(); // deleting node that is pointed by actual

    void Print() const; // print list (maybe operator<< overload)
    void PrintBackward() const; // print list but backwards

    ~XORList(); // destructor, remember to free all the memory
};

#endif //XORLIST_XORLIST_H
