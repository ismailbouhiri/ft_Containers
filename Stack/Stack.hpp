/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:23:43 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/15 15:12:54 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP 
#define STACK_HPP

#include "../Vector/vector.hpp"

namespace ft {
	
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public :
			typedef T												value_type;
			typedef Container										container_type;
			typedef size_t											size_type;
				
		protected:
			container_type vec;
		public:
			
			explicit stack (const container_type& ctnr = container_type()) : vec(ctnr) {}
			bool empty( void  ) const { return vec.empty(); }
			size_type size( void ) const { return vec.size(); }
			
			value_type& top( void ) { return vec.back(); }
			const value_type& top( void ) const { return vec.back(); }
			void push (const value_type& val) { vec.push_back(val); }
			void pop( void ) { vec.pop_back(); }



			template <class Tp, class Cntr>
			friend bool operator== (const stack<Tp,Cntr>& f, const stack<Tp,Cntr>& r);
			
			template <class Tp, class Cntr>
			friend bool operator!= (const stack<Tp,Cntr>& f, const stack<Tp,Cntr>& r);
			
			template <class Tp, class Cntr>
			friend bool operator<  (const stack<Tp,Cntr>& f, const stack<Tp,Cntr>& r);
			
			template <class Tp, class Cntr>
			friend bool operator<= (const stack<Tp,Cntr>& f, const stack<Tp,Cntr>& r);
			
			template <class Tp, class Cntr>
			friend bool operator>  (const stack<Tp,Cntr>& f, const stack<Tp,Cntr>& r);
			
			template <class Tp, class Cntr>
			friend bool operator>= (const stack<Tp,Cntr>& f, const stack<Tp,Cntr>& r);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.vec == rhs.vec; }
	
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.vec != rhs.vec; }
	
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.vec < rhs.vec; }
	
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.vec <= rhs.vec; }
	
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.vec > rhs.vec; }
	
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.vec >= rhs.vec; }

}

#endif