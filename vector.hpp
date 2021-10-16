/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:30:18 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/16 11:36:36 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
            
namespace ft
{   
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public :
        // typedefs
        typedef T                                            value_type;
        typedef Alloc                                        allocator_type;
        typedef typename allocator_type::reference           reference;
        typedef typename allocator_type::const_reference     const_reference;
        typedef typename allocator_type::size_type           size_type;
        typedef typename allocator_type::difference_type     difference_type;
        typedef typename allocator_type::pointer             pointer;
        typedef typename allocator_type::const_pointer       const_pointer;
        // typedef ft::reverse_iterator<std::iterator>           reverse_iterator;
        // typedef ft::reverse_iterator<std::const_iterator>     const_reverse_iterator;

        private :
         // private thinks
            T               *_array;
            size_type       _MyCapacity;
            size_type       _Mysize;
            allocator_type  _MyAllocator;
        public :
        //Constructors
        explicit vector (const allocator_type& alloc = allocator_type())
                    : _array(nullptr), _MyCapacity(0), _Mysize(0) {};
        explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : _MyCapacity(n), _Mysize(n)
        {
            if (this->_MyCapacity)
            {
                this->_array = _MyAllocator.allocate(this->_MyCapacity);
                for (size_type acc = 0; acc < this->_Mysize; acc++)
                    this->_array[acc] = val;
            }
            else {
                this->_array = nullptr;
            }
        };
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _Mysize(0)
        {
            this->_MyCapacity = last - first;
            if (this->_MyCapacity)
            {
                this->_array = _MyAllocator.allocate(this->_MyCapacity);
                size_type acc = 0;
                while (first != last)
                {
                    
                }
                
            }
            else {
                this->_array = nullptr;
            }
        };
        vector (const vector& x)
        { 
            this->_array = x;
        };
        //Destrutor
        ~vector()
        {
            if (this->_MyCapacity)
                this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);
        };

        //EgalOperator
        vector& operator= (const vector& x)
        {
            this->_MyCapacity = x.capacity();
            this->_Mysize = x.size();
            if (this->_MyCapacity)
            {
                this->_array = _MyAllocator.allocate(this->_MyCapacity);
                for (size_type acc = 0; acc < this->_Mysize; acc++)
                    this->_array[acc] = x[acc];
            }
            else {
                this->_array = nullptr;
            }
        };

        // eterator 
        // iterator begin();
        // const_iterator begin() const;
        // iterator end();
        // const_iterator end() const;
        // reverse_iterator rbegin();
        // const_reverse_iterator rbegin() const;
        // reverse_iterator rend();
        // const_reverse_iterator rend() const;
        
        // Capacity
        size_type size() const
        {
            return this->_Mysize;
        }
        size_type capacity() const
        {
            return this->_MyCapacity;
        }
        // size_type max_size() const;
        // void resize (size_type n, value_type val = value_type());
        // bool empty() const;
        // void reserve (size_type n);

        // // element access 
        // reference operator[] (size_type n);
        // const_reference operator[] (size_type n) const;
        // reference at (size_type n);
        // const_reference at (size_type n) const;
        // reference front();
        // const_reference front() const;
        // reference back();
        // const_reference back() const;

        // // modifiers
        // template <class InputIterator>
        // void assign (InputIterator first, InputIterator last);
        // void assign (size_type n, const value_type& val);
        void push_back (const value_type& val)
        {
            if (this->_MyCapacity > this->_Mysize)
            {
                this->_Mysize += 1;
                this->_array[this->_Mysize] = val;
            }
            else
            {
                T *temp = this->_array;
                this->_MyCapacity += 1;
                this->_Mysize = this->_MyCapacity;
                this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
                for(size_type acc = 0; acc < this->_MyCapacity; acc++)
                    this->_array[acc] = temp[acc];
            }
        }
        // void pop_back();
        // iterator insert (iterator position, const value_type& val);	
        // void insert (iterator position, size_type n, const value_type& val);	
        // template <class InputIterator>
        // void insert (iterator position, InputIterator first, InputIterator last);
        // iterator erase (iterator position);
        // iterator erase (iterator first, iterator last);
        // void swap (vector& x);
        // void clear();
        
        // Allocator
        // allocator_type get_allocator() const;

    };
    // non-member fonctions
    
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}
#endif
