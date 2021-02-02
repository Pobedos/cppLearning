#ifndef DDLIST_DOUBLELINKEDLIST_H
#define DDLIST_DOUBLELINKEDLIST_H

#include <iostream>

class DoubleLinkedList {
public:
  DoubleLinkedList():
          head_(nullptr),
          tail_(nullptr),
          count_(0)
  {};

  DoubleLinkedList(const DoubleLinkedList &src);

  DoubleLinkedList(DoubleLinkedList &&src);

  ~DoubleLinkedList();

  DoubleLinkedList &operator=(const DoubleLinkedList &src);

  DoubleLinkedList &operator=(DoubleLinkedList &&src);

  bool operator==(const DoubleLinkedList &another);

  friend std::ostream &operator<<(std::ostream &stream, const DoubleLinkedList &list);

  void insertHead(int item);

  void insertTail(int item);

  int count() const;

  int headItem() const;

  int &headItem();

  int tailItem() const;

  int &tailItem();

  bool deleteHead();

  bool deleteTail();

  bool deleteItem(int item, bool all = false);

  bool replaceItem(int oldItem, int newItem, bool all = false);

  bool searchItem(int item) const;

  void addListIntoTail(DoubleLinkedList &another);

private:
  struct Node {
    int item_;
    Node *prev_;
    Node *next_;

    Node(int item, Node *prev = nullptr, Node *next = nullptr):
            item_(item),
            prev_(prev),
            next_(next)
    {};
  };

  Node *head_;
  Node *tail_;
  int count_;

  Node *head() const;

  Node *tail() const;

  void insertHead(Node *x);

  void insertTail(Node *x);

  void deleteNode(Node *x);

  Node *searchNode(int item) const;

  Node *replaceNode(Node *x, int item);

  void swap(DoubleLinkedList &src);
};

#endif //DDLIST_DOUBLELINKEDLIST_H
