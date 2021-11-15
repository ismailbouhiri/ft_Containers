/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:05:20 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/15 10:09:21 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "../Vector/vector.hpp"
# include "Bidirectional_iterator.hpp"
# include "tree.hpp"
# include "../tools/tools.hpp"
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>


namespace ft 
{
	
	template < class Key,                                     // map::key_type
           class value,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator< ft::pair <const Key,value> >    // map::allocator_type
           > 
	class Map
	{
		public :
		// typedefs .....
			typedef Key															key_type;
			typedef value														mapped_type;
			typedef	ft::pair<const key_type, mapped_type> 						value_type;
			typedef Compare														key_compare;
			typedef class value_comp: public std::binary_function <value_type,value_type, bool>
			{
				friend class Map;
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
         	typedef ft_node<value_type>                         							node;
			typedef tree<value_type, allocator_type, key_compare, key_type> 				tree_type;
			typedef	ft::map_iterator<node, tree_type, value_type>							iterator;
			typedef	ft::map_iterator<node, tree_type, const value_type>						const_iterator;
			typedef	ft::reverse_iterator<iterator>											reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>									const_reverse_iterator;
		private:
			key_compare _compare;
			allocator_type _allocator;
			tree_type _tree;
		public :

			/////////////// members fonction //////////////////
			
			explicit Map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _allocator(alloc){};	
			
			template <class InputIterator>
			Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _allocator(alloc)
			{
				for (;first != last; first++)
				{
					_tree.insert(*first);
				}
			}
			
			Map (const Map& x)
			{
				_tree = x._tree;
				Map *y = const_cast<Map*>(&x);
				if (y->_tree.getSize() > 0)
				{
					_tree.setsize(0);
					insert(y->begin(), y->end());
				}
			}

			Map& operator= (const Map& x)
			{
				_tree = x._tree;
				Map *y = const_cast<Map*>(&x);
				if (_tree.getSize() > 0)
				{
					_tree.setsize(0);
					insert(y->begin(), y->end());
				}
		
				return *this;
			}		
			
			~Map( void )
			{};
			
			//////////////// end of members fonction ////////////

			//////////////// iterators of map //////////// 

			iterator begin( void ) { return iterator(_tree.getfirst(), &_tree); }
			iterator end( void ) { return iterator(_tree.getnullNode(), &_tree); }
			reverse_iterator rbegin( void ) { return reverse_iterator(end()); };
			reverse_iterator rend() { return reverse_iterator(begin()); };
			
			const_iterator begin( void ) const
			{ return const_iterator(_tree.getfirst(), const_cast<tree_type*>(&_tree)); }
			const_iterator end( void ) const
			{ return const_iterator(_tree.getnullNode(), const_cast<tree_type*>(&_tree)); }
			const_reverse_iterator rbegin( void ) const { return const_reverse_iterator(end()); };
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

			//////////////// end iterators of map ////////////

			bool empty( void ) const { return !_tree.getSize(); };
			
			size_type size( void ) const { return _tree.getSize(); } 
			
			size_type max_size( void ) const { return _allocator.max_size();};

			/////////////// Capacity //////////////////////////
			
			mapped_type& operator[] (const key_type& k)
			{
				return (*((_tree.insert(ft::make_pair(k,mapped_type()))).first)).second;
			}


			//////////////// Access Element /////////////



			///////////////////////// Modifiers: ////////////// 

			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
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
				size_type s = _tree.getSize();
				_tree.deleteNode(k);
				return s - _tree.getSize();
				
			}

			void erase (iterator first, iterator last)
			{
				if (_tree.getSize() > 0)
				{
					ft::vector<key_type> keys;			
					for (; first != last; first++)
					{
						keys.push_back(first->first);
					}
					
					for (size_type i = 0; i < keys.size(); i++)
						_tree.deleteNode(keys[i]);
				}
				
			}
			
			void swap (Map& x)
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
			{
				node *ret = _tree.search(k);
				if (ret)
					return iterator(ret, const_cast<tree_type*>(&_tree));
				return iterator(_tree.getnullNode(), const_cast<tree_type*>(&_tree)); 
			}

			const_iterator find (const key_type& k) const
			{
				node *ret = _tree.search(k);
				if (ret)
					return const_iterator(ret, const_cast<tree_type*>(&_tree));
				return const_iterator(_tree.getnullNode(), const_cast<tree_type*>(&_tree)); 
			}

			size_type count (const key_type& k) const
			{
				node *ret = this->_tree.search(k);
				if (ret)
					return (1);
				return (0);		
			}

			iterator lower_bound (const key_type& k)
			{ return iterator(_tree.lower(k), &_tree); }
			iterator upper_bound (const key_type& k)
			{ return iterator(_tree.upper(k), &_tree); }
			
			const_iterator lower_bound (const key_type& k) const
			{ return const_iterator(_tree.lower(k),  const_cast<tree_type*>(&_tree)); }
			const_iterator upper_bound (const key_type& k) const
			{ return const_iterator(_tree.upper(k),  const_cast<tree_type*>(&_tree)); }
			
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{ return ft::make_pair(lower_bound(k),upper_bound(k)); }
			pair<iterator,iterator>             equal_range (const key_type& k)
			{ return ft::make_pair(lower_bound(k),upper_bound(k)); }
			//////////////////// end Operations: ///////////////
			
			
			//////////////////////// allocator /////////////////
			allocator_type get_allocator() const
			{ return _allocator; }

			//////////////////////// end of allocator /////////////////

			void print_h(void) const 
			{
				_tree.tree_print();
			}
	template <class k, class T, class c, class a>
	friend bool operator< ( const Map<k,T,c,a>& l, const Map<k,T,c,a>& r );
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs )
	{ return ( lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()) ); }
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs )
	{ return !( lhs == rhs ); }
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator< ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs )
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs )
	{ return !( rhs < lhs ); }
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs )
	{ return (rhs < lhs); }
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs )
	{ return !( lhs < rhs ); }
	
	template <class Key, class T, class Compare, class Alloc>
  	void swap (Map<Key,T,Compare,Alloc>& x, Map<Key,T,Compare,Alloc>& y)
	{ x.swap(y); }

}

#endif
