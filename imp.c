#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    int done = 0;




/*
{}
1st n-1
last n-1
*/

    while (done == 0)
    {
        done =1;
        for (int i = 0; i < 5; i++)
        {
            if(arr[i] < arr[i+1]){
                done = 0;
                swap(&arr[i],&arr[i+1]);
            }
        }
        for (int i = 5; i >=1; i--)
        {
            if(arr[i] > arr[i-1]){
                done = 0;
                swap(&arr[i],&arr[i-1]);
            }
        }
        // printf("%d",arr[3]);        
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",arr[i]);
    }
    
}