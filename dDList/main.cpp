#include <iostream>

class DList {
private:
    struct Node {
        int item_;
        Node *prev_;
        Node *next_;

        Node(int item, Node *prev = nullptr, Node *next = nullptr) :
                item_(item), prev_(prev), next_(next) {};
    };

    Node *head_;
    Node *tail_;
    int count_;

    Node *head() const {
        return head_;
    }

    Node *tail() const {
        return tail_;
    }

    void insertHead(Node *x) {
        x->next_ = head_;
        if (head_ != nullptr) {
            head_->prev_ = x;
        } else {
            tail_ = x;
        }
        head_ = x;
        count_++;
    }

    void insertTail(Node *x) {
        x->prev_ = tail_;
        if (tail_ != nullptr) {
            tail_->next_ = x;
        } else {
            head_ = x;
        }
        tail_ = x;
        count_++;
    }

    void deleteNode(Node *x) {
        if (x == nullptr) {
            throw ("Неверно задан адрес узла(((");
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

    Node *searchNode(int item) const{
        Node *tmp = head_;
        while (tmp != nullptr && tmp->item_ != item) {
            tmp = tmp->next_;
        }
        return tmp;
    }

    Node *replaceNode(Node *x, int item) {
        x->item_ = item;
        return x;
    }

public:
    DList():
        count_(0), head_(nullptr), tail_(nullptr) {};

    DList(const DList &src):DList() {
        Node *tmp = src.head_;
        while (tmp != nullptr) {
            this->insertTail(tmp->item_);
            tmp = tmp->next_;
        }
    }

    void insertHead(int item) {
        insertHead(new Node(item));
    }

    void insertTail(int item) {
        insertTail(new Node(item));
    }
    
    int count() const {
        return count_;
    }

    int headItem() const {
        if (head_ != nullptr) {
            return head_->item_;
        }
        throw ("Список пуст");
    }

    int &headItem() {
        if (head_ != nullptr) {
            return head_->item_;
        }
        throw ("Список пуст");
    }

    int tailItem() const {
        if (tail_ != nullptr) {
            return tail_->item_;
        }
        throw ("Список пуст");
    }

    int &tailItem() {
        if (tail_ != nullptr) {
            return tail_->item_;
        }
        throw ("Список пуст");
    }

    bool deleteHead() {
        if (head_ == nullptr) {
            return 0;
        }
        deleteNode(head_);
        return 1;
    }

    bool deleteTail() {
        if (tail_ == nullptr) {
            return 0;
        }
        deleteNode(tail_);
        return 1;
    }

    bool deleteItem(const int item, bool all = false) {
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

    bool replaceItem(const int oldItem, const int newItem, bool all = false) {
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

    bool searchItem(const int item) const{
        return (searchNode(item) != nullptr);
    }

    friend std::ostream& operator<<(std::ostream &stream, const DList &list) {
        stream << "[";
        Node *tmp = list.head_;
        while (tmp != nullptr) {
            stream << tmp->item_;
            if (tmp != list.tail_) {
                stream << ", ";
            }
            tmp = tmp->next_;
        }
        stream << "]\n";
        return stream;
    }

    bool operator==(const DList &another) {
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

    void addList(const DList &another) {
        Node *tmp = another.head_;
        while (tmp != nullptr) {
            this->insertTail(tmp->item_);
            tmp = tmp->next_;
        }
    }

    ~DList() {
        Node *current = nullptr;
        Node *next = head_;
        while (next != nullptr) {
            current = next;
            next = next->next_;
            delete current;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    DList list, list2;
    std::cout << list;
    list.insertHead(10);
    list2.insertHead(10);
    DList list3(list2);
    std::cout << list;
    std::cout << (list == list2) << '\n';
    list.insertHead(11);
    list2.insertHead(12);
    std::cout << (list == list2) << '\n';
    std::cout << list;
    list.insertTail(5);
    std::cout << list;
    list.insertTail(5);
    std::cout << list;
    list.insertTail(5);
    std::cout << list;
    list.insertTail(10);
    std::cout << list;
    list.insertTail(10);
    std::cout << list;
    list.deleteItem(10);
    std::cout << list;
    list.deleteItem(10, true);
    std::cout << list;
    list.replaceItem(5, 7);
    std::cout << list;
    list.replaceItem(5, 7, true);
    std::cout << list;
    list.addList(list2);
    std::cout << list;
    return 0;
}
