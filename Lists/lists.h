#ifndef _P_LISTS_H_
#define _P_LISTS_H_
#include <iostream>
#include <stdexcept>
namespace pop {
template <class T>
struct Node {
    T val;
    Node* next = nullptr;
};

template <class T>
struct Dll_node {
    Dll_node<T>* prev = nullptr;
    T val;
    Dll_node<T>* next = nullptr;
};

template <class LinkedList>
class LinkedListIterator {
public:
    using ValueType = Node<typename LinkedList::ValueType>;
    using ReferenceType =  ValueType&;
    using PointerType =  ValueType*;
private:
	LinkedListIterator(PointerType ptr) : m_ptr(ptr){}
	LinkedListIterator operator*(){return *m_ptr;}
private:
    PointerType m_ptr;
};

template <class T>
class LinkedList {
public:
    using ValueType = T;
    using Iterator =  LinkedListIterator<LinkedList<T>>;

private:
    Node<T>* start;
    int size;

public:
    LinkedList()
        : start(nullptr)
        , size(0)
    {
    }

    explicit LinkedList(T v)
        : start(new Node<T> { v, nullptr })
        , size(1)
    {
    }

    Node<T>* gethead() const noexcept
    {
        return start;
    }

    void push(T v) noexcept
    {
        Node<T>* n = new Node<T> { v, nullptr };
        if (start == nullptr) {
            start = n;
        } else {
            Node<T>* dum = start;
            while (dum->next != nullptr) {
                dum = dum->next;
            }
            dum->next = n;
        }
        ++size;
    }

    void Insert_at_start(T v) noexcept
    {
        if (start == nullptr) {
            start = new Node<T> { v, nullptr };
        } else {
            Node<T>* n = new Node<T> { start->val, start->next };
            start->val = v;
            start->next = n;
        }
        ++size;
    }

    void Insert_at_Index(T v, int i)
    {
        if (i < 0 || i > size) {
            throw std::out_of_range("index out of bounds");
        }
        if (i == 0) {
            Insert_at_start(v);
            return;
        }
        Node<T>* dum = start;
        for (int j = 0; j < (i - 1); ++j) {
            dum = dum->next;
        }
        Node<T>* n = new Node<T> { v, dum->next };
        dum->next = n;
        ++size;
    }

    void Insert_at_end(T v) noexcept
    {
        push(v);
    }

    void remove_head() noexcept
    {
        if (start == nullptr)
            return;
        Node<T>* dum = start;
        start = start->next;
        delete dum;
        --size;
    }

    void pop() noexcept
    {
        if (start == nullptr)
            return;
        if (start->next == nullptr) {
            delete start;
            start = nullptr;
            size = 0;
            return;
        }
        Node<T>* dum = start;
        while (dum->next->next != nullptr) {
            dum = dum->next;
        }
        delete dum->next;
        dum->next = nullptr;
        --size;
    }

    void remove_val(T v) noexcept
    {
        if (start == nullptr)
            return;
        if (start->val == v) {
            remove_head();
            return;
        }
        Node<T>* dum = start;
        while (dum->next != nullptr && dum->next->val != v) {
            dum = dum->next;
        }
        if (dum->next == nullptr) {
            std::cout << "Value not found\n";
            return;
        }
        Node<T>* d2 = dum->next->next;
        delete dum->next;
        dum->next = d2;
        --size;
    }

    void remove_at_index(int i)
    {
        if (i < 0 || i >= size) {
            throw std::out_of_range("index out of bounds");
        }
        if (i == 0) {
            remove_head();
            return;
        }
        Node<T>* dum = start;
        for (int j = 0; j < (i - 1); ++j) {
            dum = dum->next;
        }
        Node<T>* d2 = dum->next->next;
        delete dum->next;
        dum->next = d2;
        --size;
    }

    void free() noexcept
    {
        while (start != nullptr) {
            remove_head();
        }
    }

    void show() const noexcept
    {
        Node<T>* dummy = start;
        while (dummy != nullptr) {
            std::cout << dummy->val << std::endl;
            dummy = dummy->next;
        }
    }

    int get_size() const noexcept
    {
        return size;
    }

    ~LinkedList() noexcept
    {
        free();
    }

    Iterator Begin(){
            return Iterator(this->start);
    }
};

template <class T>
class circular_linkedlist {
private:
    Node<T>* head;

public:
    circular_linkedlist() { head = new Node<T>; }

    circular_linkedlist(T v)
    {
        head = new Node<T>;
        head->next = head;
        head->val = v;
        // std::cout<<":)";
    }

    void push(T v)
    {
        if (head == nullptr) {
            head = new Node<T>;
            head->val = v;
            head->next = head;
            return;
        }
        Node<T>* n = new Node<T>;
        n->val = v;
        Node<T>* hd = head;
        while (hd->next != head) {
            hd = hd->next;
        }
        n->next = head;
        hd->next = n;
    }

    void Insert_at_head(T v)
    {
        Node<T>* n = new Node<T>;
        n->val = v;
        n->next = head;
        Node<T>* dum = head;
        while (dum->next != head) {
            dum = dum->next;
        }
        dum->next = n;
        head = n;
    }

    void show()
    {
        Node<T>* dm = head;
        do {
            std::cout << dm->val << std::endl;
            dm = dm->next;
        } while (dm != head);
    }

    void pop()
    {
        if (head == nullptr) {
            return;
        }
        if (head->next == head) {
            // std::cout<<"popped head \n";
            head = nullptr;
        }
        Node<T>* d = head;
        while (d->next->next != head) {
            d = d->next;
        }
        // std::cout<<"popped "<<d->next->val<<std::endl;
        delete d->next;
        d->next = head;
    }

    void remove_head()
    {
        if (head->next == head) {
            head = nullptr;
        }
        Node<T>* dum = head;
        Node<T>* a = head;
        while (dum->next != head) {
            dum = dum->next;
        }
        dum->next = head->next;
        delete head;
        head = dum->next;
        // o->o
        // |__|
    }

    void free()
    {
        // Node<T>* dum = head;
        while (head != nullptr) {

            pop();
        }
    }

    ~circular_linkedlist()
    {
        free();
    }
};

template <class T>
class Doubly_linkedlist {
private:
    Dll_node<T>* head;

public:
    Doubly_linkedlist()
    {
        head = nullptr;
    }
    Doubly_linkedlist(T v)
    {
        head = new Dll_node<T>;
        head->val = v;
    }
    void push(T v)
    {
        if (head == nullptr) {
            head = new Dll_node<T>;
            head->val = v;
            return;
        }

        Dll_node<T>* n = new Dll_node<T>;
        n->val = v;
        Dll_node<T>* dum = head;
        while (dum->next != nullptr) {
            dum = dum->next;
        }
        dum->next = n;
        n->prev = dum;
    }
    void Insert_at_head(T v)
    {
        Dll_node<T>* n = new Dll_node<T>;
        n->val = v;
        head->prev = n;
        n->next = head;
        head = n;
    }
    void pop()
    {
        if (head == nullptr || head->next == nullptr) {
            head = nullptr;
            return;
        }
        Dll_node<T>* dum = new Dll_node<T>;
        while (dum->next->next != nullptr) {
            dum = dum->next;
        }
        delete dum->next;
        dum->next = nullptr;
    }
    void remove_head()
    {
        Dll_node<T>* dum = head;
        head = head->next;
        head->prev = nullptr;
        delete dum;
    }
    void show()
    {
        Dll_node<T>* dum = head;
        while (dum != nullptr) {
            std::cout << dum->val << std::endl;
            dum = dum->next;
        }
    }
    void free()
    {
        Dll_node<T>* dum = head;
        while (head != nullptr) {
            dum = head->next;
            std::cout << "deleted " << head->val << std::endl;
            delete head;
            head = dum;
        }
    }
    ~Doubly_linkedlist()
    {
        free();
    }
};

} // namespace pop

#endif

int main(int argc, char const *argv[])
{
    pop::LinkedList<int> ll(10);
    // pop::LinkedList<int>::Iterator it = ll.Begin();
    return 0;
}
