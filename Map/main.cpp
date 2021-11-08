#include <utility>      // std::pair
#include <iostream>     // std::cout
#include "map.hpp"
# include <map>
int main ()
{
  ft::map<size_t,int> foo;

  for (size_t i = 0; i < 19; i++)
    foo.insert(ft::make_pair(i, i));

  ft::map<size_t, int>::const_iterator beg = foo.begin();;
  // ft::map<size_t, int>::const_iterator end = foo.end();

  // beg++;
  // std::cout << " key = " << beg->first << "   |   value = " << beg->second << std::endl;
  // beg--;
  // std::cout << " key = " << beg->first << "   |   value = " << beg->second << std::endl;
  // beg = foo.begin();
  // end = foo.end();
  // while(--end != beg)
  std::cout << " key = " << beg->first << "   |   value = " << beg->second << std::endl;
  // for (size_t i = 0; i < 1e6; i++)
  // {
  //     foo.remove(i);
  // }
  // foo.print_h();
  // std::cout << foo.size() << std::endl;

  return 0;
}
