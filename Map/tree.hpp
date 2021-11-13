/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:59:14 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/13 18:18:55 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

# include "Bidirectional_iterator.hpp"

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
         typedef value_type                                    value;              
         typedef ft_node<value_type>                           node;
         typedef Alloc                                         allocator_type;         
         typedef size_t                                        size_type;
         typedef ft::map_iterator<node, tree, value_type>      iterator;
      
      private:
         allocator_type    _Myallocator;
         
         typename Alloc::template         rebind<node>::other node_allocator;
         
         node*              _root;
         compare           _value_compare;
         size_type         _size;
         node*             _nullnode;
         
      public:
      
         tree( void ):  _root(NULL), _size(0), _nullnode(create_node(NULL)) {};
         tree( const allocator_type& alloc, const compare& comp ): _root(NULL), _size(0), _Myallocator(alloc), _value_compare(comp)
         { _nullnode = create_node(NULL); }
         tree(const tree& Cobj) : _size(0), _root(NULL), _nullnode(NULL) { *this = Cobj; };         
         ~tree(void)
         {
            if (_nullnode)
               free_node(_nullnode);
            _nullnode = NULL;
            if (_root)
               ClearRoot(_root);
            _root = NULL;
            _size = 0;
         }
         tree& operator=(const tree& cop)
         {
            if (_root)
            {
               ClearRoot(_root);
               _root = NULL;
            }
            _value_compare = cop._value_compare;
            _size = cop._size;;
            return *this;
         }
   
         void  tree_print(void) const 
         { print_helper("", _root, false); }
         void print_helper(const std::string &prefix, const node *_node, bool isLeft) const
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
               { 
                  std::cout << " : isleft(" << _node->isleftChild << ") |";
						std::cout << (isLeft ? "(R)" : "(L)") << ((!_node->isblack) ? "(Red)" : "(Black)") << std::endl;

               }
					// enter the next tree level - left and right branch
					print_helper(prefix + (isLeft ? "│   " : "    "), _node->rightChild, true);
					print_helper(prefix + (isLeft ? "│   " : "    "), _node->leftChild, false);
				}
			}
         
         size_type max_size( void ) const { return _Myallocator.max_size(); }
         
         node* lower(const key_type& k) const 
         {
            node *tmp = _root;
            node *search_n = search(k);
            if (search_n && search_n != _nullnode)
               return ( search_n );
            while (tmp)
            {
               if (_value_compare(tmp->pair->first, k))
               {
                  if (tmp->rightChild)
                     tmp = tmp->rightChild;
                  else
                     return tmp->parent;
                  continue ;
               }
               else if (_value_compare(k, tmp->pair->first))
               {
                  if (tmp->leftChild)
                     tmp = tmp->leftChild;
                  else
                     return tmp;
                  continue;
               }
            }
            return tmp;
         }

         node *upper(const key_type& k) const 
         {
            node *tmp = _root;
            node *last = getlast();
            while (tmp)
            {
               if (tmp->pair->first == k && tmp == last)
                  return (_nullnode);
               else if (tmp->pair->first != k && !tmp->rightChild && !tmp->leftChild)
                  return tmp;
               else if (_value_compare(tmp->pair->first, k))
               {
                  tmp = tmp->rightChild;
                  continue;
               }
               else if (_value_compare(k, tmp->pair->first))
               {
                  tmp = tmp->leftChild;
                  continue;
               }
               else
                  if (tmp->rightChild)
                     tmp = tmp->rightChild;
                  else
                     return (tmp->parent);
            }
            return (tmp);    
         }
         
         /////////////////////////////////// getters and sitters //////////////////////////////////

            // ------------------ setters -------------------------------
            void  setsize(size_type s) { _size = s;};
            void  setroot( node* root) { _root = root;};
            // ------------------ getters -------------------------------
            size_type getSize(void) const { return _size; }
            
            compare getvaluecomp(void) const { return _value_compare; }

            node* getroot(void) const { return _root; }
            
            node* getfirst( void ) const
            {
               node *tmp = _root;
               if (!tmp)
                  return _nullnode;
               while (tmp && tmp->leftChild)
                  tmp = tmp->leftChild;
               return tmp;
            }
            
            node* getlast( void ) const
            {
               node *tmp = _root;
               while (tmp && tmp->rightChild)
                  tmp = tmp->rightChild;
               return tmp;
            }
            
            node* getnullNode( void ) const
            { return _nullnode; }
            
			   void swap_tree (tree* x)
            {
               compare c = x->_value_compare;
               size_type size = x->_size;
               node *save = x->_root;
               allocator_type _alloc = x->_Myallocator;
      
               x->_value_compare = _value_compare;
               x->_size = _size;
               x->_root = this->_root;
               x->_Myallocator = _Myallocator;

               this->_root = save;
               _size = size;
               _value_compare = c;
               _Myallocator = _alloc;
            } 

         /////////////////////////////////// end of  getters and sitters //////////////////////////

         /////////////////////////////////// clear tree method ///////////////////////////////////
         
         void  free_node( node* del_n )
         {
            if (del_n == _root)
               _root = NULL;
            node *p = del_n->parent;
            if (del_n->pair)
            {
               _Myallocator.destroy(del_n->pair);
               _Myallocator.deallocate(del_n->pair, 1);
            }
            if (p && del_n && p->leftChild && del_n->isleftChild)
               p->leftChild = NULL;
            else if (p && del_n && p->rightChild && !del_n->isleftChild)
               p->rightChild = NULL;
            if (del_n)
            {
               del_n->pair = NULL;
               del_n->parent = NULL;
               del_n->rightChild = NULL;
               del_n->leftChild = NULL;
               node_allocator.deallocate(del_n, 1);
            }
            del_n = NULL;
         }
         
         void ClearRoot( node* del_n )
         {
            if (!del_n)
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
         
         node*  search_key( node* current, const key_type& key) const
         {
            if (!current)
               return (NULL);
            if (_value_compare(current->pair->first, key))
               return(search_key(current->rightChild, key));
             if (_value_compare(key, current->pair->first))
               return (search_key(current->leftChild, key));
            return (current);
         }
         
         node*  search(const key_type& key) const 
         {
               node *ret = search_key(_root, key);
               return ( ret ) ? ret : NULL;
         }
         
         /////////////////////////////////// end search methods  /////////////////////////////////
         
         /////////////////////////////// insert methods ///////////////////////////////////// 
         node* create_node(const value_type* val)
         {
            node *new_node = node_allocator.allocate(1);
            if (val)
               new_node->pair = _Myallocator.allocate(1);
            new_node->isblack = false;
            new_node->isleftChild = false;
            new_node->isdoubleBlack = false;
            new_node->leftChild = NULL;
            new_node->rightChild = NULL;
            new_node->parent = NULL;
            if (val)
               _Myallocator.construct(new_node->pair, *val);
            else
               new_node->pair = NULL;
            return new_node;
         }
         
         void  rightRotation(node* Gp_node)
         {
            node *tmp = Gp_node->leftChild;
            Gp_node->leftChild = tmp->rightChild;
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
                  tmp->parent->rightChild = tmp;
               }
            }
            tmp->rightChild = Gp_node;
            Gp_node->isleftChild = false;
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
                  if (_node->rightChild)
                     _node->rightChild->isblack = false;
                  if (_node->leftChild)
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
                  if (_root != _node->parent->parent)
                     _node->parent->parent->isblack = false;
                  _node->parent->isblack = true;
                  return ;
               }
            else
               if (_node->parent->parent->leftChild == NULL || _node->parent->parent->leftChild->isblack) // if uncle is black = go to rotate
                  return rotate(_node);
               else
               {
                  _node->parent->parent->leftChild->isblack = true;
                  if (_root != _node->parent->parent)
                     _node->parent->parent->isblack = false;
                  _node->parent->isblack = true;
                  return ;
               }
         }
      
         
         void  checkcolor(node* _node)
         {
            if ( !_node || _node == _root)
               return ;
            if (_node && !_node->isblack && _node->parent && !_node->parent->isblack)
               FixTree(_node);
            return (checkcolor(_node->parent));
         }


         pair<iterator, bool>  add_node(  node* current, node* new_node )
         {
            if (current && _value_compare(current->pair->first, new_node->pair->first))
            {
               if (!current->rightChild)
               {
                  current->rightChild = new_node;
                  new_node->parent = current;
                  new_node->isleftChild = false;
                  _size++;              
                  checkcolor(new_node);
                  // std::cout << "key = [ " << current->pair->first << " ] ||| isleftChild = [ " << current->isleftChild << " ] " <<std::endl;
                  return (ft::make_pair(iterator(new_node, this), true));
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
                  // std::cout << "key = [ " << current->pair->first << " ] ||| isleftChild = [ " << current->isleftChild << " ] " <<std::endl;
                  return (ft::make_pair(iterator(new_node, this), true));
               }
               return (add_node(current->leftChild, new_node));
            }
            _Myallocator.deallocate(new_node->pair, 1);
            node_allocator.deallocate(new_node, 1);
            return (ft::make_pair(iterator(current, this), false));
         }
         
         
         // void  insert(const value_type& val)
         pair<iterator,bool>  insert(const value_type& val)
         {
            if (!_root)
            {
               _root = create_node(&val);
               _root->isblack = true;
               _size++;
               return (ft::make_pair(iterator(_root, this), true));
            }
            _root->isblack = true;
            pair<iterator,bool> it = add_node(_root, create_node(&val));
            
            _root->isblack = true;
            return it;
         }
         
         /////////////////////////////////// end methods insert //////////////////////////////////    
   };
}

#endif