#include <utility>      // std::pair
#include <iostream>     // std::cout
#include "map.hpp"
# include <map>
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};
int main ()
{

  std::map<char,int> mymap;
  char c;
  size_t ret;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if ((ret = mymap.count(c))>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
    std::cout << "c = [ " << c << " ] ret  = " << ret  << std::endl;
  }

  // ft::map<char,int> mymap;

  // ft::map<char,int>::key_compare mycomp = mymap.key_comp();

  // mymap['a']=100;
  // mymap['b']=200;
  // mymap['c']=300;

  // std::cout << "mymap contains:\n";

  // char highest = mymap.rbegin()->first;     // key value of last element

  // ft::map<char,int>::iterator it = mymap.begin();
  // do {
  //   std::cout << it->first << " => " << it->second << '\n';
  // } while ( mycomp((*it++).first, highest) );

  // std::cout << '\n';


  //////////////////////--/-/-/-/-/-/-/-/-/////

  // ft::map<char,int> mymap;

  // mymap['x']=1001;
  // mymap['y']=2002;
  // mymap['z']=3003;

  // std::cout << "mymap contains:\n";

  // ft::pair<char,int> highest = *mymap.rbegin();          // last element

  // ft::map<char,int>::iterator it = mymap.begin();
  // do {
  //   std::cout << it->first << " => " << it->second << '\n';
  // } while ( mymap.value_comp()(*it++, highest) );

  //  ft::map<char,int> mymap;

  // mymap['x']=100;
  // mymap['y']=200;
  // mymap['z']=300;

  // std::cout << "mymap contains:\n";
  // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  // mymap.clear();
  // mymap['a']=1101;
  // mymap['b']=2202;

  // std::cout << "mymap contains:\n";
  // for (ft::map<char,int>::iterator it=mymap.begin(); it!= mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  // ft::map<char,int> foo,bar;

  // foo['x']=100;
  // foo['y']=200;

  // bar['a']=11;
  // bar['b']=22;
  // bar['c']=33;

  // foo.swap(bar);

  // std::cout << "foo contains:\n";
  // for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  // std::cout << "bar contains:\n";
  // for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';
//   ft::map<int,int> mymap;
//   ft::map<int,int>::iterator it;

//   // insert some values:
//   mymap[1] = 10;
//   mymap[2] = 20;
//   mymap[3] = 30;
//   mymap[4] = 40;
//   mymap[5] = 50;
//   mymap[6] = 60;

//   it=mymap.find(2);
//   mymap.erase (it);                   // erasing by iterator

//   mymap.erase (3);                  // erasing by key

//   it= mymap.find (5);
//   mymap.erase ( it, mymap.end() );    // erasing by range

//   // show content:
//  for (it=mymap.begin(); it != mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
  // ft::map<char,int> mymap;

  // // first insert function version (single parameter):
  // mymap.insert ( ft::pair<char,int>('a',100) );
  // mymap.insert ( ft::pair<char,int>('z',200) );

  // ft::pair<ft::map<char,int>::iterator,bool> ret;
  // ret = mymap.insert ( ft::pair<char,int>('z',500) );
  // if (ret.second==false)
  // {
  //   std::cout << "element 'z' already existed";
  //   std::cout << " with a value of " << ret.first->second << '\n';
  // }

  // // second insert function version (with hint position):
  // ft::map<char,int>::iterator it = mymap.begin();
  // mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
  // mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

  // // third insert function version (range insertion):
  // ft::map<char,int> anothermap;
  // anothermap.insert(mymap.begin(),mymap.find('c'));

  // // // showing contents:
  // std::cout << "mymap contains:\n";
  // for (it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  // std::cout << "anothermap contains:\n";
  // for (it=anothermap.begin(); it!=anothermap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';
  // ft::map<char,std::string> mymap;

  // mymap['a']="an element";
  // mymap['b']="another element";
  // mymap['c']=mymap['b'];

  // std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  // std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  // std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  // std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  // std::cout << "mymap now contains " << mymap.size() << " elements.\n";

  // ft::map<char,int> mymap;
  // mymap.insert(ft::make_pair('a', 10));
  // mymap.insert(ft::make_pair('b', 30));
  // mymap.insert(ft::make_pair('c', 50));
  // mymap.insert(ft::make_pair('d', 70));

  // std::cout << "mymap.size() is " << mymap.max_size() << '\n';

  // ft::map<char,int> mymap;
  // mymap.insert(ft::make_pair('b', 200));
  // mymap.insert(ft::make_pair('a', 100));
  // mymap.insert(ft::make_pair('c', 300));

  // // show content:
  // ft::map<char,int>::reverse_iterator rit;
  // for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
  //   std::cout << rit->first << " => " << rit->second << '\n';

  // std::map<char,int> first;
  // std::map<char,int> second;

  // first.insert(std::make_pair('a', 10));
  // first.insert(std::make_pair('b', 30));
  // first.insert(std::make_pair('c', 50));
  // first.insert(std::make_pair('d', 70));

  // second = first;                // second now contains 3 ints
  // first = std::map<char,int>();  // and first is now empty

  // std::cout << "Size of first: " << first.size() << '\n';
  // std::cout << "Size of second: " << second.size() << '\n';
  
  // std::cout << "------------------ " << std::endl;
  
  // ft::map<char,int> ft_first;
  // ft::map<char,int> ft_second;

  // ft_first.insert(ft::make_pair('a', 10));
  // ft_first.insert(ft::make_pair('b', 30));
  // ft_first.insert(ft::make_pair('c', 50));
  // ft_first.insert(ft::make_pair('d', 70));

  // ft_second = ft_first;                // ft_second now contains 3 ints
  // ft_first = ft::map<char,int>();  // and ft_first is now empty

  // std::cout << "Size of ft_first: " << ft_first.size() << '\n';
  // std::cout << "Size of ft_second: " << ft_second.size() << '\n';
  // ft::map<char,int> first;


  // ft::map<char,int> second (first.begin(),first.end());

  // std::cout << "first -------------------- " << std::endl;
  // first.print_h();
  // std::cout << "second -------------------- " << std::endl;
  // second.print_h();

  // ft::map<char,int> third (second);
  // std::cout << "third -------------------- " << std::endl;
  // third.print_h();
  // ft::map<char,int,classcomp> fourth;                 // class as Compare

  // bool(*fn_pt)(char,char) = fncomp;
  // ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
  // std::cout << "third -------------------- " << std::endl;
  // fifth.print_h();
  // ft::map<size_t,int> foo;

  // for (size_t i = 0; i < 19; i++)
  //   foo.insert(ft::make_pair(i, i));

  // ft::map<size_t, int>::const_iterator beg(foo.begin());
  // ft::map<size_t, int>::const_iterator end = foo.end();

  // beg++;
  // std::cout << " key = " << beg->first << "   |   value = " << beg->second << std::endl;
  // beg--;
  // std::cout << " key = " << beg->first << "   |   value = " << beg->second << std::endl;
  // beg = foo.begin();
  // end = foo.end();
  // while(--end != beg)
  // std::cout << " key = " << beg->first << "   |   value = " << beg->second << std::endl;
  // for (size_t i = 0; i < 1e6; i++)
  // {
  //     foo.remove(i);
  // }
  // foo.print_h();
  // std::cout << foo.size() << std::endl;

  system("leaks a.out");
  return 0;
}
