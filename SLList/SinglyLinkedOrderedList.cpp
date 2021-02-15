#include "SinglyLinkedOrderedList.hpp"

SinglyLinkedOrderedList::SinglyLinkedOrderedList():
  head_(nullptr)
{}

SinglyLinkedOrderedList::~SinglyLinkedOrderedList()
{
  Node *current;
  Node *next = head_;
  while (next != nullptr) {
    current = next;
    next = next->next_;
    delete current;
  }
}

std::ostream &operator<<(std::ostream &stream, const SinglyLinkedOrderedList &list)
{
  SinglyLinkedOrderedList::Node *tmp = list.head_;
  stream << '[';
  while (tmp != nullptr) {
    stream << tmp->item_;
    tmp = tmp->next_;
    if (tmp != nullptr) {
      stream << ", ";
    }
  }
  return stream << ']';
}

bool SinglyLinkedOrderedList::insertItem(int item)
{
  Node *tmp = head_;
  if (tmp == nullptr) {
    head_ = new Node(item);
    return true;
  }
  if (tmp->item_ > item) {
    head_ = new Node(item, head_);
    return true;
  }
  while (tmp->next_ != nullptr && tmp->next_->item_ <= item) {
    tmp = tmp->next_;
  }
  if (tmp->item_ == item) {
    return false;
  } else if (tmp->next_ == nullptr) {
    tmp->next_ = new Node(item);
  } else {
    tmp->next_ = new Node(item, tmp->next_);
  }
  return true;
}

bool SinglyLinkedOrderedList::searchItem(int item) const
{
  if (searchNode(item) != nullptr) {
    return true;
  }
  return false;
}

bool SinglyLinkedOrderedList::deleteItem(int item)
{
  if (head_ == nullptr) {
    return false;
  }
  if (head_->item_ == item) {
    Node *tmp = head_->next_;
    delete head_;
    head_ = tmp;
    return true;
  }
  Node *prev = nullptr;
  Node *current = head_;
  while (current != nullptr) {
    if (current->item_ == item) {
      prev->next_ = current->next_;
      delete current;
      return true;
    }
    prev = current;
    current = current->next_;
  }
  return false;
}

void SinglyLinkedOrderedList::addList(SinglyLinkedOrderedList &another)
{
  Node *node1 = head_;
  Node *node2 = another.head_;
  Node *tmp = nullptr;
  Node *tmpDel = nullptr;
  Node *newHead = nullptr;
  if (node1->item_ < node2->item_) {
    newHead = head_;
    node1 = node1->next_;
  } else if (node1->item_ == node2->item_) {
    newHead = head_;
    node1 = node1->next_;
    tmpDel = node2;
    node2 = node2->next_;
    delete tmpDel;
  } else {
    newHead = another.head_;
    node2 = node2->next_;
  }
  tmp = newHead;
  while (node1 != nullptr && node2 != nullptr) {
    if (node1->item_ < node2->item_) {
      tmp->next_ = node1;
      tmp = tmp->next_;
      node1 = node1->next_;
    } else if (node1->item_ > node2->item_) {
      tmp->next_ = node2;
      tmp = tmp->next_;
      node2 = node2->next_;
    } else {
      tmp->next_ = node1;
      tmp = tmp->next_;
      node1 = node1->next_;
      tmpDel = node2;
      node2 = node2->next_;
      delete tmpDel;
    }
  }
  if (node1 != nullptr) {
    tmp->next_ = node1;
  }
  if (node2 != nullptr) {
    tmp->next_ = node2;
  }
  head_ = newHead;
  another.head_ = nullptr;
}

void SinglyLinkedOrderedList::excludeList(const SinglyLinkedOrderedList &another)
{
  Node *node1 = head_;
  Node *node2 = another.head_;
  Node *tmp = nullptr;
  Node *tmpDel = nullptr;
  Node *newHead = nullptr;
  while (node1 != nullptr && node2 != nullptr && node1->item_ >= node2->item_) {
    if (node1->item_ == node2->item_) {
      tmpDel = node1;
      node1 = node1->next_;
      delete tmpDel;
      node2 = node2->next_;
    } else {
      node2 = node2->next_;
    }
  }
  newHead = node1;
  if (node1 == nullptr) {
    head_ = newHead;
    return;
  }
  node1 = node1->next_;
  tmp = newHead;
  while (node1 != nullptr && node2 != nullptr) {
    if (node1->item_ < node2->item_) {
      tmp->next_ = node1;
      tmp = tmp->next_;
      node1 = node1->next_;
    } else if (node1->item_ > node2->item_) {
      node2 = node2->next_;
    } else {
      tmpDel = node1;
      node1 = node1->next_;
      delete tmpDel;
      node2 = node2->next_;
    }
  }
  tmp->next_ = node1;
  head_ = newHead;

}

void SinglyLinkedOrderedList::intersectList(const SinglyLinkedOrderedList &another)
{
  Node *node1 = head_;
  Node *node2 = another.head_;
  Node *tmp = nullptr;
  Node *tmpDel = nullptr;
  Node *newHead = nullptr;
  while (node1 != nullptr && node2 != nullptr && node1->item_ != node2->item_) {
    if (node1->item_ < node2->item_) {
      tmpDel = node1;
      node1 = node1->next_;
      delete tmpDel;
    } else {
      node2 = node2->next_;
    }
  }
  if (node1 == nullptr) {
    head_ = nullptr;
    return;
  }
  if (node2 == nullptr) {
    while (node1 != nullptr) {
      tmpDel = node1;
      node1 = node1->next_;
      delete tmpDel;
      head_ = nullptr;
    }
    return;
  }
  newHead = node1;
  node1 = node1->next_;
  node2 = node2->next_;
  tmp = newHead;
  while (node1 != nullptr && node2 != nullptr) {
    if (node1->item_ < node2->item_) {
      tmpDel = node1;
      node1 = node1->next_;
      delete tmpDel;
    } else if (node1->item_ > node2->item_) {
      node2 = node2->next_;
    } else {
      tmp->next_ = node1;
      tmp = tmp->next_;
      node1 = node1->next_;
      node2 = node2->next_;
    }
  }
  while (node1 != nullptr) {
    tmpDel = node1;
    node1 = node1->next_;
    delete tmpDel;
  }
  head_ = newHead;
  tmp->next_ = nullptr;
}

SinglyLinkedOrderedList::Node *SinglyLinkedOrderedList::searchNode(int item) const
{
  Node *tmp = head_;
  while (tmp != nullptr) {
    if (tmp->item_ == item) {
      return tmp;
    }
    tmp = tmp->next_;
  }
  return nullptr;
}
