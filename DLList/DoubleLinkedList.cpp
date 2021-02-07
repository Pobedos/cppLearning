#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &src):
        DoubleLinkedList()
{
  Node *tmp = src.head_;
  while (tmp != nullptr) {
    this->insertTail(tmp->item_);
    tmp = tmp->next_;
  }
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList &&src)
{
  head_ = src.head_;
  tail_ = src.tail_;
  count_ = src.count_;
  src.head_ = nullptr;
  src.tail_ = nullptr;
  src.count_ = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
  purge();
  head_ = nullptr;
  tail_ = nullptr;
}

DoubleLinkedList &DoubleLinkedList::operator=(const DoubleLinkedList &src)
{
  if (this == &src) {
    return *this;
  }
  DoubleLinkedList tempList(src);
  swap(tempList);
  return *this;
}

DoubleLinkedList &DoubleLinkedList::operator=(DoubleLinkedList &&src)
{
  if (this == &src) {
    return *this;
  }
  purge();
  head_ = src.head_;
  tail_ = src.tail_;
  count_ = src.count_;
  src.head_ = nullptr;
  src.tail_ = nullptr;
  return *this;
}

std::ostream &operator<<(std::ostream &stream, const DoubleLinkedList &list)
{
  stream << "[";
  DoubleLinkedList::Node *tmp = list.head_;
  while (tmp != nullptr) {
    stream << tmp->item_;
    if (tmp != list.tail_) {
      stream << ", ";
    }
    tmp = tmp->next_;
  }
  stream << "]";
  return stream;
}

bool DoubleLinkedList::operator==(const DoubleLinkedList &another)
{
  Node *tmp = this->head_;
  Node *tmp2 = another.head_;
  while (tmp != nullptr) {
    if (tmp->item_ != tmp2->item_) {
      return 0;
    }
    tmp = tmp->next_;
    tmp2 = tmp2->next_;
  }
  return 1;
}

DoubleLinkedList::Node *DoubleLinkedList::head() const
{
  return head_;
}

DoubleLinkedList::Node *DoubleLinkedList::tail() const
{
  return tail_;
}

int DoubleLinkedList::count() const
{
  return count_;
}

void DoubleLinkedList::insertHead(DoubleLinkedList::Node *x)
{
  x->next_ = head_;
  if (head_ != nullptr) {
    head_->prev_ = x;
  } else {
    tail_ = x;
  }
  head_ = x;
  count_++;
}

void DoubleLinkedList::insertTail(DoubleLinkedList::Node *x)
{
  x->prev_ = tail_;
  if (tail_ != nullptr) {
    tail_->next_ = x;
  } else {
    head_ = x;
  }
  tail_ = x;
  count_++;
}

void DoubleLinkedList::deleteNode(DoubleLinkedList::Node *x)
{
  if (x == nullptr) {
    throw ("Неверно задан адрес узла");
  }
  if (x->prev_ != nullptr) {
    (x->prev_)->next_ = x->next_;
  } else {
    head_ = x->next_;
  }
  if (x->next_ != nullptr) {
    (x->next_)->prev_ = x->prev_;
  } else {
    tail_ = x->prev_;
  }
  delete x;
  count_--;
}

DoubleLinkedList::Node *DoubleLinkedList::searchNode(int item) const
{
  Node *tmp = head_;
  while (tmp != nullptr && tmp->item_ != item) {
    tmp = tmp->next_;
  }
  return tmp;
}

void DoubleLinkedList::swap(DoubleLinkedList &src)
{
  Node *tempHead = head_;
  Node *tempTail = tail_;
  int tempCount = count_;
  head_ = src.head_;
  tail_ = src.tail_;
  count_ = src.count_;
  src.head_ = tempHead;
  src.tail_ = tempTail;
  src.count_ = tempCount;
}

DoubleLinkedList::Node *DoubleLinkedList::replaceNode(DoubleLinkedList::Node *x, int item)
{
  x->item_ = item;
  return x;
}

void DoubleLinkedList::insertHead(int item)
{
  insertHead(new Node(item));
}

void DoubleLinkedList::insertTail(int item)
{
  insertTail(new Node(item));
}

int DoubleLinkedList::headItem() const
{
  if (head_ != nullptr) {
    return head_->item_;
  }
  throw ("Список пуст");
}

int &DoubleLinkedList::headItem()
{
  if (head_ != nullptr) {
    return head_->item_;
  }
  throw ("Список пуст");
}

int DoubleLinkedList::tailItem() const
{
  if (tail_ != nullptr) {
    return tail_->item_;
  }
  throw ("Список пуст");
}

int &DoubleLinkedList::tailItem()
{
  if (tail_ != nullptr) {
    return tail_->item_;
  }
  throw ("Список пуст");
}

bool DoubleLinkedList::deleteHead()
{
  if (head_ == nullptr) {
    return 0;
  }
  deleteNode(head_);
  return 1;
}

bool DoubleLinkedList::deleteTail()
{
  if (tail_ == nullptr) {
    return 0;
  }
  deleteNode(tail_);
  return 1;
}

bool DoubleLinkedList::deleteItem(const int item, bool all)
{
  Node *x = searchNode(item);
  if (x == nullptr) {
    return 0;
  }
  if (all) {
    while (x != nullptr) {
      deleteNode(x);
      x = searchNode(item);
    }
  } else {
    deleteNode(x);
  }
  return 1;
}

bool DoubleLinkedList::replaceItem(const int oldItem, const int newItem, bool all)
{
  Node *x = searchNode(oldItem);
  if (x == nullptr) {
    return 0;
  }
  if (all) {
    while (x != nullptr) {
      replaceNode(x, newItem);
      x = searchNode(oldItem);
    }
  } else {
    replaceNode(x, newItem);
  }
  return 1;
}

bool DoubleLinkedList::searchItem(const int item) const
{
  return (searchNode(item) != nullptr);
}

void DoubleLinkedList::addListIntoTail(DoubleLinkedList &another)
{
  if (tail_ != nullptr) {
    tail_->next_ = another.head_;
  } else {
    head_ = another.head_;
  }
  if (another.head_ != nullptr) {
    another.head_->prev_ = tail_;
    tail_ = another.tail_;
  }
  count_ += another.count_;
  another.count_ = 0;
  another.head_ = nullptr;
  another.tail_ = nullptr;
}

void DoubleLinkedList::purge()
{
  Node *current = nullptr;
  Node *next = head_;
  while (next != nullptr) {
    current = next;
    next = next->next_;
    delete current;
  }
}