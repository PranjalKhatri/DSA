#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    T *arr;

public:
    int total_size;
    int used_size;

    Array();
    Array(int tsize, int usize) { create(tsize, usize); }

    void create(int tsize, int usize)
    {
        total_size = tsize;
        used_size = usize;
        arr = new T[tsize];
    }

    int size()
    {
        return this->used_size;
    }

    void show()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << arr[i] << endl;
        }
    }

    void destroy()
    {
        delete[] arr;
    }

    ~Array()
    {
        delete[] arr;
    }

    T &operator[](int i)
    {
        return (arr[i]);
    }

    void insert_at(T ele, int pos)
    {
        if (used_size > (total_size - 1))
        {
            cout << "Array out of bounds\n";
            return;
        }
        used_size++;
        T temp = arr[pos];
        arr[pos] = ele;
        for (int i = (pos + 1); i < used_size; i++)
        {
            arr[i] = temp;
            temp = arr[i + 1];
        }
        arr[used_size] = temp;
        // used_size++;
    }

    void remove_at(int pos)
    {
        if (pos < 0)
        {
            return;
        }
        T temp;
        for (int i = pos; i < (used_size - 1); i++)
        {
            arr[i] = arr[i + 1];
        }
        used_size--;
    }

    int linear_search(T ele)
    {
        for (int i = 0; i < used_size; i++)
        {
            if (arr[i] == ele)
            {
                return i;
            }
        }
        return -1;
    }

    int binary_search(T ele, int s, int e)
    {
        // cout<<"iter\n";
        if (s > e)
        {
            return -1;
        }
        int mid = int((s + e) / 2);
        if (arr[mid] == ele)
        {
            // cout<<"duh";
            return mid;
        }
        else if (arr[mid] > ele)
        {
            return binary_search(ele, s, mid - 1);
        }
        else
        {
            return binary_search(ele, mid + 1, e);
        }
    }
};

int main()
{
    Array<int> m(10, 4);
    m[0] = 1;
    m[1] = 2;
    m[2] = 3;
    m[3] = 4;
    m.show();
    cout<<m.binary_search(2, 0, 4);

    return 0;
}