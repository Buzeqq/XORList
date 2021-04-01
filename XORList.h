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
    Node<T>* GetPrev() const; // getter for predecessor of actual
    Node<T>* GetNext() const; // getter for successor of actual

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

    enum COMMANDS {
        ACTUAL = 0,
        NEXT = 1,
        PREV = 2,
        ADD_BEG = 3,
        ADD_END = 4,
        ADD_ACT = 5,
        DEL_BEG = 6,
        DEL_END = 7,
        DEL_VAL = 8,
        DEL_ACT = 9,
        PRINT_FORWARD = 10,
        PRINT_BACKWARD = 11
    };

private:
    Node<T>* begin; // begin of the list
    Node<T>* end; // end of the list
    Node<T>* actual; // helping pointer
    Node<T>* prev; // predecessor of actual
    Node<T>* next; // successor of actual
    Node<T>* Create(Node<T>* ptr, T key);
};

#endif //XORLIST_XORLIST_H
