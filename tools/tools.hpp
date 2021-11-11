/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:02:57 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/10 11:06:43 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace ft
{
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
			
			reverse_iterator(void)  {};
			
			explicit reverse_iterator (iterator_type it) : _it(it) {};
			
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) { _it = rev_it.base(); };
			
			template <class Iter>
			reverse_iterator& operator=(const reverse_iterator<Iter>& rev_it) { _it = rev_it.base(); return *this; }
			
			iterator_type base  ( void )  const { return _it; };

			reference operator* ( void )  { iterator_type it2(_it); return *(--it2); };

			pointer operator-> ( void )  { iterator_type tmp(_it); --tmp; return tmp.operator->(); }

			reference operator[](const int& index) const { return _it[-index - 1]; };

			reverse_iterator operator+ (difference_type n) { return reverse_iterator(_it - n); };
			reverse_iterator operator- (difference_type n) { return reverse_iterator(_it + n); };

			reverse_iterator &operator++(void) { --_it; return *this; };
			reverse_iterator &operator--(void) { _it++; return *this; };
			reverse_iterator operator++(int){ reverse_iterator old(*this); _it--; return old; };
			reverse_iterator operator--(int) {reverse_iterator old(*this); _it++; return old; };

			reverse_iterator& operator+= (difference_type n) { _it = _it - n; return *this;};
			reverse_iterator& operator-= (difference_type n) { _it = _it + n; return *this; };
			
		template <class Iter>
		friend bool operator== (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);	
		
		template <class Iter>
		friend bool operator!= (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
		
		template <class Iter>
		friend bool operator<  (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
		
		template <class Iter>
		friend bool operator<= (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
		
		template <class Iter>
		friend bool operator>  (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

		template <class Iter>
		friend bool operator>= (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
		
		template <class Iter>
		friend reverse_iterator<Iter> operator+ ( typename reverse_iterator<Iter>::difference_type n,
		reverse_iterator<Iter>& rev_it);
		
		template <class Iter>
		friend typename reverse_iterator<Iter>::difference_type operator- (const reverse_iterator<Iter>& lhs,
		const reverse_iterator<Iter>& rhs);

	};
		
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs._it == lhs._it); };
	
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs._it != lhs._it); };
	
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs._it < lhs._it); };
	
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs._it <= lhs._it); };
	
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs._it > lhs._it); };

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs._it >= lhs._it); };
	
	template <class Iterator>
  	reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n,
	reverse_iterator<Iterator>& rev_it)
	{ return rev_it + n; };
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs) { return rhs.base() - lhs.base(); };
}


#endif