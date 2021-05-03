#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft {// start namespace ft

template < class T, class Alloc = std::allocator<T> >
class vector
{
public:
	typedef T								value_type;
	typedef Alloc							allocator_type;
	typedef allocator_type::reference		reference;
	typedef allocator_type::const_reference	const_reference;
	typedef allocator_type::pointer			pointer;
	typedef allocator_type::const_pointer	const_pointer;
	typedef ptrdiff_t						difference_type;
	typedef size_t							size_type;

	typedef ft::VectorIterator				iterator;
	typedef ft::ConstVectorIterator			const_iterator;
	typedef ft::ReverseVectorIterator		reverse_iterator;
	typedef ft::ConstReverseVectorIterator	const_reverse_iterator;

private:
	allocator_type				_alloc;
	pointer						_start;
	pointer						_end;
	size_type					_capacity;

public:
//---------------------------- Member functions ----------------------------

// default constructor
explicit vector (const allocator_type& alloc = allocator_type());

// fill constructor
explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());

// range constructor
template <class InputIterator>
vector (InputIterator first, InputIterator last,
						const allocator_type& alloc = allocator_type());

// copy constructor
vector (const vector& x);

// default destructor
~vector();

// assignment
vector& operator= (const vector& x);

//---------------------------- Iterators ----------------------------
iterator begin();
const_iterator begin() const;
iterator end();
const_iterator end() const;
//---------------------------- Capacity ----------------------------
//---------------------------- Element access ----------------------------
//---------------------------- Modifiers ----------------------------
};
//--------------------- Non-member function overloads ------------------------
}// end namespace ft
#endif