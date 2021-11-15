#include <utility>      // std::pair
#include <iostream>     // std::cout
#include "Map.hpp"
# include <map>
#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};
int main ()
{
   bool cond(false);
        // erasing all the elements in the map;
        // {
        //     time_t start, end, diff;
        //     /*------------------ std::maps ---------------------*/
        //     std::map<int, std::string> m1;
        //     ft::Map<int, std::string> ft_m1;
        //     for (size_t i = 0; i < 1e6; i++)
        //     {
        //         m1.insert(std::make_pair(i, "string2"));
        //         ft_m1.insert(ft::make_pair(i, "string2"));
        //     }

        //     // start = get_time();
        //     m1.erase(m1.begin(), m1.end());
        //     // end = get_time();
        //     diff = end - start;
        //     // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        //     /*-----------------------------------------------------*/
        //     /*------------------ ft::Maps ---------------------*/
        //     ualarm(diff * 1e3, 0);
        //     ft_m1.erase(ft_m1.begin(), ft_m1.end());    
        //     ualarm(0, 0);
        //     /*----------------------------------------------------*/
        // }
        // std::map<char, int> m;
        // ft::Map<char, int> ft_m;
        // std::map<char, int>::iterator it;
        // ft::Map<char, int>::iterator ft_it;

        // // insert some values:
        // ft_m['a'] = 10;
        // ft_m['b'] = 20;
        // ft_m['c'] = 30;
        // ft_m['d'] = 40;
        // ft_m['e'] = 50;
        // ft_m['f'] = 60;

        // m['a'] = 10;
        // m['b'] = 20;
        // m['c'] = 30;
        // m['d'] = 40;
        // m['e'] = 50;
        // m['f'] = 60;

        // // cond = m.size() == ft_m.size() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());
        // it = m.find('b');
        // ft_it = ft_m.find('b');

        // // cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second);
        // m.erase(it);       // erasing by iterator
        // ft_m.erase(ft_it); // erasing by iterator

        // // cond = cond && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());


        // int ret = m.erase('c');       // erasing by key
        // int ft_ret = ft_m.erase('c'); // erasing by key
        // // cond = cond && ret == ft_ret && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        // it = m.find('e');
        // ft_it = ft_m.find('e');

        // // cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second) && m.size() == ft_m.size();

        // m.erase(it, m.end());          // erasing by range
        // ft_m.erase(ft_it, ft_m.end()); // erasing by range

        // // cond = cond && m.empty() == ft_m.empty() && compareMaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        // /* ---------- Testing some edge cases ---------- */
        
        // std::map<int, std::string> m2;
        // ft::Map<int, std::string> ft_m2;

        // for (size_t i = 0; i < 1e5; i++)
        // {
        //     m2.insert(std::make_pair(i, "string1"));
        //     ft_m2.insert(ft::make_pair(i, "string1"));
        // }
        // std::map<int, std::string>::reverse_iterator it2 = m2.rbegin();
        // ft::Map<int, std::string>::reverse_iterator ft_it2 = ft_m2.rbegin();

        // m2.erase(m2.begin());
        // ft_m2.erase(ft_m2.begin());

        // cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        // m2.erase(it2->first);
        // ft_m2.erase(ft_it2->first);

        // cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        std::map<int, std::string> m3;
        ft::Map<int, std::string> ft_m3;
        // std::vector<int> vec;
        // std::vector<int> ft_vec;
        // std::random_device randDev;
        // std::mt19937 generator(randDev());
        // std::uniform_int_distribution<int> distr(0, 35);
        int arr[8] = { 30,20,10,15,25,9,12 };
        for (size_t i = 0; i < 7; i++)
        {
            ft_m3.insert(ft::make_pair(arr[i], "string1"));
        }
        ft::Map<int, std::string>::iterator beg = ft_m3.begin();
        ft::Map<int, std::string>::iterator end = ft_m3.end();
        for (int i = 0;beg != end; beg++, ++i)
        {
          std::cout << "key  = " << beg->first << std::endl;
          if (i > ft_m3.size())
          {
            std::cout << "stuck on : " << beg->first << std::endl;
            exit (1);
          }
        }
        // if (!m3.empty())
        // {
        //     m3.erase(m3.begin(), m3.end());
        //     m3.erase(m3.begin(), m3.end());
        // }
        // if (!ft_m3.empty())
        // {
        //     ft_m3.erase(ft_m3.begin(), ft_m3.end());
        //     ft_m3.erase(ft_m3.begin(), ft_m3.end());
        // }
        // std::cout << "done " << std::endl;
        // cond = cond && (m3.size() == ft_m3.size() && compareMaps(m3.begin(), m3.end(), ft_m3.begin(), ft_m3.end()));

     // bool cond(true);

    // std::map<int, std::string> m;
    // ft::Map<int, std::string> ft_m;
    // int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
    // for (size_t i = 0; i < 9; ++i)
    // {
    //     m.insert(std::make_pair(arr[i], "value"));
    //     ft_m.insert(ft::make_pair(arr[i], "value"));
    // }
    // std::map<int, std::string> const c_m(m.begin(), m.end());
    // ft::Map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
    // cond = (cond && (m.lower_bound(15)->first == ft_m.lower_bound(15)->first));
    
    // cond = (cond && (m.lower_bound(65)->first == ft_m.lower_bound(65)->first));
    // cond = (cond && (m.lower_bound(63)->first == ft_m.lower_bound(63)->first));
    // cond = (cond && (m.lower_bound(120)->first == ft_m.lower_bound(120)->first));
    // cond = (cond && (m.lower_bound(70)->first == ft_m.lower_bound(70)->first));

    // cond = (cond && (c_m.lower_bound(15)->first == c_ft_m.lower_bound(15)->first));
    // cond = (cond && (c_m.lower_bound(65)->first == c_ft_m.lower_bound(65)->first));
    // cond = (cond && (c_m.lower_bound(63)->first == c_ft_m.lower_bound(63)->first));
    // cond = (cond && (c_m.lower_bound(120)->first == c_ft_m.lower_bound(120)->first));
    // cond = (cond && (c_m.lower_bound(70)->first == c_ft_m.lower_bound(70)->first));
//  std::map<int, std::string> m;
//     ft::Map<int, std::string> ft_m;
//     int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
//     for (size_t i = 0; i < 9; ++i)
//     {
//         m.insert(std::make_pair(arr[i], "value"));
//         ft_m.insert(ft::make_pair(arr[i], "value"));
//     }
//     std::map<int, std::string> const c_m(m.begin(), m.end());
//     ft::Map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
//     cond = (cond && (m.upper_bound(15)->first == ft_m.upper_bound(15)->first));
//     cond = (cond && (m.upper_bound(65)->first == ft_m.upper_bound(65)->first));
//     cond = (cond && (m.upper_bound(63)->first == ft_m.upper_bound(63)->first));
//     cond = (cond && (m.upper_bound(120)->first == ft_m.upper_bound(120)->first));
//     cond = (cond && (m.upper_bound(70)->first == ft_m.upper_bound(70)->first));
//     cond = (cond && (m.upper_bound(150)->first == ft_m.upper_bound(150)->first));
//     std::cout << c_m.upper_bound(15)->first <<" || " <<  c_ft_m.upper_bound(15)->first << std::endl;
//     cond = (cond && (c_m.upper_bound(15)->first == c_ft_m.upper_bound(15)->first));
//     std::cout << "cond = " << cond << std::endl;
//     cond = (cond && (c_m.upper_bound(65)->first == c_ft_m.upper_bound(65)->first));
//     cond = (cond && (c_m.upper_bound(63)->first == c_ft_m.upper_bound(63)->first));
//     cond = (cond && (c_m.upper_bound(120)->first == c_ft_m.upper_bound(120)->first));
//     cond = (cond && (c_m.upper_bound(70)->first == c_ft_m.upper_bound(70)->first));
//     cond = (cond && (c_m.upper_bound(150)->first == c_ft_m.upper_bound(150)->first));

//     if (!cond)
//     {
//       std::cout << "hmdulilah" << std::endl;
//       exit(0);
//     }
    

  // std::map<char,int> mymap;
  // std::map<char,int>::iterator it;

  // mymap['a']=50;
  // mymap['b']=100;
  // mymap['c']=150;
  // mymap['d']=200;

  // it = mymap.find('b');
  // if (it != mymap.end())
  //   mymap.erase (it);

  // // print content:
  // mymap.find('s');
  // std::cout << "elements in mymap:" << '\n';
  // std::cout << "a => " << mymap.find('a')->second << '\n';
  // std::cout << "c => " << mymap.find('c')->second << '\n';
  // std::cout << "d => " << mymap.find('d')->second << '\n';

  // std::map<int, std::string> m3;
  // ft::Map<int, std::string> ft_m3;
  // std::vector<int> vec;
  // std::vector<int> ft_vec;
  // std::random_device randDev;
  // std::mt19937 generator(randDev());
  // std::uniform_int_distribution<int> distr(0, 1e8);

  // for (size_t i = 0; i < 1e6; i++)
  // {
  //     // m3.insert(std::make_pair(i, "string1"));
  //     ft_m3.insert(ft::make_pair(i, "string1"));
  // }

  // for (size_t i = 0; i < 1e6; ++i)
  // {
  //     int n = distr(generator);

  //     // int ret1 = m3.erase(n);
  //     int ret2 = ft_m3.erase(n);

  //     // // if (ret1 != ret2)
  //     // {
  //     //     break;
  //     // }
  // }
  // if (!m3.empty())
  // {
  //     m3.erase(m3.begin(), m3.end());
  //     m3.erase(m3.begin(), m3.end());
  // // }
  // if (!ft_m3.empty())
  // {
  //     ft_m3.erase(ft_m3.begin(), ft_m3.end());
  //     ft_m3.erase(ft_m3.begin(), ft_m3.end());
  // }
  // ft::Map<int, std::string> ft_m1;
  // for (size_t i = 0; i < 10; i++)
  //   ft_m1.insert(ft::make_pair(i, "string2"));
  // ft_m1.erase(1);
  // ft_m1.print_h();
  //  std::map<int, std::string> m1;
  // ft::Map<int, std::string> ft_m1;

  // for (size_t i = 0; i < 10; i++)
  // {
  //     m1.insert(std::make_pair(i, "string2"));
  //     ft_m1.insert(ft::make_pair(i, "string2"));
  // }

  // std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
  // ft::Map<int, std::string> const ft_m2(ft_m1.rbegin(), ft_m1.rend());

  // /*-----------------------------------------------------*/
  // /*------------------ ft::Maps ---------------------*/
  // /*----------------------------------------------------*/
  // /*------------------ strings to store the results ----*/
  // std::string res, ft_res, c_res, c_ft_res;
  // /*----------------------------------------------------*/
  // for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) // fill res from m1
  //     res += it->second;
  // for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
  //     c_res += rit->second;

  // for (ft::Map<int, std::string>::reverse_iterator it = ft_m1.rbegin(); it != ft_m1.rend(); ++it) // fill ft_res from ft_m1
  //     ft_res += it->second;
  // for (ft::Map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit)
  // {
  //   c_ft_res += rit->second; 
  // } // fill c_ft_res from const ft_m1
  // int arr[] = {12, 82, 37, 64, 15};
  // ft::Map<int, int> end_test;
  // for(size_t i = 0; i < 5; ++i)
  //     end_test.insert(ft::make_pair(arr[i], i));
  // ft::Map<int, int>::reverse_iterator rit1 = end_test.rend();
  // rit1--;
  // std::map<int, std::string> m1;z
  // ft::Map<int, std::string> ft_m1;

  // for (size_t i = 0; i < 10; i++)
  // {
  //     m1.insert(std::make_pair(i, "string2"));
  //     ft_m1.insert(ft::make_pair(i, "string2"));
  // }

  // // std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
  // ft::Map<int, std::string> const ft_m2(ft_m1.rbegin(), ft_m1.rend());
   
  /*-----------------------------------------------------*/
  /*------------------ ft::Maps ---------------------*/
  /*----------------------------------------------------*/
  /*------------------ strings to store the results ----*/
  // std::string res, ft_res, c_res, c_ft_res;
  /*----------------------------------------------------*/
  // for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) // fill res from m1
  //     res += it->second;
  // for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
  //     c_res += rit->second;
    
  // for (ft::Map<int, std::string>::reverse_iterator it = ft_m1.rbegin(); it != ft_m1.rend(); ++it) // fill ft_res from ft_m1
  //     ft_res += it->second;
  // ft_mx2.print_h();
  // exit(0);
  // for (ft::Map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit)
  // {
  //     c_ft_res += rit->second;
  // } // fill c_ft_res from const ft_m1
  
  // int arr[] = {12, 82, 37, 64, 15};
  
  // ft::Map<int, int> end_test;
  // for(size_t i = 0; i < 5; ++i)
  //     end_test.insert(ft::make_pair(arr[i], i));
  
  // ft::Map<int, int>::reverse_iterator rit1 = end_test.rend();
  // rit1--;
  // std::map<int, std::string> m1;
  // std::map<int, std::string> m2;
  // ft::Map<int, std::string> ft_m1;
  // ft::Map<int, std::string> ft_m2;

  // for (int i = 0; i < 10; ++i)
  // {
  //     m1.insert(std::make_pair(i, "string2"));
  //     ft_m1.insert(ft::make_pair(i, "string2"));
  // }
  // m1 = m2;
  // /*-----------------------------------------------------*/
  // /*------------------ ft::Map ---------------------*/
  // ft_m1 = ft_m2;

  // /*----------------------------------------------------*/
  // /*------------------ strings to store the results ----*/
  // std::string res, ft_res;
  // /*----------------------------------------------------*/
  // for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
  //     res += it->second;
  // for (ft::Map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it)
  // {
  //     ft_res += it->second;
  // } // fill ft_res from ft_m1
  // std::cout << "iter" << std::endl;
  // std::map<int, std::string> m1;
  // ft::Map<int, std::string> ft_m1;

  // for (size_t i = 0; i < 10; i++)
  // {
  //     m1.insert(std::make_pair(i, "string2"));
  //     ft_m1.insert(ft::make_pair(i, "string2"));
  // }

  // std::map<int, std::string> const m2(m1.begin(), m1.end());
  // ft::Map<int, std::string>  const ft_m2(ft_m1.begin(), ft_m1.end());

  /*-----------------------------------------------------*/
  /*------------------ ft::Maps ---------------------*/
  /*----------------------------------------------------*/
  /*------------------ strings to store the results ----*/
  // std::string res, ft_res, c_res, c_ft_res;
  /*----------------------------------------------------*/
  // for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
  //     res += it->second;
  // for (std::map<int, std::string>::const_iterator rit = m2.begin(); rit != m2.end(); ++rit) // fill c_res from const m1
  //     c_res += rit->second;

  // ft::Map<int, std::string>::const_iterator rit = ft_m2.begin();
  // for (ft::Map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
  //     ft_res += it->second;
  // for (ft::Map<int, std::string>::const_iterator rit = ft_m2.begin(); rit != ft_m2.end(); ++rit) // fill c_ft_res from const ft_m1
  //     c_ft_res += rit->second;
  
  // int arr[] = {12, 82, 37, 64, 15};
  // ft::Map<int, int> end_test;
  // for(size_t i = 0; i < 5; ++i)
  //     end_test.insert(ft::make_pair(arr[i], i));
  // ft::Map<int, int>::iterator eit = end_test.end();
  // eit--;
  // ft::Map<char,int>::const_iterator con = foo.begin();
  // std::cout << "foo contains:\n";
  // for (ft::Map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  // std::cout << "bar contains:\n";
  // for (ft::Map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';
  // std::map<char,int> mymap;

  // mymap['e']=10;
  // mymap['f']=20;
  // mymap['c']=30;

  // std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
  // ret = mymap.equal_range('b');

  // std::cout << "lower bound points to: ";
  // std::cout << ret.first->first << " => " << ret.first->second << '\n';

  // std::cout << "upper bound points to: ";
  // std::cout << ret.second->first << " => " << ret.second->second << '\n';
  
  // std::cout << "==============\n";

  // ft::Map<char,int> ft_myMap;

  // ft_myMap['a']=10;
  // ft_myMap['b']=20;
  // ft_myMap['c']=30;

  // ft::pair<ft::Map<char,int>::iterator,ft::Map<char,int>::iterator> ft_ret;
  // ft_ret = ft_myMap.equal_range('b');

  // std::cout << "lower bound points to: ";
  // std::cout << ft_ret.first->first << " => " << ft_ret.first->second << '\n';

  // std::cout << "upper bound points to: ";
  // std::cout << ft_ret.second->first << " => " << ft_ret.second->second << '\n';

  // std::Map<int,int> mymap;
  // std::map<int,int>::iterator itlow,itup;
  // ft::map<int,int> ft_mymap;
  // ft::map<int,int>::iterator ft_itlow,ft_itup;

  // for (size_t i = 0; i <37;i+=2)
  //   mymap[i] = 20;
  // for (size_t i = 0; i <37;i+=2)
  //   ft_mymap[i] = 20;
  // // std::cout << "---------------\n";
  // // mymap.print_h();
  // itlow = mymap.lower_bound (36);  // itlow points to b
  // itup = mymap.upper_bound (22);   // itup points to e (not d!)
  // std::cout << "itlow = " << itlow->first << " => " << itlow->second << '\n';
  // std::cout << "itup = " << itup->first << " => " << itup->second << '\n';

  // ft_itlow = ft_mymap.lower_bound (36);  // ft_itlow points to b
  // ft_itup = ft_mymap.upper_bound (22);   // ft_itup points to e (not d!)
  // std::cout << "ft_itlow = " << ft_itlow->first << " => " << ft_itlow->second << '\n';
  // std::cout << "ft_itup = " << ft_itup->first << " => " << ft_itup->second << '\n';

  // ft_mymap.erase(itlow,itup);        // erases [itlow,itup)

  // // print content:
  // for (ft::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  // ft::map<char,int> mymap;
  // char c;
  // size_t ret;

  // mymap ['a']=101;
  // mymap ['c']=202;
  // mymap ['f']=303;

  // for (c='a'; c<'h'; c++)
  // {
  //   std::cout << c;
  //   if ((ret = mymap.count(c))>0)
  //     std::cout << " is an element of mymap.\n";
  //   else 
  //     std::cout << " is not an element of mymap.\n";
  //   std::cout << "c = [ " << c << " ] ret  = [ " << ret << " ] " << std::endl;


  // }
  //   std::cout << "------------------------" << std::endl;
  //   std::map<char,int> mymap1;
  // char d;
  // size_t e;

  // mymap1 ['a']=101;
  // mymap1 ['c']=202;
  // mymap1 ['f']=303;

  // for (d='a'; d<'h'; d++)
  // {
  //   std::cout << d;
  //   if ((e = mymap1.count(d))>0)
  //     std::cout << " is an element of mymap1.\n";
  //   else 
  //     std::cout << " is not an element of mymap1.\n";
  //   std::cout << "c = [ " << d << " ] ret  = [ " << e << " ] " << std::endl;
  // }
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

  // system("leaks a.out");
  return 0;
}
