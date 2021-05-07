#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {// start namespace ft

template < typename T >
struct s_list;

// --------------------------- list Iterator ---------------------------
template < class T >
class ListIterator
{
protected:
	ft::s_list<T> *		_p;
public:
	ListIterator()				{}
	virtual ~ListIterator()		{}
	ListIterator(ft::s_list<T> * x)						{ this->_p = x;				}
	ListIterator(const ListIterator & copy)				{ *this = copy;				}
	ListIterator&	operator=(const ListIterator& x)	{ _p = x._p; return *this;	}

	bool			operator==(const ListIterator& rhs) const		{ return _p==rhs._p; }
	bool			operator!=(const ListIterator& rhs) const		{ return _p!=rhs._p; }

	T&				operator*()		{ return _p->value;		}
	T*				operator->()	{ return &_p->value;	}
	ft::s_list<T>*	getlist()		{ return _p;			}
	// ft::s_list<T>&	getlist()		{ return *_p;			}

	ListIterator&	operator++()			{ _p = _p->next_list; return *this;						}
	ListIterator	operator++(int)			{ ListIterator tmp(*this); operator++(); return tmp;	}
	ListIterator&	operator--()			{ _p = _p->prev_list; return *this;						}
	ListIterator	operator--(int)			{ ListIterator tmp(*this); operator--(); return tmp;	}
};

// --------------------------- Const list Iterator ---------------------------
template < class T > 
class ConstListIterator : public ListIterator<T>
{
public:
	// ConstListIterator() : ListIterator<T>()										{}
	// ConstListIterator(ft::s_list<T> * x) : ListIterator<T>(x)					{}
	// ConstListIterator(const ConstListIterator& copy) : ListIterator<T>(copy)	{}
	ConstListIterator(ListIterator<T> x) : ListIterator<T>(x)					{}

	ConstListIterator&	operator=(const ConstListIterator& x) { this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};
// --------------------------- Reverse list Iterator ---------------------------
template < class T > 
class ReverseListIterator : public ListIterator<T>
{
public:
	// ReverseListIterator() : ListIterator<T>()										{}
	ReverseListIterator(ft::s_list<T> * x) : ListIterator<T>(x)						{}
	ReverseListIterator(const ReverseListIterator& copy) : ListIterator<T>(copy)	{}

	ReverseListIterator&	operator=(const ReverseListIterator& x) { this->_p = x._p; return *this;	}

	ReverseListIterator&	operator++()			{ this->_p = this->_p->prev_list; return *this;				}
	ReverseListIterator		operator++(int)			{ ReverseListIterator tmp(*this); operator++(); return tmp; }
	ReverseListIterator&	operator--()			{ this->_p = this->_p->next_list; return *this;				}
	ReverseListIterator		operator--(int)			{ ReverseListIterator tmp(*this); operator--(); return tmp; }
};
// --------------------------- Const Reverser list Iterator ---------------------------
template < class T > 
class ConstReverseListIterator : public ReverseListIterator<T>
{
public:
	// ConstReverseListIterator() : ReverseListIterator<T>()											{}
	// ConstReverseListIterator(ft::s_list<T> * x) : ReverseListIterator<T>(x)							{}
	// ConstReverseListIterator(const ConstReverseListIterator& copy) : ReverseListIterator<T>(copy)	{}
	ConstReverseListIterator(ReverseListIterator<T> x) : ReverseListIterator<T>(x)					{}

	ConstReverseListIterator&	operator=(const ConstReverseListIterator& x)	{ this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};

}// end namespace ft
#endif