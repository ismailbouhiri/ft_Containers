/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:43:39 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/03 14:57:25 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
	// template <class T>
	// struct less : std::binary_function <T,T,bool>
	// {
  	// 	bool operator() (const T& x, const T& y) const { return x < y; }
	// };

	template <class T1, class T2> 
	struct pair
	{
			typedef T1		first_type;
			typedef T2		second_type;
			first_type first;
			second_type second;
			pair( void ) : first(0), second(0) {};
			template<class U, class V> 
			pair (const pair<U,V>& pr) {
				*this = pr;
			};
			pair (const first_type& a, const second_type& b) : first(a), second(b) {};
			pair& operator= (const pair& pr) {
				first = pr.first;
				second = pr.second;
				return *this;
			};
	};
	
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs == rhs); };

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return (lhs.first < rhs.first && lhs.second < rhs.second); };
	
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return ( lhs == rhs || lhs < rhs ); };
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs <= rhs); };
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs < rhs); };
	
	template <class T1, class T2>
  	pair<T1,T2> make_pair (T1 x, T2 y)
	{ return pair<T1, T2>(x,y); };
	
	// template < class T>
	// class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	// {
	// 	private:
	// 		Map*	Tree;
	// 		T*		
	// 	public :
		
			
	// };


	
}

#endif