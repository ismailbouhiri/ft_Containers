/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:59:14 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/31 11:44:08 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

# include "iterator.hpp"

template<class T>
struct ft_node 
{
   T  *pair;
   bool isblack;
   bool isleftChild;
   struct ft_node *parent;
   struct ft_node *leftChild;
   struct ft_node *rightChild;
};

namespace ft
{   
   template <class value_type, class Alloc, class compare>
   class rbt
   {
      public:
         typedef ft_node<value_type>   node;
         typedef Alloc                 allocator_type;         
         typedef size_t                size_type;
      
      private:
         allocator_type    _Myallocator;
         
         typename Alloc::template         rebind<node>::other node_allocator;
         
         node              *_root;
         compare           _value_compare;
         size_type         _size;
         
      public:
      
         rbt( void ): _size(0), _root(nullptr)  {};
         rbt( const allocator_type& alloc, const compare& comp ): _size(0), _root(nullptr), _Myallocator(alloc), _value_compare(comp) {};
         rbt(const rbt& Cobj) : _size(0), _root(nullptr)
         { *this = Cobj; };
         
         node& create_node(const value_type& val)
         {
            node *new_node = node_allocator.allocate(1);
            new_node->pair = _Myallocator.allocate(1);
            
            new_node->isblack = false;
            new_node->isleftChild = false;
            new_node->leftChild = nullptr;
            new_node->rightChild = nullptr;
            new_node->parent = nullptr;
            _Myallocator.construct(new_node->pair, val);
            return *new_node;
         }

         void  FixTree(node& _node)
         {
            if (_node->parent->isleftChild)
               if (_node->parent->parent->rightChild == nullptr || _node->parent->parent->rightChild->isblack)
                  return rotate(_node);
               else
               {
                  _node->parent->parent->rightChild->isblack = true;
                  _node->parent->parent->isblack = false;
                  _node->parent->isblack = true;
                  return ;
               }
            else
               if (_node->parent->parent->leftChild == nullptr || _node->parent->parent->leftChild->isblack)
                  return rotate(_node);
               else
               {
                  _node->parent->parent->leftChild->isblack = true;
                  _node->parent->parent->isblack = false;
                  _node->parent->isblack = true;
                  return ;
               }
         }
      
         
         void  checkcolor(node& _node)
         {
            if (_node == _root)
               return ;
            if (!_node->isblack && !_node->parent->isblack)
               FixTree(_node);
            checkcolor(_node->parent);
         }


         
         void treebalance(node& new_node)
         {
            checkcolor(new_node);
         }
         
         pair<std::iterator,bool>  add_node( const node& current, const node& new_node )
         {
            if (_value_compare(current->pair, new_node->pair))
            {
               if (!current->rightChild)
               {
                  current->rightChild = new_node;
                  new_node->parent = current;
                  _size++;
                  treebalance(new_node);
                  return (make_pair(iterator(current), true));
               }
               return (add_node(current->rightChild, new_node));
            }
            else if (_value_compare(new_node->pair, current->pair))
            {
               if (!current->leftChild)
               {
                  current->leftChild = new_node;
                  new_node->parent = current;
                  new_node->isleftChild = true;
                  _size++;
                  treebalance(new_node);
                  return (make_pair(iterator(current), true));
               }
               return (add_node(current->leftChild, new_node));
            }
            _Myallocator.deallocate(new_node->pair, 1);
            node_allocator.deallocate(new_node, 1);
            return (make_pair(iterator(current), false));
         }
         
         pair<std::iterator,bool>  insert(const value_type& val)
         {
            if (!_root)
            {
               _root = create_node(val);
               _root->isblack = true;
               _size++;
               return (make_pair(iterator(_root), true));
            }
            return ( add_node(_root, create_node(val)) );
         }
   };
}

#endif