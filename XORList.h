//
// Created by Milosz Chojnacki on 31.03.2021.
//

#ifndef XORLIST_XORLIST_H
#define XORLIST_XORLIST_H

template<class T>
struct Node {
    T key;
    Node* addressXOR;

    explicit Node(T key);
};

template<class T>
class XORList {

public:
    XORList();
    Node<T>* Begin() const; // getter for begin
    Node<T>* End() const; // getter for end
    Node<T>* GetActual() const; // getter for actual

    void Next() const; // print next element in list and change actual
    void Previous() const; //print previous element in list and change actual

    void PushFront(T); // adding node at front
    void PushBack(); // adding node at back
    void AddBeforeActual(); // adding node before actual

    void PopFront(); // deleting node at front
    void PopBack(); // deleting node at back
    void DeleteValues(T n); // deleting all nodes with key n
    void DeleteActual(); // deleting node that is pointed by actual

    void Print() const; // print list (maybe operator<< overload)
    void PrintBackward() const; // print list but backwards

    bool isEmpty() const; // checks if list is empty

    ~XORList(); // destructor TODO remember to free all the memory

private:
    Node<T>* begin; // begin of the list
    Node<T>* end; // end of the list
    Node<T>* actual; // helping pointer
    Node<T>* Create(Node<T>* ptr, T key);
};

#endif //XORLIST_XORLIST_H
