#include <iostream>
#include <string>
#include "XORList.h"

int main() {
    std::ios_base::sync_with_stdio(false);   //
    std::cin.tie(nullptr);                  // faster io

    XORList list;

    std::string command;
    /*while (std::cin >> command) { // to change
        if (command == "ACTUAL") {} //actual
        else if (command == "NEXT") {}
        else if (command == "PREV") {}
        else if (command == "ADD_BEG") {}
        else if (command == "ADD_END") {}
        else if (command == "ADD_ACT") {}
        else if (command == "DEL_BEG") {}
        else if (command == "DEL_END") {}
        else if (command == "DEL_VAL") {}
        else if (command == "DEL_ACT") {}
        else if (command == "PRINT_FORWARD") {}
        else if (command == "PRINT_BACKWARD") {}
    }*/

    list.PushBack(3);
    list.PushFront(2);
    list.PushBack(1);
    list.PushFront(4);
    list.Print();
    std::cout << std::endl;
    list.PrintBackward();

    return 0;
}
