	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:40:51 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/19 14:40:02 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iostream>
namespace ft {

	template<class T>
	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public :	
			typedef	T*      		pointer;
			typedef	T&				reference;
			typedef	ptrdiff_t		difference_type;
		private :
			pointer	_Pointer;
		public :
			iterator(void) : _Pointer(nullptr) {};
			iterator(pointer ptr) : _Pointer(ptr) {};
			iterator(const iterator& it) { *this = it; } ;
			~iterator(void){};
			iterator& operator=( const iterator& it) { this->_Pointer = it._Pointer; return *this; };
			operator iterator<const T>() const{ return iterator<const T>(_Pointer); }
			bool operator==(const iterator& it) const { return this->_Pointer == it._Pointer; };
			bool operator!=(const iterator& it) const { return this->_Pointer != it._Pointer; };

			reference	operator*(void) const { return *_Pointer; };
			pointer		operator->(void) const { return _Pointer; };
			iterator	operator++(int) {iterator old(*this); _Pointer++; return old; };
			iterator 	operator--(int) {iterator old(*this); _Pointer--; return old; };
			iterator 	&operator++(void) { _Pointer++; return *this; };
			iterator 	&operator--(void) { _Pointer--; return *this; };

			iterator	operator+(int n) { return (_Pointer + n); };
			iterator	operator-(int n) { return (_Pointer - n); };

			iterator	&operator+=(int n) { _Pointer = _Pointer + n; return *this; };
			iterator	&operator-=(int n) { _Pointer = _Pointer - n; return *this; };

			difference_type operator-(const iterator& it) { return _Pointer - it._Pointer; };

			bool operator<(const iterator& it) const { return (_Pointer < it._Pointer); };
			bool operator>(const iterator& it) const { return (_Pointer > it._Pointer); };
			bool operator<=(const iterator& it) const { return (_Pointer <= it._Pointer); };
			bool operator>=(const iterator& it) const { return (_Pointer >= it._Pointer); };
			
			reference operator[](const int& index) const { return _Pointer[index]; };
	};
	template <class type> 
	iterator<type>	operator+(typename ft::iterator<type>::difference_type n, ft::iterator<type>& it) { return it + n; };

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
			reverse_iterator(void) : _it(nullptr){};
			explicit reverse_iterator (iterator_type it) : _it(it) {};
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) { _it = rev_it.base(); };

			iterator_type base  ( void )  const { return _it; };

			reference operator* ( void )  { return *(_it - 1); };

			pointer operator-> ( void )  { iterator_type tmp(_it - 1); return tmp.operator->(); };

			reference operator[](const int& index) const { return _it[-index - 1]; };

			reverse_iterator operator+ (difference_type n) { return reverse_iterator(_it - n); };
			reverse_iterator operator- (difference_type n) { return reverse_iterator(_it + n); };

			reverse_iterator &operator++(void) { --_it; return *this; };
			reverse_iterator  &operator--(void) { _it++; return *this; };
			reverse_iterator  operator++(int){ reverse_iterator old(*this); _it--; return old; };
			reverse_iterator operator--(int) {reverse_iterator old(*this); _it++; return old; };

			reverse_iterator& operator+= (difference_type n) { _it = _it - n; return *this;};
			reverse_iterator& operator-= (difference_type n) { _it = _it + n; return *this; };
	};


	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return ((lhs.base() - 1) == (rhs.base() - 1)); };
	
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return ((lhs.base() - 1) != (rhs.base() - 1)); };
	
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(*(lhs.base() - 1) > *(rhs.base() - 1)); };
	
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (*(lhs.base() - 1) <= *(rhs.base() - 1)); };
	
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (*(lhs.base() - 1) > *(rhs.base() - 1)); };

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(*(lhs.base() - 1) <= *(rhs.base() - 1)); };
	
	template <class Iterator>
  	reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n,
	reverse_iterator<Iterator>& rev_it)
	{ return rev_it + n; };
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs) { return rhs.base() - lhs.base(); };
}

#endif
