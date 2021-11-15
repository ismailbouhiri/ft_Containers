/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterators.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 05:50:42 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/13 05:51:05 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "../tools/tools.hpp"
#include <iostream>
namespace ft {

	template<class T>
	class vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public :	
			typedef	T*      		pointer;
			typedef	T&				reference;
			typedef	ptrdiff_t		difference_type;
		private :
			pointer	_Pointer;
		public :
			vector_iterator(void) : _Pointer(nullptr) {};
			vector_iterator(pointer ptr) : _Pointer(ptr) {};
			vector_iterator(const vector_iterator& it) { *this = it; } ;
			~vector_iterator(void){};
			vector_iterator& operator=( const vector_iterator& it) { this->_Pointer = it._Pointer; return *this; };
			operator vector_iterator<const T>() const{ return vector_iterator<const T>(_Pointer); }
			bool operator==(const vector_iterator& it) const { return this->_Pointer == it._Pointer; };
			bool operator!=(const vector_iterator& it) const { return this->_Pointer != it._Pointer; };

			reference	operator*(void) const { return *_Pointer; };
			pointer		operator->(void) const { return _Pointer; };
			vector_iterator	operator++(int) {vector_iterator old(*this); _Pointer++; return old; };
			vector_iterator 	operator--(int) {vector_iterator old(*this); _Pointer--; return old; };
			vector_iterator 	&operator++(void) { _Pointer++; return *this; };
			vector_iterator 	&operator--(void) { _Pointer--; return *this; };

			vector_iterator	operator+(int n) { return (_Pointer + n); };
			vector_iterator	operator-(int n) { return (_Pointer - n); };

			vector_iterator	&operator+=(int n) { _Pointer = _Pointer + n; return *this; };
			vector_iterator	&operator-=(int n) { _Pointer = _Pointer - n; return *this; };

			difference_type operator-(const vector_iterator& it) { return _Pointer - it._Pointer; };

			bool operator<(const vector_iterator& it) const { return (_Pointer < it._Pointer); };
			bool operator>(const vector_iterator& it) const { return (_Pointer > it._Pointer); };
			bool operator<=(const vector_iterator& it) const { return (_Pointer <= it._Pointer); };
			bool operator>=(const vector_iterator& it) const { return (_Pointer >= it._Pointer); };
			
			reference operator[](const int& index) const { return _Pointer[index]; };
	};
	template <class type> 
	vector_iterator<type>	operator+(typename ft::vector_iterator<type>::difference_type n, ft::vector_iterator<type>& it) { return it + n; };
}

#endif
