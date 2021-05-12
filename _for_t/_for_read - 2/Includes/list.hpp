//
// Created by 1 on 22.11.2020.
//

#ifndef LIST_LIST_HPP
#define LIST_LIST_HPP
# include <memory>
#include <cstddef>
# include "ListIterator.hpp"

namespace ft {

    template<class T, class A = std::allocator<T> >
    class list {
    public:
        typedef T value_type;
        typedef A allocator_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;
        typedef const T *const_ptr;
        typedef typename ft::ListIterator<T> 				iterator;
        typedef typename ft::ConstListIterator<T>			const_iterator;
        typedef typename ft::ReverseListIterator<T>         reverse_iterator;
        typedef typename ft::ConstReverseListIterator<T>	const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;

    private:
        LinkedList<value_type>                      *head;
        LinkedList<value_type>                      *tail;
        LinkedList<value_type>                      *border;
        size_type                                    len;
        allocator_type                               allocator;
        std::allocator<LinkedList<T> > 				node_allocator;

    public:

        //Constructors
        explicit list (const allocator_type& alloc = allocator_type())
        {
            this->allocator = alloc;
            border = this->new_node(head, tail);
            border->elem = allocator.allocate(1);
			allocator.construct(border->elem, value_type());
            this->head = border;
            this->tail = border;
            border->prev = tail;
            border->next = head;
            len = 0;
        }

        explicit list (size_type n, const value_type& val = value_type(),
                       const allocator_type& alloc = allocator_type())
        {
            this->allocator = alloc;
            border = this->new_node(head, tail);
            border->elem = allocator.allocate(1);
			allocator.construct(border->elem, value_type());
            this->head = border;
            this->tail = border;
            border->prev = tail;
            border->next = head;
            len = 0;
            size_type i = 0;
            while (i < n)
            {
                push_back(val);
                i++;
            }
        }

        template <class InputIterator>
        list (InputIterator first, InputIterator last,
              const allocator_type& alloc = allocator_type())
        {
            this->allocator = alloc;
            border = this->new_node(head, tail);
            border->elem = allocator.allocate(1);
			allocator.construct(border->elem, value_type());
            this->head = border;
            this->tail = border;
            border->prev = tail;
            border->next = head;
            len = 0;
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }

        list (const list& x)
        {
            this->allocator = x.allocator;
            border = this->new_node(head, tail);
            border->elem = allocator.allocate(1);
			allocator.construct(border->elem, value_type());
            this->head = border;
            this->tail = border;
            border->prev = tail;
            border->next = head;
            len = 0;

            iterator it = x.begin();
            iterator ite = x.end();
            while (it != ite)
            {
                push_back(*it);
                it++;
            }
        }

        virtual ~list() {
            clear();
            deleteElem(border);
        }

        //Assignation operator

        list& operator = (const list& x)
        {
            clear();
            deleteElem(this->border);
            this->allocator = x.allocator;
            border = this->new_node(head, tail);
            border->elem = allocator.allocate(1);
			allocator.construct(border->elem, value_type());
            this->head = border;
            this->tail = border;
            border->prev = tail;
            border->next = head;
            len = 0;

            iterator it = x.begin();
            iterator ite = x.end();
            while (it != ite)
            {
                push_back(*it);
                it++;
            }
            return (*this);
        }

        //Iterators

        iterator begin()
        {
            return iterator(this->head);
        }

        const_iterator begin() const
        {
            return const_iterator(this->head);
        }

        iterator end()
        {
            return iterator(this->border);
        }

        const_iterator end() const
        {
            return const_iterator(this->border);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(this->tail);
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(this->tail);
        }

        reverse_iterator rend()
        {
            return reverse_iterator(this->border);
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(this->border);
        }

        //Capacity

        bool empty() const
        {
            return len == 0;
        }

        size_type size() const
        {
            return len;
        }

        size_type max_size() const
        {
        	return node_allocator.max_size();
			//return std::numeric_limits<difference_type>::max();
        }

        //Element access

        reference front()
        {
            return (*(head->elem));
        }
        
        const_reference front() const
        {
            return (*(head->elem));
        }

        reference back()
        {
            return (*(tail->elem));
        }

        const_reference back() const
        {
            return (*(tail->elem));
        }

        //Modifiers
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            this->clear();
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }

        void assign (size_type n, const value_type& val)
        {
            this->clear();
            size_type i = 0;
            while (i < n)
            {
                push_back(val);
                i++;
            }
        }

        void push_front (const value_type& val)
        {
            LinkedList<value_type> *ptr = new LinkedList<value_type>();
            ptr->elem = allocator.allocate(1);
            allocator.construct(ptr->elem, val);
            if (len == 0)
            {
                head = tail = ptr;
                ptr->next = border;
                head->prev = border;
                border->next = head;
            }
            else
            {
                ptr->next = head;
                head = ptr;
                head->prev = border;
                border->next = head;
            }
            len++;
        }

        void pop_front()
        {
            LinkedList<value_type> *new_head = head->next;
            allocator.destroy(head->elem);
            allocator.deallocate(head->elem, 1);
            delete head;
            head = new_head;
            head->prev = border;
            border->next = head;
            len--;
        }

        void push_back (const value_type& val)
        {
            LinkedList<value_type> *ptr = new LinkedList<value_type>();
            ptr->next = border;
            ptr->elem = allocator.allocate(1);
            allocator.construct(ptr->elem, val);
            if (len == 0)
            {
                head = tail = ptr;
                head->prev = border;
                border->prev = head;
                border->next = head;
            }
            else
            {
                tail->next = ptr;
                ptr->next = border;
                ptr->prev = tail;
                tail = tail->next;
                border->prev = tail;
            }
            len++;
        }

        void pop_back()
        {
            if (len == 0)
                return ;
            LinkedList<value_type> *tmp = tail->prev;
            allocator.destroy(tail->elem);
            allocator.deallocate(tail->elem, 1);
            delete tail;
            tail = tmp;
            tail->next = border;
            border->prev = tail;
            len--;
        }

        iterator insert (iterator position, const value_type& val)
        {
            iterator it = begin();
            iterator ite = end();
            LinkedList<value_type> *node = createNewElem(val);
            LinkedList<value_type> *posPrev = position.getPtr()->prev;
            node->prev = posPrev;
            posPrev->next = node;
            node->next = position.getPtr();
            position.getPtr()->prev = node;
            if (position == head)
                head = node;
            if (position == border)
                tail = node;
            len++;
            return iterator(node);
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            if (n == 0)
                return ;
            while (n)
            {
                insert(position, val);
                position--;
                n--;
            }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {
            iterator t = position;
            iterator prev = --t;
            ++t;
            if (first == last)
                return ;
            --last;
            while (first != last)
            {
                insert(position, *last);
                position--;
                if (last == t)
                    last = prev;
                else
                    last--;
            }
            insert(position, *last);
        }

        void    clear()
        {
            size_type i = 0;
            while (i < len)
            {
                LinkedList<value_type> *tmp = head->next;
                allocator.destroy(head->elem);
                allocator.deallocate(head->elem, 1);
                delete head;
                i++;
                head = tmp;
            }
            len = 0;
        }

        iterator erase(iterator position)
        {
            iterator loop = end();
            if (position == end())
                return NULL;
            if (len == 0)
                return position;
            LinkedList<T> *nxt = position.getPtr()->next;
            LinkedList<T> *pr = position.getPtr()->prev;
            deleteElem(position.getPtr());
            pr->next = nxt;
            nxt->prev = pr;
            if (position == head)
                head = nxt;
            if (position == tail)
                tail = pr;
            len--;
            return iterator(nxt);
        }

        iterator erase (iterator first, iterator last)
        {
            iterator ret;
            while (first != last)
            {
                ret = erase(first);
                first = ret;
            }
            return ret;
        }

        void swap(list& x)
        {
            LinkedList<value_type> *tmp;

            tmp = this->head;
            this->head = x.head;
            x.head = tmp;

            tmp = this->tail;
            this->tail = x.tail;
            x.tail = tmp;

            tmp = this->border;
            this->border = x.border;
            x.border = tmp;

            size_type tmp_size;
            allocator_type tmp_alloc;

            tmp_size = this->len;
            this->len = x.len;
            x.len = tmp_size;

            tmp_alloc = this->allocator;
            this->allocator = x.allocator;
            x.allocator = tmp_alloc;
        }

        void resize (size_type n, value_type val = value_type())
        {
            if (n == 0)
                clear();
            if (n == len)
                return;
            if (n < len)
            {
                while (n < len)
                    pop_back();
            }
            else
            {
                while (n > len)
                    push_back(val);
            }
        }

        // Operations

        void splice (iterator position, list& x, iterator i)
        {
//            iterator it = begin();
//            while (it != position)
//                it++;
            // Меняем указатели в this объекте, cохраняя next и prev наших this и x листов во временных объектах
            LinkedList<T> *currThis = position.getPtr();
            LinkedList<T> *prevThis = currThis->prev;
            LinkedList<T> *transfered = i.getPtr();
            LinkedList<T> *prevX = transfered->prev;
            LinkedList<T> *nextX = transfered->next;
            if (currThis == head)
                head = transfered;
            if(currThis == border)
                tail = transfered;
            currThis->prev = transfered;
            prevThis->next = transfered;
            transfered->next = currThis;
            transfered->prev = prevThis;
            len++;

            // Меняем указатели в x объекте

            if (i.getPtr() == x.head)
                x.head = nextX;
            else if(i.getPtr() == x.tail)
                x.tail = prevX;
            nextX->prev = prevX;
            prevX->next = nextX;
            x.len--;
        }

        void splice (iterator position, list& x, iterator first, iterator last)
        {
           while (first != last)
           {
               iterator tmp = ++first;
               splice(position, x, --first);
               first = tmp;
           }
        }

        void splice(iterator position, list& x)
        {
            LinkedList<T> *currThis = position.getPtr();
            LinkedList<T> *prevThis = currThis->prev;
            currThis->prev = x.tail;
            x.tail->next = currThis;
            prevThis->next = x.head;
            x.head->prev = prevThis;
            if (currThis == head)
                head = x.head;
            else if (currThis == border)
                tail = x.tail;
           len += x.len;
           x.len = 0;
           x.head = x.tail = x.border;
        }

        void remove (const value_type& val)
        {
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {
                if (*it == val)
                    it = erase(it);
                else
                    it++;
            }
        }

        template <class Predicate>
        void remove_if (Predicate pred)
        {
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {
                if (pred(*it) == true)
                    it = erase(it);
                else
                    it++;
            }
        }

        void unique()
        {
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {
                iterator nxt = iterator(it.getPtr()->next);
                if (*nxt == *it)
                    it = erase(it);
                else
                    it++;
            }
        }

        template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred)
        {
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {
                iterator nxt = iterator(it.getPtr()->next);
                if (binary_pred(*it, *nxt) == true)
                    it = erase(nxt);
                else
                    it++;
            }
        }

        void merge (list& x)
        {
            if (this == &x)
                return;
            iterator it1 = begin();
            iterator ite1 = end();
            iterator it2 = x.begin();
            iterator ite2 = x.end();
            while (it2 != ite2)
            {
                if (*it1 < *it2 && it1 != ite1)
                    it1++;
                else
                {
                    iterator tmp2 = it2.getPtr()->next;
                    splice(it1, x, it2);
                    it2 = tmp2;
                }
            }
        }

        template <class Compare>
        void merge (list& x, Compare comp)
        {
            if (this == &x)
                return;
            iterator it1 = begin();
            iterator ite1 = end();
            iterator it2 = x.begin();
            iterator ite2 = x.end();
            while (it2 != ite2)
            {
                if (comp(*it1, *it2) && it1 != ite1)
                    it1++;
                else
                {
                    iterator tmp = it2.getPtr()->next;
                    splice(it1, x, it2);
                    it2 = tmp;
                }
            }
        }

        void sort()
        {
            if (len == 1 || len == 0)
                return ;
            iterator it = begin();
            iterator ite = end();
            iterator next_loop;
            while (it != ite)
            {
                next_loop = it;
                next_loop++;
                while (next_loop != ite)
                {
                    if (*next_loop < *it) {
                       swapNodes(it.getPtr(), next_loop.getPtr());
                    }
                    next_loop++;
                }
                it++;
            }
        }

        template <class Compare>
        void sort (Compare comp)
        {
            if (len == 1 || len == 0)
                return ;
            iterator it = begin();
            iterator ite = end();
            iterator next_loop;
            while (it != ite)
            {
                next_loop = it;
                next_loop++;
                while (next_loop != ite)
                {
                    if (comp(*next_loop, *it) == true)
                        swapNodes(it.getPtr(), next_loop.getPtr());
                    next_loop++;
                }
                it++;
            }
        }

        void reverse()
        {
            if (len == 0 || len == 1)
                return ;
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {
                LinkedList<T> *curr = it.getPtr();
                LinkedList<T> *nxt = it.getPtr()->next;
                curr->next = curr->prev;
                curr->prev = nxt;
                it--;
            }
            LinkedList<T> *tmpHead = head;
            head = tail;
            tail = tmpHead;
            head->prev = border;
            border->next = head;
            border->prev = tail;
            tail->next = border;
        }

    private:

        LinkedList<value_type>   *new_node(LinkedList<value_type> *prev, LinkedList<value_type> *next)
        {
            LinkedList<value_type> *ptr;

            ptr = new LinkedList<T>();
            ptr->next = next;
            ptr->prev = prev;
            return (ptr);
        }

        LinkedList<T>       *createNewElem(const value_type& val)
        {
            LinkedList<value_type> *node = new LinkedList<T>();
            node->elem = allocator.allocate(1);
            allocator.construct(node->elem, val);
            return node;
        }

        void    deleteElem(LinkedList<T> *node)
        {
            allocator.destroy(node->elem);
            allocator.deallocate(node->elem, 1);
            delete node;
        }

        void    swapNodes(LinkedList<T> *first, LinkedList<T> *second)
        {
            LinkedList<T> *secondNext = second->next;
            LinkedList<T> *secondPrev = second->prev;
            second->next = first->next;
            second->prev = first->prev;
            first->next = secondNext;
            first->prev = secondPrev;
            LinkedList<T> tmp = *first;
            *first = *second;
            *second = tmp;
        }
        

    };

    // Non-member functions

    template <class T, class Alloc>
    void swap (list<T,Alloc>& x, list<T,Alloc>& y)
    {
        x.swap(y);
    }

    template <class T, class Alloc>
    bool operator == (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename ft::list<T>::iterator it1 = lhs.begin();
        typename ft::list<T>::iterator ite1 = lhs.end();
        typename ft::list<T>::iterator it2 = rhs.begin();
        typename ft::list<T>::iterator ite2 = rhs.end();
        while (it1 != ite1 && it2 != ite2 && *it1 == *it2)
        {
            it1++;
            it2++;
        }
        if (it1 == ite1 && it2 == ite2)
            return (true);
        return (false);
    }

    template <class T, class Alloc>
    bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator < (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        typename ft::list<T>::iterator it1 = lhs.begin();
        typename ft::list<T>::iterator ite1 = lhs.end();
        typename ft::list<T>::iterator it2 = rhs.begin();
        typename ft::list<T>::iterator ite2 = rhs.end();
        while (it1 != ite1 && it2 != ite2 && *it1 == *it2)
        {
            it1++;
            it2++;
        }
        if (it1 == ite1 && it2 != ite2)
            return (true);
        return (*it1 < *it2);
    }

    template <class T, class Alloc>
    bool operator <= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool operator > (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator >= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }
}

#endif //LIST_LIST_HPP
