#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>

namespace pop
{
    template <class T>
    class Stack_ar
    {
    private:
        int size;
        int top;
        T* arr;

    public:
        //@param ms max size
        Stack_ar(int ms)
        {
            size = ms;
            top = -1;
            arr = new T[size];
        }
        void pop()
        {
            if (top <= 0)
            {
                std::cout << "Stack underflow\n";
                return;
            }

            top--;
        }
        void push(T v)
        {
            // std::cout << size - 1 << std::endl;
            if (top >= (size - 1))
            {
                std::cout << "Stack Overflow\n";
                return;
            }
            // std::cout<<"added "<<v<<std::endl;
            arr[++top] = v;
        }
        T peek(int index)
        {
            if (index >= 0 && index <= top)
                return arr[index];
            std::cout << "Index out of bounds\n";
            return;
        }
        bool is_empty()
        {
            return (top != size);
        }
        bool is_full()
        {
            return (top == size);
        }
        void show()
        {
            for (int i = 0; i <= top; i++)
            {
                std::cout << arr[i] << std::endl;
            }
        }
    };

    template <class T>
    class Stack {
    private:
        int height = 0;
        struct node {
            T val;
            node* next = nullptr;
        }*top;
    public:
        Stack() {
            top = nullptr;
        }
        T pop() {
            if (is_empty()) {
                std::cout << "Stack underflow\n";
                return T(0);
            }
            T v = top->val;
            height--;
            if (top->next == nullptr) {
                top = nullptr;
                return v;
            }
            node* dum = top;
            top = top->next;
            delete dum;
            return v;
        }
        void push(T v) {
            if(is_full()){
                std::cout<<"Stack overflow \n";
            }
            height++;
            if (top == nullptr) {
                top = new node;
                top->val = v;
                return;
            }
            node* dum = new node;
            dum->val = v;
            dum->next = top;
            top = dum;
        }
        T peek(int index){
            node * dum = top; 
            while (index--)
            {
                dum = dum->next;
            }
            if(dum == nullptr){
                std::cout<<"Out of bounds\n";
                return 0;
            }
            return dum->val;
        }
        void show() {
            node* dum = top;
            while (dum != nullptr)
            {
                std::cout << dum->val << std::endl;
                dum = dum->next;
            }

        }
        bool is_empty() {
            return top == nullptr ? 1:0;
        }
        bool is_full() {
            node* a = new node;
            if (a == nullptr) {
                delete a;
                return true;
            }
            delete a;
            return false;
        }
        T operator[](int i){
            return peek(i);
        }
        int get_height(){
            return this->height;
        }
    };

} // namespace pop
#endif