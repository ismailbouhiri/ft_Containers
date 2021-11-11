/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:43:39 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/10 10:28:27 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
	
	template <class T1, class T2> 
	struct pair
	{
		typedef T1		first_type;
		typedef T2		second_type;
		first_type first;
		second_type second;
		pair( void ) : first(), second() {};
		template<class U, class V> 
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
		
		pair (const first_type& a, const second_type& b) : first(a), second(b) {};
		
		pair& operator= (const pair& pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		};
	};
	
	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{ 
		return pair<T1, T2>(x,y); 
	};
	
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs == rhs); };

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return (lhs.first < rhs.first && lhs.second < rhs.second); };
	
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return ( lhs == rhs || lhs < rhs ); };
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs <= rhs); };
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs < rhs); };
	
	
	template < class node, class tree_type, class pair>
	class iterator : public std::iterator<std::bidirectional_iterator_tag, pair>
	{
		public :
			
			typedef node		value_type;
			typedef node&		reference_type;
			typedef node*		pointer_type;
		private:
			pointer_type	iter;
			tree_type		*_tree;
		public :

			iterator( void ) : iter(nullptr), _tree(nullptr){}
			iterator( pointer_type it,  tree_type* tree ) : iter(it), _tree(tree) {}
			iterator( const iterator& CopyIter) : iter(CopyIter.iter), _tree(CopyIter._tree) {}
			// iterator( const iterator& CopyIter) {*this = CopyIter;}
			iterator& operator=( const iterator& it)
			{
				this->iter = it.iter;
				_tree = it._tree;
				return *this;
			};
			
			~iterator( void ){};
			operator iterator<node, tree_type, const pair>() const { return iterator<node, tree_type, const pair>(iter, _tree); }

			bool operator==(const iterator& it) const { return this->iter == it.iter; };
			bool operator!=(const iterator& it) const { return this->iter != it.iter; };
			pair&	operator*(void) const { return *(iter->pair); };
			pair*	operator->(void) const { return iter->pair; };
			iterator	operator++(int)
			{
				iterator old(*this);
				if (iter == _tree->getlast())
					iter = _tree->getnullNode();
				else if (iter->isleftChild && !iter->leftChild && !iter->rightChild)
					iter = iter->parent;
				else if (iter->rightChild)
					iter = _tree->getNodeInOrderSuccessor(iter);
				else if (!iter->isleftChild && !iter->leftChild && !iter->rightChild)
				{
					while (!iter->isleftChild)
						iter = iter->parent;
					iter = iter->parent;
				}
				return old;
			};

			iterator 	&operator++(void)
			{
				if (iter == _tree->getlast())
					iter = _tree->getnullNode();
				else if (iter->isleftChild && !iter->leftChild && !iter->rightChild)
					iter = iter->parent;
				else if (iter->rightChild)
					iter = _tree->getNodeInOrderSuccessor(iter);
				else if (!iter->isleftChild && !iter->leftChild && !iter->rightChild)
				{
					while (!iter->isleftChild)
						iter = iter->parent;
					iter = iter->parent;
				}
				return *this;
			};

			iterator 	operator--(int)
			{ 
				iterator old(*this);
				if (iter == _tree->getnullNode())
					iter = _tree->getlast();
				else if (iter->leftChild)
					iter = _tree->getNodeInOrderPredecessor(iter);
				else if (!iter->isleftChild)
					iter = iter->parent;
				else if (iter->isleftChild && !iter->leftChild && !iter->rightChild)
				{
					while (iter->isleftChild)
						iter = iter->parent;
					iter = iter->parent;
				}
				else
					iter = iter->leftChild;
				return old; 
			};

			iterator 	&operator--(void)
			{
				if (iter == _tree->getnullNode())
					iter = _tree->getlast();
				else if (iter->leftChild)
					iter = _tree->getNodeInOrderPredecessor(iter);
				else if (!iter->isleftChild)
					iter = iter->parent;
				else if (iter->isleftChild && !iter->leftChild && !iter->rightChild)
				{
					while (iter->isleftChild)
						iter = iter->parent;
					iter = iter->parent;
				}
				else
					iter = iter->leftChild;
				return *this;
			};
	};
}

#endif