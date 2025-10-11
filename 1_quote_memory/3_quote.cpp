#include <iostream>
using namespace std;
void numSwap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void numSwapCursor(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void numSwapQuote(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}



int main()
{
    int a = 10;
    cout << &a << endl;
    int &b = a;
    b=20;
    int arr[2]={30,40};
    // numSwap(arr[0],arr[1]);
    // numSwapCursor(&arr[0],&arr[1]);
    numSwapQuote(arr[0],arr[1]);
    cout << b << " and " << a << endl;
    cout << &b << endl;
    cout << arr[0] << " and " << arr[1] << endl;
    return 0;
}


