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
	T							value;
	struct s_map				*prev;
	struct s_map				*right;
	struct s_map				*left;

	s_map() {}
	// s_map(T * value) : value(value) {}		// for -> node(&tmp_pair)
	// s_map(const T * value) : value(value) {}
	// s_map(T & value) : value(&value) {}		// for -> node(tmp_pair))
	s_map(T & value) : value(value) {}
	s_map(const T & value) : value(value) {}
	~s_map() { }

	// s_map&	operator=(const s_map & x) 
	// {
	// 	this->right = x.right;
	// 	this->left = x.left;
	// 	this->prev = x.prev;
	// 	return *this;
	// }
};

// --------------------------- class map ---------------------------
template <	class Key,												// map::key_type
			class T,												// map::mapped_type
			class Compare = std::less<Key>,							// map::key_compare
			class Alloc = std::allocator<std::pair<Key,T> >	// map::allocator_type // const
			>
class map
{
	// template <class> friend class MapIterator;
public:
	typedef Key										key_type; // const
	typedef T										mapped_type;
	typedef std::pair<key_type, mapped_type>		value_type; // const
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
			{ return com(lhs.first, rhs.first); }
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

	size_type		_check_len()
	{
		iterator	it = begin();
		size_type	_len = 0;
		for(; it != _tail; ++it)
			++_len;
		return _len;
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
		while(tmp_root->left != NULL && tmp_root->left != _tail)
			tmp_root = tmp_root->left;
		return tmp_root;
	}

	void		_tail_swap()
	{
		node_ptr	tmp = _tail->right;
		_tail->right = _tail->left;
		_tail->left = tmp;
	}

	void		_tail_unlink()
	{
		node_ptr	last_node = _max_key();
		last_node->right = NULL;
		_root->prev = NULL;
	}

	void		_tail_link()
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
	{
		bool	left = _comp(x, y);
		bool	right = _comp(y, x);
		return left == right;
	}

	void		_root_erase(iterator position)
	{
		position.get_map()->prev = NULL;
		position.get_map()->left = NULL;
		position.get_map()->right = NULL;
		_alloc_node.destroy(position.get_map());
		_alloc_node.deallocate(position.get_map(), 1);
		--_len;
		_tail->prev = NULL;
		_tail->left = NULL;
		_tail->right = NULL;
		_root = _tail;
	}

	//      ----BALANCE TREE----       // --- --- ---
	int			_height(node_ptr node, int i = 1)
	{
		if(!node)
			return 0;
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
			return 0;
		return i;
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

	int			_get_balance(node_ptr x)
	{
		if (x == NULL)
			return 0;
		return _height(x->left) - _height(x->right);
	}

	node_ptr	_balance(node_ptr node)
	{
		int	balance = _get_balance(node);

		if (balance > 1) // left_height is bigger
		{
			if(_get_balance(node->left) < 0)
				_left_rotate(node->left);
			return _right_rotate(node);
		}

		if (balance < -1) // right_height is bigger
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

	void		balance_mini_insert(key_type key, mapped_type val)
	{
		node_ptr	new_node;
		new_node = _add_node(key, val);
		// _check_len();
		++_len;
		_root = _balance_map(_root);
		_tail_link();
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
			if (p == NULL || p == _tail)
			{
				std::cout << " x ";
				std::cout << std::setw(disp - 3) << "";
				return;
			}
			else 
			{
				if(p->value.first > 0)
					std::cout << " ";
				std::cout<< p->value.first << " ";
				// if(p->prev)
				// 	std::cout << "|" << p->prev->value.first;
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
		while (i <= _height(_tail->prev) - 1)
		{
			_printlv(i);
			i++;
			std::cout << std::endl;
		}
		if(i == 0)
			std::cout << "     x " << std::endl;
	}//      ----END PRINT TREE----       // --- --- ---

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
	map (const map & x)
	{
		_empty_tail();
		*this = x;
	}

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
	std::pair<iterator,bool>	insert(const value_type& val)
	{
		std::pair<iterator,bool>	tmp;
		size_type					tmp_len = _len;
		balance_mini_insert(val.first, val.second);
		iterator		tmp_it = find(val.first);
		if(tmp_len == _len)
			tmp = std::pair<iterator,bool>(tmp_it,false);
		else
			tmp = std::pair<iterator,bool>(tmp_it,true);
		return	tmp;
	}

	//with hint (2)	
	iterator	insert(iterator position, const value_type& val);

	//range (3)	
	template <class InputIterator>
	void		insert (InputIterator first, InputIterator last);

	void		_erase_root()
	{
		_alloc_node.destroy(_root);
		_alloc_node.deallocate(_root, 1);
		--_len;
		_tail->prev = NULL;
		_tail->left = NULL;
		_tail->right = NULL;
	// if(_tail)	PRT("!_tail  " << _tail->value.first);	if(_tail->prev)	PRT(" | prev " << _tail->prev->value.first);	if(_tail->left)	PRT(" | left " << _tail->left->value.first);	if(_tail->right)	PRT(" | right " << _tail->right->value.first); ENDL
	}

	void		erase(iterator position)
	{
		// PRINT("!_len " << _len);
		if(position == _tail)
			return ;
		if(position == _root && _len == 1)
			return _erase_root();
		iterator	node = position;
		iterator	tmp;
		if(node.get_map()->right != NULL && node.get_map()->right != _tail)
			++node;

	// if(position.get_map())	PRT("! pos  " << position.get_map()->value.first);	if(position.get_map()->prev)	PRT(" | prev " << position.get_map()->prev->value.first);	if(position.get_map()->left)	PRT(" | left " << position.get_map()->left->value.first);	if(position.get_map()->right)	PRT(" | right " << position.get_map()->right->value.first); ENDL
	// if(node.get_map())		PRT("! node " << node.get_map()->value.first);		if(node.get_map()->prev)		PRT(" | prev " << node.get_map()->prev->value.first);		if(node.get_map()->left)		PRT(" | left " << node.get_map()->left->value.first);		if(node.get_map()->right)		PRT(" | right " << node.get_map()->right->value.first); ENDL
	// if(_tail)	PRT("!_tail  " << _tail->value.first);	if(_tail->prev)	PRT(" | prev " << _tail->prev->value.first);	if(_tail->left)	PRT(" | left " << _tail->left->value.first);	if(_tail->right)	PRT(" | right " << _tail->right->value.first); ENDL

		if(position == node && !node.get_map()->left && (!node.get_map()->right || node.get_map()->right == _tail))
		{
			tmp = node.get_map()->prev;
			if(tmp.get_map()->left == node.get_map())
				tmp.get_map()->left = NULL;
			else
				tmp.get_map()->right = NULL;
			// tmp.get_map()->left = node.get_map()->left;

		}
		else
		{
			position.get_map()->value = node.get_map()->value;
			if(position.get_map()->right == node.get_map())
			{
				position.get_map()->right = node.get_map()->right;
				if(position.get_map()->right)
					position.get_map()->right->prev = position.get_map();
			}
			else if(position.get_map()->right != node.get_map())
				node.get_map()->prev->left = NULL;
			else if(position.get_map()->left != node.get_map())
				node.get_map()->prev->right = NULL;
		}

	// if(position.get_map())	PRT("- pos  " << position.get_map()->value.first);	if(position.get_map()->prev)	PRT(" | prev " << position.get_map()->prev->value.first);	if(position.get_map()->left)	PRT(" | left " << position.get_map()->left->value.first);	if(position.get_map()->right)	PRT(" | right " << position.get_map()->right->value.first); ENDL
	// if(node.get_map())		PRT("- node " << node.get_map()->value.first);		if(node.get_map()->prev)		PRT(" | prev " << node.get_map()->prev->value.first);		if(node.get_map()->left)		PRT(" | left " << node.get_map()->left->value.first);		if(node.get_map()->right)		PRT(" | right " << node.get_map()->right->value.first); ENDL
	// if(_tail)	PRT("-_tail  " << _tail->value.first);	if(_tail->prev)	PRT(" | prev " << _tail->prev->value.first);	if(_tail->left)	PRT(" | left " << _tail->left->value.first);	if(_tail->right)	PRT(" | right " << _tail->right->value.first); ENDL

		_alloc_node.destroy(node.get_map());
		_alloc_node.deallocate(node.get_map(), 1);
		--_len;
		_root = _balance_map(_root);
		_tail_link();
	}

	size_type	erase (const key_type& k)
	{
		erase(find(k));
		return 1;
	}

	void		erase(iterator first, iterator last)
	{
		for(; first != last; ++first)
			erase(first);
	}

	void		swap (map& x)
	{
		map	tmp = x;
		x = *this;
		*this = tmp;			
	}

	void		clear()
	{
		if(_len == 0)
			return ;
		iterator	it = begin(), ite = end();
		for(; it != ite; ++it)
			erase(it);
	}

// --------------------------- Operations ---------------------------

	iterator	find(const key_type& k)
	{
		if(_len == 0)
			return end();
		node_ptr	node = _root;
		while(_equality_check(node->value.first, k) != true)
		{
			if(_comp(node->value.first, k) == true)
				node = node->right;
			else
				node = node->left;
			if(node == NULL || node == _tail)
				return end();
		}
		return iterator(node);
	}
	const_iterator find(const key_type& k) const { return find(k); }

	size_type	count(const key_type& k) const
	{
		iterator src = find(k);
		if(src.getMap() == _tail)
			return(0);
		else
			return (1);
	}

	iterator	lower_bound(const key_type& k)
	{
		iterator src = find(k);
		if(src.getMap() == _tail)
		{
			src = begin();
			while(src.getMap()->key_value.first < k)
				src++;
			return(src);
		}
		else
			return (src);
	}
	const_iterator lower_bound(const key_type& k) const
	{ return lower_bound(k); }

	iterator	upper_bound(const key_type& k)
	{
		iterator src = find(k);
		if(src.getMap() == _tail)
		{
			src = begin();
			while(src.getMap()->key_value.first < k)
				src++;
			return(src);
		}
		else
		{
			src++;
			return (src);
		}
	}
	const_iterator upper_bound(const key_type& k) const
	{ return upper_bound(k); }

	std::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
	{
		const_iterator first = lower_bound(k);
		const_iterator second = upper_bound(k);
		return(std::pair<const_iterator, const_iterator>(first, second));
	}
	std::pair<iterator, iterator>				equal_range(const key_type& k)
	{ return equal_range(k); }

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