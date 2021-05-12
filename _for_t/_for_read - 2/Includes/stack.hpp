
#ifndef CONTAINERS_STACK_HPP
#define CONTAINERS_STACK_HPP

#include <iostream>
#include "list.hpp"

namespace  ft {
    template<class T, class Container = ft::list<T> >
    class stack {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

        //Constructor

    private:
        container_type container;

    public:

        //Coplien form
        explicit stack(const container_type &ctnr = container_type()) {
            container = ctnr;
        }

        virtual ~stack() {
        }

        //Member functions
        bool empty() const {
            return container.empty();
        }

        size_type size() const {
            return container.size();
        }

        value_type &top() {
            return container.back();
        }

        const value_type &top() const {
            return container.back();
        }

        void push(const value_type &val) {
            container.push_back(val);
        }

        void pop() {
            container.pop_back();
        }

        //Non member functions
        friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return lhs.container == rhs.container;
        }

        friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return lhs.container != rhs.container;
        }

        friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return lhs.container < rhs.container;
        }

        friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return lhs.container <= rhs.container;
        }

        friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return lhs.container > rhs.container;
        }

        friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return lhs.container >= rhs.container;
        }

		friend void swap (stack<T,Container>& x, stack<T,Container>& y)
		{
        	x.container.swap(y.container);
		}
    };
}
#endif //CONTAINERS_STACK_HPP
