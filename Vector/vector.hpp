/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:30:18 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/11/15 12:48:42 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
# include "random_access_iterators.hpp"
            
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
        typedef ft::vector_iterator<value_type>              iterator;               
        typedef ft::vector_iterator<const value_type>        const_iterator;         
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
                if (_MyCapacity > max_size())
                    throw std::length_error("no left space!!");
                this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
                if (!_array)
                    throw std::bad_alloc();
                for (size_type acc = 0; acc < this->_Mysize; acc++)
                    _MyAllocator.construct(&_array[acc], val);

            }
            else {
                this->_array = nullptr;
            }
        };
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* t = 0, 
        const allocator_type& alloc = allocator_type()) : _Mysize(0), _MyAllocator(alloc)
        {
            t = 0;
            this->_MyCapacity = std::distance(first, last);
            this->_Mysize = _MyCapacity;
            if (this->_MyCapacity)
            {
                if ( _MyCapacity > max_size() )
                    throw std::length_error("no left space!!");
                this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
                if (!_array)
                    throw std::bad_alloc();
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
                clear();
                this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);
                
            }
        };

        //EgalOperator
        vector& operator= (const vector& x)
        {
            if (this->_MyCapacity)
            {
                clear();
                this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);
            }
            this->_MyCapacity = x.capacity();
            this->_Mysize = x.size();
            this->_MyAllocator = x.get_allocator();
            if (this->_MyCapacity)
            {
                if (_MyCapacity > max_size())
                    throw std::length_error("no left space!!");
                this->_array = _MyAllocator.allocate(this->_MyCapacity);
                if (!_array)
                    throw std::bad_alloc();
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
            {
                for (size_type i = n; i < _Mysize; i++)
                    this->_MyAllocator.destroy(this->_array + i);
                _Mysize = n;
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
                if (tmp_capacity > max_size())
                    throw std::length_error("no left space!!");
                pointer tmp_array = _MyAllocator.allocate(tmp_capacity);
                if (!tmp_array)
                    throw std::bad_alloc();
                for (size_type i = 0; i < n; i++)
                    if (i < _Mysize)
                        _MyAllocator.construct(&tmp_array[i], _array[i]);
                    else
                        _MyAllocator.construct(&tmp_array[i], val);
                clear();
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
                if (n > max_size())
                    throw std::length_error("no left space!!");
                pointer tmp_array = _MyAllocator.allocate(n);
                if (!tmp_array)
                    throw std::bad_alloc();
                for (size_type i = 0; i < _Mysize; i++)
                {
                    _MyAllocator.construct(&tmp_array[i], _array[i]);
                     _MyAllocator.destroy(_array + i);
                }
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
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* t = 0)
        {
            t = 0;
            this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);
            size_type n = std::distance(first, last);
            this->_MyCapacity = (n > this->_MyCapacity) ? n : this->_MyCapacity;
            this->_Mysize = n;
            if (_MyCapacity > max_size())
                throw std::length_error("no left space!!");
            this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
            if (!_array)
                throw std::bad_alloc();
            for(size_type acc = 0; acc < n; acc++)
                _MyAllocator.construct(&_array[acc], *(first++));

        };
        void assign (size_type n, const value_type& val)
        {
            this->_MyAllocator.deallocate(this->_array, this->_MyCapacity);      
            this->_MyCapacity = (n > this->_MyCapacity) ? n : this->_MyCapacity;
            this->_Mysize = n;
            if (_MyCapacity > max_size())
                throw std::length_error("no left space!!");
            this->_array = this->_MyAllocator.allocate(this->_MyCapacity);
            if (!_array)
                throw std::bad_alloc();
            for(size_type acc = 0; acc < n; acc++)
                _MyAllocator.construct(&_array[acc], val);
        };
        void push_back (const value_type& val)
        {
            if (this->_MyCapacity == 0)
            {
                this->_MyCapacity += 1;
                this->_Mysize += 1;
                if (_MyCapacity > max_size())
                    throw std::length_error("no left space!!");
                this->_array = this->_MyAllocator.allocate(1);
                if (!_array)
                    throw std::bad_alloc();
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
                if (_MyCapacity > max_size())
                    throw std::length_error("no left space!!");
                tmp_array = this->_MyAllocator.allocate(_MyCapacity);
                if (!tmp_array)
                    throw std::bad_alloc();
                for (size_type i = 0; i < _Mysize; i++)
                    _MyAllocator.construct(&tmp_array[i], _array[i]);
                _MyAllocator.construct(&tmp_array[_Mysize], val);
                this->_MyAllocator.deallocate(_array, tmp_capacity);
                this->_Mysize += 1;
                this->_array = tmp_array;
            }
        };
        
        void pop_back(void) { this->_MyAllocator.destroy(this->_array + this->_Mysize); this->_Mysize--; };
        
        iterator insert (iterator position, const value_type& val)
        {
            size_type tmp_capacity = (!_MyCapacity) ? 1 : _MyCapacity * 2;
            size_type index = 0;
            size_type j = 0;
            if (_MyCapacity == _Mysize)
            {
                size_type tmp_size = _Mysize + 1;
                size_type sign = 0;
                pointer tmp_array = NULL;
                if (tmp_capacity > max_size())
                    throw std::length_error("no left space!!");
                tmp_array = _MyAllocator.allocate(tmp_capacity);
                if (!tmp_array)
                    throw std::bad_alloc();
                for (size_type i = 0; i < tmp_size; i++)
                {
                    iterator it(_array + i);
                    if (!_array)
                    {
                        index = i;
                        sign = 1;
                        _MyAllocator.construct(&tmp_array[j++], val);
                        break;
                    }
                    else if (position == it)
                    {
                        index = i;
                        sign = 1;
                        _MyAllocator.construct(&tmp_array[j++], val);
                    }
                    else
                    {         
                        if (sign)
                            _MyAllocator.construct(&tmp_array[j++], _array[i - 1]);
                        else
                            _MyAllocator.construct(&tmp_array[j++], _array[i]);
                    }
                }
                clear();
                if (_MyCapacity)
                    _MyAllocator.deallocate(_array, _MyCapacity);
                _Mysize = tmp_size;
                _MyCapacity = tmp_capacity;
                _array = tmp_array;
            }
            else if (_MyCapacity > _Mysize)
            {
                for (size_type i = 0; i < _Mysize; i++)
                {
                    iterator it(_array + i);
                    if (position == it)
                    {
                        for (long long acc = (!_Mysize) ? 0 : _Mysize - 1; acc >= static_cast<long long>(i); acc--)
                        {
                            _MyAllocator.construct(&_array[acc + 1], _array[acc]);
                            _MyAllocator.destroy(_array + acc);
                        }
                        index = i;
                        _MyAllocator.construct(&_array[i], val);
                    }
                }
                _Mysize++;
            }
            iterator it(_array + index);
            return it;
        };
        void insert (iterator position, size_type n, const value_type& val)
        {
            if (_MyCapacity < (_Mysize + n))
            {
                size_type tmp_alloc = ((_MyCapacity * 2) < (_Mysize + n)) ? _Mysize + n : _MyCapacity * 2;
                if (tmp_alloc > max_size())
                    throw std::length_error("no left space!!");
                pointer tmp = _MyAllocator.allocate(tmp_alloc);
                if (!tmp)
                    throw std::bad_alloc();
                size_type j = 0;
                _Mysize += n;
                for (size_type acc = 0; acc < _Mysize; acc++)
                {
                    iterator it(_array + acc);
                    if (position == it)
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
                for (size_type i = (!_Mysize) ? 0 : _Mysize - 1; i >= pos; --i)
                {
                    _MyAllocator.construct(&_array[i + n], _array[i]);
                    if (!i)
                        break;
                }
                for (size_type i = pos, k = 0; k < n; i++, k++)
                    _MyAllocator.construct(&_array[i], val);
                _Mysize += n;
            }
        };
        
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* t = 0)
        {
            t = 0;
            size_type n = std::distance(first, last);
            if (_MyCapacity < (_Mysize + n))
            {
                size_type tmp_alloc = ((_MyCapacity * 2) < (_Mysize + n)) ? _Mysize + n : _MyCapacity * 2;
                if (tmp_alloc > max_size())
                    throw std::length_error("no left space!!");
                pointer tmp = _MyAllocator.allocate(tmp_alloc);
                if (!tmp)
                    throw std::bad_alloc();
                size_type j = 0;
                size_type tmp_size = _Mysize + n;
                for (size_type acc = 0; acc < tmp_size; acc++)
                {
                    iterator it(_array + acc);
                    if (position == it)
                    {
                        for (size_type i = 0; i < n; i++)
                        {                            
                            _MyAllocator.construct(&tmp[j++], *(first++));
                        }
                        if (!_array)
                            break;
                    }
                    if (acc < (tmp_size - n))
                        _MyAllocator.construct(&tmp[j++], _array[acc]);
                }
                clear();
                _Mysize = tmp_size;
                _MyAllocator.deallocate(_array, _MyCapacity);
                _MyCapacity = tmp_alloc;
                _array = tmp;
            }
            else if (_MyCapacity > (_Mysize + n))
            {
                size_type pos = position - begin();
                for (size_type i = (!_Mysize) ? 0 : _Mysize - 1; i >= pos; --i)
                {
                    _MyAllocator.construct(&_array[i + n], _array[i]);
                    if (!i)
                        break;
                }
                for (size_type i = pos, k = 0; k < n; i++, k++)
                    _MyAllocator.construct(&_array[i], *(first++));
                _Mysize += n;
            }
        }
        
        iterator erase (iterator position)
        {
            value_type save;
            iterator it;
            for (size_type i = 0; i < _Mysize ; i++)
            {
                iterator it(_array + i);
                if (position == it)
                {
                    _MyAllocator.destroy(_array + i);
                    for (size_type acc = i + 1; acc < _Mysize  ; acc++ ,i++)
                        _MyAllocator.construct(&_array[i], _array[acc]);
                    _Mysize -= 1;
                    return it;
                }
            }
            return position;
        };
        
        iterator erase (iterator first, iterator last)
        {    
            size_type n = std::distance(first, last);
            size_type k = 0;
            size_type save;
            iterator it;
            for (size_type i = 0; i < _Mysize ; i++)
            {
                it = (_array + i); 
                if (first == it)
                {
                    save = i ;
                    size_type j = i;
                    for (; i < _Mysize; i++ )
                    {
                        while (k < n)
                        {
                            _MyAllocator.destroy(_array + i);
                            i++;
                            k++;
                        }
                        if (i != _Mysize)
                        {
                            _MyAllocator.construct(&_array[j++], _array[i]);
                            _MyAllocator.destroy(_array + i);
                        }
                    }
                    _Mysize -=n;
                    iterator it(_array + save);
                    return it;
                }
            } 
            return first;
        };
        
        void clear(void) 
        {
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
    bool operator== (const vector<T,Alloc>& left, const vector<T,Alloc>& right)
    { return left.size() == right.size() && (ft::equal(left.begin(), left.end(), right.begin())); };
	
    template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& left, const vector<T,Alloc>& right) { return !(left == right); }
	
    template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& left, const vector<T,Alloc>& right)
	{
        return (ft::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end()));
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
