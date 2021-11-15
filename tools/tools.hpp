/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:02:57 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/15 14:20:52 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace ft
{

	/// enable if /// 
	
	template<bool Cond, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };
	
	////// end enable if /// 
	
	///// is intergral // ////// //// 
	template <bool B>
	struct ret_type { static const bool value = B; };
	
	typedef ret_type<true> true_type;
	typedef ret_type<false> false_type;
	
	template <class T> 
				struct is_integral :  false_type {};
	template <> struct is_integral<bool> :  true_type {};
	template <> struct is_integral<char> :  true_type {};
	template <> struct is_integral<char16_t> :  true_type {};
	template <> struct is_integral<char32_t> :  true_type {};
	template <> struct is_integral<signed char> : true_type {};
	template <> struct is_integral<short int> :  true_type {};
	template <> struct is_integral<int> :  true_type {};
	template <> struct is_integral<long int> :  true_type {};
	template <> struct is_integral<long long int> :  true_type {};
	template <> struct is_integral<unsigned char> :  true_type {};
	template <> struct is_integral<unsigned short int> :  true_type {};
	template <> struct is_integral<unsigned int> :  true_type {};
	template <> struct is_integral<unsigned long int> :  true_type {};
	template <> struct is_integral<unsigned long long int> :  true_type {};
	///// end is intergral // ////// //// 

	///////// lexicographical_compare //// 
	
	/////// custom ////
	template <class InputIterator1, class InputIterator2, class Compare>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
    	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) 
		{
        	if (comp(*first1, *first2))
				return true;
        	if (comp(*first2, *first1)) 
				return false;
    	}
    	return (first1 == last1) && (first2 != last2);
	}
	///// default //// 
	template <class InputIterator1, class InputIterator2>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}
	///////// end lexicographical_compare //// 
	
	/// default///
	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1; ++first2;
		}
		return true;
	}
	/////// predicate  /// 
	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}
	template <class iterator> 
	class iterator_traits
	{
		public:
			typedef typename iterator::difference_type	 difference_type;
			typedef typename iterator::value_type		 value_type;
			typedef typename iterator::pointer			 pointer;
			typedef typename iterator::reference		 reference;
			typedef typename iterator::iterator_category iterator_category;
	};
	//////// end equal .///// 


	
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



	/////////////////// reverse iterator implementation ///// 
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

			reference operator* ( void )  { iterator_type it2(_it); return *--it2; };

			pointer operator-> ( void )  { iterator_type tmp(_it); --tmp; return tmp.operator->(); }

			reference operator[](const int& index) const { return _it[-index - 1]; };

			reverse_iterator operator+ (difference_type n) { return reverse_iterator(_it - n); };
			reverse_iterator operator- (difference_type n) { return reverse_iterator(_it + n); };

			reverse_iterator &operator++(void) { --_it; return *this; };
			reverse_iterator &operator--(void) { ++_it; return *this; };
			reverse_iterator operator++(int) { reverse_iterator old(*this); _it--; return old; };
			reverse_iterator operator--(int) { reverse_iterator old(*this); _it++; return old; };

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