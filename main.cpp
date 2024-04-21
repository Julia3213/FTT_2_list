#include <iostream>
#include <stdexcept>
#include "list.cpp"
#include "ListException.h" 

int main() {
    LinkedList<int> myList;
    try {
        myList.push_back(2);
        myList.push_back(3);
        myList.push_back(5);
        myList.push_back(4);
        myList.push_back(5);
        myList.push_back(3);
        std::cout <<"Size of list: "<< myList.length() << std::endl;
        std::cout << "List: ";
        myList.print();
        myList.removeAt(3);
        myList.removeVal(2);
        std::cout << "List: ";
        myList.print();
        std::cout <<"Value of the end: "<< myList.getVal(myList.end()) << std::endl;
        std::cout << "Value of element with index=1: " << myList.getVal(myList.findAt(1)) << std::endl;
    }
    catch (ListException e) {
        std::cout << e.what();
    }

    return 0;
}
