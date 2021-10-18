/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:40:51 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/18 19:53:33 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iostream>
namespace ft{

	template<class T>
	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		private :
			pointer	_Pointer;
		public :
			iterator(void) : _Pointer(nullptr) {};
			iterator(const iterator& it) { *this = it } ;
			~iterator(void);
			iterator& operator=(const iterator& it){ this->_Pointer = it._Pointer; };

			bool operator==(const iterator& it) const { return this->_Pointer == it._Pointer};
			bool operator!=(const iterator& it) const { return this->_Pointer != it._Pointer};

			reference	operator*(void) const { return *_Pointer; };
			pointer		operator->(void) const { return _Pointer; };
			iterator	&operator++(void) { iterator old = this; _Pointer++; return old; };
			iterator 	&operator--(void) { iterator old = this; _Pointer--; return old; };
			iterator 	operator++(int) { _Pointer++; return this; };
			iterator 	operator--(int) { _Pointer--; return this; };

			iterator	&operator+(int n) { _Pointer = _Pointer + n; return this; };
			iterator	&operator-(int n) { _Pointer = _Pointer - n; return this; };

			iterator	&operator+=(int n) { _Pointer + n; return this; };
			iterator	&operator-=(int n) { _Pointer - n; return this; };

			difference_type operator-(const iterator& it) { return this->_Pointer - it._Pointer; };

			bool operator<(const iterator& it) const { return _Pointer < it._Pointer };
			bool operator>(const iterator& it) const { return _Pointer > it._Pointer };
			bool operator<=(const iterator& it) const { return _Pointer <= it._Pointer };
			bool operator>=(const iterator& it) const { return _Pointer >= it._Pointer };
			
			reference operator[](const int& index) const {return _Pointer[index]}
	};

	iterator	&operator-(const int& n, iterator& it) { return it + n; };

	template <class Iterator> 
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type	 difference_type;
			typedef typename Iterator::value_type		 value_type;
			typedef typename Iterator::pointer			 pointer;
			typedef typename Iterator::reference		 reference;
			typedef typename Iterator::iterator_category iterator_category;
		
	};
	
	template <class T>
	class iterator_traits<T*>
	{
		public:

		typedef ptrdiff_t		 					     difference_type;
		typedef T	 		     					     value_type;
		typedef T*		     						     pointer;
		typedef T&		         					     reference;
		typedef std::random_access_iterator_tag               iterator_category;
	};
	
	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t		 					     difference_type;
			typedef T	 		     					     value_type;
			typedef const T*		     					 pointer;
			typedef const T&		         			 	 reference;
			typedef std::random_access_iterator_tag          iterator_category;
	};

	template <class Iterator>
	class reverse_iterator
	{
		public :
			typedef 		 Iterator	 				 							 iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category			 iterator_category;
			typedef typename iterator_traits<Iterator>::value_type				 	 value_type;
			typedef typename iterator_traits<Iterator>::difference_type	 			 difference_type;
			typedef typename iterator_traits<Iterator>::pointer						 pointer;
			typedef typename iterator_traits<Iterator>::reference					 reference;
			
		private : 
			iterator_type  _it;
		public :
			reverse_iterator(void) : _it(nullptr);
			explicit reverse_iterator (iterator_type it) : _it(it) {};
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) { _it = rev_it._it };

			iterator_type base  ( void ) const { --_it ; return _it };
			reference operator* ( void ) const { return *(_it - 1); };
			reverse_iterator operator+ (difference_type n) const{ _it = _it - n ; return this; };
			reverse_iterator operator- (difference_type n) const { _it = _it + n ; return this; };
			reverse_iterator& operator++() { _it--; return this; };
			reverse_iterator  operator++(int){ --_it; return this; };
			reverse_iterator& operator+= (difference_type n) { _it = _it - n; return this;};
			reverse_iterator& operator--() { _it++; return this; };
			reverse_iterator  operator--(int) { ++_it; return this; };
			reverse_iterator& operator-= (difference_type n) { _it = _it + n; return this; };
	};


	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() == rhs.base() };
	
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() != rhs.base() };
	
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() < rhs.base() };
	
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() <= rhs.base() };
	
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() > rhs.base() };

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() >= rhs.base(); };
	
	template <class Iterator>
  	reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator>& rev_it)
	{ return rev_it + n};
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() - rhs.base(); };
}

#endif
