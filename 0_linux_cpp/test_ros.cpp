#include <iostream>
#include <cstddef>  // 包含 size_t 的定义

class MyClass {
public:
    // 构造函数使用初始化列表
    MyClass() : value1_(10), value2_(20.5), counter_(0) 
    {
        // 这里可以访问所有成员变量，无论定义顺序
        std::cout << "构造函数体内: value1_ = " << value1_ << std::endl;
        std::cout << "构造函数体内: value2_ = " << value2_ << std::endl;
        std::cout << "构造函数体内: counter_ = " << counter_ << std::endl;
    }

    void printValues() {
        // 成员函数也可以访问所有成员变量
        std::cout << "方法中: value1_ = " << value1_ << std::endl;
        std::cout << "方法中: value2_ = " << value2_ << std::endl;
        std::cout << "方法中: counter_ = " << counter_ << std::endl;
    }

private:
    // 成员变量定义顺序不影响使用
    int value1_;           // 整数类型
    double value2_;        // 浮点类型
    size_t counter_;       // 无符号整数类型，用于计数
};

int main() {
    MyClass obj;
    obj.printValues();
    return 0;
}