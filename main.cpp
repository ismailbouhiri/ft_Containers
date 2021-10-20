# include <iostream>
#include "vector.hpp"
#include <vector>
int main ()
{
  std::vector<int> therevector;
  ft::vector<int> myvector;
  int myint;
  ft::vector<int>::iterator ft_it;
  std::vector<int>::iterator std_it;

  therevector.push_back(1);
  therevector.push_back(2);
  therevector.push_back(3);
  // std::cout << therevector.back() << std::endl;
  std_it = therevector.begin();

  myvector.push_back(1);
  myvector.push_back(2);
  myvector.push_back(3);
  // std::cout << myvector.back() << std::endl;  
  ft_it = myvector.begin();
  // int i = 0;
  // do {
  //   std::cin >> myint;
  //   myvector.push_back (myint);
  //   std::cout << "myvecteur[" << i << "] = " << myvector[i] << std::endl;
  //   i++;
  // } while (myint);
  // for (int i = 0; i < myvector.size() ; i++)
  //   std::cout << "myvecteur[" << i << "] = " << myvector[i] << std::endl;
  ++std_it;
  ++ft_it;

  std::cout << " Myiterator : " << *ft_it << " .\n";
  std::cout << " thereiterator : " << *std_it << " .\n";
  // std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
  // std::cout << "myvector capacity " << int(myvector.capacity()) << " numbers.\n";
  // std::cout << " therevector stores " << int(therevector.size()) << " numbers.\n";
  // std::cout << "therevector  capacity " << int(therevector.capacity()) << " numbers.\n";

  return 0;
}