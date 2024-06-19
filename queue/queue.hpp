#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__
#include <iostream>

namespace pop
{
    template<class T>
    class queue
    {
    private:
        struct node {
            T val;
            node* next = nullptr;
        };
        int size = 0;
        node* first;
        node* last;
    public:
        queue();
        bool enqueue(T val);
        void dequeue(T val);
        T peek(int index);
        bool is_empty();
        bool is_full();
        void show();
        ~queue();
    };

    template<class T>
    queue<T>::queue()
    {
        first = nullptr;
        last = first;
    }

    template<class T>
    bool queue<T>::enqueue(T val)
    {
        if (first == NULL) {
            first = new node;
            if (first == nullptr) {
                return false;
            }
            first->val = val;
            last = first;
        }
        else {
            node* temp = new node;
            if (temp == NULL) {
                return false;
            }
            temp->val = val;
            last->next = temp;
            last = temp;
        }
        return true;
    }

    template<class T>
    void queue<T>::dequeue(T val)
    {
        node* temp = first->next;
        delete first;
        first = temp;
    }

    template<class T>
    T queue<T>::peek(int index)
    {
        node* temp = first;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
            if (temp == nullptr) {
                std::cerr << "index out of bounds!" << std::endl;
                return T(NULL);
            }
        }
        return temp->val;
    }

    template<class T>
    bool queue<T>::is_empty()
    {
        return first == last;
    }

    template<class T>
    bool queue<T>::is_full()
    {
        node* temp = new node;
        if (temp == nullptr) {
            delete temp;
            return false;
        }
        delete temp;
        return true;
    }

    template<class T>
    void queue<T>::show()
    {
        node * temp = first;
        while(temp != nullptr)
        {
            std::cout<<temp->val<<std::endl;
            temp = temp->next;
        }
    }

    template<class T>
    queue<T>::~queue()
    {
        while (first != nullptr)
        {
            node * temp = first->next;
            delete first;
            first = temp;
        } 
    }

} // namespace pop

#endif