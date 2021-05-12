
#ifndef FT_CONTAINERS_VECTORITERATOR_HPP
#define FT_CONTAINERS_VECTORITERATOR_HPP

//#include "vector.hpp"

namespace ft
{
	template<typename T>
	class VectorIterator
	{
    protected:
		T *ptr;
	public:


		VectorIterator(T *ptr) : ptr(ptr)
		{
			this->ptr = ptr;
		}

        T *getPtr() const {
            return ptr;
        }

        VectorIterator()
		{}

		virtual ~VectorIterator()
		{}

		VectorIterator(const VectorIterator &other)
		{
			this->ptr = other.ptr;
		}

		VectorIterator &operator=(const VectorIterator &other)
		{
			this->ptr = other.ptr;
			return (*this);
		}

		//переопределение операторов

		T   *operator->()
        {
            return (ptr);
        }

		VectorIterator operator++(int)
		{
            VectorIterator iter(*this);
            this->ptr++;
			return (iter);
		}

		VectorIterator operator+(int a)
		{
		    VectorIterator iter(*this);
			iter.ptr += a;
			return (iter);
		}

		VectorIterator &operator+=(int a)
		{
			ptr += a;
			return (*this);
		}

		VectorIterator &operator++()
		{
			++ptr;
			return (*this);
		}

		VectorIterator operator--(int)
		{
            VectorIterator iter(*this);
            this->ptr--;
			return (iter);
		}

		VectorIterator operator-(int a)
		{
			return this->operator+(-a);
		}

		VectorIterator &operator-=(int a)
		{
			return operator+=(-a);
		}

		VectorIterator &operator--()
		{
			--ptr;
			return (*this);
		}

		T &operator*()
		{
			return (*ptr);
		}

		bool operator==(const VectorIterator &rhs) const
		{
			return ptr == rhs.ptr;
		}

		bool operator!=(const VectorIterator &rhs) const
		{
			return (ptr != rhs.ptr);
		}

		bool operator<(const VectorIterator &rhs) const
		{
			return ptr < rhs.ptr;
		}

		bool operator>(const VectorIterator &rhs) const
		{
			return ptr > rhs.ptr;
		}

		bool operator<=(const VectorIterator &rhs) const
		{
			return ptr <= rhs.ptr;
		}

		bool operator>=(const VectorIterator &rhs) const
		{
			return ptr >= rhs.ptr;
		}

		T &operator[](int index)
		{
			return *(ptr + index);
		}
	};

    template<typename T>
    class ReverseVectorIterator
    {
    protected:
        T *ptr;
    public:
        ReverseVectorIterator(T *ptr) : ptr(ptr)
        {}

        ReverseVectorIterator()
        {}

        virtual ~ReverseVectorIterator()
        {}

        ReverseVectorIterator(const ReverseVectorIterator &other)
        {
            this->ptr = other.ptr;
        }

        ReverseVectorIterator &operator=(const ReverseVectorIterator &other)
        {
            this->ptr = other.ptr;
            return (*this);
        }

        //переопределение операторов

		T   *operator->()
		{
			return (ptr);
		}

        ReverseVectorIterator operator++(int)
        {
            ReverseVectorIterator iter(*this);
            this->ptr--;
            return (iter);
        }

        ReverseVectorIterator operator+(int a)
        {
            ReverseVectorIterator iter(*this);
            iter.ptr -= a;
            return (iter);
        }

        ReverseVectorIterator &operator+=(int a)
        {
            ptr -= a;
            return (*this);
        }

        ReverseVectorIterator &operator++()
        {
            --ptr;
            return (*this);
        }

        ReverseVectorIterator operator--(int)
        {
            ReverseVectorIterator iter(*this);
            this->ptr++;
            return (iter);
        }

        ReverseVectorIterator operator-(int a)
        {
            return this->operator+(-a);
        }

        ReverseVectorIterator &operator-=(int a)
        {
            ptr += a;
            return (*this);
        }

        ReverseVectorIterator &operator--()
        {
            ++ptr;
            return (*this);
        }

        T &operator*()
        {
            return (*ptr);
        }

        bool operator==(const ReverseVectorIterator &rhs) const
        {
            return ptr == rhs.ptr;
        }

        bool operator!=(const ReverseVectorIterator &rhs) const
        {
            return (ptr != rhs.ptr);
        }

        bool operator<(const ReverseVectorIterator &rhs) const
        {
            return ptr < rhs.ptr;
        }

        bool operator>(const ReverseVectorIterator &rhs) const
        {
            return ptr > rhs.ptr;
        }

        bool operator<=(const ReverseVectorIterator &rhs) const
        {
            return ptr <= rhs.ptr;
        }

        bool operator>=(const ReverseVectorIterator &rhs) const
        {
            return ptr >= rhs.ptr;
        }

        T &operator[](int index)
        {
            return *(ptr - index);
        }

    };

    template<typename T>
    class ConstVectorIterator : public VectorIterator<T>
    {

    public:
        ConstVectorIterator(T *ptr) : VectorIterator<T>(ptr)
        {
        }

        ConstVectorIterator() : VectorIterator<T>()
        {}

        virtual ~ConstVectorIterator()
        {}

        ConstVectorIterator(const ConstVectorIterator &other)
        {
            this->ptr = other.ptr;
        }

        ConstVectorIterator &operator=(const ConstVectorIterator &other)
        {
            this->ptr = other.ptr;
            return (*this);
        }

        //переопределение операторов

        const T &operator*()
        {
            return (*this->ptr);
        }

        const T &operator[](int index)
        {
            return *(this->ptr + index);
        }

        ConstVectorIterator(VectorIterator<T> iterator) {
			this->ptr = iterator.operator->();
        }
    };

    template<typename T>
    class ConstReverseVectorIterator : public ReverseVectorIterator<T>
    {


    public:

        ConstReverseVectorIterator(T *ptr) : ReverseVectorIterator<T>(ptr)
        {}

        ConstReverseVectorIterator() : ReverseVectorIterator<T>()
        {}

		ConstReverseVectorIterator(ReverseVectorIterator<int> iterator)
		{
			this->ptr = iterator.operator->();
		}

		virtual ~ConstReverseVectorIterator()
        {}

        ConstReverseVectorIterator(const ConstReverseVectorIterator &other)
        {
            this->ptr = other.ptr;
        }

        ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &other)
        {
            this->ptr = other.ptr;
            return (*this);
        }

        //переопределение операторов

        const T &operator*()
        {
            return (*this->ptr);
        }

        const T &operator[](int index)
        {
            return *(this->ptr - index);
        }

        ConstReverseVectorIterator(VectorIterator<T> iterator) {
			this->ptr = iterator.operator->();
        }
    };
}

#endif //FT_CONTAINERS_VECTORITERATOR_HPP
