#ifndef map_HPP
# define map_HPP

# include <iostream>
# include "map_iterator.hpp"
# include <iomanip> // for print 
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
	typedef node *									node_ptr;
	typedef std::allocator<node>					alloc_node;

	typedef Compare									key_compare;
	typedef std::ptrdiff_t							difference_type;
	typedef std::size_t								size_type;

	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	typedef ft::MapIterator<value_type, key_compare>				iterator;
	typedef ft::ConstMapIterator<value_type, key_compare>			const_iterator;
	typedef ft::ReverseMapIterator<value_type, key_compare>			reverse_iterator;
	typedef ft::ConstReverseMapIterator<value_type, key_compare>	const_reverse_iterator;

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
	node_ptr			_root;
	size_t				_len;
	node_ptr			_tail;
	alloc_node			_alloc_node;
	


// --------------------------- private metods ---------------------------
	void		_empty_tail()
	{
		_tail = _alloc_node.allocate(1);
		_alloc_node.construct(_tail, node());
		_tail->prev = NULL;
		_tail->left = NULL;
		_tail->right = NULL;
	}

	node_ptr	_max_key()
	{
		node_ptr	tmp_root;

		tmp_root = _root;
		while(tmp_root->right != NULL && tmp_root->right != _tail)
			tmp_root = tmp_root->right;
		return tmp_root;
	}

	node_ptr	_min_key()
	{
		node_ptr	tmp_root;

		tmp_root = _root;
		while(tmp_root->left != NULL)
			tmp_root = tmp_root->left;
		return tmp_root;
	}

	void		_tail_init()
	{

		_tail->prev = _root;
		_root->prev = _tail;
		node_ptr	last_node = _max_key();
		last_node->right = _tail;
		_tail->left = last_node;
		node_ptr	first_node = _min_key();
		_tail->right = first_node;
		// _tail->prev	= _root;
		// _tail->right	= _first;
		// _tail->left	= _last;
	}

	void		_root_init(node_ptr node)
	{
		_root = node;
		_root->prev = NULL;
		_root->left = NULL;
		_root->right = _tail;
		_tail->prev = _root;
		_tail->left = _root;
		_tail->right = _root;
	}

	node_ptr	_create_node(const value_type & pair)
	{
		node_ptr	tmp_node;
		tmp_node = _alloc_node.allocate(1);
		_alloc_node.construct(tmp_node, node(pair));
		tmp_node->prev = _tail;
		tmp_node->left = NULL;
		tmp_node->right = NULL;
		return tmp_node;
	}

	node_ptr	_add_node(const key_type & k, const mapped_type & m)
	{
		value_type		pair = value_type(k, m);
		node_ptr		new_node = _create_node(pair);
		node_ptr		tmp = _root;
		node_ptr		tmp_prev;

		if(_len == 0)
			_root_init(new_node);
		else
		{

			while(tmp && tmp != _tail && new_node->value.first != tmp->value.first)
			{
				tmp_prev = tmp;
				if(_comp(new_node->value.first, tmp->value.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if(!tmp || tmp == _tail)
			{
				if(_comp(new_node->value.first, tmp_prev->value.first))
					tmp_prev->left = new_node;
				else
					tmp_prev->right = new_node;
				new_node->prev = tmp_prev;
			}
		}
		return new_node;
	}

	bool		_equality_check(const key_type & x, const key_type & y)
	{ return _comp(x, y) == _comp(y, x); }

	//      ----BALANCE TREE----       // --- --- ---
	int			_height(node_ptr node, int i = 1)
	{
		int			x, y;
		if (node && node != _tail)
		{
			if (node->left && node->right && node->right != _tail)
			{
				x = _height(node->left, i + 1);
				y = _height(node->right, i + 1);
				i = (x > y) ? x : y;
			}
			else if (node->left)
				i = _height(node->left, i + 1);
			else if (node->right && node->right != _tail)
				i = _height(node->right, i + 1);
		}
		else
			return (0);
		return (i);
	}

	int			_max(int a, int b) { return (a > b)? a : b; }

	node_ptr	_right_rotate(node_ptr node)
	{
		node_ptr	tmp;

		tmp = node->left;
		node->left = tmp->right;
		tmp->right = node;

		tmp->prev = node->prev;
		node->prev = tmp;
		if(node->left != NULL)
			node->left->prev = node;
		return tmp; // Return new root
	}

	node_ptr	_left_rotate(node_ptr node)
	{
		node_ptr	tmp;

		tmp = node->right;
		node->right = tmp->left;
		tmp->left = node;

		tmp->prev = node->prev;
		node->prev = tmp;
		if(node->right != NULL)
			node->right->prev = node;
		return tmp; // Return new root
	}

	int			_get_balance(node_ptr  x)
	{
		if (x == NULL)
			return 0;
		return _height(x->left) - _height(x->right);
	}

	node_ptr	_balance(node_ptr node)
	{
		int	balance = _get_balance(node);

		if (balance == 2) // left_height is bigger
		{
			if(_get_balance(node->left) < 0)
				_left_rotate(node->left);
			return _right_rotate(node);
		}

		if (balance == -2) // right_height is bigger
		{
			if(_get_balance(node->right) > 0)
				_right_rotate(node->right);
			return _left_rotate(node);
		}
		return node;
	}

	node_ptr	_balance_map(node_ptr tmp)
	{
		if(tmp->left != NULL)
			tmp->left = _balance_map(tmp->left);
		if(tmp->right != NULL && tmp->right != _tail)
			tmp->right = _balance_map(tmp->right);
		return _balance(tmp);
	}

	//      ----PRINT TREE----       // --- --- ---
	void		_printlv(int n) 
	{
		node_ptr		temp = _root;
		int val = pow(2, _height(_root) - n + 1);
		std::cout << std::setw(val) << "";
		_disp_lv(temp, n, val);
	}

	void		_disp_lv(node_ptr p, int lv, int d)
	{
		int disp = 2 * d;
		if (lv == 0)
		{
			if (p == NULL)
			{

			std::cout << " x ";
			std::cout << std::setw(disp - 3) << "";
			return;
			}
			else 
			{
			// int result = ((p->data.first <= 1) ? 1 : log10(p->data.first) + 1);
			std::cout << " " << p->value.first << " ";
			// std::cout << "|" << p->prev->value.first;
			std::cout << std::setw(disp - 3) << "";
			}
		}
		else
		{
			if (p == NULL && lv >= 1)
			{
			_disp_lv(NULL, lv - 1, d);
			_disp_lv(NULL, lv - 1, d);
			}
			else
			{
			_disp_lv(p->left, lv - 1, d);
			_disp_lv(p->right, lv - 1, d);
			}
		}
	}

public:// --- --- --- PUBLIC:

	void		treeprint()
	{
		int i = 0;
		while (i <= _height(_root) - 1)
		{
			_printlv(i);
			i++;
			std::cout << std::endl;
		}
	}//      ----END PRINT TREE----       // --- --- ---

	void		balance_mini_insert(key_type key, mapped_type val)
	{
		node_ptr	new_node;
		new_node = _add_node(key, val);
		++_len;
		_root = _balance_map(_root);
		_tail_init();
	}

	void		mini_insert(const key_type & k, const mapped_type & m)
	{	
		_add_node(k, m);
		_tail_init();
		++_len;
	}

	// --------------------------- Constructors ---------------------------
	// --- default
	explicit map(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _comp(comp), _root(NULL), _len(0)
	{
		_empty_tail();
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
	map (const map& x) : map() { *this = x; }

	map&		operator= (const map& x)
	{
		clear();
		_alloc = x._alloc;
		_comp = x._comp;
		_root = x._root;
		_tail = x._tail;
		_alloc_node = x._alloc_node;
		if(x._len != 0)
			insert(x.begin(), x.end());
		return *this;
	}

	// --------------------------- Modifiers ---------------------------
	//single element (1)	
	std::pair<iterator,bool>	insert(const value_type& val);

	//with hint (2)	
	iterator	insert(iterator position, const value_type& val);

	//range (3)	
	template <class InputIterator>
	void		insert (InputIterator first, InputIterator last);

	void		erase (iterator node)//position)
	{
		iterator	tmp = node;

		PRINT("\n! erase: " << node.get_map()->value.first);// ---

		if(tmp.get_map()->right)
		{
			tmp = tmp.get_map()->right;
			while(tmp.get_map()->left)
				tmp = tmp.get_map()->left;
		}
		PRINT("tmp: " << tmp.get_map()->value.first);// ---
		if(_comp(node.get_map()->value.first, node.get_map()->prev->value.first) == true)
		{
			PRINT("left: " << node.get_map()->value.first << " -> " << node.get_map()->prev->value.first << " -> " << node.get_map()->prev->left->value.first);// ---
			node.get_map()->prev->left = tmp.get_map();
		}
		else
		{
			PRINT("right: " << node.get_map()->value.first << " -> " << node.get_map()->prev->value.first << " -> " << node.get_map()->prev->right->value.first);// ---
			node.get_map()->prev->right = tmp.get_map();
			PRINT("right: " << node.get_map()->value.first << " -> " << node.get_map()->prev->value.first << " -> " << node.get_map()->prev->right->value.first);// ---
		}

		tmp.get_map()->prev = node.get_map()->prev;
		node.get_map()->left->prev = tmp.get_map();
		tmp.get_map()->left = node.get_map()->left;

		_alloc_node.destroy(node.get_map());
		// _alloc_node.deallocate(node.get_map(), 1); // sega
	}

	size_type	erase (const key_type& k);
	// {
	// 	iterator	node;

	// 	node = find(position->first).get_map();
	// 	PRINT("\n! erase: " << node.get_map()->value.first);// ---

	// 	_erase_root(node.get_map());

	// 	_alloc_node.destroy(node.get_map());
	// 	_alloc_node.deallocate(node.get_map(), 1);
	// }

	void		erase (iterator first, iterator last);

	void		swap (map& x);

	void		clear()
	{
		_tail->prev = NULL;
		_tail->left = NULL;
		_tail->right = NULL;
		if(_len == 0)
			return ;
		// iterator it = begin(), ite = end();
		// for(; it != ite; ++it, --_len)
		// {
		// 	PRINT(_len);
		// 	_alloc_node.destroy(it.get_map());
		// 	_alloc_node.deallocate(it.get_map(), 1);
		// }
	}

// --------------------------- Operations ---------------------------

	iterator	find(const key_type& k)
	{
		node_ptr	node = _root;

		while(_equality_check(node->value.first, k) != true)
		{
			if(_comp(node->value.first, k) == true)
				node = node->right;
			else
				node = node->left;
			if(node == NULL)
				return iterator(_tail);
		}
		// PRINT("Found: " << node->value.first); ENDL
		return iterator(node);
	}
	const_iterator find(const key_type& k) const { return find(k); }

	size_type	count(const key_type& k) const;

	iterator	lower_bound(const key_type& k);
	const_iterator lower_bound(const key_type& k) const;

	iterator	upper_bound(const key_type& k);
	const_iterator upper_bound(const key_type& k) const;

	std::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const;
	std::pair<iterator, iterator>				equal_range(const key_type& k);

// --------------------------- Element access ---------------------------
	mapped_type&	operator[] (const key_type& k)
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
	const_iterator begin() const			{ return const_iterator(_tail->right);		}
	const_iterator end() const				{ return const_iterator(_tail);				}

	reverse_iterator rbegin()				{ return reverse_iterator(_tail->left);			}
	reverse_iterator rend()					{ return reverse_iterator(_tail);				}
	const_reverse_iterator rbegin() const	{ return const_reverse_iterator(_tail->left);	}
	const_reverse_iterator rend() const		{ return const_reverse_iterator(_tail);			}

// --------------------------- Observers ---------------------------
	key_compare key_comp() const		{ return _comp;					}
	value_compare value_comp() const	{ return value_compare(_comp);	}

//--------------------- Allocator ---------------------------
	allocator_type		get_allocator () const	{ return _alloc; }
};

}// end namespace ft
#endif