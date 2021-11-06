/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:59:14 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/06 18:46:12 by ibouhiri         ###   ########.fr       */
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
   bool isdoubleBlack;
   struct ft_node *parent;
   struct ft_node *leftChild;
   struct ft_node *rightChild;
};

namespace ft
{   
   template <class value_type, class Alloc, class compare, class key_type>
   class tree
   {
      public:                  
         typedef ft_node<value_type>               node;
         typedef Alloc                             allocator_type;         
         typedef size_t                            size_type;
      
      private:
         allocator_type    _Myallocator;
         
         typename Alloc::template         rebind<node>::other node_allocator;
         
         node*              _root;
         compare           _value_compare;
         size_type         _size;
         
      public:
      
         tree( void ): _size(0), _root(NULL) {};
         tree( const allocator_type& alloc, const compare& comp ): _size(0), _root(NULL), _Myallocator(alloc), _value_compare(comp) {};
         tree(const tree& Cobj) : _size(0), _root(NULL)
         { *this = Cobj; };
         ~tree(void)
         {
            if (_root)
               ClearRoot(_root);
            _root = NULL;
         }
         
         size_type getSize(void)
         {
            return _size;
         }
         
         void  tree_print(void)
         {
            print_helper("", _root, false);
         }
         void print_helper(const std::string &prefix, const node *_node, bool isLeft)
			{
				if (_node != NULL)
				{
					std::cout << prefix;

					std::cout << (isLeft ? "├──" : "└──");

					// print the value of the _node
					std::cout << _node->pair->first << " ";

					if (_node == this->_root)
						std::cout << "(Root)" << std::endl;
					else
						std::cout << (isLeft ? "(R)" : "(L)") << ((!_node->isblack) ? "(Red)" : "(Black)") << std::endl;
					// enter the next tree level - left and right branch
					print_helper(prefix + (isLeft ? "│   " : "    "), _node->rightChild, true);
					print_helper(prefix + (isLeft ? "│   " : "    "), _node->leftChild, false);
				}
			}
         
         /////////////////////////////////// clear tree method ///////////////////////////////////
         
         void  free_node( node* del_n )
         {
            if (del_n == _root)
               _root = NULL;
            node *p = del_n->parent;
            // _Myallocator.destroy(del_n->pair);
            if (p && del_n->isleftChild)
               p->leftChild = NULL;
            else if (p && !del_n->isleftChild)
               p->rightChild = NULL;
            _Myallocator.deallocate(del_n->pair, 1);
            del_n->pair = NULL;
            del_n->parent = NULL;
            del_n->rightChild = NULL;
            del_n->leftChild = NULL;
            node_allocator.deallocate(del_n, 1);
            del_n = NULL;
            // std::cout << " add = " << _root << "   add = " << del_n << std::endl;
         }
         
         void ClearRoot( node* del_n )
         {
            if (del_n)
               return ;

            ClearRoot(del_n->leftChild);
            ClearRoot(del_n->rightChild);

            free_node(del_n);
         }

         ///////////////////////////////////clear tree method end /////////////////////////////////////

         /////////////////////////////////// DELETE method ///////////////////////////////////////
         
         // fonction check if the far sibling child of _n is black and near sibling child of _n is red
         bool      IfFarCSBNearCSR(const node* _n, const node* sibling)
         {
            if (_n->isleftChild)
               return ((!sibling->rightChild || sibling->rightChild->isblack)
               && sibling->leftChild && !sibling->leftChild->isblack);
            if (!_n->isleftChild)
               return ((!sibling->leftChild || sibling->leftChild->isblack)
               && sibling->rightChild && !sibling->rightChild->isblack);
            return false;
         }

         
         node*     getSibling( node* _n)
         {
            if (_n != _root)
            {
               if (_n->isleftChild)
                  return (_n->parent->rightChild);
               if (!_n->isleftChild)
                  return ( _n->parent->leftChild );
            }
            else if (_n == _root)
            {
               if (_n->rightChild && _n->rightChild->isdoubleBlack)
                  return _n->leftChild;
               if (_n->leftChild && _n->leftChild->isdoubleBlack)
                  return _n->rightChild;
            }        
            return _n;
         }

         
         node*    getNodeInOrderSuccessor( node* _n)
         {
            node  *tmp;
            if (!_n->rightChild)
               return NULL;
            tmp = _n->rightChild;
            while (tmp && tmp->leftChild)
               tmp = tmp->leftChild;
            return tmp;
         }

         node*    getNodeInOrderPredecessor(const node* _n)
         {
            node  *tmp;
            if (!_n->leftChild)
               return NULL;
            tmp = _n->leftChild;
            while (tmp && tmp->rightChild)
               tmp = tmp->rightChild;
            return tmp;
         }
         
         node* getLeaf(node* del_node)
         {
            if (!del_node->leftChild && !del_node->rightChild)
               return del_node;
            node *leaf = getNodeInOrderPredecessor(del_node);
            if (!leaf)
               leaf = getNodeInOrderSuccessor(del_node);
            // swap value of the del_node and leaf
            if (leaf)
            {
               _Myallocator.destroy(del_node->pair);
               _Myallocator.construct(del_node->pair, *(leaf->pair));
            }
            return (getLeaf(leaf));
         }

         void delete_helper( node* del_n )
         {
            node *sibling = getSibling(del_n);
            
            // if the node is leaf and red node  /// case 1
            if (!del_n->isblack && !del_n->rightChild && !del_n->leftChild)
               return ;

           // if doubleBlack in root = i remove double black // case 2
            if (del_n == _root && del_n->isdoubleBlack)
            {
               // if (!del_n->rightChild && !del_n->leftChild)
               //    return ;
               del_n->isdoubleBlack = false;
               return ; 
            }
            
            /// if the del_n doubleblack and sibling is black, his children black too // case 3
            if (sibling && del_n && del_n->isdoubleBlack && sibling->isblack && 
            ( !sibling->rightChild || sibling->rightChild->isblack ) && ( !sibling->leftChild || sibling->leftChild->isblack ))
            {
               if (del_n->parent->isblack)
               {
                  del_n->isdoubleBlack = false;
                  del_n->parent->isdoubleBlack = true;
                  sibling->isblack = false;
                  delete_helper(del_n->parent);
                  return ;
               }
               if (!del_n->parent->isblack)
               {
                  del_n->isdoubleBlack = false;
                  del_n->parent->isblack = true;
                  sibling->isblack = false;
                  return ;
               }
            }
            
            // if db's sibling is red /// case 4
            if (del_n && sibling && del_n->isdoubleBlack && !sibling->isblack)
            {
               sibling->isblack = true;
               del_n->parent->isblack = false;
               if (del_n->isleftChild)
                  leftRotation(del_n->parent);
               else
                  rightRotation(del_n->parent);
               delete_helper(del_n);
               return ;
            }
            
            // if db's sibling is black , and his child who is far from db is black but near child to db's is red // case 5
            if ( del_n && sibling && del_n->isdoubleBlack && sibling->isblack && IfFarCSBNearCSR(del_n, sibling))
            {
               sibling->isblack = false;
               if (del_n->isleftChild)
               {
                  sibling->leftChild->isblack = true;
                  rightRotation(sibling);
               }
               else
               {
                  sibling->rightChild->isblack = true;
                  leftRotation(sibling);
               }
               delete_helper(del_n);
               return ;
            }
            // case 6 :: it opposite of case 5;
            if ( del_n && sibling && del_n->isdoubleBlack && sibling->isblack && !IfFarCSBNearCSR(del_n, sibling))
            {
               del_n->isdoubleBlack = false;
               if (del_n->isleftChild)
               {
                  if (sibling->rightChild)
                     sibling->rightChild->isblack = true;
                  leftRotation(del_n->parent);
               }
               else
               {
                  if (sibling->leftChild)
                     sibling->leftChild->isblack = false;
                  rightRotation(del_n->parent);
               }
               return ;
            }
         }

         size_type deleteNode (const key_type& key)
         {
            node *del_node = search_key(_root, key);
            if (del_node)
            {
               del_node = getLeaf(del_node); // get leaf
               del_node->isdoubleBlack = ( del_node->isblack ) ? true : false; // if node is black it became double black
               node *save = del_node;
               delete_helper(del_node);
               free_node(save);
               _size--;
            }
            return ( _size );
         }
         /////////////////////////////////// end DELETE methods  /////////////////////////////////

         /////////////////////////////////// search method ///////////////////////////////////////
         
         node*  search_key( node* current, const key_type& key)
         {
            if (!current)
               return (NULL);
            if (_value_compare(current->pair->first, key))
               return(search_key(current->rightChild, key));
             if (_value_compare(key, current->pair->first))
               return (search_key(current->leftChild, key));
            return (current);
         }
         
         node&  search(const key_type& key)
         {
               node *ret = search_key(_root, key);
               return ((ret) ? ret : NULL);
         }
         
         /////////////////////////////////// end search methods  /////////////////////////////////
         
         /////////////////////////////// insert methods ///////////////////////////////////// 
         node* create_node(const value_type& val)
         {
            node *new_node = node_allocator.allocate(1);
            new_node->pair = _Myallocator.allocate(1);
            
            new_node->isblack = false;
            new_node->isleftChild = false;
            new_node->isdoubleBlack = false;
            new_node->leftChild = NULL;
            new_node->rightChild = NULL;
            new_node->parent = NULL;
            _Myallocator.construct(new_node->pair, val);
            return new_node;
         }
         
         void  rightRotation(node* Gp_node)
         {
            node *tmp = Gp_node->leftChild;
            Gp_node->leftChild = tmp->leftChild;
            if (Gp_node->leftChild)
            {
               Gp_node->leftChild->parent = Gp_node;
               Gp_node->leftChild->isleftChild = false;
            }
            if (Gp_node->parent == NULL) {
               _root = tmp;
               tmp->parent = NULL;
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

         void  leftRotation(node* Gp_node)
         {
            node *tmp = Gp_node->rightChild;
            Gp_node->rightChild = tmp->leftChild;
            if (Gp_node->rightChild)
            {
               Gp_node->rightChild->parent = Gp_node;
               Gp_node->rightChild->isleftChild = false;
            }
            if (Gp_node->parent == NULL) {
               _root = tmp;
               tmp->parent = NULL;
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
         void  rotate(node* _node)
         {
            if (_node->isleftChild)
               if (_node->parent->isleftChild)
               {
                  rightRotation(_node->parent->parent);
                  _node->isblack = false;
                  _node->parent->isblack = true;
                  if (_node->parent->rightChild)
                     _node->parent->rightChild->isblack = false;
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
               if (!_node->parent->isleftChild)
               {
                  leftRotation(_node->parent->parent);
                  _node->isblack = false;
                  _node->parent->isblack = true;
                  if (_node->parent->leftChild)
                     _node->parent->leftChild->isblack = false;
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
         
         void  FixTree(node* _node)
         {
            if (_node->parent->isleftChild)
               if (_node->parent->parent->rightChild == NULL || _node->parent->parent->rightChild->isblack)
                  return rotate(_node);
               else
               {
                  _node->parent->parent->rightChild->isblack = true;
                  _node->parent->parent->isblack = false;
                  _node->parent->isblack = true;
                  return ;
               }
            else
               if (_node->parent->parent->leftChild == NULL || _node->parent->parent->leftChild->isblack) // if aunt is black = go to rotate
                  return rotate(_node);
               else
               {
                  _node->parent->parent->leftChild->isblack = true;
                  _node->parent->parent->isblack = false;
                  _node->parent->isblack = true;
                  return ;
               }
         }
      
         
         void  checkcolor(node* _node)
         {
            if (_node == _root)
               return ;
            if (_node && !_node->isblack && _node->parent && !_node->parent->isblack)
            {
               // if (_node->pair->first == 5)
               //    std::cout << "_node->parent->isblack = true; "  << _node->parent->isblack << std::endl;
               FixTree(_node);
            }
            return (checkcolor(_node->parent));
         }

         // pair<std::iterator,bool>  add_node( const node& current, const node& new_node )

         void add_node( node* current, node* new_node )
         {
            if (current && _value_compare(current->pair->first, new_node->pair->first))
            {
               // std::cout << "current = " << current->pair->first << "        " << new_node->pair->first<< std::endl;
               if (!current->rightChild)
               {
                  current->rightChild = new_node;
                  new_node->parent = current;
                  new_node->isleftChild = false;
                  _size++;              
                  checkcolor(new_node);
                  // return (make_pair(iterator(current), true));
                  return ;
               }
               return (add_node(current->rightChild, new_node));
            }
            if (current && _value_compare(new_node->pair->first, current->pair->first))
            {
               if (!current->leftChild)
               {
                  current->leftChild = new_node;
                  new_node->parent = current;
                  new_node->isleftChild = true;
                  _size++;
                  checkcolor(new_node);
                  // return (make_pair(iterator(current), true));
                  return ;
               }
               return (add_node(current->leftChild, new_node));
            }
            _Myallocator.deallocate(new_node->pair, 1);
            node_allocator.deallocate(new_node, 1);
            // return (make_pair(iterator(current), false));
            return ;
         }
         
         // pair<std::iterator,bool>  insert(const value_type& val)
         
         void  insert(const value_type& val)
         {
            if (!_root)
            {
               _root = create_node(val);
               _root->isblack = true;
               _size++;
               // return (make_pair(iterator(_root), true));
               return ;
            }
            _root->isblack = true;
            add_node(_root, create_node(val));
            _root->isblack = true;
         }
         
         /////////////////////////////////// end methods insert //////////////////////////////////    
   };
}

#endif