#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Person
{
public:
    Person(const string &name,const int &age)
    {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};
ostream &operator<<(ostream &count, const Person &p)
{
    cout << "name: " << p.name << " and " << "age: " << p.age << endl;
    return count;
}

int main()
{
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    cout <<"-------------" << endl;
    for_each(v.begin(),v.end(),[](const Person &p){cout << p << endl;});
    cout <<"-------------" << endl;
    v.clear();
    vector<Person *> v1;
    v1.push_back(&p1);
    v1.push_back(&p2);
    v1.push_back(&p3);
    v1.push_back(&p4);
    v1.push_back(&p5);
    for (vector<Person*>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << **it << endl;
    }
}
