# include <iostream>
#include "vector.hpp"
#include <vector>
int main ()
{
  // std::vector<int> therevector;
  // ft::vector<int> myvector;
  // ft::vector<int> myvector1;
  // int myint;

  // ft::vector<int>::reverse_iterator first_ft_it;
  // ft::vector<int>::reverse_iterator end_ft_it;
  // std::vector<int>::reverse_iterator first_std_it;
  // std::vector<int>::reverse_iterator end_std_it;

  // therevector.push_back(1);
  // therevector.push_back(2);
  // therevector.push_back(3);
  // // std::cout << therevector.back() << std::endl;
  // first_std_it = therevector.rbegin();
  // end_std_it = therevector.rend();

  // myvector.push_back(1);
  // myvector.push_back(2);
  // myvector.push_back(3);
  // // std::cout << myvector.back() << std::endl;  
  // first_ft_it = myvector.rbegin();
  // end_ft_it = myvector.rend();
  // int i = 0;
  // do {
  //   std::cin >> myint;
  //   myvector.push_back (myint);
  //   std::cout << "myvecteur[" << i << "] = " << myvector[i] << std::endl;
  //   i++;
  // } while (myint);
  // for (int i = 0; i < myvector.size() ; i++)
  //   std::cout << "myvecteur[" << i << "] = " << myvector[i] << std::endl;
  // std::cout << *first_ft_it << " = Myiterator!!" << std::endl;
  // std::cout << *(end_std_it - 1) << " = Myiterator!!" << std::endl;
  // if (myvector != myvector1)
  //   std::cout << "diff true" << std::endl;
  // else 
  //   std::cout << "diff false" << std::endl;

  // std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
  // std::cout << "myvector capacity " << int(myvector.capacity()) << " numbers.\n";
  // std::cout << " therevector stores " << int(therevector.size()) << " numbers.\n";
  // std::cout << "therevector  capacity " << int(therevector.capacity()) << " numbers.\n";
  // std::vector<int> therevector;
  // ft::vector<int> myvector;
  // // set some initial content:
  // for (int i=1;i<6;i++) therevector.push_back(i);
  // for (int i=1;i<6;i++) myvector.push_back(i);
  // // myvector.resize(5);
  // // therevector.resize(5);
  // // therevector.resize(9,100);
  // // myvector.resize(9,100);
  // therevector.reserve(2);
  // myvector.reserve(2);
  // // myvector.reserve(1);
  // std::cout << "Capacity : " << therevector.capacity() << std::endl;
  // std::cout << "Size : " << therevector.size() << std::endl;
  // std::cout << "therevector contains:";
  // for (int i=0; i < therevector.size(); i++)
  //   std::cout << ' ' << therevector[i];
  // std::cout << std::endl;
  // std::cout << "Capacity : " << myvector.capacity() << std::endl;
  // std::cout << "Size : " << myvector.size() << std::endl;
  // std::cout << "myvector contains:";
  // for (int i=0; i < myvector.size(); i++)
  //   std::cout << ' ' << myvector[i];
  // std::cout << std::endl;

  // // // "it" no longer valid, get a new one:
  // it = myvector.begin();

  // std::vector<int> anothervector (9,400);
  // myvector.insert (it+2,anothervector.begin(),anothervector.end());
  
  // int myarray [] = { 501,502,503 };
  // myvector.insert (myvector.begin(), myarray, myarray+3);

  ft::vector<int> myvector(2,100);
  std::vector<int> therevector(2,100);
  ft::vector<int>::const_iterator ft_it = myvector.begin();
  std::vector<int>::const_iterator std_it = therevector.begin();

  // ft::vector<int> myvector1(2,200);
  // std::vector<int> therevector1(2,200);

  // ft::vector<int> myvector2(2,300);
  // std::vector<int> therevector2(2,300);

  
  // myvector.insert ( ft_it  , myvector1.begin(),myvector1.end()); 
  // therevector.insert ( std_it  ,therevector1.begin(),therevector1.end() );

  // ft_it = myvector.begin();
  // std_it = therevector.begin();
  // therevector.insert (std_it,therevector2.begin(),therevector2.end());
  // myvector.insert (ft_it,myvector2.begin(),myvector2.end());
    

  // std_it = therevector.erase(therevector.begin() + 2, therevector.begin() + 4);
  // std::cout << " std_it = " << *std_it << std::endl;
  // ft_it = myvector.erase(myvector.begin() + 2, myvector.begin() + 4);
  // std::cout << " ft_it = " << *ft_it << std::endl;



  std::cout << "------------------------------" << std::endl;
  std::cout << "    ::  dyalhoum ::   " << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "Capacity : " << therevector.capacity() << std::endl;
  std::cout << "Size : " << therevector.size() << std::endl;
  std::cout << "therevector contains:";
  for (std_it = therevector.begin(); std_it < therevector.end(); std_it++)
    std::cout << ' ' << *std_it;
  std::cout << '\n';
  std::cout << "------------------------------" << std::endl;
  std::cout << "       :: dyali ::    " << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "Capacity : " << myvector.capacity() << std::endl;
  std::cout << "Size : " << myvector.size() << std::endl;
  std::cout << "myvector contains:";
  for (ft_it = myvector.begin(); ft_it < myvector.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
  // std::vector<int> foo (5,100);   // three ints with a value of 100
  // std::vector<int> bar (2,100);   // two ints with a value of 200
  // ft::vector<int> myfoo (5,100);   // three ints with a value of 100
  // ft::vector<int> mybar (2,100);   // two ints with a value of 200
  // if (foo==bar) std::cout << "foo and bar are equal\n";
  // if (foo!=bar) std::cout << "foo and bar are not equal\n";
  // if (foo< bar) std::cout << "foo is less than bar\n";
  // if (foo> bar) std::cout << "foo is greater than bar\n";
  // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  // std::cout << "------------------------------" << std::endl;
  // std::cout << "       :: dyali ::    " << std::endl;
  // std::cout << "------------------------------" << std::endl;
  // if (myfoo==mybar) std::cout << "myfoo and mybar are equal\n";
  // if (myfoo!=mybar) std::cout << "myfoo and mybar are not equal\n";
  // if (myfoo< mybar) std::cout << "myfoo is less than mybar\n";
  // if (myfoo> mybar) std::cout << "myfoo is greater than mybar\n";
  // if (myfoo<=mybar) std::cout << "myfoo is less than or equal to mybar\n";
  // if (myfoo>=mybar) std::cout << "myfoo is greater than or equal to bar\n";


  return 0;
}