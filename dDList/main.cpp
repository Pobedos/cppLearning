
#include "DoubleLinkedList.h"

int main() {
    try {
        std::cout << "Hello, World!" << std::endl;
        DoubleLinkedList list1, list2;
        std::cout << "Empty list1 -> " << list1;
        list1.insertHead(10);
        std::cout << "Insert 10 into list1 -> " << list1;
        list2.insertHead(10);
        std::cout << "Insert 10 into list1 -> " << list1;
        DoubleLinkedList list3(list2);
        std::cout << list1;
        std::cout << (list1 == list2) << '\n';
        list1.insertHead(11);
        list2.insertHead(12);
        std::cout << (list1 == list2) << '\n';
        std::cout << list1;
        list1.insertTail(5);
        std::cout << list1;
        list1.insertTail(5);
        std::cout << list1;
        list1.insertTail(5);
        std::cout << list1;
        list1.insertTail(10);
        std::cout << list1;
        list1.insertTail(10);
        std::cout << list1;
        list1.deleteItem(10);
        std::cout << list1;
        list1.deleteItem(10, true);
        std::cout << list1;
        list1.replaceItem(5, 7);
        std::cout << list1;
        list1.replaceItem(5, 7, true);
        std::cout << list1;
        list1.addListIntoTail(list2);
        std::cout << list1;
    }
    catch (const char *msg) {
        std::cerr << "Произошла ошибка: " << msg;
    }

    return 0;
}
