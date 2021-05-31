#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

namespace ft {// start namespace ft

template < class T >// <class Key, class T> //
struct s_map;

// --------------------------- map Iterator ---------------------------
template < class T, class Compare >
class MapIterator
{
	public:
		typedef T 							value_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;
		typedef std::ptrdiff_t				difference_type;
		typedef ft::s_map<value_type>		node;
		typedef Compare						key_compare;

protected:
	node			*_p;
	key_compare		_comp;
public:
	MapIterator()							{}
	virtual ~MapIterator()					{}
	MapIterator(node * ptr) : _p(ptr)		{}
	// MapIterator(node & ptr) : _p(ptr)		{}
	MapIterator(const MapIterator &copy)	{ *this = copy;	}
	MapIterator&			operator=(const node & x)
	{ if(_p != x) _p = x; return _p;	}

	// MapIterator(T *x)							{ *_p->value = x;			}
	// MapIterator&	operator=(const MapIterator& x)	{ _p = x._p; return *this;	}
	
// --------------------------- class map ---------------------------
	bool		operator==(const MapIterator& rhs) const	{ return _p==rhs._p; }
	bool		operator!=(const MapIterator& rhs) const	{ return _p!=rhs._p; }

	T&			operator*()		{ return _p->value;		} // (*it).first
	T*			operator->()	{ return &(_p->value);	} // it->first
	// reference	operator*()		{ return _p->value;		}
	// pointer		operator->()	{ return &(_p->value);	} // return &(this->operator*());
	const T&	operator*() const	{ return _p->value;		}
	const T*	operator->() const	{ return &(_p->value);	}

	MapIterator&	operator++()
	{
		if(!_p)
			return *this;
		node	*tmp = _p;
		// _tail->right == _first  and  _first->left == NULL
		// _last->right == _tail   and  _tail->left  == _last
		if(_p->right)
		{
			tmp = _p->right; 
			while(tmp->left && tmp->left != _p)
				tmp = tmp->left;
		}
		else if(_p->prev)
		{
			tmp = _p->prev;
			while(tmp->prev && _comp(tmp->value.first, _p->value.first))// tmp->value.first < _p->value.first
				tmp = tmp->prev;
		}
		_p = tmp;
		return (*this);
	}
	MapIterator	operator++(int)	{ MapIterator tmp(*this);	operator++();	return tmp; }

	MapIterator&	operator--()
	{
		if(!_p)
			return *this;
		node	*tmp = _p;
		// _tail->left == _last  and  _last->right == _tail
		// _last->left == tmp    and  tmp->right   == NULL
		if (_p->left)
		{
			tmp = _p->left;
			while(tmp->right && tmp->right != _p)
				tmp = tmp->right;
		}
		else if ( _p->prev)
		{
			tmp = _p->prev;
			while(tmp->prev && _comp(_p->value.first, tmp->value.first)) // _p->value.first < tmp->value.first
				tmp = tmp->prev;
		}
		_p = tmp;
		return (*this);
	}
	MapIterator	operator--(int)	{ MapIterator tmp(*this);	operator--();	return tmp; }

	bool	operator>(const MapIterator &x)	{ return _p > x._map; }
	bool	operator<(const MapIterator &x)	{ return _p < x._map; }

	node	*get_map()	{ return _p; }

	// T&				operator[](const size_t &x)			{ return (_p + x)->value; }
	// T&				operator[](char const &x)			{ (void)x, return *x; }
	// reference			operator[](const size_t &x)			{ return *(_p + x); }
};

// --------------------------- Const map Iterator ---------------------------
template < class T, class Compare >
class ConstMapIterator : public MapIterator<T, Compare >
{
public:
	ConstMapIterator() : MapIterator<T, Compare >()										{}
	// ConstMapIterator(ft::s_map<T> * x) : MapIterator<T>(x)					{}
	ConstMapIterator(ConstMapIterator& copy) : MapIterator<T, Compare >(copy)	{}
	ConstMapIterator(MapIterator<T, Compare > x) : MapIterator<T, Compare >(x)					{}

	ConstMapIterator&	operator=(const ConstMapIterator& x) { this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};
// --------------------------- Reverse map Iterator ---------------------------
template < class T, class Compare >
class ReverseMapIterator : public MapIterator<T, Compare >
{
public:
	// ReverseMapIterator() : MapIterator<T>()										{}
	ReverseMapIterator(ft::s_map<T> * x) : MapIterator<T, Compare >(x)						{}
	ReverseMapIterator(const ReverseMapIterator& copy) : MapIterator<T, Compare >(copy)	{}

	ReverseMapIterator&	operator=(const ReverseMapIterator& x) { this->_p = x._p; return *this;	}

	ReverseMapIterator&	operator++()			{ this->_p = this->_p->prev_map; return *this;				}
	ReverseMapIterator		operator++(int)			{ ReverseMapIterator tmp(*this); operator++(); return tmp; }
	ReverseMapIterator&	operator--()			{ this->_p = this->_p->next_map; return *this;				}
	ReverseMapIterator		operator--(int)			{ ReverseMapIterator tmp(*this); operator--(); return tmp; }
};
// --------------------------- Const Reverser map Iterator ---------------------------
template < class T, class Compare >
class ConstReverseMapIterator : public ReverseMapIterator<T, Compare >
{
public:
	// ConstReverseMapIterator() : ReverseMapIterator<T>()											{}
	// ConstReverseMapIterator(ft::s_map<T> * x) : ReverseMapIterator<T>(x)							{}
	// ConstReverseMapIterator(const ConstReverseMapIterator& copy) : ReverseMapIterator<T>(copy)	{}
	ConstReverseMapIterator(ReverseMapIterator<T, Compare > x) : ReverseMapIterator<T, Compare >(x)					{}

	ConstReverseMapIterator&	operator=(const ConstReverseMapIterator& x)	{ this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};

}// end namespace ft
#endif