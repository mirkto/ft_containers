//
// Created by 1 on 28.11.2020.
//

#include <vector>
#include <iostream>
#include "../Includes/vector.hpp"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

namespace vector_test
{

	void reverse_iterators_test1();
	void reverse_iterators_test2();
	
	void push_pop_tests();

	template<typename T>
	void operators_test(T &a, T &b, T &c)
	{
		if (a == b)
			std::cout << "a and b are equal\n";
		if (b != c)
			std::cout << "b and c are not equal\n";
		if (b < c)
			std::cout << "b is less than c\n";
		if (c > b)
			std::cout << "c is greater than b\n";
		if (a <= b)
			std::cout << "a is less than or equal to b\n";
		if (a >= b)
			std::cout << "a is greater than or equal to b\n";
		std::cout << std::endl;
	}

	template<typename T>
	void printList(T &container)
	{
		typename T::iterator it1 = container.begin();
		typename T::iterator it2 = container.end();
		while (it1 != it2)
		{
			std::cout << *it1 << " ";
			it1++;
		}
		std::cout << std::endl;
	}

	template<typename T>
	void printListConst(T &container)
	{
		typename T::const_iterator it1 = container.begin();
		typename T::const_iterator it2 = container.end();
		while (it1 != it2)
		{
			std::cout << *it1 << " ";
			it1++;
		}
		std::cout << std::endl;
	}

	template<typename T>
	void printListReverse(T &container)
	{
		typename T::reverse_iterator it1 = container.rbegin();
		typename T::reverse_iterator it2 = container.rend();
		while (it1 != it2)
		{
			std::cout << *it1 << " ";
			it1++;
		}
		std::cout << std::endl;
	}

	template<typename T>
	void printListReverseConst(T &container)
	{
		typename T::const_reverse_iterator it1 = container.rbegin();
		typename T::const_reverse_iterator it2 = container.rend();
		while (it1 != it2)
		{
			std::cout << *it1 << " ";
			it1++;
		}
		std::cout << std::endl;
	}

	template<typename T>
	void vector_info(T &container, const std::string &info, const std::string &test)
	{
		std::cout << test << " " << info << " size: " << container.size() << " ,capacity: " << container.capacity() <<
				  (container.empty() ? " ,empty container" : " ,not empty container") << " ,content: ";
		printList(container);
		std::cout << RESET << std::endl;
	}

	void constructors_test()
	{
		std::cout << BLUE << "           CONSTRUCTORS TEST " << RESET << std::endl;
		std::vector<int> lib;
		ft::vector<int> my;
		std::cout << GREEN;
		vector_info(lib, "lib", "default constructor,");
		std::cout << RED;
		vector_info(my, " my", "default constructor,");
		std::vector<int> lib1((size_t) 3, 4);
		ft::vector<int> my1((size_t) 3, 4);
		std::cout << GREEN;
		vector_info(lib1, "lib", "constructor fill with val,");
		std::cout << RED;
		vector_info(my1, " my", "constructor fill with val,");
		std::vector<int> lib2((size_t) 6);
		ft::vector<int> my2((size_t) 6);
		std::cout << GREEN;
		vector_info(lib2, "lib", "constructor fill without val,");
		std::cout << RED;
		vector_info(my2, " my", "constructor fill without val,");
		std::vector<int> lib3(lib1.begin(), lib1.end());
		ft::vector<int> my3(my1.begin(), my1.end());
		std::cout << GREEN;
		vector_info(lib3, "lib", "constructor range, ");
		std::cout << RED;
		vector_info(my3, " my", "constructor range, ");
		std::vector<int> lib4(lib3);
		ft::vector<int> my4(my3);
		std::cout << GREEN;
		vector_info(lib4, "lib", "constructor copy,");
		std::cout << RED;
		vector_info(my4, " my", "constructor copy,");
		lib4 = lib2;
		my4 = my2;
		std::cout << GREEN;
		vector_info(lib4, "lib", "assignation,");
		std::cout << RED;
		vector_info(my4, " my", "assignation,");
	}

	template<typename InputIterator>
	void print_iterators_info(const std::string &msg, InputIterator it1, InputIterator it2)
	{
		std::cout << msg << " iterator it1 = " << *it1 << ". Iterator it2 = " << *it2 << std::endl;
	}

	void iterators_test1()
	{
		std::cout << BLUE <<  "           ITERATORS TEST " << RESET << std::endl;
		std::vector<int> lib1((size_t) 1, 2);
		ft::vector<int> my1((size_t) 1, 2);
		lib1.push_back(3);
		lib1.push_back(4);
		lib1.push_back(5);
		my1.push_back(3);
		my1.push_back(4);
		my1.push_back(5);
		std::cout << GREEN;
		std::cout << "iterators begin ---> end lib: ";
		printList(lib1);
		std::cout << RED;
		std::cout << "iterators begin ---> end  my: ";
		printList(my1);

		std::cout << GREEN;
		std::cout << "iterators end ---> begin lib: ";
		printListReverse(lib1);
		std::cout << RED;
		std::cout << "iterators end ---> begin  my: ";
		printListReverse(my1);
		std::cout << BLUE << "           ITERATORS OPERATORS TEST " << RESET << std::endl;
		typedef std::vector<int>::iterator iterator_lib;
		typedef ft::vector<int>::iterator iterator_my;
		iterator_lib it1 = lib1.begin();
		iterator_lib it2 = lib1.begin();
		std::cout << GREEN;
		print_iterators_info("lib: ", it1, it2);
		it1 = it2 + 2;
		std::cout << "lib: " << " iterator it1 = it2 + 2" << std::endl;
		print_iterators_info("lib: ", it1, it2);
		std::cout << RESET;

		iterator_my itm1 = my1.begin();
		iterator_my itm2 = my1.begin();
		std::cout << std::endl;
		std::cout << GREEN;
		print_iterators_info(" my: ", itm1, itm2);
		itm1 = itm2 + 2;
		std::cout << " my: " << " iterator it1 = it2 + 2" << std::endl;
		print_iterators_info(" my: ", itm1, itm2);

		std::cout << RESET << std::endl;
		iterator_lib it3 = lib1.begin();
		iterator_lib it4 = lib1.begin();
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it3 = it4 += 2;
		std::cout << "lib: " << " iterator it1 = it2 += 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		iterator_my itm3 = my1.begin();
		iterator_my itm4 = my1.begin();
		std::cout <<RESET << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm3 = itm4 += 2;
		std::cout << " my: " << " iterator it1 = it2 += 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << RESET << std::endl;
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it3 = it4 -= 2;
		std::cout << "lib: " << " iterator it1 = it2 -= 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		std::cout << RESET << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm3 = itm4 -= 2;
		std::cout << " my: " << " iterator it1 = it2 -= 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << RESET << std::endl;
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it4 += 3;
		it3 = it4 - 2;
		std::cout << "lib: " << " iterator it1 = it2 - 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		std::cout << RESET << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm4 += 3;
		itm3 = itm4 - 2;
		std::cout << " my: " << " iterator it1 = it2 - 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);
		std::cout << RESET;

		std::cout << GREEN << "it++ lib: " << *(it3++) << std::endl;
		std::cout << RED << "it++  my: " << *(itm3++) << std::endl;
		std::cout << GREEN << "++it lib: " << *(++it3) << std::endl;
		std::cout << RED << "++it  my: " << *(++itm3) << std::endl;
		std::cout << GREEN << "--it lib: " << *(--it3) << std::endl;
		std::cout << RED << "--it  my: " << *(--itm3) << std::endl;
		std::cout << GREEN << "it-- lib: " << *(it3--) << std::endl;
		std::cout << RED << "it--  my: " << *(itm3--) << std::endl;
		reverse_iterators_test1();
	}
	
	void iterators_test2()
	{
		std::cout << BLUE <<  "           CONST ITERATORS TEST " << RESET << std::endl;
		std::vector<int> lib1((size_t) 1, 2);
		ft::vector<int> my1((size_t) 1, 2);
		lib1.push_back(3);
		lib1.push_back(4);
		lib1.push_back(5);
		my1.push_back(3);
		my1.push_back(4);
		my1.push_back(5);
		std::cout << GREEN;
		std::cout << "iterators begin ---> end lib: ";
		printListConst(lib1);
		std::cout << RED;
		std::cout << "iterators begin ---> end  my: ";
		printListConst(my1);

		std::cout << GREEN;
		std::cout << "iterators end ---> begin lib: ";
		printListReverseConst(lib1);
		std::cout << RED;
		std::cout << "iterators end ---> begin  my: ";
		printListReverseConst(my1);
		std::cout << BLUE << "           CONST ITERATORS OPERATORS TEST " << RESET << std::endl;
		typedef std::vector<int>::const_iterator iterator_lib;
		typedef ft::vector<int>::const_iterator iterator_my;
		iterator_lib it1 = lib1.begin();
		iterator_lib it2 = lib1.begin();
		std::cout << GREEN;
		print_iterators_info("lib: ", it1, it2);
		it1 = it2 + 2;
		std::cout << "lib: " << " iterator it1 = it2 + 2" << std::endl;
		print_iterators_info("lib: ", it1, it2);
		std::cout << RESET;

		iterator_my itm1 = my1.begin();
		iterator_my itm2 = my1.begin();
		std::cout << std::endl;
		std::cout << GREEN;
		print_iterators_info(" my: ", itm1, itm2);
		itm1 = itm2 + 2;
		std::cout << " my: " << " iterator it1 = it2 + 2" << std::endl;
		print_iterators_info(" my: ", itm1, itm2);

		std::cout << RESET << std::endl;
		iterator_lib it3 = lib1.begin();
		iterator_lib it4 = lib1.begin();
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it3 = it4 += 2;
		std::cout << "lib: " << " iterator it1 = it2 += 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		iterator_my itm3 = my1.begin();
		iterator_my itm4 = my1.begin();
		std::cout <<RESET << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm3 = itm4 += 2;
		std::cout << " my: " << " iterator it1 = it2 += 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << RESET << std::endl;
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it3 = it4 -= 2;
		std::cout << "lib: " << " iterator it1 = it2 -= 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		std::cout << RESET << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm3 = itm4 -= 2;
		std::cout << " my: " << " iterator it1 = it2 -= 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << RESET << std::endl;
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it4 += 3;
		it3 = it4 - 2;
		std::cout << "lib: " << " iterator it1 = it2 - 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		std::cout << RESET << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm4 += 3;
		itm3 = itm4 - 2;
		std::cout << " my: " << " iterator it1 = it2 - 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);
		std::cout << RESET;

		std::cout << GREEN << "it++ lib: " << *(it3++) << std::endl;
		std::cout << RED << "it++  my: " << *(itm3++) << std::endl;
		std::cout << GREEN << "++it lib: " << *(++it3) << std::endl;
		std::cout << RED << "++it  my: " << *(++itm3) << std::endl;
		std::cout << GREEN << "--it lib: " << *(--it3) << std::endl;
		std::cout << RED << "--it  my: " << *(--itm3) << std::endl;
		std::cout << GREEN << "it-- lib: " << *(it3--) << std::endl;
		std::cout << RED << "it--  my: " << *(itm3--) << std::endl;
		reverse_iterators_test2();
	}

	void reverse_iterators_test2()
	{
		std::vector<int> lib1((size_t) 1, 2);
		ft::vector<int> my1((size_t) 1, 2);
		lib1.push_back(3);
		lib1.push_back(4);
		lib1.push_back(5);
		my1.push_back(3);
		my1.push_back(4);
		my1.push_back(5);
		std::cout << BLUE << "           CONST REVERSE ITERATORS OPERATORS TEST " << RESET << std::endl;
		typedef std::vector<int>::const_reverse_iterator iterator_lib;
		typedef ft::vector<int>::const_reverse_iterator iterator_my;
		iterator_lib it1 = lib1.rbegin();
		iterator_lib it2 = lib1.rbegin();
		std::cout << GREEN;
		print_iterators_info("lib: ", it1, it2);
		it1 = it2 + 2;
		std::cout << "lib: " << " iterator it1 = it2 + 2" << std::endl;
		print_iterators_info("lib: ", it1, it2);

		iterator_my itm1 = my1.rbegin();
		iterator_my itm2 = my1.rbegin();
		std::cout << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm1, itm2);
		itm1 = itm2 + 2;
		std::cout << " my: " << " iterator it1 = it2 + 2" << std::endl;
		print_iterators_info(" my: ", itm1, itm2);

		std::cout << std::endl;
		iterator_lib it3 = lib1.rbegin();
		iterator_lib it4 = lib1.rbegin();
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it3 = it4 += 2;
		std::cout << "lib: " << " iterator it1 = it2 += 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		iterator_my itm3 = my1.rbegin();
		iterator_my itm4 = my1.rbegin();
		std::cout << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm3 = itm4 += 2;
		std::cout << " my: " << " iterator it1 = it2 += 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << std::endl;
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it3 = it4 -= 2;
		std::cout << "lib: " << " iterator it1 = it2 -= 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		std::cout << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm3 = itm4 -= 2;
		std::cout << " my: " << " iterator it1 = it2 -= 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << std::endl;
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it4 += 3;
		it3 = it4 - 2;
		std::cout << "lib: " << " iterator it1 = it2 - 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		std::cout << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm4 += 3;
		itm3 = itm4 - 2;
		std::cout << " my: " << " iterator it1 = it2 - 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << GREEN << "it++ lib: " << *(it3++) << std::endl;
		std::cout << RED << "it++  my: " << *(itm3++) << std::endl;
		std::cout << GREEN << "++it lib: " << *(++it3) << std::endl;
		std::cout << RED << "++it  my: " << *(++itm3) << std::endl;
		std::cout << GREEN << "--it lib: " << *(--it3) << std::endl;
		std::cout << RED << "--it  my: " << *(--itm3) << std::endl;
		std::cout << GREEN << "it-- lib: " << *(it3--) << std::endl;
		std::cout << RED << "it--  my: " << *(itm3--) << std::endl;
	}

	void reverse_iterators_test1()
	{
		std::vector<int> lib1((size_t) 1, 2);
		ft::vector<int> my1((size_t) 1, 2);
		lib1.push_back(3);
		lib1.push_back(4);
		lib1.push_back(5);
		my1.push_back(3);
		my1.push_back(4);
		my1.push_back(5);
		std::cout << BLUE << "           REVERSE ITERATORS OPERATORS TEST " << RESET << std::endl;
		typedef std::vector<int>::reverse_iterator iterator_lib;
		typedef ft::vector<int>::reverse_iterator iterator_my;
		iterator_lib it1 = lib1.rbegin();
		iterator_lib it2 = lib1.rbegin();
		std::cout << GREEN;
		print_iterators_info("lib: ", it1, it2);
		it1 = it2 + 2;
		std::cout << "lib: " << " iterator it1 = it2 + 2" << std::endl;
		print_iterators_info("lib: ", it1, it2);

		iterator_my itm1 = my1.rbegin();
		iterator_my itm2 = my1.rbegin();
		std::cout << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm1, itm2);
		itm1 = itm2 + 2;
		std::cout << " my: " << " iterator it1 = it2 + 2" << std::endl;
		print_iterators_info(" my: ", itm1, itm2);

		std::cout << std::endl;
		iterator_lib it3 = lib1.rbegin();
		iterator_lib it4 = lib1.rbegin();
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it3 = it4 += 2;
		std::cout << "lib: " << " iterator it1 = it2 += 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		iterator_my itm3 = my1.rbegin();
		iterator_my itm4 = my1.rbegin();
		std::cout << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm3 = itm4 += 2;
		std::cout << " my: " << " iterator it1 = it2 += 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << std::endl;
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it3 = it4 -= 2;
		std::cout << "lib: " << " iterator it1 = it2 -= 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		std::cout << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm3 = itm4 -= 2;
		std::cout << " my: " << " iterator it1 = it2 -= 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << std::endl;
		std::cout << GREEN;
		print_iterators_info("lib: ", it3, it4);
		it4 += 3;
		it3 = it4 - 2;
		std::cout << "lib: " << " iterator it1 = it2 - 2" << std::endl;
		print_iterators_info("lib: ", it3, it4);

		std::cout << std::endl;
		std::cout << RED;
		print_iterators_info(" my: ", itm3, itm4);
		itm4 += 3;
		itm3 = itm4 - 2;
		std::cout << " my: " << " iterator it1 = it2 - 2" << std::endl;
		print_iterators_info(" my: ", itm3, itm4);

		std::cout << GREEN << "it++ lib: " << *(it3++) << std::endl;
		std::cout << RED << "it++  my: " << *(itm3++) << std::endl;
		std::cout << GREEN << "++it lib: " << *(++it3) << std::endl;
		std::cout << RED << "++it  my: " << *(++itm3) << std::endl;
		std::cout << GREEN << "--it lib: " << *(--it3) << std::endl;
		std::cout << RED << "--it  my: " << *(--itm3) << std::endl;
		std::cout << GREEN << "it-- lib: " << *(it3--) << std::endl;
		std::cout << RED << "it--  my: " << *(itm3--) << std::endl;
	}

	void capacity_tests()
	{
		std::cout << BLUE << "           CAPACITY TEST " << RESET << std::endl;
		std::vector<int> lib1((size_t) 1, 2);
		ft::vector<int> my1((size_t) 1, 2);
		std::cout << GREEN;
		vector_info(lib1, "lib: ", "without push");
		std::cout << RED;
		vector_info(my1, " my: ", "without push");
		lib1.push_back(3);
		my1.push_back(3);
		std::cout << GREEN;
		vector_info(lib1, "lib: ", "push one elem");
		std::cout << RED;
		vector_info(my1, " my: ", "push one elem");
		lib1.push_back(4);
		my1.push_back(4);
		std::cout << GREEN;
		vector_info(lib1, "lib: ", "push another one elem");
		std::cout << RED;
		vector_info(my1, " my: ", "push another one elem");
		lib1.push_back(5);
		my1.push_back(5);
		lib1.push_back(0);
		my1.push_back(0);
		std::cout << GREEN;
		vector_info(lib1, "lib: ", "push two elems");
		std::cout << RED;
		vector_info(my1, " my: ", "push two elems");
		std::cout << std::endl;
		std::cout << GREEN <<"max size lib: " << lib1.max_size() << std::endl;
		std::cout << RED << "max size  my: " << my1.max_size() << std::endl;
		lib1.resize(7);
		my1.resize(7);
		std::cout << GREEN;
		vector_info(lib1, "lib: ", "resize");
		std::cout << RED;
		vector_info(my1, " my: ", "resize");
		lib1.resize(7, 5);
		my1.resize(7, 5);
		std::cout << GREEN;
		vector_info(lib1, "lib: ", "resize");
		std::cout << RED;
		vector_info(my1, " my: ", "resize");
		lib1.resize(8, 5);
		my1.resize(8, 5);
		std::cout << GREEN;
		vector_info(lib1, "lib: ", "resize");
		std::cout << RED;
		vector_info(my1, " my: ", "resize");
		lib1.resize(9, 1);
		my1.resize(9, 1);
		std::cout << GREEN;
		vector_info(lib1, "lib: ", "resize");
		std::cout << RED;
		vector_info(my1, " my: ", "resize");
		lib1.resize(4, 1);
		my1.resize(4, 1);
		std::cout << GREEN;
		vector_info(lib1, "lib: ", "resize");
		std::cout << RED;
		vector_info(my1, " my: ", "resize");
		std::vector<int> lib2;
		ft::vector<int> my2;
		lib2.reserve(2);
		my2.reserve(2);
		std::cout << GREEN;
		vector_info(lib2, "lib: ", "reserve 0 --> 2");
		std::cout << RED;
		vector_info(my2, " my: ", "reserve 0 --> 2");
		lib2.push_back(1);
		my2.push_back(1);
		lib2.push_back(1);
		my2.push_back(1);
		lib2.reserve(5);
		my2.reserve(5);
		std::cout << GREEN;
		vector_info(lib2, "lib: ", "reserve 2 --> 5");
		std::cout << RED;
		vector_info(my2, " my: ", "reserve 2 --> 5");
	}

	void element_access_test()
	{
		std::cout << BLUE << "           ELEMENT ACCESS    " << RESET<< std::endl;
		std::vector<int> lib((size_t) 2, 4);
		ft::vector<int> my((size_t) 2, 4);
		std::cout << GREEN <<"lib[1]: " << lib[1] << ", vector size: " << lib.size() << std::endl;
		std::cout << RED <<" my[1]: " << my[1] << ", vector size: " << my.size() << std::endl;
		//std::cout << std::endl;
		//std::cout << "lib[2]: " << lib[3] << ", vector size: " << lib.size() << std::endl;
		//std::cout << " my[2]: " << my[3] << ", vector size: " << my.size() << std::endl;
		//std::cout << std::endl;
		std::cout << GREEN << "lib.at(1): " << lib.at(1) << ", vector size: " << lib.size() << std::endl;
		std::cout << RED << " my.at(1): " << my.at(1) << ", vector size: " << my.size() << std::endl;
		std::cout << std::endl;
		try
		{
			std::cout << "lib.at(2): " << lib.at(2) << ", vector size: " << lib.size() << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << " my.at(2): " << my.at(2) << ", vector size: " << my.size() << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << GREEN <<"lib front(): " << lib.front() << " ,content: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED << "my front(): " << my.front() << " ,content: ";
		printList(my);
		std::cout << std::endl;
		std::cout << GREEN << "lib back(): " << lib.back() << " ,content: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED << "my back(): " << my.back() << " ,content: ";
		printList(my);
		std::cout << std::endl;
		lib.push_back(8);
		my.push_back(8);
		std::cout << GREEN <<  "push in the end, now lib back(): " << lib.back() << " ,content: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED << "push in the end, now  my back(): " << my.back() << " ,content: ";
		printList(my);
	}

	void modifiers_test()
	{
		std::cout << BLUE << "           MODIFIERS TEST    " << RESET << std::endl;
		std::vector<int> vLib((size_t) 2, 3);
		ft::vector<int> vMy((size_t) 2, 3);

		std::vector<int> vLib1;
		ft::vector<int> vMy1;
		vLib1.push_back(2);
		vLib1.push_back(5);
		vLib1.push_back(7);
		vMy1.push_back(2);
		vMy1.push_back(5);
		vMy1.push_back(7);
		vLib.assign(vLib1.begin(), vLib1.end());
		vMy.assign(vMy1.begin(), vMy1.end());
		std::cout << GREEN;
		vector_info(vLib, "lib", "assign test range");
		std::cout << RED;
		vector_info(vMy, " my", "assign test range");
		vLib.assign(++vLib1.begin(), vLib1.end());
		vMy.assign(++vMy1.begin(), vMy1.end());
		std::cout << GREEN;
		vector_info(vLib, "lib", "assign test range");
		std::cout << RED;
		vector_info(vMy, " my", "assign test range");
		vLib.assign(++vLib1.begin(), --vLib1.end());
		vMy.assign(++vMy1.begin(), --vMy1.end());
		std::cout << GREEN;
		vector_info(vLib, "lib", "assign test range");
		std::cout << RED;
		vector_info(vMy, " my", "assign test range");
		vLib.push_back(100);
		vLib.push_back(101);
		vLib.push_back(102);
		vMy.push_back(100);
		vMy.push_back(101);
		vMy.push_back(102);

		vLib1.push_back(100);
		vLib1.push_back(101);
		vLib1.push_back(102);
		vMy1.push_back(100);
		vMy1.push_back(101);
		vMy1.push_back(102);
		vLib1.push_back(100);
		vLib1.push_back(101);
		vLib1.push_back(102);
		vMy1.push_back(100);
		vMy1.push_back(101);
		vMy1.push_back(102);
		std::cout << GREEN;
		vector_info(vLib, "lib", "push...");
		std::cout << RED;
		vector_info(vMy, " my", "push...");
		vLib.assign(vLib1.begin(), vLib1.end());
		vMy.assign(vMy1.begin(), vMy1.end());
		std::cout << GREEN;
		vector_info(vLib, "lib", "assign test range");
		std::cout << RED;
		vector_info(vMy, " my", "assign test range");
		vLib.assign(vLib1.begin(), --vLib1.end());
		vMy.assign(vMy1.begin(), --vMy1.end());
		std::cout << GREEN;
		vector_info(vLib, "lib", "assign test range");
		std::cout << RED;
		vector_info(vMy, " my", "assign test range");

		vLib.assign((size_t) 3, 1);
		vMy.assign((size_t) 3, 1);
		std::cout << GREEN;
		vector_info(vLib, "lib", "assign test val");
		std::cout << RED;
		vector_info(vMy, " my", "assign test val");
		vLib.assign((size_t) 10, 2);
		vMy.assign((size_t) 10, 2);
		std::cout << GREEN;
		vector_info(vLib, "lib", "assign test val");
		std::cout << RED;
		vector_info(vMy, " my", "assign test val");
		vLib.clear();
		vMy.clear();

		std::cout << GREEN;
		vector_info(vLib, "lib", "clear test");
		std::cout << RED;
		vector_info(vMy, " my", "clear test");

		push_pop_tests();

	}

	void push_pop_tests()
	{
		std::vector<int> vlib(2);
		ft::vector<int> vMy(2);
		vlib.push_back(1);
		vMy.push_back(1);
		std::cout << GREEN;
		vector_info(vlib, "lib", "push test");
		std::cout << RED;
		vector_info(vMy, " my", "push test");
		vlib.push_back(3);
		vMy.push_back(3);
		std::cout << GREEN;
		vector_info(vlib, "lib", "push test");
		std::cout << RED;
		vector_info(vMy, " my", "push test");
		vlib.push_back(20);
		vMy.push_back(20);
		std::cout << GREEN;
		vector_info(vlib, "lib", "push test");
		std::cout << RED;
		vector_info(vMy, " my", "push test");
		vlib.pop_back();
		vMy.pop_back();
		std::cout << GREEN;
		vector_info(vlib, "lib", "pop test");
		std::cout << RED;
		vector_info(vMy, " my", "pop test");
		vlib.pop_back();
		vMy.pop_back();
		std::cout << GREEN;
		vector_info(vlib, "lib", "pop test");
		std::cout << RED;
		vector_info(vMy, " my", "pop test");

		std::vector<int> vLib2(2);
		ft::vector<int> vMy2(2);
		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib2.insert(vLib2.end(), 33) << std::endl;
		vector_info(vLib2, "", "insert one value in end");
		std::cout << RED << "INSERT MY: ret value: " << *vMy2.insert(vMy2.end(), 33) << std::endl;
		vector_info(vMy2, "", "insert one value in end");
		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib2.insert(vLib2.end(), 1) << std::endl;
		vector_info(vLib2, "", "insert one value in end");
		std::cout << RED << "INSERT MY: ret value: " << *vMy2.insert(vMy2.end(), 1) << std::endl;
		vector_info(vMy2, "", "insert one value in end");
		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib2.insert(vLib2.end(), 45) << std::endl;
		vector_info(vLib2, "", "insert one value in end");
		std::cout << RED << "INSERT MY: ret value: " << *vMy2.insert(vMy2.end(), 45) << std::endl;
		vector_info(vMy2, "", "insert one value in end");
		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib2.insert(vLib2.end(), 45) << std::endl;
		vector_info(vLib2, "", "insert one value in end");
		std::cout << RED << "INSERT MY: ret value: " << *vMy2.insert(vMy2.end(), 45) << std::endl;
		vector_info(vMy2, "", "insert one value in end");

		std::vector<int> vLib3;
		ft::vector<int> vMy3;

		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib3.insert(vLib3.begin(), 33) << std::endl;
		vector_info(vLib3, "", "insert one value in begin");
		std::cout << RED << "INSERT MY: ret value: " << *vMy3.insert(vMy3.begin(), 33) << std::endl;
		vector_info(vMy3, "", "insert one value in begin");
		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib3.insert(vLib3.begin(), 2) << std::endl;
		vector_info(vLib3, "", "insert one value in begin");
		std::cout << RED << "INSERT MY: ret value: " << *vMy3.insert(vMy3.begin(), 2) << std::endl;
		vector_info(vMy3, "", "insert one value in begin");
		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib3.insert(vLib3.begin(), 10) << std::endl;
		vector_info(vLib3, "", "insert one value in begin");
		std::cout << RED << "INSERT MY: ret value: " << *vMy3.insert(vMy3.begin(), 10) << std::endl;
		vector_info(vMy3, "", "insert one value in begin");

		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib3.insert(vLib3.begin() + 2, 12) << std::endl;
		vector_info(vLib3, "", "insert one value in middle");
		std::cout << RED << "INSERT MY: ret value: " << *vMy3.insert(vMy3.begin() + 2, 12) << std::endl;
		vector_info(vMy3, "", "insert one value in middle");
		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib3.insert(vLib3.begin() + 1, 6) << std::endl;
		vector_info(vLib3, "", "insert one value in middle");
		std::cout << RED << "INSERT MY: ret value: " << *vMy3.insert(vMy3.begin() + 1, 6) << std::endl;
		vector_info(vMy3, "", "insert one value in middle");
		std::cout << GREEN << "INSERT LIB: ret value: " << *vLib3.insert(vLib3.end() - 3, 7) << std::endl;
		vector_info(vLib3, "", "insert one value in middle");
		std::cout << RED << "INSERT MY: ret value: " << *vMy3.insert(vMy3.end() - 3, 7) << std::endl;
		vector_info(vMy3, "", "insert one value in middle");

		std::vector<int> vLib4;
		ft::vector<int> vMy4;

		std::cout << GREEN << "INSERT LIB" << std::endl;
		vLib4.insert(vLib4.end(), (size_t) 4, 11);
		vector_info(vLib4, "", "insert 4 values in end");
		vMy4.insert(vMy4.end(), (size_t) 4, 11);
		std::cout << RED << "INSERT MY" << std::endl;
		vector_info(vMy4, "", "insert 4 values in end");
		std::cout << GREEN << "INSERT LIB" << std::endl;
		vLib4.insert(vLib4.end(), (size_t) 6, 8);
		vector_info(vLib4, "", "insert 6 values in end");
		std::cout << RED << "INSERT MY" << std::endl;
		vMy4.insert(vMy4.end(), (size_t) 6, 8);
		vector_info(vMy4, "", "insert 6 values in end");

		std::cout << GREEN << "INSERT LIB" << std::endl;
		vLib4.insert(vLib4.begin(), (size_t) 2, 11);
		vector_info(vLib4, "", "insert 2 values in begin");
		vMy4.insert(vMy4.begin(), (size_t) 2, 11);
		std::cout << RED << "INSERT MY" << std::endl;
		vector_info(vMy4, "", "insert 2 values in begin");
		std::cout << GREEN << "INSERT LIB" << std::endl;
		vLib4.insert(vLib4.begin(), (size_t) 3, 8);
		vector_info(vLib4, "", "insert 3 values in begin");
		std::cout << RED << "INSERT MY" << std::endl;
		vMy4.insert(vMy4.begin(), (size_t) 3, 8);
		vector_info(vMy4, "", "insert 3 values in begin");

		std::cout << GREEN << "INSERT LIB" << std::endl;
		vLib4.insert(++vLib4.begin(), (size_t) 1, 45);
		vector_info(vLib4, "", "insert 1 values in random place");
		vMy4.insert(++vMy4.begin(), (size_t) 1, 45);
		std::cout << RED << "INSERT MY" << std::endl;
		vector_info(vMy4, "", "insert 1 values in random place");

		std::cout << GREEN << "INSERT LIB" << std::endl;
		vLib4.insert(vLib4.begin() + 4, (size_t) 14, 45);
		vector_info(vLib4, "", "insert 14 values in random place");
		vMy4.insert(vMy4.begin() + 4, (size_t) 14, 45);
		std::cout << RED << "INSERT MY" << std::endl;
		vector_info(vMy4, "", "insert 14 values in random place");
		std::cout << GREEN << "INSERT LIB" << std::endl;
		vLib4.insert(vLib4.begin() + 5, (size_t) 1, 45);
		vector_info(vLib4, "", "insert 1 values in random place");
		vMy4.insert(vMy4.begin() + 5, (size_t) 1, 45);
		std::cout << RED << "INSERT MY" << std::endl;
		vector_info(vMy4, "", "insert 1 values in random place");

		std::vector<int> lib;
		lib.push_back(1);
		lib.push_back(2);
		lib.push_back(3);
		ft::vector<int> my;
		my.push_back(1);
		my.push_back(2);
		my.push_back(3);
		std::cout << GREEN << "INSERT LIB" << std::endl;
		lib.insert(lib.begin() + 2, lib.begin(), lib.end());
		vector_info(lib, "", "insert range in middle");
		std::cout << RED << "INSERT MY" << std::endl;
		my.insert(my.begin() + 2, my.begin(), my.end());
		vector_info(my, "", "insert range in middle");

		std::cout << GREEN << "INSERT LIB" << std::endl;
		lib.insert(lib.begin(), lib.begin(), --lib.end());
		vector_info(lib, "", "insert range in begin");
		std::cout << RED << "INSERT MY" << std::endl;
		my.insert(my.begin(), my.begin(), --my.end());
		vector_info(my, "", "insert range in begin");

		std::cout << GREEN << "INSERT LIB" << std::endl;
		lib.insert(lib.end(), ++lib.begin(), lib.end());
		vector_info(lib, "", "insert range in begin");
		std::cout << RED << "INSERT MY" << std::endl;
		my.insert(my.end(), ++my.begin(), my.end());
		vector_info(my, "", "insert range in begin");

	}

	void erase_test()
	{
		std::vector<int> lib;
		lib.push_back(1);
		lib.push_back(2);
		lib.push_back(3);
		lib.push_back(7);
		lib.push_back(11);
		lib.push_back(5);
		ft::vector<int> my;
		my.push_back(1);
		my.push_back(2);
		my.push_back(3);
		my.push_back(7);
		my.push_back(11);
		my.push_back(5);
		std::cout << GREEN << "ERASE LIB, ret value: " << *lib.erase(lib.begin()) << std::endl;
		vector_info(lib, "lib", "erase");
		std::cout << RED << "ERASE MY, ret value: " << *my.erase(my.begin()) << std::endl;
		vector_info(my, " my", "erase");

		std::cout << GREEN << "ERASE LIB, ret value: " << *lib.erase(--lib.end()) << std::endl;
		vector_info(lib, "lib", "erase");
		std::cout << RED <<"ERASE MY, ret value: " << *my.erase(--my.end()) << std::endl;
		vector_info(my, " my", "erase");

		std::cout << GREEN <<"ERASE LIB, ret value: " << *lib.erase(lib.end() - 2) << std::endl;
		vector_info(lib, "lib", "erase");
		std::cout << RED << "ERASE MY, ret value: " << *my.erase(my.end() - 2) << std::endl;
		vector_info(my, " my", "erase");

		lib.push_back(11);
		lib.push_back(5);
		my.push_back(11);
		my.push_back(5);
		std::cout << GREEN;
		vector_info(lib, "lib", "push lib...");
		std::cout << RED;
		vector_info(my, "my", "push lib...");

		std::cout << GREEN << "ERASE LIB, ret value: " << *lib.erase(++lib.begin(), lib.end() - 2) << std::endl;
		vector_info(lib, "lib", "erase");
		std::cout << RED << "ERASE MY, ret value: " << *my.erase(++my.begin(), my.end() - 2) << std::endl;
		vector_info(my, " my", "erase");
	}

	void swap_test()
	{
		ft::vector<int> my;
		my.push_back(1);
		my.push_back(2);
		my.push_back(3);
		my.push_back(7);
		my.push_back(11);
		my.push_back(5);

		ft::vector<int> my2;
		my2.push_back(70);
		my2.push_back(110);
		my2.push_back(50);
		std::cout << RED << "Class function swap" << std::endl;
		vector_info(my, " my1", "before swap");
		std::cout << RED;
		vector_info(my2, " my2", "before swap");
		my.swap(my2);
		std::cout << RED;
		vector_info(my, " my1", "after swap");
		std::cout << RED;
		vector_info(my2, " my2", "after swap");

		std::cout << RED;
		std::cout << "Non member function swap" << std::endl;
		swap(my, my2);
		std::cout << RED;
		vector_info(my, " my1", "after swap");
		std::cout << RED;
		vector_info(my2, " my2", "after swap");
	}

	void operators()
	{
		std::cout <<  BLUE << "                  OPERATORS TEST" << RESET << std::endl;
		std::vector<int> a1;
		std::vector<int> a2;
		std::vector<int> a3;
		ft::vector<int> b1;
		ft::vector<int> b2;
		ft::vector<int> b3;
		a1.push_back(10);
		a1.push_back(20);
		a1.push_back(30);
		a2.push_back(10);
		a2.push_back(20);
		a2.push_back(30);
		a3.push_back(30);
		a3.push_back(20);
		a3.push_back(10);

		b1.push_back(10);
		b1.push_back(20);
		b1.push_back(30);
		b2.push_back(10);
		b2.push_back(20);
		b2.push_back(30);
		b3.push_back(30);
		b3.push_back(20);
		b3.push_back(10);
		std::cout << "OPERATORS" << std::endl;
		std::cout << "a: ";
		printList(a1);
		std::cout << "b: ";
		printList(a2);
		std::cout << "c: ";
		printList(a3);
		std::cout << GREEN << "Lib operators: " << std::endl;
		operators_test(a1, a2, a3);
		std::cout << RED << "My operators: " << std::endl;
		operators_test(b1, b2, b3);

		a1.push_back(2);
		a3.pop_back();
		b1.push_back(2);
		b3.pop_back();

		std::cout << "a: ";
		printList(a1);
		std::cout << "b: ";
		printList(a2);
		std::cout << "c: ";
		printList(a3);
		std::cout << GREEN << "Lib operators: " << std::endl;

		operators_test(a1, a2, a3);
		std::cout << RED << "My operators: " << std::endl;
		operators_test(b1, b2, b3);

		a1.insert(++a1.begin(), 20);
		b1.insert(++b1.begin(), 20);

		std::cout << "a: ";
		printList(a1);
		std::cout << "b: ";
		printList(a2);
		std::cout << "c: ";
		printList(a3);
		std::cout << GREEN << "Lib operators: " << std::endl;

		operators_test(a1, a2, a3);
		std::cout << RED << "My operators: " << std::endl;
		operators_test(b1, b2, b3);

	}
}
	int vector_main()
	{
		vector_test::constructors_test();
		vector_test::iterators_test1();
		vector_test::iterators_test2();
		vector_test::capacity_tests();
		vector_test::element_access_test();
		vector_test::modifiers_test();
		vector_test::erase_test();
		vector_test::swap_test();
		vector_test::operators();
		return (1);
	}

