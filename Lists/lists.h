#ifndef _P_LISTS_H_
#define _P_LISTS_H_
#include <iostream>

namespace pop
{
    template <class T>
    struct Node
    {
        T val;
        Node *next = nullptr;
    };

    template <class T>
    struct Dll_node
    {
        Dll_node<T> *prev = nullptr;
        T val;
        Dll_node<T> *next = nullptr;
    };

    template <class T>
    class LinkedList
    {
    private:
        Node<T> *start;
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

        Node<T> *gethead(void)
        {
            return start;
        }

        void push(T v)
        {
            Node<T> *n = new Node<T>;
            n->val = v;
            Node<T> *dum = start;
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
            Node<T> *n = new Node<T>;
            n->next = start->next;
            n->val = start->val;
            start->next = n;
            start->val = v;
            size++;
            // start = start->next;
        }

        void Insert_at_Index(T v, int i)
        {
            Node<T> *dum = start;
            for (int j = 0; j < (i - 1); j++)
            {
                if (dum->next == nullptr)
                {
                    std::cout << "out of bounds\n";
                    return;
                }
                dum = dum->next;
            }
            Node<T> *n = new Node<T>;
            n->val = v;
            n->next = dum->next;
            dum->next = n;
            size++;
        }

        void Insert_at_end(T v)
        {
            push(v);
        }

        void remove_head()
        {
            Node<T> *dum = start;
            start = start->next;
            delete dum;
            size--;
        }

        void pop(void)
        {
            Node<T> *dum = start;
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
            Node<T> *dum = start;
            if (start->val == v)
            {
                remove_head();
                return;
            }
            while (dum->next->val != v)
            {
                if (dum == nullptr)
                {
                    std::cout << "out of bounds\n";
                    return;
                }
                dum = dum->next;
            }
            Node<T> *d2 = dum->next->next;
            delete dum->next;
            dum->next = d2;
            size--;
        }

        void remove_at_index(int i)
        {
            Node<T> *dum = start;
            for (int j = 0; j < (i - 1); j++)
            {
                dum = dum->next;
            }
            Node<T> *d2 = dum->next->next;
            delete dum->next;
            size--;
            dum->next = d2;
        }

        void free()
        {
            size = 0;
            Node<T> *dum;
            do
            {
                dum = start;
                std::cout << "deleted " << start->val << std::endl;
                start = start->next;
                delete dum;
            } while (start != nullptr);
            // delete dum;
        }

        void show()
        {
            Node<T> *dummy = start;
            while (dummy != nullptr)
            {
                std::cout << dummy->val << std::endl;
                dummy = dummy->next;
            }
        }

        int get_size() { return size; }

        ~LinkedList()
        {
            Node<T> *dum;
            while (start != nullptr)
            {
                dum = start;
                std::cout << "deleted " << start->val << std::endl;
                start = start->next;
                delete dum;
            }
        }
    };

    template <class T>
    class circular_linkedlist
    {
    private:
        Node<T> *head;

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
            if (head == nullptr)
            {
                head = new Node<T>;
                head->val = v;
                head->next = head;
                return;
            }
            Node<T> *n = new Node<T>;
            n->val = v;
            Node<T> *hd = head;
            while (hd->next != head)
            {
                hd = hd->next;
            }
            n->next = head;
            hd->next = n;
        }

        void Insert_at_head(T v)
        {
            Node<T> *n = new Node<T>;
            n->val = v;
            n->next = head;
            Node<T> *dum = head;
            while (dum->next != head)
            {
                dum = dum->next;
            }
            dum->next = n;
            head = n;
        }

        void show()
        {
            Node<T> *dm = head;
            do
            {
                std::cout << dm->val << std::endl;
                dm = dm->next;
            } while (dm != head);
        }

        void pop()
        {
            if (head == nullptr)
            {
                return;
            }
            if (head->next == head)
            {
                // std::cout<<"popped head \n";
                head = nullptr;
            }
            Node<T> *d = head;
            while (d->next->next != head)
            {
                d = d->next;
            }
            // std::cout<<"popped "<<d->next->val<<std::endl;
            delete d->next;
            d->next = head;
        }

        void remove_head()
        {
            if (head->next == head)
            {
                head = nullptr;
            }
            Node<T> *dum = head;
            Node<T> *a = head;
            while (dum->next != head)
            {
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
            while (head != nullptr)
            {

                pop();
            }
        }

        ~circular_linkedlist()
        {
            free();
        }
    };

    template <class T>
    class Doubly_linkedlist
    {
    private:
        Dll_node<T> *head;

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
            if (head == nullptr)
            {
                head = new Dll_node<T>;
                head->val = v;
                return;
            }

            Dll_node<T> *n = new Dll_node<T>;
            n->val = v;
            Dll_node<T> *dum = head;
            while (dum->next != nullptr)
            {
                dum = dum->next;
            }
            dum->next = n;
            n->prev = dum;
        }
        void Insert_at_head(T v)
        {
            Dll_node<T> *n = new Dll_node<T>;
            n->val = v;
            head->prev = n;
            n->next = head;
            head = n;
        }
        void pop()
        {
            if (head == nullptr || head->next == nullptr)
            {
                head = nullptr;
                return;
            }
            Dll_node<T> *dum = new Dll_node<T>;
            while (dum->next->next != nullptr)
            {
                dum = dum->next;
            }
            delete dum->next;
            dum->next = nullptr;
        }
        void remove_head()
        {
            Dll_node<T> *dum = head;
            head = head->next;
            head->prev = nullptr;
            delete dum;
        }
        void show()
        {
            Dll_node<T> *dum = head;
            while (dum != nullptr)
            {
                std::cout << dum->val << std::endl;
                dum = dum->next;
            }
        }
        void free()
        {
            Dll_node<T> *dum = head;
            while (head != nullptr)
            {
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