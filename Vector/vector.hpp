/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:30:18 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/10/30 13:39:28 by ibouhiri         ###   ########.fr       */
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
                    : _array(nullptr), _MyCapacity(0), _Mysize(0), _MyAllocator(alloc) {};
        explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : _MyCapacity(n), _Mysize(n), _MyAllocator(alloc)
        {
            
            if (this->_MyCapacity)
            {
                this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
                for (size_type acc = 0; acc < this->_Mysize; acc++)
                    _MyAllocator.construct(&_array[acc], val);

            }
            else {
                this->_array = nullptr;
            }
        };
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
        typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* t = 0, 
        const allocator_type& alloc = allocator_type()) : _Mysize(0), _MyAllocator(alloc)
        {
            t = 0;
            this->_MyCapacity = last - first;
            this->_Mysize = _MyCapacity;
            if (this->_MyCapacity)
            {
                this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
                for (size_type acc = 0; acc < _Mysize; acc++)
                    _MyAllocator.construct(&_array[acc], *(first++));

            }
            else {
                this->_array = nullptr;
            }
        };
        vector (const vector& x) : _MyCapacity(0), _Mysize(0)
        { *this = x; };
        //Destrutor
        ~vector()
        {
            if (this->_MyCapacity)
            {
                for (size_type acc = 0; acc < _Mysize; acc++)
                    this->_MyAllocator.destroy(this->_array + acc);
                this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);
            }
        };

        //EgalOperator
        vector& operator= (const vector& x)
        {
            if (this->_MyCapacity)
                this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);
            this->_MyCapacity = x.capacity();
            this->_Mysize = x.size();
            this->_MyAllocator = x.get_allocator();
            if (this->_MyCapacity)
            {
                this->_array = _MyAllocator.allocate(this->_MyCapacity);
                for (size_type acc = 0; acc < this->_Mysize; acc++)
                    _MyAllocator.construct(&_array[acc], x[acc]);
            }
            else {
                this->_array = nullptr;
            }
            return *this;
        };
        // eterator 
        iterator begin( void ) { iterator it(_array); return it; };
        iterator end( void ) { iterator it(_array + _Mysize ); return it; };
        
        const_iterator begin( void ) const  { const_iterator it(_array); return it; };;
        const_iterator end() const { const_iterator it(_array + _Mysize ); return it; };;
        
        reverse_iterator rbegin( void ) { reverse_iterator rev_it(end()); return rev_it; };
        reverse_iterator rend( void ) { reverse_iterator rev_it(begin()); return rev_it; };
        
        const_reverse_iterator rbegin( void ) const { const_reverse_iterator rev_it(end()); return rev_it; };
        const_reverse_iterator rend( void ) const { const_reverse_iterator rev_it(begin()); return rev_it; };
        
        // Capacity
        size_type size() const { return this->_Mysize; };
        size_type capacity() const { return this->_MyCapacity; };
        bool empty() const { return !_Mysize; };
        size_type max_size() const  { return _MyAllocator.max_size(); };
        void resize (size_type n, value_type val = value_type())
        {
            if (_Mysize > n)
                for (size_type i = _Mysize - 1; _Mysize != n; i--)
                {
                    this->_MyAllocator.destroy(this->_array + i);
                    _Mysize--;
                }
            else if (_Mysize < n && _MyCapacity >= n)
            {
                for (size_type i = _Mysize; i < n; i++)
                    _MyAllocator.construct(&_array[i], val);
                _Mysize = n;
            }
            else if (_MyCapacity < n)
            {
                size_type tmp_capacity = ((_MyCapacity * 2) < n) ? n : _MyCapacity * 2;
                pointer tmp_array = _MyAllocator.allocate(tmp_capacity);
                for (size_type i = 0; i < n; i++)
                    if (i < _Mysize)
                        _MyAllocator.construct(&tmp_array[i], _array[i]);
                    else
                        _MyAllocator.construct(&tmp_array[i], val);
                _MyAllocator.deallocate(this->_array, _MyCapacity);
                _array = tmp_array;
                _Mysize = n;
                _MyCapacity = tmp_capacity;
            }
        };
        void reserve (size_type n)
        {
            if (n > _MyCapacity)
            {
                pointer tmp_array = _MyAllocator.allocate(n);
                for (size_type i = 0; i < _Mysize; i++)
                    _MyAllocator.construct(&tmp_array[i], _array[i]);
                _MyAllocator.deallocate(_array, _MyCapacity);
                _MyCapacity = n;
                _array = tmp_array;
            }
        };

        // // element access
        reference operator[] (size_type n) { return this->_array[n]; };
        reference at (size_type n)  { return (n > _Mysize) ? throw std::out_of_range("this element n is out of range") : _array[n]; };
        
        const_reference operator[] (size_type n) const { return this->_array[n]; };
        const_reference at (size_type n) const { return (n > _Mysize) ? throw std::out_of_range("this element n is out of range") : _array[n]; };
        
        reference front() { return _array[0]; };
        reference back() { return _array[_Mysize - 1]; };
        
        const_reference front() const { return _array[0]; };
        const_reference back() const { return _array[_Mysize - 1]; };

        // // modifiers
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last,
                    typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* t = 0)
        {
            t = 0;
            this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);
            size_type n = last - first;
            this->_MyCapacity = (n > this->_MyCapacity) ? n : this->_MyCapacity;
            this->_Mysize = n;
            this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
            for(size_type acc = 0; acc < n; acc++)
                _MyAllocator.construct(&_array[acc], *(first++));

        };
        void assign (size_type n, const value_type& val)
        {
            this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);      
            this->_MyCapacity = (n > this->_MyCapacity) ? n : this->_MyCapacity;
            this->_Mysize = n;
            this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
            for(size_type acc = 0; acc < n; acc++)
                _MyAllocator.construct(&_array[acc], val);
        };
        void push_back (const value_type& val)
        {
            if (this->_MyCapacity == 0)
            {
                this->_MyCapacity += 1;
                this->_Mysize += 1;
                this->_array = this->_MyAllocator.allocate(1);
                _MyAllocator.construct(&_array[0], val);

            }
            else if (this->_MyCapacity > this->_Mysize)
            {
                _MyAllocator.construct(&_array[_Mysize], val);
                this->_Mysize += 1;
            }
            else
            {
                pointer tmp_array;
                size_type tmp_capacity = this->_MyCapacity;
                this->_MyCapacity *= 2;
                tmp_array = this->_MyAllocator.allocate(_MyCapacity);
                for (size_type i = 0; i < _Mysize; i++)
                    _MyAllocator.construct(&tmp_array[i], _array[i]);
                _MyAllocator.construct(&tmp_array[_Mysize], val);
                this->_MyAllocator.deallocate(_array, tmp_capacity);
                this->_Mysize += 1;
                this->_array = tmp_array;
            }
        };
        void pop_back(void) { this->_MyAllocator.destroy(this->_array + this->_Mysize); this->_Mysize--; };
        iterator insert (iterator position, const value_type& val) {
            
            size_type index = 0;
            size_type j = 0;
            if (_MyCapacity == _Mysize)
            {
                size_type tmp_capacity = (!_MyCapacity) ? 1 : _MyCapacity * 2;
                _Mysize++;
                size_type sign = 0;
                pointer tmp_array = _MyAllocator.allocate(tmp_capacity);
                for (size_type i = 0; i < _Mysize; i++)
                {
                    if (!_array)
                    {
                        index = i;
                        sign = 1;
                        tmp_array[j++] = val;
                    }
                    else if (position == _array + i)
                    {
                        index = i;
                        sign = 1;
                        tmp_array[j++] = val;
                    }
                    else
                    {         
                        if (sign)
                            tmp_array[j++] = _array[i - 1];
                        else    
                            tmp_array[j++] = _array[i];
                    }
                }
                _MyAllocator.deallocate(_array, _MyCapacity);
                _MyCapacity = tmp_capacity;
                _array = tmp_array;
            }
            else if (_MyCapacity > _Mysize)
            {
                _Mysize++;
                value_type save;
                value_type saveTwo;
                for (size_type i = 0; i < _Mysize; i++)
                {
                    if (position == _array + i)
                    {
                        save = _array[i];
                        index = i;
                        _array[i] = val;
                    }
                    else
                        if (index)
                        {
                            saveTwo = _array[i];
                            _array[i] = save;
                            save = saveTwo;
                        }
                }
            }
            iterator it(_array + index);
            return it;
        };
        void insert (iterator position, size_type n, const value_type& val)
        {
            if (_MyCapacity < (_Mysize + n))
            {
                size_type tmp_alloc = ((_MyCapacity * 2) < (_Mysize + n)) ? _Mysize + n : _MyCapacity * 2;
                pointer tmp = _MyAllocator.allocate(tmp_alloc);
                size_type j = 0;
                _Mysize += n;
                for (size_type acc = 0; acc < _Mysize; acc++)
                {
                    if (&*position == (_array + acc))
                    {
                        for (size_type i = 0; i < n; i++)
                            _MyAllocator.construct(&tmp[j++], val);
                        if (!_array)
                            break;
                    }
                    if (acc < (_Mysize - n))
                        _MyAllocator.construct(&tmp[j++], _array[acc]);
                }
                _MyAllocator.deallocate(_array, _MyCapacity);
                _MyCapacity = tmp_alloc;
                _array = tmp;
            }
            else if (_MyCapacity > (_Mysize + n))
            {
                size_type pos = position - begin();
                for (size_type i = _Mysize - 1; i >= pos; --i)
                    _array[i + n] = _array[i];
                for (size_type i = pos, k = 0; k < n; i++, k++)
                    _array[i] = val;
                _Mysize += n;
            }
        };
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last,
                typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* t = 0)
        {
            t = 0;
            size_type n = std::distance(first, last);
            if (_MyCapacity < (_Mysize + n))
            {
                size_type tmp_alloc = ((_MyCapacity * 2) < (_Mysize + n)) ? _Mysize + n : _MyCapacity * 2;
                pointer tmp = _MyAllocator.allocate(tmp_alloc);
                size_type j = 0;
                _Mysize += n;
                for (size_type acc = 0; acc < _Mysize; acc++)
                {
                    if (&*position == (_array + acc))
                    {
                        for (size_type i = 0; i < n; i++)
                            _MyAllocator.construct(&tmp[j++], *(first++));
                        if (!_array)
                            break;
                    }
                    if (acc < (_Mysize - n))
                        _MyAllocator.construct(&tmp[j++], _array[acc]);
                }
                _MyAllocator.deallocate(_array, _MyCapacity);
                _MyCapacity = tmp_alloc;
                _array = tmp;
            }
            else if (_MyCapacity > (_Mysize + n))
            {
                size_type pos = position - begin();
                for (size_type i = _Mysize - 1; i >= pos; --i)
                    _array[i + n] = _array[i];
                for (size_type i = pos, k = 0; k < n; i++, k++)
                    _array[i] = *(first++);
                _Mysize += n;
            }
        }
        iterator erase (iterator position)
        {
            return (erase(position, position + 1));
        };
        iterator erase (iterator first, iterator last)
        {            
            value_type save;
            for (size_type i = 0; i < _Mysize ; i++)
            {
                if (first == (_array + i))
                {
                    size_type n = last - first;
                    size_type j = i;
                    for (size_type acc = i; acc < _Mysize  ; acc++ )
                    {
                        while ((acc - i) < n)
                        {
                            _MyAllocator.destroy(_array + acc);
                            acc += 1;
                        }
                        _array[j++] = _array[acc];
                    }
                    _Mysize -= n;
                    iterator it(_array + i);
                    return it;
                }
            }
            return first;
        };
        void clear(void) {
            while (_Mysize)
            {
                _Mysize--;
                _MyAllocator.destroy(_array + _Mysize);
            }
        };
        void swap (vector& x) {
            
            size_type       tmp_MyCapacity = x.capacity();
            size_type       tmp_Mysize = x.size();
            allocator_type  tmp_MyAllocator = x.get_allocator();
            
            pointer save = x._array;
            x._array = _array;
            x._MyAllocator = _MyAllocator;
            x._Mysize = _Mysize;
            x._MyCapacity = _MyCapacity;
            
            _array = save;
            _MyAllocator = tmp_MyAllocator;
            _Mysize = tmp_Mysize;
            _MyCapacity = tmp_MyCapacity;
        };
        
        // Allocator
        allocator_type get_allocator() const { return _MyAllocator; };

    };
    
    // non-member fonctions
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& left, const vector<T,Alloc>& right)  {
        size_t left_size = left.size();
        size_t right_size = right.size();
        if (left_size == right_size)
        {
            for (size_t i = 0; i < left_size; i++)
                if (left[i] != right[i])
                    return false;
            return true;   
        }
        return false;
    };
	
    template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& left, const vector<T,Alloc>& right) { return !(left == right); }
	
    template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& left, const vector<T,Alloc>& right)
	{
        size_t left_size = left.size();
        size_t right_size = right.size();
        for (size_t i = 0; i < right_size && i < left_size; i++)
            if (left[i] < right[i])
                return true;
            else if (left[i] > right[i])
                return false;
        if (left_size >= right_size)
            return false;
        return true;
    }
	
    template <class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& left, const vector<T,Alloc>& right) { return !(right < left); }
    
    template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& left, const vector<T,Alloc>& right) { return right < left; }
	
    template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& left, const vector<T,Alloc>& right) { return !(left < right); }
    
    
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); };
    
}
#endif
