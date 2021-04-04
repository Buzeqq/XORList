#include <iostream>
#include <string>
#include "XORList.h"

std::ostream& operator<<(std::ostream& stream, XORList& list) {
    list.Print();
    return stream;
}

int main() {
    std::ios_base::sync_with_stdio(false);   //
    std::cin.tie(nullptr);                  // faster io

    XORList list;

    std::string command;
    while (std::cin >> command) {
        if (command == "ACTUAL") {
            if (!list.Actual()) std::cout << "NULL" << std::endl;
            else std::cout << list.Actual()->GetKey() << std::endl;
        } else if (command == "NEXT") {
            list.Next();
            if (!list.Actual()) std::cout << "NULL" << std::endl;
            else std::cout << list.Actual()->GetKey() << std::endl;
        } else if (command == "PREV") {
            list.Previous();
            if (!list.Actual()) std::cout << "NULL" << std::endl;
            else std::cout << list.Actual()->GetKey() << std::endl;
        } else if (command == "ADD_BEG") {
            int value;
            std::cin >> value;
            list.PushFront(value);
        } else if (command == "ADD_END") {
            int value;
            std::cin >> value;
            list.PushBack(value);
        } else if (command == "ADD_ACT") {
            int value;
            std::cin >> value;
            list.AddBeforeActual(value);
        } else if (command == "DEL_BEG") {
            list.PopFront();
        } else if (command == "DEL_END") {
            list.PopBack();
        } else if (command == "DEL_VAL") {
            int value;
            std::cin >> value;
            list.DeleteValues(value);
        } else if (command == "DEL_ACT") {
            list.DeleteActual();
        } else if (command == "PRINT_FORWARD") {
            std::cout << list;
        } else if (command == "PRINT_BACKWARD") {
            list.PrintBackward();
        }
    }

    return 0;
}
