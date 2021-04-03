//
// Created by Milosz Chojnacki on 31.03.2021.
//

#ifndef XORLIST_XORLIST_H
#define XORLIST_XORLIST_H

#include <iostream>
#include <string>

class XORList {
    struct Node {
    private:
        int key;
        Node* addressXOR;

    public:
        Node(int key, Node* predecessor, Node* successor);

        [[nodiscard]] int GetKey() const; // getter for key
        Node* GetPrev(Node* successor) const; // getter for pointer of predecessor
        Node* GetNext(Node* predecessor) const; // getter for pointer of successor

        void SetXOR(Node* predecessor, Node* successor); // setter for addressXOR
    };

public:
    XORList();
    [[nodiscard]] Node* Begin() const; // getter for begin
    [[nodiscard]] Node* End() const; // getter for end
    [[nodiscard]] Node* Actual() const; // getter for actual

    Node* Next(); // sets new actual as successor of actual and returns new actual
    Node* Previous(); // sets new actual as predecessor of actual and returns new actual

    void PushFront(int key); // adds node at front
    void PushBack(int key); // adds node at back
    void AddBeforeActual(int key); // adds node before actual

    void PopFront(); // deletes node at front
    void PopBack(); // deletes node at back
    void DeleteValues(int n); // deletes all nodes with key n
    void DeleteActual(); // deletes node that is pointed by actual

    void Print() const; // prints list (maybe operator<< overload)
    void PrintBackward() const; // prints list, but backwards

    [[nodiscard]] bool isEmpty() const; // checks if list is empty

    ~XORList(); // destructor

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
    Node* begin; // begin of the list
    Node* end; // end of the list
    Node* actual; // helping pointer
    Node* prev; // predecessor of actual
    Node* next; // successor of actual

    static Node* XOR(Node* left, Node* right) {
        return (Node*)((unsigned long)left ^ (unsigned long)right);
    }

    [[nodiscard]] Node* GetPrev() const; // getter for predecessor of actual
    [[nodiscard]] Node* GetNext() const; // getter for successor of actual
};

#endif //XORLIST_XORLIST_H