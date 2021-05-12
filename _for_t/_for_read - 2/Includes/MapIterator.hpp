

#ifndef CONTAINERS_MAPITERATOR_HPP
#define CONTAINERS_MAPITERATOR_HPP

#include "Tree.hpp"

namespace ft {

    template < class Key, class T, class Compare, class Alloc >

    class MapIterator {
    protected:
       s_tree<Key, T> *ptr;
       Tree<Key, T, Compare, Alloc> *tree;

    public:

        MapIterator(Tree<Key, T, Compare, Alloc> *tree)
        {
            this->tree = tree;
        }

        void setPtr(s_tree<Key, T> *ptr) {
            this->ptr = ptr;
        }



        //Coplien's form

        virtual ~MapIterator() {

        }

        MapIterator(){
            ptr = 0;
        }

        MapIterator(const MapIterator<Key, T, Compare, Alloc> &copy) {
            this->ptr = copy.ptr;
        }

        MapIterator &operator=(const MapIterator<Key, T, Compare, Alloc> &copy) {
            this->ptr = copy.ptr;
            this->tree = copy.tree;
            return (*this);
        }

        //operators equal

        bool operator==(const MapIterator &rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const MapIterator &rhs) const {
            return rhs.ptr != ptr;
        }

        //pointers

        std::pair<Key, T> &operator*() {
            return (*(ptr->pair));
        }

        std::pair<Key, T> *operator->() {
            return (ptr->pair);
        }

        s_tree<Key, T> *getPtr() const {
            return ptr;
        }

        MapIterator &operator++() {
            ptr = tree->inc(ptr);
            return (*this);
        }

        MapIterator operator++(int) {
            MapIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        MapIterator &operator--() {
            ptr = tree->dec(ptr);
            return (*this);
        }

        MapIterator operator--(int) {
            MapIterator tmp(*this);
            this->operator--();
            return (tmp);
        }
    };

    template < class Key, class T, class Compare, class Alloc >
    class ReverseMapIterator
    {
    protected:
        s_tree<Key, T> *ptr;
        Tree<Key, T, Compare, Alloc> *tree;

    public:

        ReverseMapIterator(Tree<Key, T, Compare, Alloc> *tree)
        {
            this->tree = tree;
        }

        void setPtr(s_tree<Key, T> *ptr) {
            this->ptr = ptr;
        }

        //Coplien's form
        ReverseMapIterator() {
            ptr = 0;
        }

        virtual ~ReverseMapIterator() {}

        ReverseMapIterator(const ReverseMapIterator<Key, T, Compare, Alloc> &copy) {
            this->ptr = copy.ptr;
        }

        ReverseMapIterator &operator=(const ReverseMapIterator<Key, T, Compare, Alloc> &copy) {
            this->ptr = copy.ptr;
            return (*this);
        }

        //operators equal

        bool operator==(const ReverseMapIterator &rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const ReverseMapIterator &rhs) const {
            return rhs.ptr != ptr;
        }

        //pointers

        std::pair<Key, T> &operator*() {
            return (*(ptr->pair));
        }

        std::pair<Key, T> *operator->() {
            return (ptr->pair);
        }

        Tree<Key, T, Compare> *getPtr() const {
            return ptr;
        }

        ReverseMapIterator &operator++() {
            ptr = tree->dec(ptr);
            return (*this);
        }

        ReverseMapIterator operator++(int) {
            ReverseMapIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        ReverseMapIterator &operator--() {
            ptr = tree->inc(ptr);
            return (*this);
        }

        ReverseMapIterator operator--(int) {
            ReverseMapIterator tmp(*this);
            this->operator--();
            return (tmp);
        }
    };

    template < class Key, class T, class Compare, class Alloc >
    class ConstReverseMapIterator : public MapIterator<Key, T, Compare, Alloc>
    {
    public:
        ConstReverseMapIterator(s_tree<Key, T> *ptr) : ReverseMapIterator<Key, T, Compare, Alloc>(ptr) {}

        ConstReverseMapIterator() : ReverseMapIterator<Key, T, Compare, Alloc>() {}

        ConstReverseMapIterator(const ConstReverseMapIterator<Key, T, Compare, Alloc> &copy) : ReverseMapIterator<Key, T, Compare, Alloc>(copy) {}

        ConstReverseMapIterator(ReverseMapIterator<Key, T, Compare, Alloc> iterator) {
        	this->ptr = iterator.getPtr();
        }

        const T &operator*() {
            return *(this->ptr->pair);
        }
    };

    template < class Key, class T, class Compare, class Alloc >
    class ConstMapIterator : public MapIterator<Key, T, Compare, Alloc>
    {
    public:
        ConstMapIterator(s_tree<Key, T> *ptr) : ReverseMapIterator<Key, T, Compare, Alloc>(ptr) {}

        ConstMapIterator() : ReverseMapIterator<Key, T, Compare, Alloc>() {}

        ConstMapIterator(const ConstMapIterator<Key, T, Compare, Alloc> &copy) : MapIterator<Key, T, Compare, Alloc>(copy) {}

        ConstMapIterator(MapIterator<Key, T, Compare, Alloc> iterator) {
        	this->ptr = iterator.getPtr();
        }

        const T &operator*() {
            return *(this->ptr->pair);
        }
    };
    
}
#endif //CONTAINERS_MAPITERATOR_HPP
