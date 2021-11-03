/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:05:20 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/03 12:33:28 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include "iterator.hpp"
# include "tree.hpp"

namespace ft 
{
	
	template < class Key,                                     // map::key_type
           class value,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator< ft::pair <const Key,value> >    // map::allocator_type
           > 
	class map
	{
		public :
			typedef Key											key_type;
			typedef value										mapped_type;
			typedef	ft::pair<const key_type, mapped_type> 		value_type;
			typedef Compare										key_compare;
			
			typedef class value_comp: public std::binary_function <value_type,value_type, bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_comp (Compare c) : comp(c) {}  // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{   return comp(x.first, y.first);   };
			}													value_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;
			// typedef	ft::iterator<value_type>					iterator;
			// typedef	ft::iterator<const value_type>				const_iterator;
			// typedef	ft::reverse_iterator<iterator>				reverse_iterator;
			// typedef	ft::const_reverse_iterator<const_iterator>	const_reverse_iterator;
	};

}
  
#endif
