# include <iostream>
#include "vector.hpp"
int main(void)
{
    // constructors used in the same order as described above:
    ft::vector<int> first;                                // empty vector of ints
    ft::vector<int> second (4,100);                      // four ints with value 100

    second.push_back(5);
    // std::vector<int> third (second.begin(),second.end());  // iterating through second
    // std::vector<int> fourth (third);                       // a copy of third
    // double size = second.end() - second.begin();
    
    // std::cout << "iterator end :: " << second.begin() << std::endl;
    // std::cout << "iterator begin :: " << second.end() << std::endl;
    // // the iterator constructor can also be used to construct from arrays:
    // int myints[] = {16,2,77,29};
    // std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    // std::cout << "The contents of fifth are:";
    // for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
        
    // std::vector<int> test(4, 100);
    // std::cout << "capacity  ::  " << test.capacity() << std::endl;
    // std::cout << "size  ::  " << test.size() << std::endl;
    // std::cout << second.empty() << std::endl;

    return 0;
}