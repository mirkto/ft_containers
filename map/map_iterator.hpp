#ifndef map_ITERATOR_HPP
# define map_ITERATOR_HPP

namespace ft {// start namespace ft

template <class Key, typename T >
struct s_map;

// --------------------------- map Iterator ---------------------------
template < class T >
class MapIterator
{
	// template <class, class> friend class map;
protected:
	ft::s_map<T> *		_p;
public:
	MapIterator()				{}
	virtual ~MapIterator()		{}
	MapIterator(ft::s_map<T> * x)						{ this->_p = x;				}
	MapIterator(const MapIterator & copy)				{ *this = copy;				}
// private:
	MapIterator&	operator=(const MapIterator& x)	{ _p = x._p; return *this;	}

	bool			operator==(const MapIterator& rhs) const		{ return _p==rhs._p; }
	bool			operator!=(const MapIterator& rhs) const		{ return _p!=rhs._p; }

	ft::s_map<T>*	getmap()		{ return _p;			}
	// ft::s_map<T>&	getmap()		{ return *_p;			}
	// const T&		operator*() const	{ return _p->value;		}
// public:
	T&				operator*()		{ return _p->value;		}
	T*				operator->()	{ return &_p->value;	}


	MapIterator&	operator++()			{ _p = _p->next_map; return *this;							}
	MapIterator	operator++(int)			{ MapIterator tmp(*this); _p = _p->next_map; return tmp;	}
	MapIterator&	operator--()			{ _p = _p->prev_map; return *this;							}
	MapIterator	operator--(int)			{ MapIterator tmp(*this); _p = _p->prev_map; return tmp;	}
};

// --------------------------- Const map Iterator ---------------------------
template < class T > 
class ConstMapIterator : public MapIterator<T>
{
public:
	// ConstMapIterator() : MapIterator<T>()										{}
	// ConstMapIterator(ft::s_map<T> * x) : MapIterator<T>(x)					{}
	// ConstMapIterator(const ConstMapIterator& copy) : MapIterator<T>(copy)	{}
	ConstMapIterator(MapIterator<T> x) : MapIterator<T>(x)					{}

	ConstMapIterator&	operator=(const ConstMapIterator& x) { this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};
// --------------------------- Reverse map Iterator ---------------------------
template < class T > 
class ReverseMapIterator : public MapIterator<T>
{
public:
	// ReverseMapIterator() : MapIterator<T>()										{}
	ReverseMapIterator(ft::s_map<T> * x) : MapIterator<T>(x)						{}
	ReverseMapIterator(const ReverseMapIterator& copy) : MapIterator<T>(copy)	{}

	ReverseMapIterator&	operator=(const ReverseMapIterator& x) { this->_p = x._p; return *this;	}

	ReverseMapIterator&	operator++()			{ this->_p = this->_p->prev_map; return *this;				}
	ReverseMapIterator		operator++(int)			{ ReverseMapIterator tmp(*this); operator++(); return tmp; }
	ReverseMapIterator&	operator--()			{ this->_p = this->_p->next_map; return *this;				}
	ReverseMapIterator		operator--(int)			{ ReverseMapIterator tmp(*this); operator--(); return tmp; }
};
// --------------------------- Const Reverser map Iterator ---------------------------
template < class T > 
class ConstReverseMapIterator : public ReverseMapIterator<T>
{
public:
	// ConstReverseMapIterator() : ReverseMapIterator<T>()											{}
	// ConstReverseMapIterator(ft::s_map<T> * x) : ReverseMapIterator<T>(x)							{}
	// ConstReverseMapIterator(const ConstReverseMapIterator& copy) : ReverseMapIterator<T>(copy)	{}
	ConstReverseMapIterator(ReverseMapIterator<T> x) : ReverseMapIterator<T>(x)					{}

	ConstReverseMapIterator&	operator=(const ConstReverseMapIterator& x)	{ this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};

}// end namespace ft
#endif