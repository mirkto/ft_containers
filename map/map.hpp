#ifndef map_HPP
# define map_HPP

# include <iostream>
# include "map_iterator.hpp"
// # include "../utils/ft_enable_if.hpp"
// # include "Identifiers.hpp"

namespace ft {// start namespace ft

// --------------------------- struct s_map ---------------------------
template < class T >// <class Key, class T> // 
struct					s_map
{
	// std::pair<const Key, T>		value;
	T							*value;
	struct s_map				*prev;
	struct s_map				*right;
	struct s_map				*left;
	// int					color; // for red/black
	// size_t				height; // for AVL

	// // construct default - clear trash
	// s_map() { std::memset(&value, 0, sizeof(value)); }
	// // construct default - for map<char, int>
	// s_map() : value('a',0) { value.second = 1; }

	// // construct default
	// s_map(const Key &k, T &val ) : value(Key, T) {}

	s_map() {}
	// s_map(T * value) : value(value) {}		// for -> node(&tmp_pair)
	s_map(T & value) : value(&value) {}		// for -> node(tmp_pair))
	~s_map() { }
};

// --------------------------- class map ---------------------------
template <	class Key,												// map::key_type
			class T,												// map::mapped_type
			class Compare = std::less<Key>,							// map::key_compare
			class Alloc = std::allocator<std::pair<const Key,T> >	// map::allocator_type // const
			>
class map
{
	// template <class> friend class MapIterator;
public:
	typedef const Key								key_type; // const
	typedef T										mapped_type;
	typedef std::pair<const key_type, mapped_type>	value_type; // const
	typedef ft::s_map<value_type> 					node;
	typedef std::allocator<node>					alloc_node;

	typedef Compare									key_compare;
	typedef std::ptrdiff_t							difference_type;
	typedef std::size_t								size_type;

	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	typedef ft::MapIterator<value_type>					iterator;
	typedef ft::ConstMapIterator<value_type>			const_iterator;
	typedef ft::ReverseMapIterator<value_type>			reverse_iterator;
	typedef ft::ConstReverseMapIterator<value_type>		const_reverse_iterator;

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
	allocator_type		_alloc;
	key_compare			_comp;
	node				*_root;
	size_t				_len;

	// node				*_begin;	// = _tail;
	// node				*_end;	// = _tail;
	// node				*_start;	// = _tail->left, _tail->right;
	// node				*_last;	// = _tail->prev; 
	node			*_tail;
	node			*_empty_node;

	alloc_node		_alloc_node;
	


// --------------------------- private metods ---------------------------
void			empty_tail()
{
	_tail = _alloc_node.allocate(1);
	_alloc_node.construct(_tail, node());
	// // print size_val
	// std::cout << "size_construct: " << sizeof(*_tail) << std::endl;
	_tail->value = nullptr;
	_tail->prev = _tail;
	_tail->left = _tail;
	_tail->right = _tail;

	// _begin = _alloc_node.allocate(1);	// _end = _alloc_node.allocate(1);
	// _alloc_node.construct(_begin, s_map);	// _alloc_node.construct(_end, s_map);
	// _begin->prev = _end;	// _begin->left = _end;	// _begin->right = _end;
	// _end->prev = _begin;	// _end->left = _begin;	// _end->right = _begin;
}

node *			empty_node()
{
	node	*tmp_node = _alloc_node.allocate(1);
	tmp_node->value = nullptr;
	tmp_node->prev = _tail;
	tmp_node->left = _tail;
	tmp_node->right = _tail;
	_empty_node = tmp_node;
	++_len;
	return tmp_node;
}

void			new_node(key_type k,mapped_type m)
{
	node			*tmp_node = empty_node();
	value_type		tmp_pair = value_type(k, m);
	
	// // --- print value of new node
	// std::cout << "new_node - |" << tmp_pair.first << "/" << tmp_pair.second << "|" << std::endl;

	// _alloc_node.construct(tmp_node, node(&tmp_pair)); // for . s_map(T * value) : value(value) {}
	_alloc_node.construct(tmp_node, node(tmp_pair)); // for -> s_map(T & value) : value(&value) {}

	// --- print value of new node
	std::cout << "map_key: '" << (tmp_node->value)->first << "' | map_value: \"" << (tmp_node->value)->second << "\"" << std::endl;

	if(_len == 0)
	{
		_root = tmp_node;
		_root->prev = _tail;
		_root->left = _tail;
		_root->right = _tail;
		_tail->prev = _root;
		_tail->left = _root;
		_tail->right = _root;
	}
	else
	{
		_empty_node = tmp_node;
		_tail->left->left = _empty_node;
		_empty_node->prev = _tail->prev;
		_tail->prev = _empty_node;
		_empty_node->left = _tail;
	}
}

// map(node & node, value_type & pair)
// {
// 	_alloc_node.construct(node, node(pair));
// }

// map(value_type & pair)
// {
	
// }

public:
void		add_node(key_type k,mapped_type m)
{
	new_node(k, m);
}

// --------------------------- Constructors ---------------------------
	// --- default
	explicit map(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _comp(comp), _root(NULL), _len(0)
	{
		empty_tail();
		// empty_node();
		// _new_node('X',21);
		// // test key/val
		// std::cout << "! - |" << (_tail->value).first << "/" << (_tail->value).second << "|" << std::endl;

	}

	// --- range
	template <class InputIterator>
	map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());

	// --- destructor
	virtual ~map()
	{
		clear();

		_alloc_node.destroy(_tail);
		_alloc_node.deallocate(_tail, 1);
		if(_len == 0)
			return ;
		_alloc_node.destroy(_empty_node);
		_alloc_node.deallocate(_empty_node, 1);
	}

	// --- copy
	map (const map& x);
	map& operator= (const map& x);

// --------------------------- Modifiers ---------------------------
	//single element (1)	
	std::pair<iterator,bool> insert (const value_type& val);

	//with hint (2)	
	iterator insert (iterator position, const value_type& val);

	//range (3)	
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

	void erase (iterator position);

	size_type erase (const key_type& k);

	void erase (iterator first, iterator last);

	void swap (map& x);

	void clear()
	{
		if(_len == 0)
			return ;
		// _alloc_node.destroy(_root);
		// _alloc_node.deallocate(_root, 1);
	}

// --------------------------- Operations ---------------------------
	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;

	size_type count (const key_type& k) const;

	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const;

	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;

	std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	std::pair<iterator,iterator>             equal_range (const key_type& k);

// --------------------------- Element access ---------------------------
	mapped_type& operator[] (const key_type& k)
	{
		iterator	src = find(k);
		if(src.getMap() == _tail)
		{
			insert(std::make_pair(k, mapped_type()));
			src = find(k);
			return(src.getMap()->value.second);
		}
		else
			return(src.getMap()->value.second);
	}

// --------------------------- Capacity ---------------------------
	size_type		size() const		{ return _len;			}
	bool			empty() const		{ return _len == 0;		}
	size_type		max_size() const	{ return
		// std::numeric_limits<size_type>::max() / sizeof(ft::map<Key,T>);	}
		_alloc.max_size(); }

// --------------------------- Iterators ---------------------------
	iterator begin()						{ return iterator(_tail);				}
	iterator end()							{ return iterator(_tail);				}
	const_iterator begin() const			;//{ return const_iterator(_tail->next_map);			}
	const_iterator end() const				;//{ return const_iterator(_tail);						}

	reverse_iterator rbegin()				;//{ return reverse_iterator(_tail->prev_map);		}
	reverse_iterator rend()					;//{ return reverse_iterator(_tail);					}
	const_reverse_iterator rbegin() const	;//{ return const_reverse_iterator(_tail->prev_map);	}
	const_reverse_iterator rend() const		;//{ return const_reverse_iterator(_tail);				}

// --------------------------- Observers ---------------------------
	key_compare key_comp() const		{ return _comp;					}
	value_compare value_comp() const	{ return value_compare(_comp);	}

//--------------------- Allocator ---------------------------
	allocator_type		get_allocator () const	{ return _alloc; }
};

}// end namespace ft
#endif