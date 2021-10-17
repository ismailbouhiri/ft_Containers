/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:40:51 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/17 16:43:43 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iostream>
namespace ft{

	template<class T>
	class Myiterator : public std::iterator<random_access_iterator_tag, T>
	{
		private :
			T	*_Pointer;
		public :
		
			Myiterator(void) : _Pointer(nullptr) {};
			Myiterator(const Myiterator& it) { *this = it } ;
			~Myiterator(void);
			Myiterator& operator=(const Myiterator& it){ this->_Pointer = it._Pointer; };
			
			bool operator==(const Myiterator& it) const { return it._Pointer == this->_Pointer };
			bool operator!=(const Myiterator& it) const { return it._Pointer != this->_Pointer };
			
			reference operator*(void) const { return *_Pointer; };
			pointer operator->(void) const { return _Pointer; };
			
			Myiterator operator++(void)
			{
				this->_Pointer++;
				return *this;
			}
			
			
			
			
	};
}

#endif
