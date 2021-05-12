#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft {

// --------------------------- list Iterator ---------------------------
template < class T >
class VectorIterator
{
protected:
	T*		_p;
public:
	VectorIterator()				{}
	virtual ~VectorIterator()		{}
	VectorIterator(T* x)								{ _p = x;				}
	VectorIterator(T& x)								{ *_p = x;				}

	VectorIterator(const VectorIterator& copy)			{ *this = copy;			}
	VectorIterator&	operator=(const VectorIterator& x)	{ _p = x._p; return *this;	}
	// VectorIterator&	operator=(const T*& x)				{ _p = x; return *this;		}

	bool			operator==(const VectorIterator& rhs) const		{ return _p==rhs._p; }
	bool			operator!=(const VectorIterator& rhs) const		{ return _p!=rhs._p; }

	const T&		operator*() const	{ return *_p;	}
	const T*		operator->() const	{ return &_p;	}
	T&				operator*()			{ return *_p;	}
	T*				operator->()		{ return &_p;	}
	T*				getVector()			{ return _p;	}

	T&				operator[](const size_t &x)			{ return *(_p + x); }
	const T&		operator[](const size_t &x) const	{ return *(_p + x); }

	VectorIterator&	operator++()			{ ++_p; return *this;							}
	VectorIterator	operator++(int)			{ VectorIterator tmp(*this); ++_p; return tmp;	}
	VectorIterator&	operator--()			{ --_p; return *this;							}
	VectorIterator	operator--(int)			{ VectorIterator tmp(*this); --_p; return tmp;	}

	std::ptrdiff_t	operator-(const VectorIterator& x)	{ return this->_p - x._p;	}
	std::ptrdiff_t	operator+(const VectorIterator& x)	{ return this->_p + x._p;	}
	VectorIterator	operator-(const size_t& x)			{ return this->_p - x;		}
	VectorIterator	operator+(const size_t& x)			{ return this->_p + x;		}
	void			operator-=(std::ptrdiff_t n)		{ return _p -= n;			}
	void			operator+=(std::ptrdiff_t n)		{ return _p += n;			}
	bool			operator>(const VectorIterator& x)	{ return _p > x._p;			}
	bool			operator>=(const VectorIterator& x)	{ return _p >= x._p;		}
	bool			operator<(const VectorIterator& x)	{ return _p < x._p;			}
	bool			operator<=(const VectorIterator& x)	{ return _p <= x._p;		}
	
};

// --------------------------- Const list Iterator ---------------------------
template < class T > 
class ConstVectorIterator : public VectorIterator<T>
{
public:
	ConstVectorIterator() : VectorIterator<T>()										{}
	ConstVectorIterator(T * x) : VectorIterator<T>(x)					{}
	ConstVectorIterator(const ConstVectorIterator& copy) : VectorIterator<T>(copy)	{}
	ConstVectorIterator(VectorIterator<T> x) : VectorIterator<T>(x)					{}

	ConstVectorIterator&	operator=(const ConstVectorIterator& x) { this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};
// --------------------------- Reverse list Iterator ---------------------------
template < class T > 
class ReverseVectorIterator : public VectorIterator<T>
{
public:
	// ReverseVectorIterator() : VectorIterator<T>()										{}
	ReverseVectorIterator(T* x) : VectorIterator<T>(x)						{}
	ReverseVectorIterator(const ReverseVectorIterator& copy) : VectorIterator<T>(copy)	{}

	ReverseVectorIterator&	operator=(const ReverseVectorIterator& x) { this->_p = x._p; return *this;	}
	
	ReverseVectorIterator&	operator++()			{ --this->_p; return *this;											}
	ReverseVectorIterator	operator++(int)			{ ReverseVectorIterator tmp(*this); --this->_p; return tmp;	}
	ReverseVectorIterator&	operator--()			{ ++this->_p; return *this;											}
	ReverseVectorIterator	operator--(int)			{ ReverseVectorIterator tmp(*this); ++this->_p; return tmp;	}
};
// --------------------------- Const Reverser list Iterator ---------------------------
template < class T > 
class ConstReverseVectorIterator : public ReverseVectorIterator<T>
{
public:
	// ConstReverseVectorIterator() : ReverseVectorIterator<T>()											{}
	// ConstReverseVectorIterator(T * x) : ReverseVectorIterator<T>(x)							{}
	// ConstReverseVectorIterator(const ConstReverseVectorIterator& copy) : ReverseVectorIterator<T>(copy)	{}
	ConstReverseVectorIterator(ReverseVectorIterator<T> x) : ReverseVectorIterator<T>(x)					{}

	ConstReverseVectorIterator&	operator=(const ConstReverseVectorIterator& x)	{ this->_p = x._p; return *this;	}

	const T &		operator*()				{ return this->_p->value; }
};

}// end namespace ft
#endif