#include "DoubleLinkedList.h"

int main()
{
  try {
    DoubleLinkedList list1, list2;
    std::cout << "Empty list1 -> " << list1 << '\n';
    list1.insertHead(10);
    std::cout << "Insert 10 into head of list1 -> " << list1 << '\n';
    list2.insertHead(10);
    std::cout << "Insert 10 into head of list2 -> " << list2 << '\n';
    DoubleLinkedList list3(list2);
    std::cout << "list3(list2) -> " << list3 << '\n';
    std::cout << "list1 == list2 -> " << (list1 == list2) << '\n';
    list1.insertHead(11);
    list2.insertHead(12);
    std::cout << "list1 -> " << list1 << '\n';
    std::cout << "list2 -> " << list2 << '\n';
    std::cout << "list1 == list2 -> " << (list1 == list2) << '\n';
    list1.insertTail(5);
    std::cout << "Insert 5 into tail of list1 -> " << list1 << '\n';
    list1.insertTail(5);
    list1.insertTail(5);
    std::cout << "Insert 5, 5 into tail of list1 -> " << list1 << '\n';
    list1.insertTail(10);
    list1.insertTail(10);
    std::cout << "Insert 10, 10 into tail of list1 -> " << list1 << '\n';
    list1.deleteItem(10);
    std::cout << "Delete 10 from list1 -> " << list1 << '\n';
    list1.deleteItem(10, true);
    std::cout << "Delete 10 from list1 with all=true -> " << list1 << '\n';
    list1.replaceItem(5, 7);
    std::cout << "Replace 5 with 7 -> " << list1 << '\n';
    list1.replaceItem(5, 7, true);
    std::cout << "Replace 5 with 7 with all=true -> " << list1 << '\n';
    std::cout << "list2 -> " << list2 << '\n';
    list1.addListIntoTail(list2);
    std::cout << "list1 add list2 -> " << list1 << '\n';
    std::cout << "list2 -> " << list2 << '\n';
    list1.addListIntoTail(list2);
    std::cout << "list2 -> " << list2 << '\n';
    list2.tailItem();
  }
  catch (const char *msg) {
    std::cout << "Произошла ошибка: " << msg << '\n';
    return 2;
  }

  return 0;
}