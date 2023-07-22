#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <class T>

struct Node
{
    T val;
    Node* next = nullptr;
};

template <class T>
class LinkedList
{
private:
    Node<T>* start;
    int size;
public:
    LinkedList()
    {
        start = nullptr;
        size = 1;
    }

    LinkedList(T v)
    {
        start = new Node<T>;
        start->next = nullptr;
        start->val = v;
        size = 1;
    }

    Node<T>* gethead(void)
    {
        return start;
    }

    void push(T v)
    {
        Node<T>* n = new Node<T>;
        n->val = v;
        Node<T>* dum = start;
        if (start == nullptr)
        {
            start->val = v;
            return;
        }
        
        while (dum->next != nullptr)
        {
            dum = dum->next;
        }
        dum->next = n;
        size++;
        // while(star)
    }

    void Insert_at_start(T v)
    {
        Node<T>* n = new Node<T>;
        n->next = start->next;
        n->val = start->val;
        start->next = n;
        start->val = v;
        size++;
        // start = start->next;
    }

    void Insert_at_Index(T v, int i)
    {
        Node<T>* dum = start;
        for (int j = 0; j < (i - 1); j++)
        {
            if (dum->next == nullptr)
            {
                cout << "out of bounds\n";
                return;
            }
            dum = dum->next;
        }
        Node<T>* n = new Node<T>;
        n->val = v;
        n->next = dum->next;
        dum->next = n;
        size++;
    }

    void Insert_at_end(T v)
    {
        push(v);
    }

    void remove_head() {
        Node<T>* dum = start;
        start = start->next;
        delete dum;
        size--;
    }

    void pop(void)
    {
        Node<T>* dum = start;
        while (dum->next->next != nullptr)
        {
            dum = dum->next;
        }
        delete dum->next;
        dum->next = nullptr;
        size--;
    }

    void remove_val(T v)
    {
        Node<T>* dum = start;
        if (start->val == v) {
            remove_head();
            return;
        }
        while (dum->next->val != v)
        {
            if (dum == nullptr) {
                cout << "out of bounds\n";
                return;
            }
            dum = dum->next;
        }
        Node<T>* d2 = dum->next->next;
        delete dum->next;
        dum->next = d2;
        size--;
    }

    void remove_at_index(int i)
    {
        Node<T>* dum = start;
        for (int j = 0; j < (i - 1); j++)
        {
            dum = dum->next;
        }
        Node<T>* d2 = dum->next->next;
        delete dum->next;
        size--;
        dum->next = d2;
    }

    void free()
    {
        size = 0;
        Node<T>* dum;
        do
        {
            dum = start;
            cout << "deleted " << start->val << endl;
            start = start->next;
            delete dum;
        } while (start != nullptr);
        // delete dum;
    }

    void show()
    {
        Node<T>* dummy = start;
        while (dummy != nullptr)
        {
            cout << dummy->val << endl;
            dummy = dummy->next;
        }

    }

    int get_size(){return size;}

    ~LinkedList()
    {
        Node<T>* dum;
        while (start != nullptr)
        {
            dum = start;
            cout << "deleted " << start->val << endl;
            start = start->next;
            delete dum;
        }
    }
};

template <class T>
class circular_linkedlist
{
private:
    Node<T>* head;
public:
    
    circular_linkedlist() { head = new Node<T>; }
    
    circular_linkedlist(T v)
    {
        head = new Node<T>;
        head->next = head;
        head->val = v;
        // cout<<":)";
    }

    void push(T v)
    {
        if(head == nullptr){
            head= new Node<T>;
            head->val = v;
            head->next = head;
            return;
        }
        Node<T>* n = new Node<T>;
        n->val = v;
        Node<T>* hd = head;
        while (hd->next != head)
        {
            hd = hd->next;   
        }
        n->next = head;
        hd->next = n;
    }

    void show(){
        Node<T> *dm = head;
        do
        {
            cout<<dm->val<<endl;
            dm = dm->next;
        } while (dm != head);
        
    }

    void pop()
    {
        if(head == nullptr){return;}
        if(head->next == head){
            head = nullptr;
        }
        Node<T> * d = head;
        while(d->next->next != head){
            d= d->next;
        }
        delete d->next;
        d->next = head;
    }
};

int main()
{

    circular_linkedlist<int> cll(10);
    cll.push(11);
    cll.push(12);
    cll.push(13);
    cll.show();
    cll.pop();
    cll.show();
    return 0;
}