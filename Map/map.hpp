/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:05:20 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/11 16:52:03 by ibouhiri         ###   ########.fr       */
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
				{   return comp(x.first, y.first); };
			}																				value_compare;
			typedef Alloc																	allocator_type;
			typedef typename allocator_type::reference										reference;
			typedef typename allocator_type::const_reference								const_reference;
			typedef typename allocator_type::pointer										pointer;
			typedef typename allocator_type::const_pointer									const_pointer;
			typedef typename allocator_type::difference_type								difference_type;
			typedef typename allocator_type::size_type										size_type;
			typedef tree<value_type, allocator_type, key_compare, key_type> 				tree_type;
			typedef	ft::iterator<ft_node<value_type>, tree_type, value_type>				iterator;
			typedef	ft::iterator<ft_node<value_type>, tree_type, const value_type>			const_iterator;
			typedef	ft::reverse_iterator<iterator>											reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>									const_reverse_iterator;
		private:
			key_compare _compare;
			allocator_type _allocator;
			tree_type _tree;
		public :

			/////////////// members fonction //////////////////
			
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _allocator(alloc){};	
			
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _allocator(alloc)
			{
				for (;first != last; first++)
					_tree.insert(*first);
			}
			
			map (const map& x)
			{
				_tree = x._tree;
				map *y = const_cast<map*>(&x);
				if (y->_tree.getSize() > 0)
				{
					_tree.setsize(0);
					insert(y->begin(), y->end());
				}
			}

			map& operator= (const map& x)
			{
				_tree = x._tree;
				map *y = const_cast<map*>(&x);
				if (_tree.getSize() > 0)
				{
					_tree.setsize(0);
					insert(y->begin(), y->end());
				}
		
				return *this;
			}		
			
			~map( void )
			{};
			
			//////////////// end of members fonction ////////////

			//////////////// iterators of map //////////// 

			iterator begin( void ) { return iterator(_tree.getfirst(), &_tree); }
			iterator end( void ) { return iterator(_tree.getnullNode(), &_tree); }
			
			const_iterator begin( void ) const  { return const_iterator(_tree.getfirst(), &_tree); }
			const_iterator end( void ) const { return const_iterator(_tree.getnullNode(), &_tree); }

			reverse_iterator rbegin( void ) { return reverse_iterator(end()); };
			reverse_iterator rend() { return reverse_iterator(begin()); };
			
			const_reverse_iterator rbegin( void ) const { return const_reverse_iterator(end()); };
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

			//////////////// end iterators of map ////////////

			bool empty( void ) const { return !_tree.getSize(); };
			
			size_type size( void ) { return _tree.getSize(); }
			
			size_type max_size( void ) const { return _allocator.max_size();};

			/////////////// Capacity //////////////////////////
			
			mapped_type& operator[] (const key_type& k)
			{
				return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
				// iterator it = this->insert(make_pair(k,mapped_type())).first;
				// std::cout << it->first << std::endl;
				// return it->second;
			}


			//////////////// Access Element /////////////



			///////////////////////// Modifiers: ////////////// 

			iterator insert (iterator position, const value_type& val)
			{
				return this->_tree.insert(val).first;
			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
					_tree.insert(*(first++));						
			}

			ft::pair<iterator,bool>	insert (const value_type& val)
			{
				return this->_tree.insert(val);
			}
			
			void erase (iterator position)
			{
				_tree.deleteNode(position->first);
			}

			size_type erase (const key_type& k)
			{
				return (_tree.deleteNode(k));
			}

			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					_tree.deleteNode(first->first);
					first++;
				}
			}
			
			void swap (map& x)
			{
				_tree.swap_tree(&x._tree);
			}

			void clear( void )
			{
				_tree.ClearRoot(_tree.getroot());
				_tree.setsize(0);
			}
			//////////////////// end Modifiers: ///////////////

			/////////////////////////// Observers: ////////////

			key_compare key_comp() const { return _tree.getvaluecomp(); }
			
			value_compare value_comp() const { return _tree.getvaluecomp(); }
			//////////////////// end Observers: ///////////////
			

			///////////////////// Operations: /////////////////

			iterator find (const key_type& k) 
			{ return iterator(_tree.search(k), &_tree); }

			const_iterator find (const key_type& k) const
			{ return const_iterator(_tree.search(k), &_tree); }

			// size_type count (const key_type& k) const
			// {
				
			// }


			//////////////////// end Operations: ///////////////
			// void print_h(void)
			// {
			// 	_tree.tree_print();
			// }
	};
	
}

#endif
