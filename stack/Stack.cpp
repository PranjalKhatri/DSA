#include <iostream>

namespace pop
{
    template <class T>
    class Stack
    {
    private:
        int size;
        int top;
        T *arr;

    public:
        //@param ms max size
        Stack(int ms)
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
} // namespace pop

using namespace pop;
int main()
{

    return 0;
}