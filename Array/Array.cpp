#include <iostream>

using namespace std;

template <class T>
class Array{
private:
    T *arr;
public:
    int total_size;
    int used_size;

    Array();
    Array(int tsize,int usize){create(tsize,usize);}

    void create(int tsize,int usize)
    {
        total_size = tsize;
        used_size = usize;
        arr = new T[tsize];
    }

    int size(){
        return this->used_size;
    }

    void show(){
        for (int i = 0; i < used_size; i++)
        {
            cout<<arr[i]<<endl;
        }
        
    }

    void destroy(){
        delete [] arr;
    }
    ~Array(){
        delete [] arr;
    }
    
    T &operator[](int i){
        return (arr[i]);
    }
};

int main()
{
    {
        Array<double> a(100,5);
    }
    Array<int> m(10,4);
    m[0] = 1;
    m[1] = 2;
    m[2] = 3;
    m[3] = 4;
    
    return 0;
}