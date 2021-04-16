#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include "Iterator.hpp"

# include <list>
# include <iterator>

namespace ft {

// --------------------------- struct s_list ---------------------------
template < typename T >
struct s_list
{
	T				value;
	size_t			len;
	struct s_list	*next_list;
	struct s_list	*prev_list;
};

// --------------------------- class List ---------------------------
template < class T, class Alloc = std::allocator<T> > 
class List
{
public:
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef T &											reference;
	typedef T const &									const_reference;
	typedef T *											pointer;
	typedef T const *									const_pointer;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

	typedef typename ft::ListIterator<T>				iterator;
	typedef typename ft::ConstListIterator<T>			const_iterator;
	typedef typename ft::ReverseListIterator<T>			reverse_iterator;
	typedef typename ft::ConstReverseListIterator<T>	const_reverse_iterator;

	// typedef typename ft::ListIterator<pointer>					iterator;
	// typedef typename ft::ListIterator<const_pointer>			const_iterator;
	// typedef typename ft::ReverseListIterator<pointer>			reverse_iterator;
	// typedef typename ft::ReverseListIterator<const_pointer>		const_reverse_iterator;

private:
	allocator_type				_alloc;
	s_list<value_type> *		_tail;
public:
// --------------------------- Constructors ---------------------------
	// --- default
	explicit List(const allocator_type& alloc = allocator_type())
	{
		_alloc = alloc;
		_tail = new s_list<value_type>;
		_tail->next_list = _tail;
		_tail->prev_list = _tail;
		_tail->len = 0;
		bzero(&_tail->value, sizeof(T));
	}

	// --- fill
	explicit List(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
	{
		_alloc = alloc;
		_tail = new s_list<value_type>;
		_tail->next_list = _tail;
		_tail->prev_list = _tail;
		_tail->len = 0;
		bzero(&_tail->value, sizeof(T));
		for (size_type i = 0; i < n; i++)
			this->push_back(val);
	}

	// --- range
	template <class InputIterator, 
	class std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type*>
	List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	{
		if (!first || !last)
			std::cout << " --- empty input iterator ---" << std::endl;
		_alloc = alloc;
		_tail = new s_list<value_type>;
		_tail->next_list = _tail;
		_tail->prev_list = _tail;
		_tail->len = 0;
		bzero(&_tail->value, sizeof(T));
		for (; first != last; first++)
			push_back(*first);
	}

	// --- destructor
	virtual ~List()
	{
		clear();
		delete _tail;
	}

	// --- copy
	List (const List& x) {
		_tail = new s_list<value_type>;
		_tail->next_list = _tail;
		_tail->prev_list = _tail;
		_tail->len = 0;
		bzero(&_tail->value, sizeof(T));
		*this = x;
	}

	List& operator= (const List& x)
	{
		struct s_list<T>	*tmp;
		tmp = x._tail->next_list; 

		clear();
		if(x._tail->len != 0)
			for(; _tail->len != x._tail->len; tmp = tmp->next_list)
				push_back(tmp->value);
		return *this;
	}

// --------------------------- Modifiers ---------------------------
	void			push_back( value_type value)
	{

		s_list<value_type> *new_list;
		new_list = new s_list<value_type>;
		new_list->len = 0;
		if (_tail->len == 0)
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
		++_tail->len;
	}

	void			push_front( value_type value)
	{
		s_list<value_type> *new_list;
		new_list = new s_list<value_type>;
		new_list->len = 0;
		if (_tail->len == 0)
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
		++_tail->len;
	}

	void			pop_back()
	{
		if (_tail->len == 0)
			return ;
		s_list<value_type> *new_back_list;
		new_back_list = _tail->prev_list->prev_list;

		_tail->prev_list->prev_list->next_list = _tail;
		delete _tail->prev_list;
		_tail->prev_list = new_back_list;
		--_tail->len;
	}

	void			pop_front()
	{
		if (_tail->len == 0)
			return ;
		s_list<value_type> *new_front_list;
		new_front_list = _tail->next_list->next_list;

		_tail->next_list->next_list->prev_list = _tail;
		delete _tail->next_list;
		_tail->next_list = new_front_list;
		--_tail->len;
	}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last);
	void assign (size_type n, const value_type& val);

	iterator insert (iterator position, const value_type& val);
	void insert (iterator position, size_type n, const value_type& val);
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last);

	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);

	void swap (List & x)
	{
		List<value_type> tmp;

		tmp = *this;
		*this = x;
		x = tmp;
	}

	void resize (size_type n, value_type val = value_type())
	{
		if (n < _tail->len)
			while (_tail->len != n)
				pop_back();
		else if (n > _tail->len)
			while (_tail->len != n)
				push_back(val);
	}

	void clear() {
		while (_tail->len != 0)
			pop_back();
	}

// --------------------------- Operations ---------------------------
	void splice (iterator position, List& x);
	void splice (iterator position, List& x, iterator i);
	void splice (iterator position, List& x, iterator first, iterator last);

	void remove (const value_type& val)
	{
		s_list<value_type> *	tmp;
		tmp = _tail->next_list;

		for (size_type i = _tail->len; i != 0; --i)
		{
			if (tmp->value == val)
			{
				tmp->next_list->prev_list = tmp->prev_list;
				tmp->prev_list->next_list = tmp->next_list;
				--_tail->len;
				delete tmp;
			}
			tmp = tmp->next_list;
		}
	}

	template <class Predicate>
	void remove_if (Predicate pred);

	void unique();
	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred);

	void merge (List& x);
	template <class Compare>
	void merge (List& x, Compare comp);

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

	void reverse();

// --------------------------- Element access ---------------------------
	reference		front()				{ return _tail->next_list->value; }
	const_reference	front() const		{ return _tail->next_list->value; }
	reference		back()				{ return _tail->prev_list->value; }
	const_reference	back() const		{ return _tail->prev_list->value; }

// --------------------------- Capacity ---------------------------
	size_type		size() const		{ return _tail->len;		}
	bool			empty() const		{ return _tail->len == 0;	}
	size_type		max_size() const	{ return _alloc.max_size();	}
										// return std::numeric_limits<difference_type>::max();

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
	void swap (List<T,Alloc>& x, List<T,Alloc>& y) { x.swap(y); }

// --------------------------- Relational operators ---------------------------
	template <class T, class Alloc>
	bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

}// end  of namespace ft
#endif