//
// Created by Casie Carl on 11/10/20.
//

#ifndef ARRAY_VECTOR_HPP
#define ARRAY_VECTOR_HPP
#include "VectorIterator.hpp"
#include <cstdio>
#include <stddef.h>
#include <exception>
#include <memory>
#include <stdexcept>
#include <limits>


namespace ft
{
	template<typename T, typename A = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef A allocator_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_ptr;
		typedef typename ft::VectorIterator<T> 				iterator;
		typedef typename ft::ConstVectorIterator<T>			const_iterator;
		typedef typename ft::ReverseVectorIterator<T>		reverse_iterator;
		typedef typename ft::ConstReverseVectorIterator<T>	const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		size_type	_size;
		size_type	_capacity;
		pointer		arr;
		allocator_type allocator;

	public:

		//Constructors, destructors, operator=

		explicit vector(const allocator_type &alloc = allocator_type())
		{
			_size = 0;
			this->allocator = alloc;
			_capacity = 0;
			arr = NULL;
		}

		explicit vector(size_type _size, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type())
		{
			this->_size = _size;
			this->_capacity = _size;
			this->allocator = alloc;
			if (_size == 0)
            {
			    arr = NULL;
			    return ;
            }
			arr = allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				arr[i] = val;
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last,
               const allocator_type &alloc = allocator_type())
		{
		    size_type size = iterator_dist(first, last);
            this->_size = size;
            this->_capacity = size;
            this->allocator = alloc;
            if (_size == 0)
            {
                arr = NULL;
                return ;
            }
            arr = allocator.allocate(_capacity);
            for (size_type i = 0; i < _size;i++)
            {
                arr[i] = *first;
                first++;
            }
		}

		vector(const vector &x)
		{
			this->allocator = x.allocator;
			this->_capacity = x._capacity;
			this->_size = x._size;
			this->arr = allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				arr[i] = x[i];
		}

		virtual ~vector()
		{
			allocator.deallocate(this->arr, _capacity);
		}

		const vector &operator=(const vector &x)
		{
			this->allocator = x.allocator;
			allocator.deallocate(this->arr, _capacity);
			this->_capacity = x._capacity;
			this->_size = x._size;
			this->arr = allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				arr[i] = x[i];
			return (*this);
		}
		//Iterators

		iterator	begin()
		{
			return (iterator(arr));
		}

        const_iterator	begin() const
        {
            return (const_iterator(arr));
        }

		reverse_iterator	rbegin()
		{
			return (reverse_iterator(arr + _size - 1));
		}

		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(arr + _size - 1));
		}

        iterator	end()
        {
            return (iterator(arr + _size));
        }

        const_iterator	end() const
        {
            return (const_iterator(arr + _size));
        }

        reverse_iterator	rend()
        {
            return (reverse_iterator(arr - 1));
        }

        const_reverse_iterator	rend() const
        {
            return (const_reverse_iterator(arr - 1));
        }

        //

		//Capacity

		size_type size() const
		{
			return _size;
		}

		size_type max_size()
		{
			//return std::numeric_limits<size_type>::max() / sizeof(value_type);
			return allocator.max_size();
		}

        void resize(size_type n, value_type val = value_type())
		{
            pointer resized;
            try
            {
                resized = allocator.allocate(n);
            }
            catch (std::bad_alloc &e)
            {
                e.what();
                return ;
            }
			if (n <= _size)
			{
			    for (size_type i = 0; i < n; i++)
					resized[i] = arr[i];
			    allocator.deallocate(arr, _capacity);
				arr = resized;
			}
			else {
                for (size_type i = 0; i < _size; i++)
                    resized[i] = arr[i];
                for(size_type i = _size;i < n;i++)
                    resized[i] = val;
			    allocator.deallocate(arr, _capacity);
			    arr = resized;
			    if (_capacity < n)
                    _capacity = _size * 2;
			}
            _size = n;
		}

        size_type capacity() const
        {
            return _capacity;
        }

        bool empty() const
        {
		    return _size == 0;
        }

        void reserve (size_type n)
        {
		    if (n > _capacity){
                pointer tmp = allocator.allocate(n);
                for (size_type i = 0; i < _size; i++)
                    tmp[i] = arr[i];
                allocator.deallocate(arr, _capacity);
                arr = tmp;
                _capacity = n;
		    }
		    else
                return;

        }

        //Element acess

        reference operator[] (size_type n)
		{
			return *(arr + n);
		}

        const_reference operator[] (size_type n) const
        {
            return *(arr + n);
        }

        reference at(size_type n)
        {
		    if (n >= _size)
		        throw std::out_of_range("Out of range exception");
		    else
		        return (this->operator[](n));
        }

        const_reference at (size_type n) const
        {
            if (n >= _size)
                throw std::out_of_range("Out of range exception");
            else
                this->operator[](n);
        }

        reference front()
        {
            return arr[0];
        }
        const_reference front() const
        {
            return arr[0];
        }
        reference back()
        {
            return (arr[_size - 1]);
        }
        const_reference back() const
        {
            return (arr[_size - 1]);
        }

        //Moifiers

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            clear();
            size_type n = iterator_dist(first, last);
            if (n > _capacity)
                _capacity = n;
            arr = allocator.allocate(_capacity);
            while (first != last) {
                arr[_size] = *first;
                first++;
                _size++;
            }
        }

        void assign(size_type n, const value_type& val)
        {
            clear();
            if (n > _capacity)
                _capacity = n;
            arr = allocator.allocate(_capacity);
            size_type count = 0;
            while (count < n) {
                push_back(val);
                count++;
            }
        }


        void push_back(const value_type& val)
        {
            if ((this->_size + 1) <= _capacity)
            {
                arr[_size] = val;
                _size++;
            }
            else
            {
                if (_capacity == 0)
                    reserve(1);
                else
                    reserve(_capacity * 2);
                arr[_size] = val;
                _size++;
            }
        }

        void 	pop_back()
        {
            _size--;
        }

        void clear()
        {
		    allocator.deallocate(arr, _capacity);
		    arr = NULL;
		    _size = 0;

        }

        iterator insert (iterator position, const value_type& val)
        {
            difference_type diff = position.operator->() - this->begin().operator->();
            iterator end = this->end();
            position = this->begin() + diff;
		    if (_size + 1 > _capacity) {
                if (_capacity == 0)
                    reserve(1);
                else
                    reserve(_capacity * 2);
            }
		    if (end == position) {
		        arr[_size] = val;
		        _size++;
		        return this->begin() + diff;
		    }
		    end--;
		    for (int i = (int)_size - 1; i >= 0 ;i--)
		    {
		        if (end == position) {
		            arr[i + 1] = arr[i];
		            arr[i] = val;
		            break;
		        }
		        arr[i + 1] = arr[i];
		        end--;
		    }
		    _size++;
		    return this->begin() + diff;
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            if (n == 0)
                return ;
            size_type diff = position.operator->() - this->begin().operator->();
            iterator end = this->end();
            position = this->begin() + diff;
            reserve_if(n);
            if (end == position) {
                fill(n, val, _size + n - 1);
                _size += n;
                return ;
            }
            end--;
            for (int i = (int)_size - 1; i >= 0 ;i--)
            {
                if (end == position) {
                    arr[i + n] = arr[i];
                    fill(n, val, i + n - 1);
                    break;
                }
                arr[i + n] = arr[i];
                end--;
            }
            _size += n;
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {
		    difference_type diff = position.operator->() - this->begin().operator->();
            size_type n = iterator_dist(first, last);
            vector copy(first, last);
            iterator firstCopy = copy.begin();
            iterator lastCopy = copy.end();
            reserve_if(n);
            iterator end = this->end();
            position = this->begin() + diff;
            if (end == position) {
                fill(firstCopy, lastCopy, _size + n - 1);
                _size += n;
                copy.clear();
                return ;
            }
            end--;
            for (int i = (int)_size - 1; i >= 0 ;i--)
            {
                if (end == position) {
                    arr[i + n] = arr[i];
                    fill(firstCopy, lastCopy, i + n - 1);
                    break;
                }
                arr[i + n] = arr[i];
                end--;
            }
            _size += n;
            copy.clear();
        }

        iterator erase (iterator position)
        {
		    ptrdiff_t diff = position.operator->() - this->begin().operator->();
		    size_type index = (size_type)diff;
		    while (diff < (ptrdiff_t)_size - 1)
            {
		        arr[diff] = arr[diff + 1];
		        diff++;
            }
		    _size--;
		    return (iterator(arr + index));
        }

        iterator erase(iterator first, iterator last)
        {
		    size_type n = iterator_dist(first, last);
			ptrdiff_t diff = first.operator->() - this->begin().operator->();
			size_type index = (size_type)diff;
		    while (diff < (ptrdiff_t)_size - 1)
            {
		        arr[diff] = arr[diff + n];
		        diff++;
            }
		    _size -= n;
            return (iterator(arr + index));
        }

        void swap (vector& x)
        {
            size_type tmp_size = this->_size;
            this->_size = x._size;
            x._size = tmp_size;

            size_type tmp_capacity = this->_capacity;
            this->_capacity = x._capacity;
            x._capacity = tmp_capacity;

            pointer tmp_arr = this->arr;
            this->arr = x.arr;
            x.arr = tmp_arr;

            allocator_type tmp_allocator = this->allocator;
            this->allocator = x.allocator;
            x.allocator = tmp_allocator;
        }


    private:
	    void    reserve_if(size_type n)
        {
            if (_size + n > _capacity) {
                if (_capacity == 0)
                    reserve(n);
                else {
                    if (_size + n > _capacity * 2)
                        reserve(_size + n);
                    else
                        reserve(_capacity * 2);
                }
            }
        }

        void    fill(size_type n, const value_type& val, int pos)
        {
		    while (n)
            {
		        arr[pos] = val;
		        pos--;
		        n--;
            }
        }

        template <class InputIterator>
        void    fill(InputIterator first, InputIterator last, size_type pos)
        {
		    last--;
		    while (last != first)
            {
		        arr[pos] = *last;
		        last--;
		        pos--;
            }
		    arr[pos] = *last;
        }

        template <class InputIterator>
	    size_type iterator_dist(InputIterator first, InputIterator last)
        {
		    size_type count = 0;
		    while (first != last)
            {
		        count++;
		        first++;
            }
            return (count);
        }
	};

	//Non member functions

    template <class T, class Alloc>
    bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        for(size_t i = 0; i < lhs.size(); i++)
        {
             if (lhs[i] != rhs[i])
                 return (false);
        }
        return (true);
    }

    template <class T, class Alloc>
    bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator < (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        size_t i = 0;
        while (i < lhs.size() && i < rhs.size())
		{
        	if (lhs[i] < rhs[i])
        		return (true);
        	i++;
		}
        if (i == lhs.size() && i != rhs.size())
        	return (true);
        return (false);
    }

    template <class T, class Alloc>
    bool operator > (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs < rhs || lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}

#endif
	