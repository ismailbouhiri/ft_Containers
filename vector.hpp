/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:30:18 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/15 18:10:12 by ibouhiri         ###   ########.fr       */
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
        typedef T                                        value_type;
        typedef Alloc                                    allocator_type;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        typedef ft::reverse_iterator<iterator>           reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;

        private :
         // private thinks
            T               *array;
            size_type       MyCapacity;
            size_type       MySize;
            allocator_type  MyAllocator;
        public :
        //Constructors
        explicit vector (const allocator_type& alloc = allocator_type())
                    : array(nullptr), MyCapacity(0), MySize(0) {}
        explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : MyCapacity(n), MySize(n)
        {
            if (this->MyCapacity)
            {
                this->array = MyAllocator.allocate(this->MyCapacity + 1);
                for (size_type acc = 0; acc < this->Mysize; acc++)
                    this->array[acc] = val;
                this->array[this->MyCapacity] = nullptr; 
            }
            else {
                this->array = nullptr;
            }
        }
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : MySize(0)
        {
            this->MyCapacity = last - first;
            if (this->MyCapacity)
            {
                this->array = MyAllocator.allocate(this->MyCapacity + 1);
                for (InputIterator it = first; it != last; it++)
                    this->array.pushback(*it);
                this->array[this->MyCapacity] = nullptr;
            }
            else {
                this->array = nullptr;
            }
        }
        vector (const vector& x)
        { 
            this->array = x;
        };
        //Destrutor
        ~vector()
        {
            if (this->MyCapacity)
                this->MyAllocator.deallocate(this->array, this->MyCapacity);
        }
        //EgalOperator
        vector& operator= (const vector& x)
        {
            
        }
        // eterator 
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;
        
        // Capacity
        size_type size() const
        {
            return this->MySize;
        }
        size_type capacity() const
        {
            return this->MyCapacity;
        }
        size_type max_size() const;
        void resize (size_type n, value_type val = value_type());
        bool empty() const;
        void reserve (size_type n);

        // element access 
        reference operator[] (size_type n);
        const_reference operator[] (size_type n) const;
        reference at (size_type n);
        const_reference at (size_type n) const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;

        // modifiers
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last);
        void assign (size_type n, const value_type& val);
        void push_back (const value_type& val)
        {
            if (this->MyCapacity > this->MySize)
            {
                this->MySize += 1;
                this->array[this->MySize] = val;
            }
            else
            {
                T *temp = this->array;
                this->MyCapacity += 1;
                this->MySize = this->MyCapacity;
                this->array = this->MyAllocator.allocate(this->MyCapacity + 1);
                for(type_size acc = 0; acc < this->MyCapacity; acc++)
                    this->array[acc] = temp[acc];
                this->array[this->MySize] = nullptr;
            }
        }
        void pop_back();
        iterator insert (iterator position, const value_type& val);	
        void insert (iterator position, size_type n, const value_type& val);	
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last);
        iterator erase (iterator position);
        iterator erase (iterator first, iterator last);
        void swap (vector& x);
        void clear();
        
        // Allocator
        allocator_type get_allocator() const;

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
