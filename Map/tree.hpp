/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:59:14 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/01 19:14:40 by ibouhiri         ###   ########.fr       */
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
         
         /////////////////////////////// insert methods ///////////////////////////////////// 
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
         
         void  rightRotation(node& Gp_node)
         {
            node *tmp = Gp_node->leftChild;
            Gp_node->leftChild = tmp->leftChild;
            if (Gp_node->leftChild)
            {
               Gp_node->leftChild->parent = Gp_node;
               Gp_node->leftChild->isleftChild = false;
            }
            if (Gp_node->parent == nullptr) {
               _root = tmp;
               tmp->parent = nullptr;
            } else {
               tmp->parent = Gp_node->parent;
               if (Gp_node->isleftChild) {
                  tmp->isleftChild = true;
                  tmp->parent->leftChild = tmp;
               }
               else {
                  tmp->isleftChild = false;
                  tmp->parent->leftChild = tmp;
               }
            }
            tmp->leftChild = Gp_node;
            Gp_node->isleftChild = true;
            Gp_node->parent = tmp;         
         }

         void  leftRotation(node& Gp_node)
         {
            node *tmp = Gp_node->rightChild;
            Gp_node->rightChild = tmp->leftChild;
            if (Gp_node->rightChild)
            {
               Gp_node->rightChild->parent = Gp_node;
               Gp_node->rightChild->isleftChild = false;
            }
            if (Gp_node->parent == nullptr) {
               _root = tmp;
               tmp->parent = nullptr;
            } else {
               tmp->parent = Gp_node->parent;
               if (Gp_node->isleftChild) {
                  tmp->isleftChild = true;
                  tmp->parent->leftChild = tmp;
               }
               else {
                  tmp->isleftChild = false;
                  tmp->parent->rightChild = tmp;
               }
            }
            tmp->leftChild = Gp_node;
            Gp_node->isleftChild = true;
            Gp_node->parent = tmp;
         }
         void  rotate(node& _node)
         {
            if (_node->isleftChild)
               if (_node->parent->isleftChild)
               {
                  rightRotation(_node->parent->parent);
                  _node->isblack = false;
                  _node->parent->isblack = true;
                  if (_node->parent->rightChild)
                     _node->parent->rightChild->isblackChild = false;
               }
               else
               {
                  rightRotation(_node->parent);
                  leftRotation(_node->parent);
                  _node->isblack = true;
                  _node->rightChild->isblack = false;
                  _node->leftChild->isblack = false;
               }
            else
               if (_node->parent->isleftChild)
               {
                  leftRotation(_node->parent->parent);
                  _node->isblack = false;
                  _node->parent->isblack = true;
                  if (_node->parent->rightChild)
                     _node->parent->rightChild->isblackChild = false;
               }
               else
               {
                  leftRotation(_node->parent);
                  rightRotation(_node->parent);
                  _node->isblack = true;
                  _node->rightChild->isblack = false;
                  _node->leftChild->isblack = false;
               }
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

         pair<std::iterator,bool>  add_node( const node& current, const node& new_node )
         {
            if (_value_compare(current->pair, new_node->pair))
            {
               if (!current->rightChild)
               {
                  current->rightChild = new_node;
                  new_node->parent = current;
                  _size++;
                  checkcolor(new_node);
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
                  checkcolor(new_node);
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
         /////////////////////////////////// end methods insert //////////////////////////////////
         
         /////////////////////////////////// search method ///////////////////////////////////////
         
         node  search(const value_type& )
         
         /////////////////////////////////// end search methods  /////////////////////////////////
         
   };
}

#endif