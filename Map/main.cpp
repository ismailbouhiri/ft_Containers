#include <utility>      // std::pair
#include <iostream>     // std::cout
#include "map.hpp"
int main ()
{
  ft::map<size_t,int> foo;

  for (size_t i = 0; i < 1e6; i++)
  {
    // std::cout << "i  = " << i << std::endl;
    foo.insert(ft::make_pair(i, 300));
  }
  std::cout << foo.size() << std::endl;
  for (size_t i = 0; i < 1e6; i++)
  {
      foo.remove(i);
  }
  foo.print_h();
  std::cout << foo.size() << std::endl;
  return 0;
}
