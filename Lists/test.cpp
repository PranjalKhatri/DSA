#include <iostream>
// #include < 
using namespace std;
 
int main(int argc, char const *argv[])
{
    int * ptr = new int(10);
    int * po = ptr;
    delete po;

return 0;
}