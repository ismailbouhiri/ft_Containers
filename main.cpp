# include <iostream>
// #include "vector.hpp"
#include <vector>
int main(void)
{
    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);   // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << '\n';
    std::cout << "foo size : " << foo.size() << " foo capacity : " << foo.capacity() << std::endl;

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << '\n';
    std::cout << "bar size : " << bar.size() << " bar capacity : " << bar.capacity() << std::endl;

    return 0;
}