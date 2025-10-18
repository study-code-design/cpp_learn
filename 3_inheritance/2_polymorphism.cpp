#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout <<"animal 构造" << endl;
    }
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat :public Animal
{
public:
    Cat()
    {
        cout <<"cat 构造" << endl;
    }

    void speak()
    {
        cout << "Cat在说话" << endl;
    }
    void test()
    {

    }

};

//执行说话的函数
//地址早绑定，在编译阶段就确定地址
// 如果想要猫说话，就得让这个函数地址不能提前绑定
void dospeak(Animal &animal)
{
    animal.speak();
}


int main()
{
    Cat cat1;
    dospeak(cat1);
}