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
	T							value;
	struct s_map				*prev;
	struct s_map				*right;
	struct s_map				*left;
	// int					color; // for red/black
	// size_t				height; // for AVL

	s_map() {}
	// s_map(T * value) : value(value) {}		// for -> node(&tmp_pair)
	// s_map(T & value) : value(&value) {}		// for -> node(tmp_pair))
	s_map(T & value) : value(value) {}
	s_map(const T & value) : value(value) {}
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
	node				*_tail;
	alloc_node			_alloc_node;
	


// --------------------------- private metods ---------------------------
void			empty_tail()
{
	_tail = _alloc_node.allocate(1);
	_alloc_node.construct(_tail, node());
	_tail->prev = _tail;
	_tail->left = _tail;
	_tail->right = _tail;
	// _alloc.destroy(&_tail->value);
	// _tail->value = NULL;
}

void			tail_init()
{
	node	*tmp_root;
	_tail->prev = _root;

	tmp_root = _root;
	while(tmp_root->right != NULL && tmp_root->right != _tail)
		tmp_root = tmp_root->right;
	tmp_root->right = _tail;
	_tail->left = tmp_root;

	tmp_root = _root;
	while(tmp_root->left != NULL)
		tmp_root = tmp_root->left;
	_tail->right = tmp_root;

	// _tail->prev	= _root;
	// _tail->right	= _first;
	// _tail->left	= _last;
}

void			root_init(node * node)
{
	_root = node;
	_root->prev = NULL;
	_root->left = NULL;
	_root->right = _tail;
	_tail->prev = _root;
	_tail->left = _root;
	_tail->right = _root;
}

node			*create_node(const value_type & pair)
{
	node		*tmp_node;
	tmp_node = _alloc_node.allocate(1);
	_alloc_node.construct(tmp_node, node(pair));
	tmp_node->prev = _tail;
	tmp_node->left = NULL;
	tmp_node->right = NULL;
	return tmp_node;
}

void			add_node(const key_type & k, const mapped_type & m)
{
	value_type		pair = value_type(k, m);
	node			*new_node = create_node(pair);
	node			*tmp = _root;
	node			*tmp_prev;

	if(_len == 0)
		root_init(new_node);
	else
	{

		while(new_node->value.first != tmp->value.first && tmp != NULL && tmp != _tail)
		{
			tmp_prev = tmp;
			if(_comp(new_node->value.first, tmp->value.first))
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		if(tmp == NULL || tmp == _tail)
		{
			if(_comp(new_node->value.first, tmp_prev->value.first))
				tmp_prev->left = new_node;
			else
				tmp_prev->right = new_node;
			new_node->prev = tmp_prev;
		}
	}
	tail_init();
	++_len;
}

public:

void		mini_insert(const key_type & k, const mapped_type & m)
{	
	add_node(k, m);
	//balance_new_node();
}

node * const		get_tail() const	{ return &_tail; }

// --------------------------- Constructors ---------------------------
	// --- default
	explicit map(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _comp(comp), _root(NULL), _len(0)
	{
		empty_tail();
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
		for(iterator it = begin(), ite = end(); it != ite; ++it, --_len)
		{
			_alloc_node.destroy(it.get_map());
			_alloc_node.deallocate(it.get_map(), 1);
		}
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
		if(src.get_map() == _tail)
		{
			insert(std::make_pair(k, mapped_type()));
			src = find(k);
			return(src.get_map()->value.second);
		}
		else
			return(src.get_map()->value.second);
	}

// --------------------------- Capacity ---------------------------
	size_type		size() const		{ return _len;			}
	bool			empty() const		{ return _len == 0;		}
	size_type		max_size() const	{ return
		// std::numeric_limits<size_type>::max() / sizeof(ft::map<Key,T>);	}
		_alloc.max_size(); }

// --------------------------- Iterators ---------------------------
	iterator begin()						{ return iterator(_tail->right);			}
	iterator end()							{ return iterator(_tail);					}
	const_iterator begin() const			;//{ return const_iterator(_tail->right);			}
	const_iterator end() const				;//{ return const_iterator(_tail);					}

	reverse_iterator rbegin()				;//{ return reverse_iterator(_tail->left);			}
	reverse_iterator rend()					;//{ return reverse_iterator(_tail);				}
	const_reverse_iterator rbegin() const	;//{ return const_reverse_iterator(_tail->left);		}
	const_reverse_iterator rend() const		;//{ return const_reverse_iterator(_tail);				}

// --------------------------- Observers ---------------------------
	key_compare key_comp() const		{ return _comp;					}
	value_compare value_comp() const	{ return value_compare(_comp);	}

//--------------------- Allocator ---------------------------
	allocator_type		get_allocator () const	{ return _alloc; }
};

}// end namespace ft
#endif