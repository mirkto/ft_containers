#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include "list_iterator.hpp"
// # include "../utils/ft_enable_if.hpp"
// # include "Identifiers.hpp"

namespace ft {// start namespace ft

// --------------------------- struct s_list ---------------------------
template < typename T >
struct s_list
{
	T				value;
	struct s_list	*next_list;
	struct s_list	*prev_list;
};

// --------------------------- class list ---------------------------
template < class T, class Alloc = std::allocator<T> > 
class list
{
public:

	typedef T									value_type;
	typedef Alloc								allocator_type;
	typedef T &									reference;
	typedef T const &							const_reference;
	typedef T *									pointer;
	typedef T const *							const_pointer;
	typedef ptrdiff_t							difference_type;
	typedef size_t								size_type;
	typedef s_list<value_type>					node;
	typedef s_list<value_type> *					node_ptr;
	typedef std::allocator<node>				allocator_node;

	typedef typename ft::ListIterator<T>				iterator;
	typedef typename ft::ConstListIterator<T>			const_iterator;
	typedef typename ft::ReverseListIterator<T>			reverse_iterator;
	typedef typename ft::ConstReverseListIterator<T>	const_reverse_iterator;

private:
	allocator_type				_alloc;
	allocator_node				_alloc_node;
	node_ptr					_tail;
	size_t						_len;
// --------------------------- private metods ---------------------------
	void				tail_vallen()
	{
		// if (std::isdigit(_tail->value))
			_tail->value = _len;
	}

public:
// --------------------------- Constructors ---------------------------
	// --- default
	explicit list(const allocator_type& alloc = allocator_type())
	{
		_alloc = alloc;
		// _tail = new s_list<value_type>;
		_tail = _alloc_node.allocate(1);
		_alloc_node.construct(_tail, node());
		_tail->next_list = _tail;
		_tail->prev_list = _tail;
		_len = 0;
		// bzero(&_tail->value, sizeof(T));
	}

	// --- fill
	explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	{
		_alloc = alloc;
		_tail = new s_list<value_type>;
		_tail->next_list = _tail;
		_tail->prev_list = _tail;
		_len = 0;
		bzero(&_tail->value, sizeof(T));
		for (size_type i = 0; i < n; i++)
			push_back(val);
	}

	// --- range
	template <class InputIterator>
	list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename std::enable_if<! std::numeric_limits< InputIterator >::is_specialized >::type* = NULL)
		// typename ft::enable_if<!is_integral<InputIterator>::value> * = NULL)
	{
		_alloc = alloc;
		_tail = new s_list<value_type>;
		_tail->next_list = _tail;
		_tail->prev_list = _tail;
		_len = 0;
		bzero(&_tail->value, sizeof(T));
		for (; first != last; first++)
			push_back(*first);
	}

	// --- destructor
	virtual ~list()
	{
		clear();
		delete _tail;
	}

	// --- copy
	list (const list& x)
	{
		// _alloc = x.alloc;
		_tail = new s_list<value_type>;
		_tail->next_list = _tail;
		_tail->prev_list = _tail;
		_len = 0;
		bzero(&_tail->value, sizeof(T));
		*this = x;
	}

	list& operator= (const list& x)
	{
		clear();
		struct s_list<T>	*tmp;
		if(x._len != 0)
			for(tmp = x._tail->next_list; _len != x._len; tmp = tmp->next_list)
				push_back(tmp->value);
		return *this;
	}

// --------------------------- Modifiers ---------------------------
	void			push_back( value_type value)
	{

		s_list<value_type> *new_list;
		new_list = new s_list<value_type>;
		if (_len == 0)
		{
			_tail->next_list = new_list;
			_tail->prev_list = new_list;
			new_list->prev_list = _tail;
			new_list->next_list = _tail;
		}
		else
		{
			_tail->prev_list->next_list = new_list;
			new_list->prev_list = _tail->prev_list;
			_tail->prev_list = new_list;
			new_list->next_list = _tail;
		}
		new_list->value = value;
		++_len;
		tail_vallen();
	}

	void			push_front( value_type value)
	{
		s_list<value_type> *new_list;
		new_list = new s_list<value_type>;
		if (_len == 0)
		{
			_tail->next_list = new_list;
			_tail->prev_list = new_list;
			new_list->prev_list = _tail;
			new_list->next_list = _tail;
		}
		else
		{
			_tail->next_list->prev_list = new_list;
			new_list->next_list = _tail->next_list;
			_tail->next_list = new_list;
			new_list->prev_list = _tail;
		}
		new_list->value = value;
		++_len;
		tail_vallen();
	}

	void			pop_back()
	{
		if (_len == 0)
			return ;
		s_list<value_type> *new_back_list;
		new_back_list = _tail->prev_list->prev_list;

		_tail->prev_list->prev_list->next_list = _tail;
		delete _tail->prev_list;
		_tail->prev_list = new_back_list;
		--_len;
		tail_vallen();
	}

	void			pop_front()
	{
		if (_len == 0)
			return ;
		s_list<value_type> *new_front_list;
		new_front_list = _tail->next_list->next_list;

		_tail->next_list->next_list->prev_list = _tail;
		delete _tail->next_list;
		_tail->next_list = new_front_list;
		--_len;
		tail_vallen();
	}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = NULL)
		// typename ft::enable_if<!is_integral<InputIterator>::value> * = NULL )
	{
		clear();
		for(; first != last; first++)
			push_back(*first);
	}

	void assign (size_type n, const value_type& val)
	{
		clear();
		for(; _len != n; )
			push_back(val);
	}

	iterator insert (iterator position, const value_type& val)
	{
		if (_len == 0)
			push_back(val);
		else
		{
			s_list<value_type> *new_list;
			new_list = new s_list<value_type>;
			new_list->value = val;
			new_list->next_list = position.getlist();
			new_list->prev_list = position.getlist()->prev_list;
			position.getlist()->prev_list->next_list = new_list;
			position.getlist()->prev_list = new_list;
			_len++;
			tail_vallen();
		}
		return --position;
	}

	void insert (iterator position, size_type n, const value_type& val)
	{
		for (; n != 0; n--)
			insert(position, val);
		return ;
	}

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = NULL)
		// typename ft::enable_if<!is_integral<InputIterator>::value> * = NULL )
	{
		for (; first != last; first++)
			insert(position, *first);
		return ;
	}

	iterator erase (iterator position)
	{
		if (position.getlist() == _tail)
			return position;
		position.getlist()->prev_list->next_list = position.getlist()->next_list;
		position.getlist()->next_list->prev_list = position.getlist()->prev_list;
		delete position.getlist();
		--_len;
		tail_vallen();
		return position.getlist()->next_list;
	}

	iterator erase (iterator first, iterator last)
	{
		for (; first != last; first++)
			erase(first);
		return first;
	}

	void swap (list & x)
	{
		list<value_type> tmp;

		tmp = *this;
		*this = x;
		x = tmp;
	}

	void resize (size_type n, value_type val = value_type())
	{
		if (n < _len)
			while (_len != n)
				pop_back();
		else if (n > _len)
			while (_len != n)
				push_back(val);
	}

	void clear() {
		while (_len != 0)
			pop_back();
	}

// --------------------------- Operations ---------------------------
	void splice (iterator position, list& x)
	{
		for (iterator it = x.begin(); it != x.end(); it++)
			insert(position, *it);
		x.clear();
	}

	void splice (iterator position, list& x, iterator i)
	{
		for(iterator it = x.begin(); it != x.end(); it++)
			if (i == it)
			{
				insert(position, *i);
				x.erase(i);
			}
	}

	void splice (iterator position, list& x, iterator first, iterator last)
	{
		for (; first != last; first++)
			splice(position, x, first);
	}

	void remove (const value_type& val)
	{
		s_list<value_type> *	tmp;
		tmp = _tail->next_list;

		for (size_type i = _len; i != 0; --i)
		{
			if (tmp->value == val)
			{
				tmp->next_list->prev_list = tmp->prev_list;
				tmp->prev_list->next_list = tmp->next_list;
				--_len;
				delete tmp;
			}
			tmp = tmp->next_list;
		}
	}

	template <class Predicate>
	void remove_if (Predicate pred)
	{
		for (iterator it = begin(); it != end(); it++)
			if (pred(*it))
				erase(it);
	}

	void unique()
	{
		for (iterator	it = begin(); it != end(); )
			if (*it == *(++it))
				erase(it);
	}
 
	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred)
	{
		for (iterator	it = begin(); it != end(); )
			if (binary_pred(*it, *(++it)))
				erase(it);
	}

	void merge (list& x)
	{
		if (&x == this)
		return ;

		iterator it = begin();
		iterator it2 = x.begin();

		while (it != end() && it2 != x.end())
		{
			while (it2 != x.end() && *it > *it2)
			{
				insert(it, it2.getlist()->value);
				it2++;
			}
			it++;
		}
		if (it2 != x.end())
		this->splice(end(), x, it2, x.end());
		x.clear();
	}

	template <class Compare>
	void merge (list& x, Compare comp)
	{
		if (this->end() == x.end())
			return ;
		for(iterator it = begin(); it != end(); it++)
			if (comp(*x.begin(), *it))
				splice(it, x);
	}

	void sort()
	{
		s_list<value_type> *	tmp;
		value_type				tmp_val;
		tmp = _tail->next_list;

		while (tmp->next_list != _tail)
		{
			if (tmp->value > tmp->next_list->value)
			{
				tmp_val = tmp->value;
				tmp->value = tmp->next_list->value;
				tmp->next_list->value = tmp_val;
				tmp = _tail;
			}
			tmp = tmp->next_list;
		}
	}

	template <class Compare>
	void sort(Compare comp)
	{
		s_list<value_type> *	tmp;
		value_type				tmp_val;
		tmp = _tail->next_list;

		while (tmp->next_list != _tail)
		{
			if (comp(tmp->next_list->value, tmp->value))
			{
				tmp_val = tmp->value;
				tmp->value = tmp->next_list->value;
				tmp->next_list->value = tmp_val;
				tmp = _tail;
			}
			tmp = tmp->next_list;
		}
	}

	void reverse()
	{
		iterator	it = --end();
		for (size_t i = size(); i != 0; i--)
		{
			push_back(*it);
			erase(it--);
		}
	}

// --------------------------- Element access ---------------------------
	reference		front()				{ return _tail->next_list->value; }
	const_reference	front() const		{ return _tail->next_list->value; }
	reference		back()				{ return _tail->prev_list->value; }
	const_reference	back() const		{ return _tail->prev_list->value; }

// --------------------------- Capacity ---------------------------
	size_type		size() const		{ return _len;			}
	bool			empty() const		{ return _len == 0;		}
	size_type		max_size() const	{ return
		std::numeric_limits<size_type>::max() / sizeof(ft::list<T>);	}

// --------------------------- Iterators ---------------------------
	iterator begin()						{ return iterator(_tail->next_list);				}
	iterator end()							{ return iterator(_tail);							}
	const_iterator begin() const			{ return const_iterator(_tail->next_list);			}
	const_iterator end() const				{ return const_iterator(_tail);						}

	reverse_iterator rbegin()				{ return reverse_iterator(_tail->prev_list);		}
	reverse_iterator rend()					{ return reverse_iterator(_tail);					}
	const_reverse_iterator rbegin() const	{ return const_reverse_iterator(_tail->prev_list);	}
	const_reverse_iterator rend() const		{ return const_reverse_iterator(_tail);				}
};

// --------------------------- Non-member functions ---------------------------

	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y)
	{ x.swap(y); }

// --------------------------- Relational operators ---------------------------
	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::list<T>::iterator	r_it = rhs.begin();
		typename ft::list<T>::iterator	l_it = lhs.begin();
		for (; l_it != lhs.end(); l_it++, r_it++)
			if (*l_it != *r_it)
				return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{ return !(lhs == rhs); }

	template <class T, class Alloc>
	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		typename ft::list<T>::iterator	r_it = rhs.begin();
		typename ft::list<T>::iterator	l_it = lhs.begin();
		for (; l_it != lhs.end(); l_it++, r_it++)
			if (*l_it != *r_it)
				break ;
		return (*l_it < *r_it);
	}

	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{ return !(rhs < lhs); }

	template <class T, class Alloc>
	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{ return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{ return !(lhs < rhs); }

}// end namespace ft
#endif