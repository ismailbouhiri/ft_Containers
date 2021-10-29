/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:59:14 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/29 18:38:02 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

# include "iterator.hpp"

#define black 0
#define red 1

template<class T>
struct ft_node 
{
   T  *_Ptr;
   int color;
   struct ft_node *parent;
   struct ft_node *leftChild;
   struct ft_node *rightChild;
};

// template < class Key, class value, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> >> 
// class tree 
// {
   
// }
// node *root;
// template <class key, class value>
// void  insert_Node(ft::pair<key, value> pairs)
// {
   
// }

#endif