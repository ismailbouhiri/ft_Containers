# include <iostream>
#include "vector.hpp"
#include <vector>
int main ()
{
  std::vector<int> therevector;
  ft::vector<int> myvector;
  int myint;
  // ft::vector<int>::iterator it;
  // std::cout << "Please enter some integers (enter 0 to end):\n";
  // therevector.push_back(15);
  // std::cout << therevector.at(15) << std::endl;
  
  myvector.push_back(15);
  std::cout << myvector.at(15) << std::endl;
  
  // int i = 0;
  // do {
  //   std::cin >> myint;
  //   myvector.push_back (myint);
  //   std::cout << "myvecteur[" << i << "] = " << myvector[i] << std::endl;
  //   i++;
  // } while (myint);
  // for (int i = 0; i < myvector.size() ; i++)
  //   std::cout << "myvecteur[" << i << "] = " << myvector[i] << std::endl;
  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
  std::cout << "myvector capacity " << int(myvector.capacity()) << " numbers.\n";

  return 0;
}