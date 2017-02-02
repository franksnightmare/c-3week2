#include <iostream>
template<unsigned long num>
struct Bin
{
    static unsigned const value =
        Bin<num/2>::value << 1 | num % 2;
};

template<>
struct Bin<0>
{
    static unsigned const value = 0;
};

int main()
{
    std::cout << Bin<5>::value  << '\n';
    std::cout << "New item\n";
    std::cout << Bin<27>::value << '\n';
}
