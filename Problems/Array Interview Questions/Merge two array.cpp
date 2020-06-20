#include<iostream>
using namespace std;

int main()
{
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,4,6,8,10};
    int a1=(sizeof(arr1)/sizeof(*arr1));
    int a2=(sizeof(arr2)/sizeof(*arr2));
    int len = a1+a2;
    int arr3[len];
    int i=0;

    

    for(int j=0;j<len;j++)
    {
        cout<<arr3[j]<<" ";
    }

}