//
// Created by 1 on 26.11.2020.
//

#ifndef CONTAINERS_QUEUE_HPP
#define CONTAINERS_QUEUE_HPP
#include "list.hpp"

namespace  ft {
    template<class T, class Container = ft::list<T> >
    class queue {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

        //Constructor

    private:
        container_type container;

    public:

        //Coplien form
        explicit queue(const container_type &ctnr = container_type()) {
            container = ctnr;
        }

        virtual ~queue() {
        }

        //Member functions
        bool empty() const {
            return container.empty();
        }

        size_type size() const {
            return container.size();
        }

        value_type &front() {
            return container.front();
        }

        const value_type &front() const {
            return container.front();
        }

        const value_type &back() const {
            return container.back();
        }

        value_type &back(){
            return container.back();
        }

        void push(const value_type &val) {
            container.push_back(val);
        }

        void pop() {
            container.pop_front();
        }

        //Non member functions
        friend bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
            return lhs.container == rhs.container;
        }

        friend bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
            return lhs.container != rhs.container;
        }

        friend bool operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
            return lhs.container < rhs.container;
        }

        friend bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
            return lhs.container <= rhs.container;
        }

        friend bool operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
            return lhs.container > rhs.container;
        }

        friend bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
            return lhs.container >= rhs.container;
        }

		friend void swap (queue<T,Container>& x, queue<T,Container>& y)
		{
			x.container.swap(y.container);
		}
    };
}
#endif //CONTAINERS_QUEUE_HPP
