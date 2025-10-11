# include <iostream>

using namespace std;

int *func()
{
    static int a=10;
    return &a;

}



int main() {
    int *p = func();
    cout << "The value of a is: " << *p << endl; // This will lead to undefined behavior

    return 0;
}