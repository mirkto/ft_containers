//
// Created by 1 on 27.11.2020.
//

#include <map>
#include <iostream>
#include "../Includes/map.hpp"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

namespace map_test
{
	void different_tests();

	void find_tests();

	template<typename T>
	void printMap(T &container)
	{
		typename T::iterator i = container.begin();
		typename T::iterator ie = container.end();
		while (i != ie)
		{
			std::cout << i->first << ":" << i->second << " ";
			i++;
		}
		std::cout << ",size: " << container.size();
		std::cout << RESET << std::endl;
	}

	template<typename T>
	void printReverseMap(T &container)
	{
		typename T::reverse_iterator i = container.rbegin();
		typename T::reverse_iterator ie = container.rend();
		while (i != ie)
		{
			std::cout << i->first << ":" << i->second << " ";
			i++;
		}
		std::cout << ",size: " << container.size();
		std::cout << std::endl;
	}

	void constructors_test()
	{
		std::cout << BLUE << "--------------CONSTRUCTORS TEST--------------------" << RESET << std::endl;
		std::map<int, int> lib1;
		ft::map<int, int> my1;
		std::cout << GREEN << "lib default constructor content: ";
		printMap(lib1);
		std::cout << RED << " my default constructor content: ";
		printMap(my1);

		lib1[9] = 3;
		lib1[10] = 4;
		lib1[8] = 100;
		lib1[9] = 50;
		lib1[4] = 30;
		lib1[12] = 3;

		my1[9] = 3;
		my1[10] = 4;
		my1[8] = 100;
		my1[9] = 50;
		my1[4] = 30;
		my1[12] = 3;

		std::cout << std::endl;
		std::map<int, int> lib2(lib1.begin(), lib1.end());
		ft::map<int, int> my2(my1.begin(), my1.end());
		std::cout << GREEN <<  "lib constructor range content: ";
		printMap(lib2);
		std::cout << RED << " my constructor range content: ";
		printMap(my2);

		std::map<int, int> lib3(++lib1.begin(), --lib1.end());
		ft::map<int, int> my3(++my1.begin(), --my1.end());
		std::cout << GREEN <<  "lib constructor range content: ";
		printMap(lib3);
		std::cout << RED << " my constructor range content: ";
		printMap(my3);

		std::cout << std::endl;
		std::map<int, int> lib4(lib3);
		ft::map<int, int> my4(my3);
		std::cout << GREEN <<  "lib constructor copy content: ";
		printMap(lib4);
		std::cout << RED << " my constructor copy content: ";
		printMap(my4);

		std::cout << std::endl;
		lib4 = lib1;
		my4 = my1;
		std::cout << GREEN <<  "lib assignation content: ";
		printMap(lib4);
		std::cout << RED <<" my assignation content: ";
		printMap(my4);

		std::map<int, int> lib5;
		ft::map<int, int> my5;
		lib4 = lib5;
		my4 = my5;
		std::cout << GREEN <<  "lib assignation content: ";
		printMap(lib4);
		std::cout << RED << " my assignation content: ";
		printMap(my4);
	}

	void iterators_test()
	{
		std::cout << BLUE << "--------------ITERATORS TEST--------------------" << RESET << std::endl;
		std::map<int, int> lib1;
		ft::map<int, int> my1;
		lib1[100] = 3;
		lib1[60] = 2;
		lib1[65] = 1;
		lib1[68] = 3;
		lib1[63] = 5;
		lib1[64] = 2;
		lib1[62] = 2;
		lib1[67] = 2;
		lib1[66] = 2;
		lib1[80] = 2;
		lib1[90] = 2;
		lib1[75] = 2;
		lib1[88] = 2;
		lib1[95] = 2;
		lib1[40] = 2;
		lib1[50] = 2;
		lib1[30] = 2;
		lib1[45] = 2;
		lib1[55] = 2;
		lib1[160] = 8;
		lib1[140] = 8;
		lib1[200] = 8;
		lib1[120] = 8;
		lib1[150] = 9;
		lib1[150] = 10;
		lib1[190] = 11;
		lib1[210] = 8;
		std::cout << GREEN << "begin --> end lib (standart comparator):" << std::endl;
		printMap(lib1);

		my1[100] = 3;
		my1[60] = 2;
		my1[65] = 1;
		my1[68] = 3;
		my1[63] = 5;
		my1[64] = 2;
		my1[62] = 2;
		my1[67] = 2;
		my1[66] = 2;
		my1[80] = 2;
		my1[90] = 2;
		my1[75] = 2;
		my1[88] = 2;
		my1[95] = 2;
		my1[40] = 2;
		my1[50] = 2;
		my1[30] = 2;
		my1[45] = 2;
		my1[55] = 2;
		my1[160] = 8;
		my1[140] = 8;
		my1[200] = 8;
		my1[120] = 8;
		my1[150] = 9;
		my1[150] = 10;
		my1[190] = 11;
		my1[210] = 8;
		std::cout << RED << "begin --> end my (standart comparator):" << std::endl;
		printMap(my1);

		std::cout << std::endl;

		std::map<int, int, std::greater<int> > lib2;
		ft::map<int, int, std::greater<int> > my2;
		lib2[100] = 3;
		lib2[60] = 2;
		lib2[65] = 1;
		lib2[68] = 3;
		lib2[63] = 5;
		lib2[64] = 2;
		lib2[62] = 2;
		lib2[67] = 2;
		lib2[66] = 2;
		lib2[80] = 2;
		lib2[90] = 2;
		lib2[75] = 2;
		lib2[88] = 2;
		lib2[95] = 2;
		lib2[40] = 2;
		lib2[50] = 2;
		lib2[30] = 2;
		lib2[45] = 2;
		lib2[55] = 2;
		lib2[160] = 8;
		lib2[140] = 8;
		lib2[200] = 8;
		lib2[120] = 8;
		lib2[150] = 9;
		lib2[150] = 10;
		lib2[190] = 11;
		lib2[210] = 8;

		my2[100] = 3;
		my2[60] = 2;
		my2[65] = 1;
		my2[68] = 3;
		my2[63] = 5;
		my2[64] = 2;
		my2[62] = 2;
		my2[67] = 2;
		my2[66] = 2;
		my2[80] = 2;
		my2[90] = 2;
		my2[75] = 2;
		my2[88] = 2;
		my2[95] = 2;
		my2[40] = 2;
		my2[50] = 2;
		my2[30] = 2;
		my2[45] = 2;
		my2[55] = 2;
		my2[160] = 8;
		my2[140] = 8;
		my2[200] = 8;
		my2[120] = 8;
		my2[150] = 9;
		my2[150] = 10;
		my2[190] = 11;
		my2[210] = 8;
		std::cout << GREEN <<"begin --> end lib (comparator std::greater):" << std::endl;
		printMap(lib2);
		std::cout << RED <<"begin --> end my (comparator std::greater):" << std::endl;
		printMap(my2);

		std::cout << std::endl;

		std::cout << GREEN << "rbegin --> rend lib standart comparator:" << std::endl;
		printReverseMap(lib1);
		std::cout << RED << "rbegin --> rend  my standart comparator:" << std::endl;
		printReverseMap(my1);

		std::cout << std::endl;

		std::cout << GREEN << "rbegin --> rend lib (comparator std::greater):" << std::endl;
		printReverseMap(lib2);
		std::cout << RED << "rbegin --> rend  my (comparator std::greater):" << std::endl;
		printReverseMap(my2);

		std::cout << std::endl;
	}

	void capacity_test()
	{
		std::cout << BLUE << "--------------CAPACITY TEST--------------------" << RESET << std::endl;
		std::map<int, int> lib1;
		ft::map<int, int> my1;

		std::cout << GREEN << "lib content: ";
		printMap(lib1);
		std::cout << "Lib container is " << (lib1.empty() ? "empty" : "not empty") << std::endl;
		std::cout << " my content: ";
		printMap(my1);
		std::cout << RED << " My container is " << (my1.empty() ? "empty" : "not empty") << std::endl;
		lib1[100] = 1;
		lib1[10] = 2;
		lib1[100] = 3;
		my1[100] = 1;
		my1[10] = 2;
		my1[100] = 3;
		std::cout << std::endl;
		std::cout << GREEN << "lib content: ";
		printMap(lib1);
		std::cout << "Lib container is " << (lib1.empty() ? "empty" : "not empty") << std::endl;
		std::cout << " my content: ";
		printMap(my1);
		std::cout << RED << " My container is " << (my1.empty() ? "empty" : "not empty") << std::endl;

		std::cout << std::endl;
		std::cout << GREEN << "Lib max size: " << lib1.max_size() << std::endl;
		std::cout << RED << " My max size: " << my1.max_size() << std::endl;
	}

	void access_tests()
	{
		std::cout << BLUE << "--------------ACCESS TEST--------------------" << RESET << std::endl;
		std::map<int, int> lib1;
		ft::map<int, int> my1;
		lib1[6] = 100;
		my1[6] = 100;

		std::cout << GREEN << "lib[6] = 100, content: ";
		printMap(lib1);
		std::cout << RED << "lib[6] = 100, content: ";
		printMap(my1);
		std::cout << std::endl;
		lib1[10] = 10;
		my1[10] = 10;
		std::cout << GREEN << "lib[10] = 10, content: ";
		printMap(lib1);
		std::cout << RED << "lib[10] = 10, content: ";
		printMap(my1);
		std::cout << std::endl;
		lib1[6] = 1;
		my1[6] = 1;
		std::cout << GREEN <<  "lib[6] = 1, content: ";
		printMap(lib1);
		std::cout << RED <<  "lib[6] = 1, content: ";
		printMap(my1);
		std::cout << std::endl;

		lib1[6] = 1;
		my1[6] = 1;
		std::cout << GREEN <<  "lib[6] = 1, content: ";
		printMap(lib1);
		std::cout << RED << "lib[6] = 1, content: ";
		printMap(my1);
		std::cout << std::endl;
	}

	void insert_test()
	{
		std::cout << BLUE << "--------------ACCESS TEST--------------------" << RESET << std::endl;
		std::cout << "insert single element: " << std::endl;
		std::map<int, int> lib1;
		ft::map<int, int> my1;
		std::pair<std::map<int, int>::iterator, bool> ret1;
		std::pair<ft::map<int, int>::iterator, bool> ret2;
		ret1 = lib1.insert(std::pair<int, int>(28, 6));
		ret2 = my1.insert(std::pair<int, int>(28, 6));
		std::cout << GREEN << "insert 28:6 in lib, ret value: ";
		std::cout << "Iter: " << ret1.first->first << ":" << ret1.first->second << ", bool: " << ret1.second
				  << ",content: " << std::endl;
		printMap(lib1);
		std::cout << RED << "insert 28:6 in my, ret value: ";
		std::cout << "Iter: " << ret2.first->first << ":" << ret2.first->second << ", bool: " << ret2.second
				  << ",content: " << std::endl;
		printMap(my1);
		std::cout << std::endl;

		ret1 = lib1.insert(std::pair<int, int>(33, 4));
		ret2 = my1.insert(std::pair<int, int>(33, 4));
		std::cout << GREEN << "insert 33:4 in lib, ret value: ";
		std::cout << "Iter: " << ret1.first->first << ":" << ret1.first->second << ", bool: " << ret1.second
				  << ",content: " << std::endl;
		printMap(lib1);
		std::cout << RED << "insert 33:4 in  my, ret value: ";
		std::cout << "Iter: " << ret2.first->first << ":" << ret2.first->second << ", bool: " << ret2.second
				  << ",content: " << std::endl;
		printMap(my1);
		std::cout << std::endl;

		ret1 = lib1.insert(std::pair<int, int>(26, 4));
		ret2 = my1.insert(std::pair<int, int>(26, 4));
		std::cout << GREEN << "insert 26:4 in lib, ret value: ";
		std::cout << "Iter: " << ret1.first->first << ":" << ret1.first->second << ", bool: " << ret1.second
				  << ",content: " << std::endl;
		printMap(lib1);
		std::cout << RED << "insert 26:4 in  my, ret value: ";
		std::cout << "Iter: " << ret2.first->first << ":" << ret2.first->second << ", bool: " << ret2.second
				  << ",content: " << std::endl;
		printMap(my1);
		std::cout << std::endl;

		ret1 = lib1.insert(std::pair<int, int>(28, 100));
		ret2 = my1.insert(std::pair<int, int>(28, 100));
		std::cout << GREEN << "insert 28:100 in lib, ret value: ";
		std::cout << "Iter: " << ret1.first->first << ":" << ret1.first->second << ", bool: " << ret1.second
				  << ",content: " << std::endl;
		printMap(lib1);
		std::cout << RED << "insert 28:100 in  my, ret value: ";
		std::cout << "Iter: " << ret2.first->first << ":" << ret2.first->second << ", bool: " << ret2.second
				  << ",content: " << std::endl;
		printMap(my1);
		std::cout << std::endl;

		std::cout << "insert element at position: " << std::endl;
		std::map<int, int>::iterator ret3;
		ft::map<int, int>::iterator ret4;
		ret3 = lib1.insert(lib1.begin(), std::pair<int, int>(38, 4));
		ret4 = my1.insert(my1.begin(), std::pair<int, int>(38, 4));
		std::cout << GREEN << "insert 38:4 in lib, ret value: ";
		std::cout << "Iter: " << ret3->first << ":" << ret3->second << ",content: " << std::endl;
		printMap(lib1);
		std::cout << RED << "insert 38:4 in  my, ret value: ";
		std::cout << "Iter: " << ret4->first << ":" << ret4->second << ",content: " << std::endl;
		printMap(my1);
		std::cout << std::endl;

		ret3 = lib1.insert(lib1.begin(), std::pair<int, int>(-5, 8));
		ret4 = my1.insert(my1.begin(), std::pair<int, int>(-5, 8));
		std::cout << GREEN <<  "insert -5:8 in lib, ret value: ";
		std::cout  << "Iter: " << ret3->first << ":" << ret3->second << ",content: " << std::endl;
		printMap(lib1);
		std::cout << RED << "insert -5:8 in  my, ret value: ";
		std::cout << "Iter: " << ret4->first << ":" << ret4->second << ",content: " << std::endl;
		printMap(my1);
		std::cout << std::endl;

		ret3 = lib1.insert(lib1.begin(), std::pair<int, int>(33, 100));
		ret4 = my1.insert(my1.begin(), std::pair<int, int>(33, 100));
		std::cout << GREEN <<  "insert 33:100 in lib, ret value: ";
		std::cout << "Iter: " << ret3->first << ":" << ret3->second << ",content: " << std::endl;
		printMap(lib1);
		std::cout << RED << "insert 33:100 in  my, ret value: ";
		std::cout << "Iter: " << ret4->first << ":" << ret4->second << ",content: " << std::endl;
		printMap(my1);
		std::cout << std::endl;

		std::cout << "insert range of elements: " << std::endl;
		std::map<int, int> lib2;
		ft::map<int, int> my2;

		lib2[100] = 1;
		lib2[10] = 2;
		lib2[100] = 3;
		lib2[6] = 4;
		my2[100] = 1;
		my2[10] = 2;
		my2[100] = 3;
		my2[6] = 4;
		std::cout << GREEN << "insert range lib, content: ";
		lib1.insert(lib2.begin(), lib2.end());
		printMap(lib1);
		std::cout << RED << "insert range  my, content: ";
		my1.insert(my2.begin(), my2.end());
		printMap(my1);
//
		std::map<int, int> lib3;
		ft::map<int, int> my3;
		lib3[1] = 0;
		lib3[100] = 1000;
		lib3[10] = 1;

		my3[1] = 0;
		my3[100] = 1000;
		my3[10] = 1;

		std::cout << GREEN << "insert range lib, content: ";
		lib1.insert(lib3.begin(), lib3.end());
		printMap(lib1);
		std::cout << RED << "insert range  my, content: ";
		my1.insert(my3.begin(), my3.end());
		printMap(my1);

	}

	void equal_range()
	{
		std::map<char, int> mymap;

		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;

		std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << RED << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << RESET << '\n';
	}

	void count_test()
	{
		std::map<char, int> mymap;
		char c;

		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;

		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c) > 0)
				std::cout << " is an element of mymap.\n";
			else
				std::cout << " is not an element of mymap.\n";
		}
	}

	void iterator_test()
	{
		ft::map<int, int> lib;
		lib[20] = 3;
		lib[10] = 2;
		lib[30] = 4;
		ft::map<int, int>::iterator it = lib.begin();
		ft::map<int, int>::iterator ite = lib.end();
		while (it != ite)
		{
			std::cout << it->first << ":" << it->second << std::endl;
			it++;
		}

	}

	template<typename T>
	void find_test(T &container)
	{
		container['a'] = 50;
		container['b'] = 100;
		container['c'] = 150;
		container['d'] = 200;

		typename T::iterator it = container.find('b');
		typename T::iterator ite = container.find('x');
		if (ite == container.end())
			std::cout << "x is not the key of this container" << std::endl;
		if (it != container.end())
			container.erase(it);

		// print content:
		std::cout << "elements in container:" << '\n';
		std::cout << "a => " << container.find('a')->second << '\n';
		std::cout << "c => " << container.find('c')->second << '\n';
		std::cout << "d => " << container.find('d')->second << '\n';
		std::cout << std::endl;

	}

	void erase_test()
	{
		std::cout << BLUE << "--------------ERASE TEST--------------------" << RESET << std::endl;
		std::map<int, int> lib1;
		ft::map<int, int> my1;
		lib1[100] = 3;
		lib1[60] = 2;
		lib1[65] = 1;
		lib1[68] = 3;
		lib1[63] = 5;
		lib1[64] = 2;
		lib1[62] = 2;
		lib1[67] = 2;
		lib1[66] = 2;
		lib1[80] = 2;
		lib1[90] = 2;
		lib1[75] = 2;
		lib1[88] = 2;
		lib1[95] = 2;
		lib1[40] = 2;
		lib1[50] = 2;
		lib1[30] = 2;
		lib1[45] = 2;
		lib1[55] = 2;
		lib1[160] = 8;
		lib1[140] = 8;
		lib1[200] = 8;
		lib1[120] = 8;
		lib1[150] = 9;
		lib1[150] = 10;
		lib1[190] = 11;
		lib1[210] = 8;
		std::cout << GREEN << "lib before erase:" << std::endl;
		printMap(lib1);

		my1[100] = 3;
		my1[60] = 2;
		my1[65] = 1;
		my1[68] = 3;
		my1[63] = 5;
		my1[64] = 2;
		my1[62] = 2;
		my1[67] = 2;
		my1[66] = 2;
		my1[80] = 2;
		my1[90] = 2;
		my1[75] = 2;
		my1[88] = 2;
		my1[95] = 2;
		my1[40] = 2;
		my1[50] = 2;
		my1[30] = 2;
		my1[45] = 2;
		my1[55] = 2;
		my1[160] = 8;
		my1[140] = 8;
		my1[200] = 8;
		my1[120] = 8;
		my1[150] = 9;
		my1[150] = 10;
		my1[190] = 11;
		my1[210] = 8;
		std::cout << RED <<  " my before erase:" << std::endl;
		printMap(my1);
		std::map<int, int>::iterator itl = lib1.begin();
		itl++;
		itl++;
		ft::map<int, int>::iterator itlm = my1.begin();
		itlm++;
		itlm++;
		std::cout << std::endl;
		std::cout << GREEN << "lib erase iterator: ";
		lib1.erase(itl);
		printMap(lib1);
		std::cout << RED << " my erase iterator: ";
		my1.erase(itlm);
		printMap(my1);

		std::cout << std::endl;
		itl = lib1.begin();
		itlm = my1.begin();
		itl++;
		itl++;
		itl++;
		itl++;
		itlm++;
		itlm++;
		itlm++;
		itlm++;
		std::cout << GREEN << "lib erase iterator: ";
		lib1.erase(itl);
		printMap(lib1);
		std::cout << RED << " my erase iterator: ";
		my1.erase(itlm);
		printMap(my1);

		std::cout << std::endl;
		size_t ret1 = lib1.erase(63);
		std::cout << GREEN << "lib erase from value, ret: " << ret1 << ",content: ";
		printMap(lib1);
		size_t ret2 = my1.erase(63);
		std::cout << RED << " my erase from value, ret: " << ret2 << ",content: ";
		printMap(my1);

		std::cout << std::endl;
		ret1 = lib1.erase(90);
		std::cout << GREEN << "lib erase from value, ret: " << ret1 << ",content: ";
		printMap(lib1);
		ret2 = my1.erase(90);
		std::cout << RED << " my erase from value, ret: " << ret2 << ",content: ";
		printMap(my1);

		std::cout << std::endl;
		ret1 = lib1.erase(10000);
		std::cout << GREEN << "lib erase from value, ret: " << ret1 << ",content: ";
		printMap(lib1);
		ret2 = my1.erase(10000);
		std::cout << RED << " my erase from value, ret: " << ret2 << ",content: ";
		printMap(my1);

		std::cout << std::endl;
		ret1 = lib1.erase(29);
		std::cout << GREEN << "lib erase from value, ret: " << ret1 << ",content: ";
		printMap(lib1);
		ret2 = my1.erase(29);
		std::cout << RED << " my erase from value, ret: " << ret2 << ",content: ";
		printMap(my1);

		std::cout << std::endl;
		ret1 = lib1.erase(42);
		std::cout << GREEN << "lib erase from value, ret: " << ret1 << ",content: ";
		printMap(lib1);
		ret2 = my1.erase(42);
		std::cout << RED << " my erase from value, ret: " << ret2 << ",content: ";
		printMap(my1);

		std::cout << std::endl;
		ret1 = lib1.erase(56);
		std::cout << GREEN << "lib erase from value, ret: " << ret1 << ",content: ";
		printMap(lib1);
		ret2 = my1.erase(56);
		std::cout << RED << " my erase from value, ret: " << ret2 << ",content: ";
		printMap(my1);

		std::cout << std::endl;
		ret1 = lib1.erase(56);
		std::cout << GREEN << "lib erase from value, ret: " << ret1 << ",content: ";
		printMap(lib1);
		ret2 = my1.erase(56);
		std::cout << RED << " my erase from value, ret: " << ret2 << ",content: ";
		printMap(my1);

		std::cout << std::endl;
		std::map<int, int>::iterator l1 = lib1.begin();
		ft::map<int, int>::iterator m1 = my1.begin();
		std::map<int, int>::iterator l2 = lib1.end();
		ft::map<int, int>::iterator m2 = my1.end();
		l1++;
		l1++;
		l1++;
		l1++;
		l2--;
		l2--;
		l2--;
		m1++;
		m1++;
		m1++;
		m1++;
		m2--;
		m2--;
		m2--;
		lib1.erase(l1, l2);
		std::cout << GREEN <<  "lib erase range content: ";
		printMap(lib1);
		my1.erase(m1, m2);
		std::cout << RED << " my erase range content: ";
		printMap(my1);
		l1 = lib1.begin();
		m1 = my1.begin();
		l2 = lib1.end();
		m2 = my1.end();
		l1++;
		l1++;
		m1++;
		m1++;
		l2--;
		l2--;
		m2--;
		m2--;

		std::cout << std::endl;
		lib1.erase(l1, l2);
		std::cout << GREEN << "lib erase range content: ";
		printMap(lib1);
		my1.erase(m1, m2);
		std::cout << RED << " my erase range content: ";
		printMap(my1);
		std::cout << BLUE << "--------------CLEAR TEST--------------------" << RESET << std::endl;
		lib1.clear();
		my1.clear();
		std::cout << "lib clear: ";
		printMap(lib1);
		std::cout << " my clear: ";
		printMap(my1);
	}

	void swap_test()
	{
		std::cout << BLUE <<  "----------------SWAP TEST--------------------" << RESET << std::endl;
		ft::map<char, int> my1;
		ft::map<char, int> my2;
		my1['a'] = 10;
		my1['b'] = 30;
		my1['c'] = 10;
		my2['z'] = 1;
		my2['f'] = 8;
		my2['e'] = 7;
		my2['x'] = 6;
		std::cout << RED << "BEFORE swap:" << std::endl;
		std::cout << "my1: ";
		printMap(my1);
		std::cout << RED << "my2: ";
		printMap(my2);
		std::cout << std::endl;
		my1.swap(my2);
		std::cout << RED "AFTER swap:" << std::endl;
		std::cout << "my1: ";
		printMap(my1);
		std::cout << RED << "my2: ";
		printMap(my2);
	}

	template<typename T>
	void observKeyPrint(T &container, std::string compare_msg1, std::string compare_msg2)
	{
		container[3] = 100;
		container[2] = 3;
		container[4] = 10;
		typename T::iterator i1 = container.begin();
		typename T::iterator i2 = container.begin();
		typename T::key_compare key_comparator = container.key_comp();
		i2++;
		std::cout << "iterator first key: " << (*i1).first << "  " << "iterator second key: " << (*i2).first
				  << std::endl;
		std::cout << "first is " << (key_comparator((*i1).first, i2->first) ? compare_msg1 : compare_msg2) << std::endl;
		i1++;
		std::cout << std::endl;
		std::cout << "iterator first key: " << (*i1).first << "  " << "iterator second key: " << (*i2).first
				  << std::endl;
		std::cout << "first is " << (key_comparator((*i1).first, i2->first) ? compare_msg1 : compare_msg2) << std::endl;
		i1++;
		std::cout << std::endl;
		std::cout << "iterator first key: " << (*i1).first << "  " << "iterator second key: " << (*i2).first
				  << std::endl;
		std::cout << "first is " << (key_comparator((*i1).first, i2->first) ? compare_msg1 : compare_msg2) << std::endl;
	}

	template<typename T>
	void observPairPrint(T &container, std::string compare_msg1, std::string compare_msg2)
	{
		container[3] = 100;
		container[2] = 3;
		container[4] = 10;
		typename T::iterator i1 = container.begin();
		typename T::iterator i2 = container.begin();
		typename T::value_compare val_comparator = container.value_comp();
		i2++;
		std::cout << "first pair: " << (*i1).first << ":" << (*i1).second << ",second pair: " << (*i2).first << ":"
				  << (*i2).second << std::endl;
		std::cout << "first is " << (val_comparator(*i1, *i2) ? compare_msg1 : compare_msg2) << std::endl;
		i1++;
		std::cout << std::endl;
		std::cout << "first pair: " << (*i1).first << ":" << (*i1).second << ",second pair: " << (*i2).first << ":"
				  << (*i2).second << std::endl;
		std::cout << "first is " << (val_comparator(*i1, *i2) ? compare_msg1 : compare_msg2) << std::endl;
		i1++;
		std::cout << std::endl;
		std::cout << "first pair: " << (*i1).first << ":" << (*i1).second << ",second pair: " << (*i2).first << ":"
				  << (*i2).second << std::endl;
		std::cout << "first is " << (val_comparator(*i1, *i2) ? compare_msg1 : compare_msg2) << RESET << std::endl;
	}

	void observers_test()
	{
		std::cout << BLUE << "----------------OBSERVERS TEST--------------------" << RESET << std::endl;
		ft::map<int, int> mymap;
		std::map<int, int> mymapLib;
		ft::map<int, int, std::greater<int> > mymap1;
		std::map<int, int, std::greater<int> > mymapLib1;
		std::cout << RED << "My default comparator test" << std::endl;
		observKeyPrint(mymap, "less than second", "greater or equal than second");
		std::cout << std::endl;
		std::cout << GREEN << "Lib default comparator test" << std::endl;
		observKeyPrint(mymapLib, "less than second", "greater or equal than second");

		std::cout << std::endl;
		std::cout << RED << "My std::greater test" << std::endl;
		observKeyPrint(mymap1, "greater than second", "less or equal than second");
		std::cout << std::endl;
		std::cout << GREEN << "Lib std::greater test" << std::endl;
		observKeyPrint(mymapLib1, "greater than second", "less or equal than second");

		std::cout << RED << "My default comparator test" << std::endl;
		observPairPrint(mymap, "less than second", "greater or equal than second");
		std::cout << std::endl;
		std::cout << GREEN << "Lib default comparator test" << std::endl;
		observPairPrint(mymapLib, "less than second", "greater or equal than second");

		std::cout << RED << "My std::greater test" << std::endl;
		observPairPrint(mymap, "less than second", "greater or equal than second");
		std::cout << std::endl;
		std::cout << GREEN << "Lib std::greater test" << std::endl;
		observPairPrint(mymapLib, "less than second", "greater or equal than second");
		find_tests();
		different_tests();

	}

	void find_tests()
	{
		std::cout << BLUE << "----------------OPERATIONS TEST--------------------" << RESET << std::endl;
		std::map<char, int> lib1;
		ft::map<char, int> my1;
		std::cout << GREEN << "find lib test: " << std::endl;
		find_test(lib1);
		std::cout << RED << "find  my test: " << std::endl;
		find_test(my1);
	}

	template<typename T>
	void count_test(T &container)
	{
		container['a'] = 101;
		container['c'] = 202;
		container['f'] = 303;
		container['t'] = 303;
		char c;

		printMap(container);
		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (container.count(c) == 1)
				std::cout << " is an element of container" << std::endl;
			else if (container.count(c) == 0)
				std::cout << " is not an element of container" << std::endl;
		}
		std::cout << RESET << std::endl;
	}

	template<typename T>
	void lower_upper_bound(T &container)
	{
		container['a'] = 20;
		container['c'] = 60;
		container['d'] = 80;
		container['e'] = 100;

		typename T::iterator itlow = container.lower_bound('b');  // itlow points to b
		typename T::iterator itup = container.upper_bound('d');   // itup points to e (not d!)

		printMap(container);

		std::cout << "lower bound('b') iter: " << itlow->first << ":" << itlow->second << std::endl;
		std::cout << "upper bound('d') iter: " << itup->first << ":" << itup->second << std::endl;

		container['b'] = 32;
		itlow = container.lower_bound('b');  // itlow points to b
		itup = container.upper_bound('d');   // itup points to e (not d!)

		printMap(container);

		std::cout << "lower bound('b') iter: " << itlow->first << ":" << itlow->second << std::endl;
		std::cout << "upper bound('d') iter: " << itup->first << ":" << itup->second << std::endl;
		std::cout << std::endl;
	}

	template<typename T>
	void equal_range_test(T &container)
	{
		container['a'] = 10;
		container['b'] = 20;
		container['c'] = 30;

		printMap(container);
		std::pair<typename T::iterator, typename T::iterator> ret;
		ret = container.equal_range('b');

		std::cout << "lower bound points to b: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to b: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
		std::cout << std::endl;
	}


	void different_tests()
	{
		std::map<char, int> lib;
		ft::map<char, int> my;
		std::cout << GREEN <<  "Lib count test" << std::endl;
		count_test(lib);

		std::cout << RED << " My count test" << std::endl;
		count_test(my);

		std::cout << GREEN << "Lib lower/upper bounds test" << std::endl;
		lower_upper_bound(lib);

		std::cout << RED << " My lower/upper bounds test" << std::endl;
		lower_upper_bound(my);

		std::cout << GREEN <<  "Lib equal range test" << std::endl;
		equal_range_test(lib);

		std::cout << RED << " My equal range test" << std::endl;
		equal_range_test(my);
	}
}
	int map_main()
	{
		map_test::constructors_test();
		map_test::iterators_test();
		map_test::capacity_test();
		map_test::access_tests();
		map_test::insert_test();
		map_test::erase_test();
		map_test::swap_test();
		map_test::observers_test();
		return (1);
	}
