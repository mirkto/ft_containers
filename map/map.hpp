#ifndef map_HPP
# define map_HPP

# include <iostream>
# include "map_iterator.hpp"
// # include "../utils/ft_enable_if.hpp"
// # include "Identifiers.hpp"

namespace ft {// start namespace ft

// --------------------------- struct s_map ---------------------------
template < class Key, typename T >
struct					s_map
{
	std::pair<Key,T>	value;
	struct s_map		*parent;
	struct s_map		*right;
	struct s_map		*left;
};

// --------------------------- class map ---------------------------
template <	class Key,												// map::key_type
			class T,												// map::mapped_type
			class Compare = std::less<Key>,							// map::key_compare
			class Alloc = std::allocator<std::pair<const Key,T> >	// map::allocator_type
			>
class map
{
	// template <class> friend class MapIterator;
public:
	typedef struct s_map<Key,T> 				Node;
	typedef Key									key_type;
	typedef T									mapped_type;
	typedef pair<const key_type,mapped_type>	value_type;
	typedef Compare								key_compare;
	typedef ptrdiff_t							difference_type;
	typedef size_t								size_type;

	typedef Alloc								allocator_type;
	typedef allocator_type::reference			reference;
	typedef allocator_type::const_reference		const_reference;
	typedef allocator_type::pointer				pointer;
	typedef allocator_type::const_pointer		const_pointer;

	typedef typename ft::MapIterator<Key,T>					iterator;
	typedef typename ft::ConstMapIterator<Key,T>			const_iterator;
	typedef typename ft::ReverseMapIterator<Key,T>			reverse_iterator;
	typedef typename ft::ConstReverseMapIterator<Key,T>		const_reverse_iterator;

	class value_compare
	{
		friend class map;
		protected:
			Compare com;
			value_compare (Compare c) : com(c) {}

		public:
			typedef bool result;
			typedef value_type firstArg;
			typedef value_type secondArg;

			bool operator() (const value_type& lhs, const value_type& rhs) const
			{
				return com(lhs.first, rhs.first);
			}
	};


private:
	Node	*_map;
	Node	*_root;
	Node	*_start;
	Node	*_finish;
	Node	*_tail;
	Node	*_begin;
	
	allocator_type		_alloc;
	key_compare			_key;
	size_t				_len;

// --------------------------- private metods ---------------------------

public:
// --------------------------- Constructors ---------------------------
	// --- default
	explicit map(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());
	// {
	// 	_alloc = alloc;
	// 	_tail = new s_map<value_type>;
	// 	_tail->next_map = _tail;
	// 	_tail->prev_map = _tail;
	// 	_len = 0;
	// 	bzero(&_tail->value, sizeof(T));
	// }

	// --- range
	template <class InputIterator>
	map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());
	// {
	// 	_alloc = alloc;
	// 	_tail = new s_map<value_type>;
	// 	_tail->next_map = _tail;
	// 	_tail->prev_map = _tail;
	// 	_len = 0;
	// 	bzero(&_tail->value, sizeof(T));
	// 	for (; first != last; first++)
	// 		push_back(*first);
	// }

	// --- destructor
	virtual ~map();
	// {
	// 	clear();
	// 	delete _tail;
	// }

	// --- copy
	map (const map& x);
	// {
	// 	// _alloc = x.alloc;
	// 	_tail = new s_map<value_type>;
	// 	_tail->next_map = _tail;
	// 	_tail->prev_map = _tail;
	// 	_len = 0;
	// 	bzero(&_tail->value, sizeof(T));
	// 	*this = x;
	// }

	map& operator= (const map& x);
	// {
	// 	clear();
	// 	struct s_map<T>	*tmp;
	// 	if(x._len != 0)
	// 		for(tmp = x._tail->next_map; _len != x._len; tmp = tmp->next_map)
	// 			push_back(tmp->value);
	// 	return *this;
	// }

// --------------------------- Modifiers ---------------------------
//single element (1)	
pair<iterator,bool> insert (const value_type& val);
	// iterator insert (iterator position, const value_type& val)
	// {
	// 	if (_len == 0)
	// 		push_back(val);
	// 	else
	// 	{
	// 		s_map<value_type> *new_map;
	// 		new_map = new s_map<value_type>;
	// 		new_map->value = val;
	// 		new_map->next_map = position.getmap();
	// 		new_map->prev_map = position.getmap()->prev_map;
	// 		position.getmap()->prev_map->next_map = new_map;
	// 		position.getmap()->prev_map = new_map;
	// 		_len++;
	// 		tail_vallen();
	// 	}
	// 	return --position;
	// }

//with hint (2)	
iterator insert (iterator position, const value_type& val);

//range (3)	
template <class InputIterator>
void insert (InputIterator first, InputIterator last);
	// template <class InputIterator>
	// void insert (iterator position, InputIterator first, InputIterator last,
	// 	typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = NULL)
	// 	// typename ft::enable_if<!is_integral<InputIterator>::value> * = NULL )
	// {
	// 	for (; first != last; first++)
	// 		insert(position, *first);
	// 	return ;
	// }

	void erase (iterator position);
	// iterator erase (iterator position)
	// {
	// 	if (position.getmap() == _tail)
	// 		return position;
	// 	position.getmap()->prev_map->next_map = position.getmap()->next_map;
	// 	position.getmap()->next_map->prev_map = position.getmap()->prev_map;
	// 	delete position.getmap();
	// 	--_len;
	// 	tail_vallen();
	// 	return position.getmap()->next_map;
	// }

	size_type erase (const key_type& k);

	void erase (iterator first, iterator last);
	// iterator erase (iterator first, iterator last)
	// {
	// 	for (; first != last; first++)
	// 		erase(first);
	// 	return first;
	// }

	void swap (map& x);
	// void swap (map & x)
	// {
	// 	map<value_type> tmp;

	// 	tmp = *this;
	// 	*this = x;
	// 	x = tmp;
	// }

	void clear();
	// void clear() {
	// 	while (_len != 0)
	// 		pop_back();
	// }

// --------------------------- Operations ---------------------------
	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;

	size_type count (const key_type& k) const;

	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const;

	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	pair<iterator,iterator>             equal_range (const key_type& k);

// --------------------------- Element access ---------------------------
	mapped_type& operator[] (const key_type& k);
	// {
	// 	iterator src = find(k);
	// 	if(src.getMap() == _tail)
	// 	{
	// 		insert(std::make_pair(k, mapped_type()));
	// 		src = find(k);
	// 		return(src.getMap()->key_value.second);
	// 	}
	// 	else
	// 		return(src.getMap()->key_value.second);
	// }

// --------------------------- Capacity ---------------------------
	size_type		size() const		{ return _len;			}
	bool			empty() const		{ return _len == 0;		}
	size_type		max_size() const	{ return
		// std::numeric_limits<size_type>::max() / sizeof(ft::map<Key,T>);	}
		_alloc.max_size(); }

// --------------------------- Iterators ---------------------------
	iterator begin()						{ return iterator(_tail->next_map);				}
	iterator end()							{ return iterator(_tail);							}
	const_iterator begin() const			{ return const_iterator(_tail->next_map);			}
	const_iterator end() const				{ return const_iterator(_tail);						}

	reverse_iterator rbegin()				{ return reverse_iterator(_tail->prev_map);		}
	reverse_iterator rend()					{ return reverse_iterator(_tail);					}
	const_reverse_iterator rbegin() const	{ return const_reverse_iterator(_tail->prev_map);	}
	const_reverse_iterator rend() const		{ return const_reverse_iterator(_tail);				}

// --------------------------- Observers ---------------------------
	key_compare key_comp() const		{ return _key;					}
	value_compare value_comp() const	{ return value_compare(_key);	}

//--------------------- Allocator ---------------------------
	allocator_type		get_allocator () const	{ return _alloc; }
};

}// end namespace ft
#endif