/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:05:20 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/08 17:07:31 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include "Bidirectional_iterator.hpp"
# include "tree.hpp"
# include "../tools/tools.hpp"

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
		// typedefs .....
			typedef Key															key_type;
			typedef value														mapped_type;
			typedef	ft::pair<const key_type, mapped_type> 						value_type;
			typedef Compare														key_compare;
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
			}																	value_compare;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::difference_type					difference_type;
			typedef typename allocator_type::size_type							size_type;
			typedef tree<value_type, allocator_type, key_compare, key_type> 	tree_type;

		private:
			tree_type _tree;
			
		public : 
			typedef	ft::iterator<ft_node<value_type>, tree_type>				iterator;
			typedef	ft::iterator<ft_node<const value_type>, tree_type>			const_iterator;
			typedef	ft::reverse_iterator<iterator>								reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		public :

			void	insert (const value_type& val)
			{
				_tree.insert(val);
			}
			void remove(const key_type& val)
			{
				_tree.deleteNode(val);
			}
			
			void print_h(void)
			{
				_tree.tree_print();
			}
			
			size_type size(void)
			{
				return _tree.getSize();
			}
			
			iterator begin( void ) { return iterator(_tree.getfirst(), &_tree); }
			const_iterator begin( void ) const { return const_iterator(_tree.getfirst(), &_tree); }

			iterator end( void ) { return iterator(_tree.getnullNode(), &_tree); }
			const_iterator end( void ) const { return const_iterator(_tree.getnullNode(), &_tree); }
	};
	
}

#endif
