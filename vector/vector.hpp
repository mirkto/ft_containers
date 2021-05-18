#ifndef VECTOR_HPP
# define VECTOR_HPP
 
# include <iostream>
# include "vector_iterator.hpp"
// # include "../utils/ft_enable_if.hpp"

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
explicit vector (const allocator_type& alloc = allocator_type())
: _alloc(alloc), _first(NULL), _last(NULL), _capacity(0), _len(0) {}

// fill constructor
explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
: _alloc(alloc), _first(NULL), _last(NULL), _capacity(0), _len(0)
{
	ft_realloc(n);
	for(size_type i = 0; i != n; ++i, ++_last, ++_len)
		_alloc.construct(_last, val);
}

// range constructor
template <class InputIterator>
vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
	typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = NULL )
	// typename ft::enable_if<!is_integral<InputIterator>::value> * = NULL )
: _alloc(alloc), _first(NULL), _last(NULL), _capacity(0), _len(0)
{
	for(; first != last; ++first)
		push_back(*first);
}

// copy constructor
vector (const vector& x)
: _alloc(x._alloc), _first(NULL), _last(NULL), _capacity(0), _len(0)
{
	ft_realloc(x._capacity);
	*this = x;
}

// default destructor
virtual ~vector()
{
	clear();
	ft_realloc(0);
}

// assignment
vector& operator= (const vector& x)
{
	clear();
	if(_capacity < x._capacity)
		ft_realloc(x._capacity);
	for(ft::VectorIterator<T> first = x.begin(); first != x._last; ++first, ++_last, ++_len)
		_alloc.construct(_last, *first);
	return *this;
}

//---------------------------- Iterators ----------------------------
iterator begin()				{ return iterator(_first);			}
iterator end()					{ return iterator(_last);			}
const_iterator begin() const	{ return const_iterator(_first);	}
const_iterator end() const		{ return const_iterator(_last);		}

reverse_iterator rbegin()				{ return reverse_iterator(_last - 1);				}
reverse_iterator rend()					{ return reverse_iterator(_first - 1);				}
const_reverse_iterator rbegin() const	{ return const_reverse_iterator(_first[_len - 1]);	}
const_reverse_iterator rend() const		{ return const_reverse_iterator(_first - 1);		}

//---------------------------- Capacity ----------------------------
size_type size() const					{ return _len; 				}
bool empty() const						{ return _len == 0;			}
size_type max_size() const				{ return _alloc.max_size(); }
size_type capacity() const				{ return _capacity; 		}

void reserve (size_type n)
{
	if(n > _capacity)
		ft_realloc(n);
}

void resize (size_type n, value_type val = value_type())
{
	while(n < _len)
		pop_back();
	while(n > _len)
		push_back(val);
}

//---------------------------- Element access ----------------------------
reference operator[] (size_type n)				{ return _first[n];		}
const_reference operator[] (size_type n) const	{ return _first[n];		}
reference front()								{ return *_first;		}
const_reference front() const					{ return *_first;		}
reference back()								{ return *(_last - 1);	}
const_reference back() const					{ return *(_last - 1);	}

reference at (size_type n)						{
	if(n < 0 && n > _len)
		throw std::out_of_range("");
	else
		return (_first[n]);							}
const_reference at (size_type n) const			{ return at(n);			}

//---------------------------- Modifiers ----------------------------
// range (1)	
template <class InputIterator>
void assign (InputIterator first, InputIterator last,
	typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = NULL )
	// typename ft::enable_if<!is_integral<InputIterator>::value> * = NULL )
{
	clear();
	size_type i = 0;
	for(InputIterator it = first; it != last; ++it)
		++i;
	ft_realloc(i);
	insert(begin(), first, last);
	_len = i;
}
// fill (2)	
void assign (size_type n, const value_type& val)
{
	clear();
	ft_realloc(n);
	for(size_type i = 0; i != n; ++i)
		push_back(val);
}

void push_back (const value_type& val)
{
	if(_capacity == 0)
		ft_realloc(1);
	else if(_len == _capacity)
		ft_realloc(_capacity * 2);
	++_len;
	_alloc.construct(_last, val);
	_last = &_first[_len];
}

void pop_back()
{
	if (_len == 0)
		return ;
	--_len;
	_alloc.destroy(_last);
	_last = &_first[_len];
}

// single element (1)
iterator insert (iterator position, const value_type& val)
{
	difference_type		diff;
	diff = position.operator->() - begin().operator->();
	if(_capacity == 0)
	{
		ft_realloc(1);
		push_back(val);
	}
	else if(_len == _capacity)
		ft_realloc(_capacity * 2);
	++_len;
	// *(begin() + diff) = val;
	// *(--_last + diff) = val;
	_last = _first + diff;
	value_type	tmp_val = *_last;
	value_type	tmp;
	_alloc.destroy(_last);
	_alloc.construct(_last, val);
	while(_last != &_first[_len])
	{
		++_last;
		tmp = *_last;
		_alloc.destroy(_last);
		_alloc.construct(_last, tmp_val);
		// push_back(tmp_val);
		tmp_val = tmp;
	}
	_last = &_first[_len];
	return _first + diff;
}

// fill (2)
void insert (iterator position, size_type n, const value_type& val)
{
	for(; n > 0; --n)
		insert(position, val);
}

// range (3)
template <class InputIterator>
void insert (iterator position, InputIterator first, InputIterator last,
	typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = NULL )
	// typename ft::enable_if<!is_integral<InputIterator>::value> * = NULL )
{
	difference_type		diff;
	diff = position.operator->() - begin().operator->();

	for(iterator it = first, ite = last; ite != it; --ite)
		insert(_first + diff, *(ite - 1)); 
}

iterator erase (iterator position)
{
	difference_type		diff;
	diff = position.operator->() - begin().operator->();
	_last = _first + diff;

	// _alloc.destroy(_last);
	--_len;

	for(; _last != &_first[_len]; ++_last)
	{
		_alloc.destroy(_last);
		_alloc.construct(_last, *(_last + 1));
	}
	_last = &_first[_len];
	return _first + diff;
}

iterator erase (iterator first, iterator last)
{
	// std::cout << *(tmp_first) << std::endl;
	difference_type		diff;
	diff = first.operator->() - begin().operator->();

	iterator	tmp_first = _first;
	while(tmp_first != first)
		++tmp_first;

	iterator	tmp_last = tmp_first;
	while(tmp_last != last)
		++tmp_last;

	for(iterator it = tmp_first, ite = tmp_last; it != ite; ++it)
		erase(tmp_first);

	_last = &_first[_len];
	return _first + diff;
}

void swap (vector& x)
{
	vector	tmp;

	tmp = *this;
	*this = x;
	x = tmp;
}

void clear() 
{
	while (_len != 0)
		pop_back();
}

//--------------------- Template specializations
// template < class T, class Alloc = std::allocator<T> >
// class vector;									// generic template

// template <class Alloc>
// class vector<bool,Alloc>;						// bool specialization

//--------------------- Allocator
allocator_type		get_allocator () const	{ return _alloc; }

};
//--------------------- Non-member function overloads ------------------------
template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{ x.swap(y); }

template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T>::iterator	r_it = rhs.begin();
	typename ft::vector<T>::iterator	l_it = lhs.begin();
	for (; l_it != lhs.end(); l_it++, r_it++)
		if (*l_it != *r_it)
			return false;
	return true;
}

template <class T, class Alloc>
bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return !(lhs == rhs); }

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	typename ft::vector<T>::iterator	r_it = rhs.begin();
	typename ft::vector<T>::iterator	l_it = lhs.begin();
	for (; l_it != lhs.end(); l_it++, r_it++)
		if (*l_it != *r_it)
			break ;
	return (*l_it < *r_it);
}

template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return !(rhs < lhs); }

template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return (rhs < lhs); }

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return !(lhs < rhs); }

}// end namespace ft
#endif