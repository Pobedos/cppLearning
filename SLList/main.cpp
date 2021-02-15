#include <iostream>
#include "SinglyLinkedOrderedList.hpp"

int main()
{
  typedef SinglyLinkedOrderedList SLOList;
  SLOList list, list2;
//  list.insertItem(9);
//  list.insertItem(10);
  list.insertItem(11);
  list.insertItem(13);
  list.insertItem(12);
//  std::cout << list.searchItem(9) << list.searchItem(14) << std::endl;
//  std::cout << list.deleteItem(9) << std::endl;
//  std::cout << list.deleteItem(14) << std::endl;
//  std::cout << list.deleteItem(10) << std::endl;
//  std::cout << list.deleteItem(11) << std::endl;
//  std::cout << list.deleteItem(13) << std::endl;
//  std::cout << list.deleteItem(12) << std::endl;
//  std::cout << list.deleteItem(12) << std::endl;
//  std::cout << list << std::endl;

  list2.insertItem(10);
//  list2.insertItem(112);
//  list2.insertItem(13);
//  list2.insertItem(93);
//  list2.insertItem(12);
//  list2.insertItem(121);
//  list2.insertItem(13);

//  std::cout << list2 << std::endl;
//  list.addList(list2);
  std::cout << list << std::endl;

  std::cout << list2 << std::endl;
  list.intersectList(list2);
  std::cout << list << std::endl;
  std::cout << list2 << std::endl;
  return 0;
}
