#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include <iostream>
// # include "List.hpp"

namespace ft {
// --------------------------- base Iterator ---------------------------
template <	class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T&	>
struct iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

template < typename T >
struct s_list;

// --------------------------- base Iterator ---------------------------
// template < class T >
// class MyIterator : public std::iterator<std::input_iterator_tag, class T >
// {
// public:

// private:
// 	int*	p;
// public:
// 	MyIterator(int* x) : p(x)	{}
// 	MyIterator(const MyIterator& mit) : p(mit.p)	{}

// 	MyIterator& operator++()	{ ++p; return *this; }
// 	MyIterator operator++(int)	{ MyIterator tmp(*this); operator++(); return tmp; }

// 	bool operator==(const MyIterator& rhs) const	{ return p==rhs.p; }
// 	bool operator!=(const MyIterator& rhs) const	{ return p!=rhs.p; }

// 	int& operator*()	{ return *p; }
// };

// --------------------------- List Iterator ---------------------------
template < class T > 
class ListIterator
{
public:
	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef std::ptrdiff_t	difference_type;
protected:
	ft::s_list<T> *		_p;
public:
	ListIterator()	{}
	virtual ~ListIterator()	{}
	ListIterator(ft::s_list<T> * x)						{ this->_p = x;				}
	ListIterator(ft::s_list<T> & x)						{ this->_p = x;				}
	ListIterator(const ListIterator & x)				{ *this = x;				}
	// ListIterator(const ListIterator & x)				{ this->_p = x._p;			}
	ListIterator&	operator=(const ListIterator& x)	{ _p = x._p; return *this;	}

	bool			operator==(const ListIterator& rhs) const		{ return _p==rhs._p; }
	bool			operator!=(const ListIterator& rhs) const		{ return _p!=rhs._p; }

	T&				operator*()		{ return _p->value;		}
	T&				operator->()	{ return &_p->value;	}
	// ft::s_list<T>*	getList()		{ return _p;			}

	ListIterator&	operator++()			{ _p = _p->next_list; return *this;						}
	ListIterator	operator++(int)			{ ListIterator tmp(*this); operator++(); return tmp;	}
	ListIterator&	operator--()			{ _p = _p->prev_list; return *this;						}
	ListIterator	operator--(int)			{ ListIterator tmp(*this); operator--(); return tmp;	}


};

// --------------------------- Const List Iterator ---------------------------
template < class T > 
class ConstListIterator : public ListIterator<T>
{
public:
	ConstListIterator()				{}
	virtual ~ConstListIterator()	{}
	ConstListIterator(ft::s_list<T> * x)						{ this->_p = x;						}
	ConstListIterator(ft::s_list<T> & x)						{ this->_p = x;						}
	ConstListIterator(const ConstListIterator& x)				{ *this = x;						}
	ConstListIterator&	operator=(const ConstListIterator& x)	{ this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};
// --------------------------- Reverse List Iterator ---------------------------
template < class T > 
class ReverseListIterator : public ListIterator<T>
{
public:
	ReverseListIterator()			{}
	virtual ~ReverseListIterator()	{}
	ReverseListIterator(ft::s_list<T> * x)							{ this->_p = x;						}
	ReverseListIterator(const ReverseListIterator& x)				{ this->_p = x._p;					}
	ReverseListIterator&	operator=(const ReverseListIterator& x) { this->_p = x._p; return *this;	}

	ReverseListIterator&	operator++()			{ this->_p = this->_p->prev_list; return *this;				}
	ReverseListIterator		operator++(int)			{ ReverseListIterator tmp(*this); operator++(); return tmp; }
	ReverseListIterator&	operator--()			{ this->_p = this->_p->next_list; return *this;				}
	ReverseListIterator		operator--(int)			{ ReverseListIterator tmp(*this); operator--(); return tmp; }
};
// --------------------------- Const Reverser List Iterator ---------------------------
template < class T > 
class ConstReverseListIterator : public ReverseListIterator<T>
{
public:
	const T &		operator*()				{ return this->_p->value; }
};

}// end  of namespace ft
#endif