#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {// start namespace ft
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

// --------------------------- list Iterator ---------------------------
template < class T > 
class listIterator
{
public:
	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef std::ptrdiff_t	difference_type;
protected:
	ft::s_list<T> *		_p;
public:
	listIterator()		{}
	~listIterator()		{}
	listIterator(ft::s_list<T> * x)						{ this->_p = x;				}
	listIterator(ft::s_list<T> & x)						{ this->_p = x;				}
	listIterator(const listIterator & x)				{ *this = x;				}
	listIterator&	operator=(const listIterator& x)	{ _p = x._p; return *this;	}

	bool			operator==(const listIterator& rhs) const		{ return _p==rhs._p; }
	bool			operator!=(const listIterator& rhs) const		{ return _p!=rhs._p; }

	T&				operator*()		{ return _p->value;		}
	T&				operator->()	{ return &_p->value;	}
	ft::s_list<T>*	getlist()		{ return _p;			}

	listIterator&	operator++()			{ _p = _p->next_list; return *this;						}
	listIterator	operator++(int)			{ listIterator tmp(*this); operator++(); return tmp;	}
	listIterator&	operator--()			{ _p = _p->prev_list; return *this;						}
	listIterator	operator--(int)			{ listIterator tmp(*this); operator--(); return tmp;	}
};

// --------------------------- Const list Iterator ---------------------------
template < class T > 
class ConstlistIterator : public listIterator<T>
{
public:
	ConstlistIterator()		{}
	~ConstlistIterator()	{}
	ConstlistIterator(ft::s_list<T> * x)						{ this->_p = x;						}
	ConstlistIterator(ft::s_list<T> & x)						{ this->_p = x;						}
	ConstlistIterator(const ConstlistIterator& x)				{ *this = x;						}
	ConstlistIterator&	operator=(const ConstlistIterator& x)	{ this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};
// --------------------------- Reverse list Iterator ---------------------------
template < class T > 
class ReverselistIterator : public listIterator<T>
{
public:
	ReverselistIterator()		{}
	~ReverselistIterator()		{}
	ReverselistIterator(ft::s_list<T> * x)							{ this->_p = x;						}
	ReverselistIterator(ft::s_list<T> & x)							{ this->_p = x;						}
	ReverselistIterator(const ReverselistIterator& x)				{ this->_p = x._p;					}
	ReverselistIterator&	operator=(const ReverselistIterator& x) { this->_p = x._p; return *this;	}

	ReverselistIterator&	operator++()			{ this->_p = this->_p->prev_list; return *this;				}
	ReverselistIterator		operator++(int)			{ ReverselistIterator tmp(*this); operator++(); return tmp; }
	ReverselistIterator&	operator--()			{ this->_p = this->_p->next_list; return *this;				}
	ReverselistIterator		operator--(int)			{ ReverselistIterator tmp(*this); operator--(); return tmp; }
};
// --------------------------- Const Reverser list Iterator ---------------------------
template < class T > 
class ConstReverselistIterator : public ReverselistIterator<T>
{
public:
	ConstReverselistIterator()		{}
	~ConstReverselistIterator()		{}
	ConstReverselistIterator(ft::s_list<T> * x)									{ this->_p = x;						}
	ConstReverselistIterator(ft::s_list<T> & x)									{ this->_p = x;						}
	ConstReverselistIterator(const ConstReverselistIterator& x)					{ *this = x;						}
	ConstReverselistIterator&	operator=(const ConstReverselistIterator& x)	{ this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};

}// end namespace ft
#endif