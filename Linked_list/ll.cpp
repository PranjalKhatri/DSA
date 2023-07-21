#include <iostream>

using namespace std;

template <class T>

struct Node
{
    T val;
    Node *next = nullptr;
};

template <class T>
class LinkedList
{
private:
    Node<T> *start;

public:
    LinkedList()
    {
        start = nullptr;
    }

    LinkedList(T v)
    {
        start = new Node<T>;
        start->next = nullptr;
        start->val = v;
    }

    void push(T v)
    {
        Node<T> *n = new Node<T>;
        n->val = v;
        Node<T> *dum = start;
        while (dum->next != nullptr)
        {
            dum = dum->next;
        }
        dum->next = n;
        // while(star)
    }

    void Insert_at_start(T v)
    {
        Node<T> *n = new Node<T>;
        n->next = start->next;
        n->val = start->val;
        start->next = n;
        start->val = v;
        // start = start->next;
    }

    void Insert_at_Index(T v, int i)
    {
        Node<T> *dum = start;
        for (int j = 0; j < (i-1); j++)
        {
            if (dum->next == nullptr)
            {
                cout << "out of bounds\n";
                return;
            }
            dum = dum->next;
        }
        Node<T> *n = new Node<T>;
        n->val = v;
        n->next = dum->next;
        dum->next = n;
    }

    void Insert_at_end(T v)
    {
        Node<T> * dum = start;
        while (dum->next != nullptr)
        {
            dum = dum->next;
        }
        Node<T>* n = new Node<T>;
        n->val = v;
        dum->next = n;
    }

    void free()
    {
        Node<T> *dum;
        do.
        {
            dum = start;
            cout << "deleted " << start->val << endl;
            start = start->next;
            delete dum;.
        } while (start != nullptr);
        // delete dum;
    }

    void show()
    {
        Node<T> *dummy = start;
        while (dummy != nullptr)
        {
            cout<<dummy->val<<endl;
            dummy = dummy->next;
        }
        
    }

    ~LinkedList()
    {
        Node<T> *dum;
        while (start != nullptr)
        {
            dum = start;
            cout << "deleted " << start->val << endl;
            start = start->next;
            delete dum;
        }
    }
};

int main()
{

    LinkedList<int> ll(10);
    ll.push(11);
    ll.push(12);
    ll.push(13);
    ll.Insert_at_start(9);
    ll.Insert_at_Index(14, 1);
    ll.Insert_at_end(150);
    ll.show();
    ll.free();
    cout << "end\n";

    return 0;
}