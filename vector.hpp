/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:30:18 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/19 15:53:03 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
# include "iterators.hpp"
            
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
        typedef ft::iterator<value_type>                     iterator;               
        typedef ft::iterator<const value_type>               const_iterator;         
        typedef ft::reverse_iterator<iterator>               reverse_iterator;      
        typedef ft::reverse_iterator<const_iterator>         const_reverse_iterator;            

        private :
         // private thinks
            pointer         _array;
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
                this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
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
            this->_Mysize = _MyCapacity;
            if (this->_MyCapacity)
            {
                this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
                for (size_type acc = 0; acc < this->_Mysize; acc++)
                    this->_array[acc] = *(first++);
            }
            else {
                this->_array = nullptr;
            }
        };
        vector (const vector& x)
        { 
            *this = x;
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
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;
        
        // Capacity
        size_type size() const { return this->_Mysize; };
        size_type capacity() const { return this->_MyCapacity; };
        bool empty() const
        {
            if (this->Mysize)
                return true;
            else 
                return false;
        };
        size_type max_size() const;
        void resize (size_type n, value_type val = value_type());
        void reserve (size_type n);

        // // element access
        reference operator[] (size_type n) { return this->_array[n]; };
        const_reference operator[] (size_type n) const { return this->_array[n]; };
        reference at (size_type n)  { return (n > _Mysize) ? throw std::out_of_range("this element n is out of range") : _array[n]; };
        const_reference at (size_type n) const { return (n > _Mysize) ? throw std::out_of_range("this element n is out of range") : _array[n]; };
        reference front() { return _array[0]; };
        const_reference front() const { return _array[0]; };
        reference back() { return _array + _Mysize; };
        const_reference back() const { return _array + _Mysize; };

        // // modifiers
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);
            size_type n = last - first;
            this->_MyCapacity = (n > this->_MyCapacity) ? n : this->_MyCapacity;
            this->_Mysize = n;
            this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
            for(size_type acc = 0; acc < n; acc++)
                this->_array[acc] = *(first++);
        };
        void assign (size_type n, const value_type& val)
        {
            this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);      
            this->_MyCapacity = (n > this->_MyCapacity) ? n : this->_MyCapacity;
            this->_Mysize = n;
            this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
            for(size_type acc = 0; acc < n; acc++)
                this->_array[acc] = val;
        };
        void push_back (const value_type& val)
        {
            if (this->_MyCapacity == 0)
            {
                this->_MyCapacity += 1;
                this->_Mysize += 1;
                this->_array = this->_MyAllocator.allocate(1);
                this->_array[0] = val;
            }
            else if (this->_MyCapacity > this->_Mysize)
            {
                this->_array[this->_Mysize] = val;
                this->_Mysize += 1;
            }
            else
            {
                pointer tmp_array;
                size_type tmp_capacity = this->_MyCapacity;
                this->_MyCapacity *= 2;
                tmp_array = this->_MyAllocator.allocate(_MyCapacity);
                for (size_type i = 0; i < _Mysize; i++)
                    tmp_array[i] = this->_array[i];
                tmp_array[_Mysize] = val;
                this->_MyAllocator.deallocate(_array, tmp_capacity);
                this->_Mysize += 1;
                this->_array = tmp_array;
            }
        }
        void pop_back(void)
        {
            this->_MyAllocator.destroy(this->_array + this->_Mysize);
            this->_Mysize--;
        };
        iterator insert (iterator position, const value_type& val){};
        void insert (iterator position, size_type n, const value_type& val){};
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last);
        iterator erase (iterator position);
        iterator erase (iterator first, iterator last);
        void swap (vector& x) {
            
            
        };
        void clear(void) {
            
        };
        
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
