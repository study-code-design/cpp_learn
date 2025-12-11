#include <iostream>
#include <vector>
template <typename T,typename U>
class MagicType
{
    public:
        T dark;
        U magic;
};
// template<typename T>
typedef MagicType<int,std::string> FakeDarkMagic;
int main()
{
    FakeDarkMagic magic;
    magic.dark = 21;
    std::cout << magic.dark << std::endl;
}