#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <deque>
// # include "stack_iterator.hpp"
namespace ft {// start namespace ft

	template <class T, class Container = std::deque<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type		_container;

		public:
			//--- constructor
			explicit stack (const container_type& ctnr = container_type())
			{ _container = ctnr; }

			// stack::empty
			bool empty() const
			{ return _container.empty(); }

			// stack::size
			size_type size() const
			{ return _container.size(); }

			// stack::front
			value_type& top()				{ return _container.back(); }
			const value_type& top() const	{ return _container.back(); }

			// stack::push
			void push (const value_type& val)
			{ _container.push_back(val); }

			// stack::pop
			void pop()
			{ _container.pop_back(); }
	
	// --------------------------- swap ---------------------------
	friend void swap(stack<T,Container>& x, stack<T,Container>& y)
	{ x._container.swap(y._container); }

	// --------------------------- Relational operators ---------------------------

	friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs._container == rhs._container; }

	friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs._container != rhs._container; }

	friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs._container < rhs._container; }

	friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs._container <= rhs._container; }

	friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs._container > rhs._container; }

	friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs._container >= rhs._container; }
	
	};

	// --------------------------- Non-member functions ---------------------------

	template <class T, class Container>
	void swap(stack<T,Container>& x, stack<T,Container>& y)
	{ x.swap(y); }

	// --------------------------- Relational operators ---------------------------
	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs == rhs; }

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs != rhs; }

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs < rhs; }

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs <= rhs; }

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs > rhs; }

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs >= rhs; }

	// template <class T, class Container, class Alloc>
	// struct uses_allocator<stack<T,Container>,Alloc>;

}// end namespace ft
#endif