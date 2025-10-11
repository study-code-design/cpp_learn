#include <iostream>
using namespace std;

class Student
{
    public:
        string name;
        int stuID;
        void displayInfo()
        {
            cout << "Name: " << name << endl;
            cout << "Student ID: " << stuID << endl;
        }
};


int main()
{
    int a=1;int b=2;
    cout << (++a==b) << endl;

    Student stu = Student();
    stu.name = "Alice";
    stu.stuID = 12345;
    stu.displayInfo();
    return 0;
}