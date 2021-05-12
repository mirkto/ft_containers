#include <iostream>
#include <list>
#include "../Includes/list.hpp"
#include <string>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

namespace lst_test
{
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
		std::cout << RESET << std::endl;
	}

	bool remove_if_pred(int curr)
	{
		if (curr <= 25)
			return true;
		return false;
	}

	bool condition(int curr, int prev)
	{
		if (prev > curr)
			return true;
		return false;
	}

	bool comp(int first, int second)
	{
		if (first > second)
			return true;
		return false;
	}

	struct Predicate
	{
		bool operator()(int curr, int next)
		{
			if (next - curr == 1)
				return true;
			return false;
		}
	};

	void constructors_test()
	{
		std::cout << BLUE "            CONSTRUCTORS && ASSIGNATION         " << RESET << std::endl;
		std::cout << GREEN << "Default constructor lib: " << std::endl;
		std::list<int> lib;
		printList(lib);
		std::cout << RED << "Default constructor my: " << std::endl;
		ft::list<int> my;
		printList(my);
		std::cout << GREEN "Constructor fill lib: " << std::endl;
		std::list<int> lib2((size_t) 3, 4);
		printList(lib2);
		std::cout << RED << "Constructor fill my: " << std::endl;
		ft::list<int> my2((size_t) 3, 4);
		printList(my2);

		lib2.push_back(100);
		lib2.push_back(1);
		lib2.push_back(3);
		my2.push_back(100);
		my2.push_back(1);
		my2.push_back(3);
		std::cout << GREEN <<  "Constructor range lib: " << std::endl;
		std::list<int> lib3(lib2.begin(), lib2.end());
		printList(lib3);
		std::cout << RED << "Constructor range my: " << std::endl;
		ft::list<int> my3(my2.begin(), my2.end());
		printList(my3);
		std::cout << GREEN << "Constructor copy lib: " << std::endl;
		std::list<int> lib4(lib3);
		printList(lib4);
		std::cout << RED <<"Constructor copy my: " << std::endl;
		ft::list<int> my4(my3);
		printList(my4);
		std::list<int> lib5;
		ft::list<int> my5;
		lib5.push_back(100);
		my5.push_back(100);
		std::cout << GREEN <<"Assignation operator lib: " << std::endl;
		lib4 = lib5;
		printList(lib4);
		std::cout << RED << "Assignation operator my: " << std::endl;
		my4 = my5;
		printList(my4);
	}

	void iterators_test()
	{
		std::cout << BLUE <<  "            ITERATORS         " << std::endl;
		std::list<double> lib((size_t) 2, 10);
		lib.push_back(11);
		lib.push_back(12);
		ft::list<double> my((size_t) 2, 10);
		my.push_back(11);
		my.push_back(12);
		std::list<double>::iterator itl = lib.begin();
		std::list<double>::iterator itle = lib.end();
		ft::list<double>::iterator itm = my.begin();
		ft::list<double>::iterator itme = my.end();
		std::cout << GREEN <<"Iterators lib: " << std::endl;
		while (++itl != itle)
			std::cout << *itl << " ";
		std::cout << RESET << std::endl;
		std::cout << RED <<"Iterators my: " << std::endl;
		while (++itm != itme)
			std::cout << *itm << RESET << " ";
		std::cout << std::endl;

		std::list<double>::reverse_iterator itlr = lib.rbegin();
		std::list<double>::reverse_iterator itlre = lib.rend();
		ft::list<double>::reverse_iterator itmr = my.rbegin();
		ft::list<double>::reverse_iterator itmre = my.rend();
		std::cout << GREEN << "Reverse Iterators lib: " << std::endl;
		while (++itlr != itlre)
			std::cout << *itlr << " ";
		std::cout << RESET << std::endl;
		std::cout << RED << "Reverse Iterators my: " << std::endl;
		while (++itmr != itmre)
			std::cout << *itmr << RESET << " ";
		std::cout << std::endl;
	}

	void capacity_test()
	{
		std::cout << BLUE << "            CAPACITY         " << std::endl;
		std::list<int> lib;
		std::cout <<  GREEN << "Empty lib: " << lib.empty() << " ,size = " << lib.size() << " ,list : ";
		printList(lib);
		std::cout << std::endl;
		ft::list<int> my;
		std::cout << RED << "Empty my:  " << my.empty() << " ,size = " << my.size() << " ,list : ";
		printList(my);
		std::cout << std::endl;

		lib.push_front(2);
		my.push_front(2);

		std::cout << GREEN << "Empty lib: " << lib.empty() << " ,size = " << lib.size() << " ,list : ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED << "Empty my:  " << my.empty() << " ,size = " << my.size() << " ,list : ";
		printList(my);
		std::cout << std::endl;

		lib.push_front(2);
		my.push_front(2);
		lib.push_back(100);
		my.push_back(100);
		lib.push_front(2);
		my.push_front(2);
		lib.push_back(13);
		my.push_back(13);
		lib.pop_front();
		my.pop_front();
		lib.pop_back();
		my.pop_back();
		lib.push_back(99);
		my.push_back(99);

		std::cout << GREEN << "Empty lib: " << lib.empty() << " ,size = " << lib.size() << " ,list : ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED << "Empty my:  " << my.empty() << " ,size = " << my.size() << " ,list : ";
		printList(my);
		std::cout << std::endl;

		std::cout << GREEN << "Max size lib = " << lib.max_size() << RESET << std::endl;
		std::cout << RED << "Max size my  = " << my.max_size() << RESET << std::endl;
		std::cout << std::endl;
	}

	template<typename T>
	void print_access_info(T &cont, const std::string &msg)
	{
		std::cout << msg << " front: " << cont.front() << " , back: " << cont.back() << ", list: ";
		printList(cont);
		std::cout << RESET << std::endl;
	}

	void access_test()
	{
		std::cout << BLUE <<  "            ACCESS         " << std::endl;
		std::list<int> lib;
		ft::list<int> my;
		lib.push_front(2);
		my.push_front(2);
		std::cout << GREEN;
		print_access_info(lib, "lib");
		std::cout << RED;
		print_access_info(my, "my ");
		lib.push_back(100);
		my.push_back(100);
		lib.push_front(2);
		my.push_front(2);
		std::cout << GREEN;
		print_access_info(lib, "lib");
		std::cout << RED;
		print_access_info(my, "my ");
		lib.push_back(13);
		my.push_back(13);
		lib.pop_front();
		my.pop_front();
		std::cout << GREEN;
		print_access_info(lib, "lib");
		std::cout << RED;
		print_access_info(my, "my ");
		lib.pop_back();
		my.pop_back();
		std::cout << GREEN;
		print_access_info(lib, "lib");
		std::cout << RED;
		print_access_info(my, "my ");
		lib.push_back(99);
		my.push_back(99);
		lib.insert(lib.begin(), 10000);
		my.insert(my.begin(), 10000);
		std::cout << GREEN;
		print_access_info(lib, "lib");
		std::cout << RED;
		print_access_info(my, "my ");
		lib.insert(lib.end(), 88888);
		my.insert(my.end(), 88888);
		std::cout << GREEN;
		print_access_info(lib, "lib");
		std::cout << RED;
		print_access_info(my, "my ");
		lib.insert(++lib.end(), 0);
		my.insert(++my.end(), 0);
		std::cout << GREEN;
		print_access_info(lib, "lib");
		std::cout << RED;
		print_access_info(my, "my ");
		lib.insert(--lib.begin(), 26);
		my.insert(--my.begin(), 26);
		std::cout << GREEN;
		print_access_info(lib, "lib");
		std::cout << RED;
		print_access_info(my, "my");
	}

	void assign()
	{
		std::cout << std::endl;
		std::list<int> lib((size_t) 4, 12);
		lib.push_back(1);
		std::cout << GREEN;
		std::cout << "Before assign lib: ";
		printList(lib);
		std::cout << std::endl;
		ft::list<int> my((size_t) 4, 12);
		my.push_back(1);
		std::cout << RED;
		std::cout << "Before assign my : ";
		printList(my);
		std::cout << std::endl;

		lib.assign((size_t) 10, 10);
		my.assign((size_t) 10, 10);
		std::cout << GREEN;
		std::cout << "After assign lib: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED;
		std::cout << "After assign my : ";
		printList(my);
		std::cout << std::endl;

		lib.assign((size_t) 0, 100);
		my.assign((size_t) 0, 100);

		std::cout << GREEN;
		std::cout << "After assign lib to 0 elems: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED;
		std::cout << "After assign my  to 0 elems: ";
		printList(my);
		std::cout << std::endl;

		std::list<int> lib2;
		lib2.push_back(1);
		lib2.push_back(2);
		lib2.push_back(3);
		lib2.push_back(4);
		std::list<int> my2;
		my2.push_back(1);
		my2.push_back(2);
		my2.push_back(3);
		my2.push_back(4);

		lib.assign(lib2.begin(), lib2.end());
		my.assign(my2.begin(), my2.end());
		std::cout << GREEN;
		std::cout << "After assign lib to interval first case: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED;
		std::cout << "After assign my  to interval first case: ";
		printList(my);
		std::cout << std::endl;

		lib.assign(++lib2.begin(), --lib2.end());
		my.assign(++my2.begin(), --my2.end());
		std::cout << GREEN;
		std::cout << "After assign lib to interval second case: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED;
		std::cout << "After assign my  to interval second case: ";
		printList(my);
		std::cout << std::endl;

		lib.assign(--lib2.begin(), ++lib2.end());
		my.assign(--my2.begin(), ++my2.end());

		std::cout << GREEN;
		std::cout << "After assign lib to interval third case: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED;
		std::cout << "After assign my  to interval third case: ";
		printList(my);
		std::cout << std::endl;
	}

	void push_pop_tests()
	{
		std::cout << std::endl;
		std::list<int> lib((size_t) 4, 12);
		lib.push_back(1);
		std::cout << GREEN;
		std::cout << "Push back lib: ";
		printList(lib);
		std::cout << std::endl;
		ft::list<int> my((size_t) 4, 12);
		my.push_back(1);
		std::cout << RED;
		std::cout << "Push back  my: ";
		printList(my);
		std::cout << std::endl;

		lib.push_front(11);
		std::cout << GREEN;
		std::cout << "Push front lib: ";
		printList(lib);
		std::cout << std::endl;
		my.push_front(11);
		std::cout << RED;
		std::cout << "Push front  my: ";
		printList(my);
		std::cout << std::endl;

		lib.pop_back();
		my.pop_back();
		std::cout << GREEN;
		std::cout << "Pop back lib: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED;
		std::cout << "Pop back  my: ";
		printList(my);
		std::cout << std::endl;

		lib.pop_front();
		my.pop_front();
		std::cout << GREEN;
		std::cout << "Pop front lib: ";
		printList(lib);
		std::cout << std::endl;
		std::cout << RED;
		std::cout << "Pop front  my: ";
		printList(my);
		std::cout << std::endl;

	}

	template<typename T, typename InputIterator>
	void erase_tests(T &container, const std::string &msg1, InputIterator pos, const std::string &msg2)
	{
		std::cout << "Erase(one elem) in " << msg2 << " list " << msg1 << " ,ret value: ";
		std::cout << *container.erase(pos);
		std::cout << " ,list: ";
		printList(container);
	}

	template<typename T, typename InputIterator>
	void
	erase_tests(T &container, const std::string &msg1, InputIterator pos1, InputIterator pos2, const std::string &msg2)
	{
		std::cout << "Erase(interval) in " << msg2 << " list " << msg1 << " ,ret value: ";
		std::cout << *container.erase(pos1, pos2);
		std::cout << " ,list: ";
		printList(container);
	}

	void insert_test()
	{
		std::cout << std::endl;
		std::list<int> lib;
		ft::list<int> my;
		lib.insert(lib.begin(), 2);
		my.insert(my.begin(), 2);
		std::cout << GREEN;
		std::cout << "Insert in empty list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert in empty list  my: ";
		printList(my);
		lib.insert(lib.begin(), 3);
		my.insert(my.begin(), 3);
		std::cout << GREEN;
		std::cout << "Insert in begin list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert in begin list  my: ";
		printList(my);
		lib.insert(++lib.begin(), 10);
		my.insert(++my.begin(), 10);
		std::cout << GREEN;
		std::cout << "Insert in random place list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert in random place list  my: ";
		printList(my);
		lib.insert(lib.end(), 3);
		my.insert(my.end(), 3);
		std::cout << GREEN;
		std::cout << "Insert in end list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert in end list  my: ";
		printList(my);

		lib.insert(lib.begin(), (size_t) 3, 3);
		my.insert(my.begin(), (size_t) 3, 3);
		std::cout << GREEN;
		std::cout << "Insert(fill) in begin list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert(fill) in begin list  my: ";
		printList(my);
		lib.insert(++lib.begin(), (size_t) 2, 10);
		my.insert(++my.begin(), (size_t) 2, 10);
		std::cout << GREEN;
		std::cout << "Insert(fill) in random place list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert(fill) in random place list  my: ";
		printList(my);
		lib.insert(lib.end(), (size_t) 4, 3);
		my.insert(my.end(), (size_t) 4, 3);
		std::cout << GREEN;
		std::cout << "Insert(fill) in end list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert(fill) in end list  my: ";
		printList(my);

		lib.clear();
		my.clear();
		lib.push_back(12);
		lib.push_back(13);
		lib.push_back(14);
		my.push_back(12);
		my.push_back(13);
		my.push_back(14);
		lib.insert(lib.begin(), ++lib.begin(), --lib.end());
		my.insert(my.begin(), ++my.begin(), --my.end());
		std::cout << GREEN;
		std::cout << "Insert(range) in begin list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert(range) in begin list  my: ";
		printList(my);
		std::list<int>::iterator il = lib.begin();
		il++;
		il++;
		lib.insert(il, lib.begin(), lib.end());
		ft::list<int>::iterator im = my.begin();
		im++;
		im++;
		my.insert(im, my.begin(), my.end());
		std::cout << GREEN;
		std::cout << "Insert(range) in random place list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert(range) in random place list  my: ";
		printList(my);
		lib.insert(lib.end(), --lib.begin(), lib.end());
		my.insert(my.end(), --my.begin(), my.end());
		std::cout << GREEN;
		std::cout << "Insert(range) in end list lib: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Insert(range) in end list  my: ";
		printList(my);

		std::cout << GREEN;
		erase_tests(lib, "lib", lib.begin(), "begin");
		std::cout << RED;
		erase_tests(my, " my", my.begin(), "begin");
		std::cout << GREEN;
		erase_tests(lib, "lib", --lib.end(), "end");
		std::cout << RED;
		erase_tests(my, " my", --my.end(), "end");
		std::cout << GREEN;
		erase_tests(lib, "lib", --lib.end(), "end");
		std::cout << RED;
		erase_tests(my, " my", --my.end(), "end");

		std::list<int>::iterator lb = lib.begin();
		ft::list<int>::iterator lm = my.begin();
		lb++;
		lb++;;
		lm++;
		lm++;
		std::cout << GREEN;
		erase_tests(lib, "lib", lb, "random place");
		std::cout << RED;
		erase_tests(my, " my", lm, "random place");
		std::cout << GREEN;
		erase_tests(lib, "lib", ++lib.begin(), --lib.end(), "random place");
		std::cout << RED;
		erase_tests(my, " my", ++my.begin(), --my.end(), "random place");
		lib.push_back(33);
		my.push_back(33);
		std::cout << GREEN;
		erase_tests(lib, "lib", lib.begin(), --lib.end(), "random place");
		std::cout << RED;
		erase_tests(my, " my", my.begin(), --my.end(), "random place");
		std::cout << GREEN;
		erase_tests(lib, "lib", lib.begin(), lib.end(), "all");
		std::cout << RED;
		erase_tests(my, " my", my.begin(), my.end(), "all");
	}

	void swap_tests()
	{
		std::cout << std::endl;
		std::list<int> first((size_t) 3, 100);   // three ints with a value of 100
		std::list<int> second((size_t) 5, 200);
		std::cout << GREEN;
		std::cout << "lib before swap  first: ";
		printList(first);
		std::cout << GREEN;
		std::cout << "lib before swap second: ";
		printList(second);
		first.swap(second);// five ints with a value of 200
		std::cout << GREEN;
		std::cout << "lib after swap  first: ";
		printList(first);
		std::cout << GREEN;
		std::cout << "lib after swap second: ";
		printList(second);
		ft::list<int> firstMy((size_t) 3, 100);   // three ints with a value of 100
		ft::list<int> secondMy((size_t) 5, 200);
		std::cout << RED << " my before swap  first: ";
		printList(firstMy);
		std::cout << RED << " my before swap second: ";
		printList(secondMy);
		firstMy.swap(secondMy);
		std::cout << RED;
		std::cout << " my after swap  first: ";
		printList(firstMy);
		std::cout << RED;
		std::cout << " my after swap second: ";
		printList(secondMy);
		first.push_back(1);
		first.push_back(2);
		second.push_back(10);
		second.push_back(20);
		firstMy.push_back(1);
		firstMy.push_back(2);
		secondMy.push_back(10);
		secondMy.push_back(20);

		std::cout << GREEN << std::endl;
		std::cout << "lib before swap  first: ";
		printList(first);
		std::cout << GREEN;
		std::cout << "lib before swap second: ";
		printList(second);
		first.swap(second);// five ints with a value of 200
		std::cout << GREEN;
		std::cout << "lib after swap  first: ";
		printList(first);
		std::cout << GREEN;
		std::cout << "lib after swap second: ";
		printList(second);

		std::cout << RED << " my before swap  first: ";
		printList(firstMy);

		std::cout << RED << " my before swap second: ";
		printList(secondMy);
		firstMy.swap(secondMy);

		std::cout << RED << " my after swap  first: ";
		printList(firstMy);
		std::cout << RED;
		std::cout << " my after swap second: ";
		printList(secondMy);

	}

	void resize_clear_tests()
	{
		std::cout << std::endl;
		std::list<int> lib((size_t) 3, 100);
		ft::list<int> my((size_t) 3, 100);
		lib.resize(4, 11);
		my.resize(4, 11);
		std::cout << GREEN;
		std::cout << "lib list after resize: ";
		printList(lib);
		std::cout << RED;
		std::cout << " my list after resize: ";
		printList(my);
		lib.resize(2, 11);
		my.resize(2, 11);
		std::cout << GREEN;
		std::cout << "lib list after resize: ";
		printList(lib);
		std::cout << RED;
		std::cout << " my list after resize: ";
		printList(my);
		lib.push_front(2);
		my.push_front(2);
		lib.resize(2, 11);
		my.resize(2, 11);
		std::cout << GREEN;
		std::cout << "lib list after resize: ";
		printList(lib);
		std::cout << RED;
		std::cout << " my list after resize: ";
		printList(my);
		lib.resize(0, 0);
		my.resize(0, 0);
		std::cout << GREEN;
		std::cout << "lib list after resize: ";
		printList(lib);
		std::cout << RED;
		std::cout << " my list after resize: ";
		printList(my);

		std::cout << std::endl;
		lib.resize(10, 11);
		my.resize(10, 11);
		std::cout << GREEN;
		std::cout << "Before clear: ";
		printList(lib);
		std::cout << RED;
		std::cout << "Before clear: ";
		printList(my);

		lib.clear();
		my.clear();
		std::cout << GREEN;
		std::cout << "After clear: ";
		printList(lib);
		std::cout << RED;
		std::cout << "After clear: ";
		printList(my);


	}

	void splice_remove_uniq_test()
	{
		std::list<int> lib1;
		ft::list<int> my1;
		lib1.push_back(1);
		lib1.push_back(2);
		lib1.push_back(3);
		lib1.push_back(4);
		my1.push_back(1);
		my1.push_back(2);
		my1.push_back(3);
		my1.push_back(4);
		std::list<int> lib2;
		ft::list<int> my2;
		lib2.push_back(25);
		lib2.push_back(26);
		lib2.push_back(27);
		lib2.push_back(28);
		my2.push_back(25);
		my2.push_back(26);
		my2.push_back(27);
		my2.push_back(28);
		lib1.splice(lib1.begin(), lib2);
		std::cout << GREEN;
		std::cout << "After splice all lib2 into lib1, lib1 : ";
		printList(lib1);
		std::cout << "lib2: ";
		std::cout << GREEN;
		printList(lib2);
		std::cout << RED;
		my1.splice(my1.begin(), my2);
		std::cout << "After splice all  my2 into  my1,  my1 : ";
		printList(my1);
		std::cout << RED;
		std::cout << " my2: ";
		printList(my2);
		lib2.push_back(100);
		lib2.push_back(101);
		my2.push_back(100);
		my2.push_back(101);
		lib1.splice(lib1.begin(), lib2, ++lib2.begin());
		std::cout << GREEN;
		std::cout << "After splice one elem from lib2 into lib1, lib1 : ";
		printList(lib1);
		std::cout << GREEN;
		std::cout << "lib2: ";
		printList(lib2);
		std::cout << RED;
		my1.splice(my1.begin(), my2, ++my2.begin());
		std::cout << "After splice one elem from  my2 into  my1,  my1 : ";
		printList(my1);
		std::cout << RED;
		std::cout << " my2: ";
		printList(my2);

		lib2.splice(lib2.end(), lib1, ++lib1.begin(), --lib1.end());
		my2.splice(my2.end(), my1, ++my1.begin(), --my1.end());
		std::cout << GREEN;
		std::cout << "After splice range from lib1 into lib2, lib1 : ";
		printList(lib1);
		std::cout << GREEN;
		std::cout << "lib2: ";
		printList(lib2);
		std::cout << RED;
		std::cout << "After splice range from  my1 into   my2,  my1 : ";
		printList(my1);
		std::cout << RED;
		std::cout << " my2: ";
		printList(my2);

		lib2.splice(lib2.end(), lib1, lib1.begin(), lib1.end());
		my2.splice(my2.end(), my1, my1.begin(), my1.end());
		std::cout << GREEN;
		std::cout << "After splice range from lib1 into lib2, lib1 : ";
		printList(lib1);
		std::cout << GREEN;
		std::cout << "lib2: ";
		printList(lib2);
		std::cout << RED;
		std::cout << "After splice range from my1 into   my2,   my1 : ";
		printList(my1);
		std::cout << RED;
		std::cout << " my2: ";
		printList(my2);

		std::cout << std::endl;
		lib2.remove(100);
		lib2.remove(101);
		my2.remove(100);
		my2.remove(101);
		std::cout << GREEN;
		std::cout << "After remove elems equal value lib : ";
		printList(lib2);
		std::cout << RED;
		std::cout << "After remove elems equal value  my : ";
		printList(my2);
		my2.push_back(1);
		lib2.push_back(1);
		lib2.remove(1);
		my2.remove(1);
		std::cout << GREEN;
		std::cout << "After remove elems equal value lib : ";
		printList(lib2);
		std::cout << RED;
		std::cout << "After remove elems equal value  my : ";
		printList(my2);
		lib2.remove_if(remove_if_pred);
		my2.remove_if(remove_if_pred);
		std::cout << GREEN;
		std::cout << "After remove if(predicate a <= 25) lib : ";
		printList(lib2);
		std::cout << RED;
		std::cout << "After remove if(predicate a <= 25)  my : ";
		printList(my2);
		std::cout << std::endl;
		lib2.push_front(26);
		lib2.push_front(26);
		lib2.push_back(26);
		my2.push_front(26);
		my2.push_front(26);
		my2.push_back(26);
		lib2.unique();
		my2.unique();
		std::cout << GREEN;
		std::cout << "Unique func lib : ";
		printList(lib2);
		std::cout << RED;
		std::cout << "Unique func  my : ";
		printList(my2);
		Predicate pred;

		lib2.push_back(27);
		my2.push_back(27);
		lib2.unique(pred);
		my2.unique(pred);
		std::cout << GREEN;
		std::cout << "Unique func(predicate next - prev == 1) lib : ";
		printList(lib2);
		std::cout << RED;
		std::cout << "Unique func(predicate next - prev == 1)  my : ";
		printList(my2);
	}

	void merge_test()
	{
		std::list<std::string> lib0;
		ft::list<std::string> my0;
		std::list<std::string> lib;
		ft::list<std::string> my;
		lib0.push_back("b");
		lib0.push_back("e");
		lib0.push_back("x");
		lib.push_back("a");
		my0.push_back("b");
		my0.push_back("e");
		my0.push_back("x");
		my.push_back("a");
		lib0.merge(lib);
		my0.merge(my);
		std::cout << GREEN;
		std::cout << "After merge (default comp) lib: ";
		printList(lib0);
		std::cout << RED;
		std::cout << "After merge (default comp)  my: ";
		printList(my0);
		
		std::list<int> lib1;
		std::list<int> lib2;
		lib1.push_back(2);
		lib1.push_back(3);
		lib1.push_back(5);
		lib2.push_back(1);
		lib2.push_back(9);
		lib2.push_back(10);
		lib2.push_back(10);
		ft::list<int> my1;
		ft::list<int> my2;
		my1.push_back(2);
		my1.push_back(3);
		my1.push_back(5);
		my2.push_back(1);
		my2.push_back(9);
		my2.push_back(10);
		my2.push_back(10);
		lib1.merge(lib2);
		my1.merge(my2);
		std::cout << GREEN;
		std::cout << "After merge (default comp) lib: ";
		printList(lib1);
		std::cout << RED;
		std::cout << "After merge (default comp)  my: ";
		printList(my1);
		lib1.clear();
		lib2.clear();
		my1.clear();
		my2.clear();
		lib1.push_back(5);
		lib1.push_back(10);
		lib2.push_back(9);
		my1.push_back(5);
		my1.push_back(10);
		my2.push_back(9);
		lib1.merge(lib2);
		my1.merge(my2);
		std::cout << GREEN;
		std::cout << "After merge (default comp) lib: ";
		printList(lib1);
		std::cout << RED;
		std::cout << "After merge (default comp)  my: ";
		printList(my1);
		my2.push_back(21);
		my2.push_back(22);
		lib2.push_back(21);
		lib2.push_back(22);
		my1.merge(my2);
		lib1.merge(lib2);
		std::cout << GREEN;
		std::cout << "After merge (default comp) lib: ";
		printList(lib1);
		std::cout << RED;
		std::cout << "After merge (default comp)  my: ";
		printList(my1);
		lib1.clear();
		lib2.clear();
		my1.clear();
		my2.clear();

		lib1.push_back(3);
		lib2.push_back(1);
		lib2.push_back(4);
		my1.push_back(3);
		my2.push_back(1);
		my2.push_back(4);

		lib1.merge(lib2);
		my1.merge(my2);
		std::cout << GREEN;
		std::cout << "After merge (default comp) lib: ";
		printList(lib1);
		std::cout << RED;
		std::cout << "After merge (default comp)  my: ";
		printList(my1);

		lib1.clear();
		lib2.clear();
		my1.clear();
		my2.clear();

		lib1.push_back(1);
		lib1.push_back(10);
		lib2.push_back(4);
		my1.push_back(1);
		my1.push_back(10);
		my2.push_back(4);

		lib1.merge(lib2);
		my1.merge(my2);
		std::cout << GREEN;
		std::cout << "After merge (default comp) lib: ";
		printList(lib1);
		std::cout << RED;
		std::cout << "After merge (default comp)  my: ";
		printList(my1);

		lib1.clear();
		lib2.clear();
		my1.clear();
		my2.clear();

		lib1.push_back(1);
		lib1.push_back(2);
		lib1.push_back(8);
		lib1.push_back(10);
		lib2.push_back(11);
		my1.push_back(1);
		my1.push_back(2);
		my1.push_back(8);
		my1.push_back(10);
		my2.push_back(11);

		lib1.merge(lib2);
		my1.merge(my2);
		std::cout << GREEN;
		std::cout << "After merge (default comp) lib: ";
		printList(lib1);
		std::cout << RED;
		std::cout << "After merge (default comp)  my: ";
		printList(my1);

		lib1.clear();
		lib2.clear();
		my1.clear();
		my2.clear();

		lib2.push_back(1);
		lib2.push_back(2);
		lib2.push_back(8);
		lib2.push_back(10);
		lib1.push_back(11);
		my2.push_back(1);
		my2.push_back(2);
		my2.push_back(8);
		my2.push_back(10);
		my1.push_back(11);

		lib1.merge(lib2);
		my1.merge(my2);
		std::cout << GREEN;
		std::cout << "After merge (default comp) lib: ";
		printList(lib1);
		std::cout << RED;
		std::cout << "After merge (default comp)  my: ";
		printList(my1);

		lib1.clear();
		lib2.clear();
		my1.clear();
		my2.clear();

		lib2.push_back(11);
		lib2.push_back(10);
		lib2.push_back(8);
		lib2.push_back(7);
		lib1.push_back(15);
		lib1.push_back(14);
		my2.push_back(11);
		my2.push_back(10);
		my2.push_back(8);
		my2.push_back(7);
		my1.push_back(15);
		my1.push_back(14);

		lib1.merge(lib2, comp);
		my1.merge(my2, comp);
		std::cout << GREEN;
		std::cout << "After merge (function comp) lib: ";
		printList(lib1);
		std::cout << RED;
		std::cout << "After merge (function comp)  my: ";
		printList(my1);
	}

	void sort_test()
	{
		std::cout << std::endl;
		ft::list<double> a1((size_t) 3, 10.1);
		a1.push_back(2.5);
		a1.push_back(17.2);
		a1.push_back(3.2);
		std::cout << RED;
		std::cout << "list before sort: ";
		printList(a1);
		std::cout << RED;
		std::cout << "List  after sort: ";
		a1.sort();
		printList(a1);
		a1.clear();
		a1.push_back(56);
		a1.push_back(12);
		a1.push_back(132);
		a1.push_back(1);
		std::cout << RED;
		std::cout << "list before sort: ";
		printList(a1);
		std::cout << RED;
		std::cout << "List  after sort with comparator: ";
		a1.sort(comp);
		printList(a1);

		a1.clear();
		a1.push_back(1);
		a1.push_back(3);
		a1.push_back(2);
		std::cout << RED;
		std::cout << "list before sort: ";
		printList(a1);
		std::cout << RED;
		std::cout << "List  after sort with comparator: ";
		a1.sort(comp);
		printList(a1);
	}

	void reverse_test()
	{
		std::cout << std::endl;
		ft::list<int> mylist;

		for (int i = 1; i < 10; ++i)
			mylist.push_back(i);
		std::cout << RED;
		std::cout << "List before reverse: ";
		printList(mylist);
		mylist.reverse();
		std::cout << RED;
		std::cout << "List after reverse: ";
		printList(mylist);
	}

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
		std::cout << RESET << std::endl;
	}

	void operations_test()
	{
		std::cout << BLUE << "            OPERATIONS         " << RESET << std::endl;
		splice_remove_uniq_test();
		merge_test();
		sort_test();
		reverse_test();
	}

	void modifiers_test()
	{
		std::cout << BLUE << "            MODIFIERS         " << RESET << std::endl;
		assign();
		push_pop_tests();
		insert_test();
		swap_tests();
		resize_clear_tests();
		operations_test();
		std::cout << std::endl;
	}

	void operators()
	{
		std::cout << "                  OPERATORS TEST" << std::endl;
		std::list<int> a1;
		std::list<int> a2;
		std::list<int> a3;
		ft::list<int> b1;
		ft::list<int> b2;
		ft::list<int> b3;
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
	int list_main()
	{
		lst_test::constructors_test();
		lst_test::iterators_test();
		lst_test::capacity_test();
		lst_test::access_test();
		lst_test::modifiers_test();
		lst_test::operators();
		return (1);
	}


