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
	node				*_root;
	size_t				_len;
	node				*_tail;
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

node		*_max_key()
{
	node	*tmp_root;

	tmp_root = _root;
	while(tmp_root->right != NULL && tmp_root->right != _tail)
		tmp_root = tmp_root->right;
	return tmp_root;
}

node		*_min_key()
{
	node	*tmp_root;

	tmp_root = _root;
	while(tmp_root->left != NULL)
		tmp_root = tmp_root->left;
	return tmp_root;
}

void		_tail_init()
{

	_tail->prev = _root;
	node	*last_node = _max_key();
	last_node->right = _tail;
	_tail->left = last_node;
	node	*first_node = _min_key();
	_tail->right = first_node;
	// _tail->prev	= _root;
	// _tail->right	= _first;
	// _tail->left	= _last;
}

void		_root_init(node * node)
{
	_root = node;
	_root->prev = NULL;
	_root->left = NULL;
	_root->right = _tail;
	_tail->prev = _root;
	_tail->left = _root;
	_tail->right = _root;
}

node		*_create_node(const value_type & pair)
{
	node		*tmp_node;
	tmp_node = _alloc_node.allocate(1);
	_alloc_node.construct(tmp_node, node(pair));
	tmp_node->prev = _tail;
	tmp_node->left = NULL;
	tmp_node->right = NULL;
	return tmp_node;
}

void		_add_node(const key_type & k, const mapped_type & m)
{
	value_type		pair = value_type(k, m);
	node			*new_node = _create_node(pair);
	node			*tmp = _root;
	node			*tmp_prev;

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
	_tail_init();
	++_len;
}
//      ----BALANCE TREE----       // --- --- ---
int			_height(node * tmp, int i = 1)
{
	int		x, y;
	node	*last_node = _tail->left;
	if (tmp && tmp != last_node)
	{
		if (tmp->left && tmp->right && tmp->right != last_node)
		{
			x = _height(tmp->left, i + 1);
			y = _height(tmp->right, i + 1);
			i = (x > y) ? x : y;
		}
		else if (tmp->left)
			i = _height(tmp->left, i + 1);
		else if (tmp->right && tmp->right != last_node)
			i = _height(tmp->right, i + 1);
	}
	else
		return (0);
	return (i);
}

int			_max(int a, int b) { return (a > b)? a : b; }

node		*_right_rotate(node *y)
{
	node *x = y->left;
	node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	// _height(y) = _max(_height(y->left), _height(y->right)) + 1;
	// _height(x) = _max(_height(x->left), _height(x->right)) + 1;

	// Return new root
	return x;
}

node		*_left_rotate(node *x)
{
	node *y = x->right;
	node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	// _height(x) = _max(_height(x->left), _height(x->right)) + 1;
	// _height(y) = _max(_height(y->left), _height(y->right)) + 1;

	// Return new root
	return y;
}

int			_get_balance(node * x)
{
	if (x == NULL)
		return 0;
	return _height(x->left) - _height(x->right);
}

node*		_insert(node * new_node, value_type pair)
{
	/* 1. Perform the normal BST insertion */
	if (new_node == NULL)
		return _create_node(pair);//(newNode(key));

	if (pair.first < new_node->value.first)
		new_node->left = _insert(new_node->left, pair);
	else if (pair.first > new_node->value.first)
		new_node->right = _insert(new_node->right, pair);
	else // Equal keys are not allowed in BST
		return new_node;

	/* 2. Update height of this ancestor node */
	// new_node->height = 1 + _max(_height(new_node->left), _height(new_node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = _get_balance(new_node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && pair.first < new_node->left->value.first)
		return _right_rotate(new_node);

	// Right Right Case
	if (balance < -1 && pair.first > new_node->right->value.first)
		return _left_rotate(new_node);

	// Left Right Case
	if (balance > 1 && pair.first > new_node->left->value.first)
	{
		new_node->left = _left_rotate(new_node->left);
		return _right_rotate(new_node);
	}

	// Right Left Case
	if (balance < -1 && pair.first < new_node->right->value.first)
	{
		new_node->right = _right_rotate(new_node->right);
		return _left_rotate(new_node);
	}

	/* return the (unchanged) node pointer */
	return new_node;
}

//      ----PRINT TREE----       // --- --- ---
void		_printlv(int n) 
{
	node *		temp = _root;
	int val = pow(2, _height(_root) - n + 1);
	std::cout << std::setw(val) << "";
	_disp_lv(temp, n, val);
}

void		_disp_lv(node * p, int lv, int d)
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
	while (i <= _height(_root) - 0)
	{
		_printlv(i);
		i++;
		std::cout << std::endl;
	}
}//      ----END PRINT TREE----       // --- --- ---

void		balance_mini_insert(key_type key, mapped_type val)
{
	value_type		pair = value_type(key, val);
	_insert(_root, pair);
	// _tail_init();
	
	++_len;
}

void		mini_insert(const key_type & k, const mapped_type & m)
{	
	_add_node(k, m);
	//balance_new_node();
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

void		erase (iterator position);

size_type	erase (const key_type& k);

void		erase (iterator first, iterator last);

void		swap (map& x);

void		clear()
{
	if(_len == 0)
		return ;
	for(iterator it = begin(), ite = end(); it != ite; ++it, --_len)
	{
		_alloc_node.destroy(it.get_map());
		_alloc_node.deallocate(it.get_map(), 1);
	}
	_tail->prev = NULL;
	_tail->left = NULL;
	_tail->right = NULL;
}

// --------------------------- Operations ---------------------------
iterator	find(const key_type& k);
const_iterator find(const key_type& k) const;

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