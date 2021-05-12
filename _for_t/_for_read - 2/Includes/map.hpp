//
// Created by 1 on 27.11.2020.
//

#ifndef CONTAINERS_MAP_HPP
#define CONTAINERS_MAP_HPP
#include <utility>
#include <memory>
#include <functional>
#include <cstddef>
#include <iostream>
#include "MapIterator.hpp"

namespace ft {
    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<Key, T> > >
    class map {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        //typedef Tree<key_type, mapped_type> node;
        typedef std::pair<Key, T> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        //Iterators
        typedef typename ft::MapIterator<Key, T, Compare, Alloc> 				        iterator;
        typedef typename ft::ConstMapIterator<Key, T, Compare, Alloc> 			        const_iterator;
        typedef typename ft::ReverseMapIterator<Key, T, Compare, Alloc> 				reverse_iterator;
        typedef typename ft::ConstReverseMapIterator<Key, T, Compare, Alloc> 			const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;

        //value_compare function from docs
        class value_compare {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            friend class map;

        protected:
            Compare comp;
            allocator_type allocator;

            value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;

            bool operator()(const value_type &x, const value_type &y) const {
                return comp(x.first, y.first);
            }
        };

    private:
        Compare 									comp;
        allocator_type 								allocator;
        size_type       							_size;
        Tree<Key, T, Compare> 						*tree;
        std::allocator<s_tree<Key, T> >		node_allocator;

    public:

        //Constructors, destructors
        explicit map (const key_compare& comp = key_compare(),
                      const allocator_type& alloc = allocator_type())
        {
            this->comp = comp;
            this->allocator = alloc;
            tree = new Tree<Key, T, Compare, Alloc>(comp, allocator);
            _size = 0;
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
             const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type())
        {
            this->comp = comp;
            this->allocator = alloc;
            tree = new Tree<Key, T, Compare, Alloc>(comp, allocator);
            _size = 0;
            this->insert(first, last);
        }

        map (const map& x)
        {
            this->comp = x.comp;
            this->allocator = x.allocator;
            tree = new Tree<Key, T, Compare, Alloc>(comp, allocator);
            iterator it = x.begin();
            iterator ite = x.end();
            this->insert(it, ite);
        }

        ~map()
        {
            clear();
            delete tree;
        }

        map& operator= (const map& x)
        {
            clear();
            delete tree;
            this->comp = x.comp;
            this->allocator = x.allocator;
            this->tree = new Tree<Key, T, Compare, Alloc>(comp, allocator);
            iterator it = x.begin();
            iterator ite = x.end();
            this->insert(it, ite);
            return (*this);
        }
        //iterators
        iterator       begin()
        {
            iterator it = iterator(tree);
            it.setPtr(tree->findMin());
            return it;
        }

        const_iterator       begin() const
        {
            const_iterator it = const_iterator(tree);
            it.setPtr(tree->findMin());
            return it;
        }

        iterator        end()
        {
            iterator it = iterator (tree);
            it.setPtr(tree->getAnEnd());
            return (it);
        }

        const_iterator        end() const
        {
            const_iterator it = const_iterator (tree);
            it.setPtr(tree->getAnEnd());
            return (it);
        }

        reverse_iterator                rbegin()
        {
            reverse_iterator it = reverse_iterator(tree);
            it.setPtr(tree->findMax());
            return it;
        }

        const_reverse_iterator       rbegin() const
        {
            const_reverse_iterator it = const_reverse_iterator(tree);
            it.setPtr(tree->findMax());
            return it;
        }

        const_reverse_iterator       rend() const
        {
            const_reverse_iterator it = const_reverse_iterator(tree);
            it.setPtr(tree->getBegin());
            return it;
        }

        reverse_iterator        rend()
        {
            reverse_iterator it = reverse_iterator (tree);
            it.setPtr(tree->getBegin());
            return (it);
        }

        //Capacity

        bool empty() const
        {
            return (_size == 0);
        }

        size_type size() const
        {
            return _size;
        }

        size_type max_size() const
        {
			return node_allocator.max_size();
            //return std::numeric_limits<difference_type>::max();
        }

        //Element acess
        mapped_type& operator[] (const key_type& k)
        {
            mapped_type &m = tree->find(k);
            _size = tree->getSize();
            return m;
        }

        //Modifiers
        std::pair<iterator,bool> insert (const value_type& val)
        {
            iterator it = iterator (tree);
            it.setPtr(tree->add(val.first, val.second));
			std::pair<iterator, bool> ret(it, tree->isAdd());
            _size = tree->getSize();
            return (ret);
        }

        iterator insert(iterator position, const value_type& val)
        {
            (void)position;
            s_tree<Key, T> *ret = tree->add(NULL, val.first, val.second);
            iterator it(tree);
            it.setPtr(ret);
            _size = tree->getSize();
            return (it);
        }

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                insert(*first);
                first++;
            }
        }

        void erase (iterator position)
        {
            tree->remove(position.getPtr());
            _size = tree->getSize();
        }

        size_type erase (const key_type& k)
        {
            s_tree<Key, T> *node = tree->findNode(k);
            if (!node)
                return (0);
            tree->remove(node);
            _size = tree->getSize();
            return (1);
        }

        void erase (iterator first, iterator last)
        {
            while (first != last)
            {
                iterator tmp = ++first;
                --first;
                erase(first);
                first = tmp;
            }
        }

        void swap (map& x)
        {
            Compare tmp = comp;
            comp = x.comp;
            x.comp = tmp;

            Alloc tmp_allocator = allocator;
            allocator = x.allocator;
            x.allocator = tmp_allocator;

            size_type tmp_size = _size;
            _size = x._size;
            x._size = tmp_size;

            Tree<Key, T, Compare> *tmp_tree = tree;
            tree = x.tree;
            x.tree = tmp_tree;
        }

        void clear()
        {
        	erase(begin(), end());
        }

        //Observers

        key_compare key_comp() const
        {
            return comp;
        }

        value_compare value_comp() const
        {
            return value_compare(comp);
        }

        //

        iterator find (const key_type& k)
        {
            s_tree<Key, T> *node = tree->findNode(k);
            if (!node)
                return (end());
            iterator it(tree);
            it.setPtr(node);
            return (it);
        }

        const_iterator find (const key_type& k) const
        {
            s_tree<Key, T> *node = tree->findNode(k);
            if (!node)
                return (end());
            const_iterator it(tree);
            it.setPtr(node);
            return (it);
        }

        size_type count (const key_type& k) const
        {
            s_tree<Key, T> *node = tree->findNode(k);
            if (node)
                return (1);
            return (0);
        }

        iterator lower_bound (const key_type& k)
        {
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {
                if (!comp(it->first, k))
                    return it;
                it++;
            }
            return (it);
        }

        const_iterator lower_bound (const key_type& k) const
        {
            const_iterator it = begin();
            const_iterator ite = end();
            while (it != ite)
            {
                if (!comp(it->first, k))
                    return it;
                it++;
            }
            return (it);
        }

        iterator upper_bound (const key_type& k)
        {
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {
                if (comp(k, it->first))
                    return it;
                it++;
            }
            return (it);
        }

        const_iterator upper_bound (const key_type& k) const
        {
            const_iterator it = begin();
            const_iterator ite = end();
            while (it != ite)
            {
                if (comp(k, it->first))
                    return it;
                it++;
            }
            return (it);
        }

        std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            return std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
        }

        std::pair<iterator,iterator>             equal_range (const key_type& k)
        {
            return std::pair<iterator,iterator>(lower_bound(k), upper_bound(k));
        }

    private:


    };
}

#endif
