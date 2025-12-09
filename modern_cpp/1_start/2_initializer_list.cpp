//
// Created by fiz on 2025/12/8.
//
#include <list>
#include <iostream>
class Animal
{
public:
    Animal() {std::cout << "Animal" << std::endl;}
    virtual void show()
    {
        std::cout << "animal::show" << std::endl;
    }
};

class cat : public Animal
{
public:
    cat()
    {
        std::cout << "cat inital" << std::endl;
    }
    void show()
    {
        std::cout << "cat::show" << std::endl;
    }
};
void test(Animal &a)
{
    a.show();
}
template<typename T>
auto print_type_info(const T &t)
{
    if constexpr (std::is_integral<T>::value)
    {
        return t+1;
    }
    else
    {
        return t+0.001;
    }
}
int main()
{
    using namespace std;
    cat* c = new cat();

    Animal* a = static_cast<cat*>(c);
    a->show();

    initializer_list<int> l1{1,2,3,4};
    // cat cat;
    // test(cat);
    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;
}