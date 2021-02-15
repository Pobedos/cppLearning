#ifndef SLLIST_SINGLYLINKEDORDEREDLIST_HPP
#define SLLIST_SINGLYLINKEDORDEREDLIST_HPP

#include <iostream>

class SinglyLinkedOrderedList {
public:
  SinglyLinkedOrderedList();

  ~SinglyLinkedOrderedList();

  friend std::ostream &operator<<(std::ostream &stream, const SinglyLinkedOrderedList &list);

  bool insertItem(int item);

  bool searchItem(int item) const;

  bool deleteItem(int item);

  void addList(SinglyLinkedOrderedList &another);

  void excludeList(const SinglyLinkedOrderedList &another);

  void intersectList(const SinglyLinkedOrderedList &another);

private:
  struct Node {
    int item_;
    Node *next_;

    Node(int item, Node *next = nullptr):
      item_(item),
      next_(next)
    {}
  };

  Node *head_;

  Node *searchNode(int item) const;
};

#endif
