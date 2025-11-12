#include <iostream>
using namespace std;

template <typename T>
void Mswap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void sort(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int max = i;
        for(int j=i+1;j<len;j++)
        {
            if (arr[max] < arr[j])
            {
                max=j;
            }
        }
        if(max != i)
        {
            //进行交换
            Mswap<T>(arr[max],arr[i]);
        }
    }
}


int main()
{
    char arr[] = "fsvbaeta";
    int len = sizeof(arr)/sizeof(arr[0]);
    sort<char>(arr,len);
    for(auto i:arr)
    {
        cout<<i<<endl;
    }
    return 0;
}
