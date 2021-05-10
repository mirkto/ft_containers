#ifndef VECTOR_HPP
# define VECTOR_HPP
 
# include <iostream>
# include "vector_iterator.hpp"

namespace ft {// start namespace ft

template < class T, class Alloc = std::allocator<T> >
class vector
{
public:
	typedef T									value_type;
	typedef Alloc								allocator_type;
	typedef ptrdiff_t							difference_type;
	typedef size_t								size_type;

	// typedef value_type &								reference;
	// typedef const value_type &						const_reference;
	// typedef value_type *								pointer;
	// typedef const value_type *						const_pointer;

	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;

	typedef ft::VectorIterator<T>				iterator;
	typedef ft::ConstVectorIterator<T>			const_iterator;
	typedef ft::ReverseVectorIterator<T>		reverse_iterator;
	typedef ft::ConstReverseVectorIterator<T>	const_reverse_iterator;

private:
	allocator_type				_alloc;
	pointer						_first;
	pointer						_last;
	size_type					_capacity;
	size_type					_len;

// --------------------------- private metods ---------------------------

void			ft_realloc(size_type new_capacity)
{
	if (_len < _capacity)
		return ;
	if (new_capacity == 0)
	{
		_alloc.deallocate(_first, _capacity);
		_first = NULL;
		_last = NULL;
		_capacity = 0;
	}
	else
	{
		value_type	*tmp = _alloc.allocate(new_capacity);
		for(size_type i = 0; i < _len; i++)
			tmp[i] = _first[i];
		_alloc.deallocate(_first, _capacity);
		_first = tmp;
		_last = &tmp[_len];
		_capacity = new_capacity;
	}
}
public:
//---------------------------- Member functions ----------------------------

// default constructor
explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _first(NULL), _last(NULL), _capacity(0), _len(0) {}

// fill constructor
explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());

// range constructor
template <class InputIterator>
vector (InputIterator first, InputIterator last,
						const allocator_type& alloc = allocator_type());

// copy constructor
vector (const vector& x);

// default destructor
~vector() { clear(); }

// assignment
vector& operator= (const vector& x);

//---------------------------- Iterators ----------------------------
iterator begin()		{ return _first;	}
iterator end()			{ return _last;		}
const_iterator begin() const;
const_iterator end() const;

reverse_iterator rbegin();
reverse_iterator rend();
const_reverse_iterator rbegin() const;
const_reverse_iterator rend() const;

//---------------------------- Capacity ----------------------------
size_type size() const					{ return _len; 				}
bool empty() const;

size_type max_size() const				{ return _alloc.max_size(); }
size_type capacity() const				{ return _capacity; 		}

void reserve (size_type n);
void resize (size_type n, value_type val = value_type());

//---------------------------- Element access ----------------------------
reference operator[] (size_type n);
const_reference operator[] (size_type n) const;

reference at (size_type n);
const_reference at (size_type n) const;

reference front();
const_reference front() const;

reference back();
const_reference back() const;

//---------------------------- Modifiers ----------------------------
// range (1)	
template <class InputIterator>
  void assign (InputIterator first, InputIterator last);
// fill (2)	
void assign (size_type n, const value_type& val);

void push_back (const value_type& val)
{
	if(_len == 0)
		ft_realloc(1);
	else if(_len == _capacity)
		ft_realloc(_capacity * 2);
	_alloc.construct(_last, val);
	_last = &_first[++_len];
}

void pop_back();

// single element (1)	
iterator insert (iterator position, const value_type& val);
// fill (2)	
    void insert (iterator position, size_type n, const value_type& val);
// range (3)	
template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last);

iterator erase (iterator position);
iterator erase (iterator first, iterator last);

void swap (vector& x);

void clear() 
{
	if (_len == 0)
		return ;
	_alloc.deallocate(_first, _capacity);
	_len = 0;
	_capacity = 0;
	// ft_realloc(0);
}

//--------------------- Template specializations
// template < class T, class Alloc = std::allocator<T> > class vector; // generic template
// template <class Alloc> class vector<bool,Alloc>;               // bool specialization

};
//--------------------- Non-member function overloads ------------------------
template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

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


}// end namespace ft
#endif