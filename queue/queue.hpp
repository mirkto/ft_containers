#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <iostream>
# include <deque>
// # include "queue_iterator.hpp"
namespace ft {// start namespace ft

	template <class T, class Container = std::deque<T> >
	class queue
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type		_container;

		public:
			//--- constructor
			explicit queue (const container_type& ctnr = container_type())
			{ _container = ctnr; }

			// queue::empty
			bool empty() const
			{ return _container.empty(); }

			// queue::size
			size_type size() const
			{ return _container.size(); }

			// queue::front
			value_type& front()				{ return _container.front(); }
			const value_type& front() const	{ return _container.front(); }

			// queue::back
			value_type& back()				{ return _container.back(); }
			const value_type& back() const	{ return _container.back(); }

			// queue::push
			void push (const value_type& val)
			{ _container.push_back(val); }

			// queue::pop
			void pop()
			{ _container.pop_front(); }
	
	// --------------------------- swap ---------------------------
	friend void swap(queue<T,Container>& x, queue<T,Container>& y)
	{ x._container.swap(y._container); }

	// --------------------------- Relational operators ---------------------------

	friend bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container == rhs._container; }

	friend bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container != rhs._container; }

	friend bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container < rhs._container; }

	friend bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container <= rhs._container; }

	friend bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container > rhs._container; }

	friend bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container >= rhs._container; }
	
	};

	// --------------------------- Non-member functions ---------------------------

	template <class T, class Container>
	void swap(queue<T,Container>& x, queue<T,Container>& y)
	{ x.swap(y); }

	// --------------------------- Relational operators ---------------------------
	template <class T, class Container>
	bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs == rhs; }

	template <class T, class Container>
	bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs != rhs; }

	template <class T, class Container>
	bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs < rhs; }

	template <class T, class Container>
	bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs <= rhs; }

	template <class T, class Container>
	bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs > rhs; }

	template <class T, class Container>
	bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs >= rhs; }

	// template <class T, class Container, class Alloc>
	// struct uses_allocator<queue<T,Container>,Alloc>;

}// end namespace ft
#endif