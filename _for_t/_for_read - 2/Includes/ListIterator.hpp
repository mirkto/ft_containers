//
// Created by 1 on 21.11.2020.
//

#ifndef LinkedList_LinkedListITERATOR_HPP
#define LinkedList_LinkedListITERATOR_HPP

namespace ft {

    template <typename  T>
    struct  LinkedList
    {
        struct LinkedList *next;
        struct LinkedList *prev;
        T *elem;
    };

    template <typename  T>
    class ListIterator {

    protected:
        LinkedList<T> *ptr;

    public:
        ListIterator(LinkedList<T> *ptr) : ptr(ptr) {}

        //Coplien's form
        ListIterator() {
            ptr = 0;
        }

        virtual ~ListIterator() {}

        ListIterator(const ListIterator<T> &copy)
        {
            this->ptr = copy.ptr;
        }

        ListIterator    &operator=(const ListIterator<T> &copy)
        {
            this->ptr = copy.ptr;
            return (*this);
        }

        //operators equal

        bool operator==(const ListIterator &rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const ListIterator &rhs) const {
            return rhs.ptr != ptr;
        }

        // pointers

        T&      		operator*()			{ return (*(ptr->elem)); }
        T*       		operator->()		{ return (ptr->elem);    }
        LinkedList<T>*	getPtr() const		{ return ptr;            }

        // increment/decrement

        ListIterator       &operator++()
        {
            ptr = ptr->next;
            return (*this);
        }

        ListIterator       operator++(int)
        {
            ListIterator tmp(*this);
            this->operator++();
            return (tmp);
        }

        ListIterator        &operator--()
        {
            ptr = ptr->prev;
            return (*this);
        }

        ListIterator       operator--(int)
        {
            ListIterator tmp(*this);
            this->operator--();
            return (tmp);
        }

    };

    template <typename T>
    class ConstListIterator : public ListIterator<T>
    {
    public:
        ConstListIterator(LinkedList<T> *ptr) : ListIterator<T>(ptr) {}

        ConstListIterator() : ListIterator<T>() {}

        ConstListIterator(const ListIterator<T> &copy) : ListIterator<T>(copy) {}

        ConstListIterator(ListIterator<T> iterator) {
        	this->ptr = iterator.operator->();
        }

        const T &operator*() {
            return *(this->ptr->elem);
        }
    };

    template <typename T>
    class ReverseListIterator
    {
    protected:
        LinkedList<T> *ptr;

    public:
        ReverseListIterator(LinkedList<T> *ptr) : ptr(ptr) {}

        //Coplien's form
        ReverseListIterator() {
            ptr = 0;
        }

        virtual ~ReverseListIterator() {}

        ReverseListIterator(const ReverseListIterator<T> &copy)
        {
            this->ptr = copy.ptr;
        }

        ReverseListIterator    &operator=(const ReverseListIterator<T> &copy)
        {
            this->ptr = copy.ptr;
            return (*this);
        }

        //operators equal

        bool operator==(const ReverseListIterator &rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const ReverseListIterator &rhs) const {
            return rhs.ptr != ptr;
        }

        // pointers

        T      &operator*()
        {
            return (*(ptr->elem));
        }

        T       *operator->()
        {
            return (ptr->elem);
        }

        // increment/decrement

        ReverseListIterator       &operator++()
        {
            ptr = ptr->prev;
            return (*this);
        }

        ReverseListIterator       operator++(int)
        {
            ReverseListIterator<T> tmp(*this);
            this->operator++();
            return (tmp);
        }

        ReverseListIterator        &operator--()
        {
            ptr = ptr->next;
            return (*this);
        }

        ReverseListIterator       operator--(int)
        {
            ReverseListIterator<T> tmp(*this);
            this->operator--();
            return (tmp);
        }
    };

    template <typename T>
    class ConstReverseListIterator : public ReverseListIterator<T>
    {
    public:
        ConstReverseListIterator(LinkedList<T> *ptr) : ReverseListIterator<T>(ptr) {}

        ConstReverseListIterator() : ReverseListIterator<T>() {}

        ConstReverseListIterator(const ReverseListIterator<T> &copy) : ReverseListIterator<T>(copy) {}

        ConstReverseListIterator(ReverseListIterator<T> iterator) {
        	this->ptr = iterator.operator->();
        }

        const T &operator*() {
            return *(this->ptr->elem);
        }
    };
}


#endif //LinkedList_LinkedListITERATOR_HPP
