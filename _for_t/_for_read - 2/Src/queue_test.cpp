//
// Created by 1 on 26.11.2020.
//

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <iostream>
#include "../Includes/queue.hpp"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

namespace queue_test
{
	template<typename T>
	void empty_test(T &queue)
	{
		std::cout << "Default constructor was called" << std::endl;
		std::cout << "queue is " << (queue.empty() ? "empty" : "not empty") << std::endl;
		for (int i = 1; i <= 3; i++)
			queue.push(i);
		std::cout << "push 3 elems" << std::endl;
		std::cout << "queue is " << (queue.empty() ? "empty" : "not empty") << RESET <<  std::endl;
	}

	template<typename T>
	void size_test(T &queue)
	{
		std::cout << "Default constructor was called" << std::endl;
		std::cout << "size: " << queue.size() << '\n';
		std::cout << "push 5 elements" << std::endl;
		for (int i = 0; i < 5; i++)
			queue.push(i);
		std::cout << "size: " << queue.size() << '\n';
		std::cout << "pop one element" << std::endl;
		queue.pop();
		std::cout << "size: " << queue.size() << RESET << '\n';
	}

	template<typename T>
	void back_front_test(T &queue)
	{
		std::cout << "push 10 11 12" << std::endl;
		for (int i = 10; i < 13; i++)
			queue.push(i);
		std::cout << "back: " << queue.back() << std::endl;
		std::cout << "front: " << queue.front() << std::endl;
	}

	template<typename T>
	void push_pop_test(T &queue)
	{
		std::cout << "push 1 2 3" << std::endl;
		for (int i = 1; i < 4 ; i++)
			queue.push(i);
		std::cout << "while container is not empty pop()" << std::endl;
		while (!queue.empty())
		{
			std::cout << "back: " << queue.back() << std::endl;
			std::cout << "front: " << queue.front() << std::endl;
			queue.pop();
		}
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
	
	void operators()
	{
		std::cout << BLUE << "                  OPERATORS TEST" << RESET <<  std::endl;
		std::queue<int> a1;
		std::queue<int> a2;
		std::queue<int> a3;
		ft::queue<int> b1;
		ft::queue<int> b2;
		ft::queue<int> b3;
		a1.push(10);
		a1.push(20);
		a2.push(10);
		a2.push(20);
		a2.push(30);
		a3.push(30);
		a3.push(20);
		a3.push(10);

		b1.push(10);
		b1.push(20);
		b2.push(10);
		b2.push(20);
		b2.push(30);
		b3.push(30);
		b3.push(20);
		b3.push(10);
		std::cout << GREEN << "Lib operators: " << std::endl;
		operators_test(a1, a2, a3);
		std::cout << RED << "My operators: " << std::endl;
		operators_test(b1, b2, b3);

		a1.push(2);
		a3.pop();
		b1.push(2);
		b3.pop();

		std::cout << GREEN << "Lib operators: " << std::endl;

		operators_test(a1, a2, a3);
		std::cout << RED << "My operators: " << std::endl;
		operators_test(b1, b2, b3);

		a1.push(12);
		b1.push(12);

		std::cout << GREEN << "Lib operators: " << std::endl;

		operators_test(a1, a2, a3);
		std::cout << RED << "My operators: " << std::endl;
		operators_test(b1, b2, b3);
	}

}

int queue_main()
{
	std::queue<int> lib;
	ft::queue<int> my;
	std::cout << BLUE <<  "          SIZE TEST " << RESET << std::endl;
	std::cout << GREEN;
	queue_test::size_test(lib);
	std::cout << RED;
	queue_test::size_test(my);
	std::cout << BLUE <<  "          EMPTY TEST " << RESET << std::endl;
	std::queue<int> lib1;
	ft::queue<int> my1;
	std::cout << GREEN;
	queue_test::empty_test(lib1);
	std::cout << RED;
	queue_test::empty_test(my1);
	std::queue<int> lib2;
	ft::queue<int> my2;
	std::cout << BLUE <<  "          BACK && FRONT TEST " << RESET << std::endl;
	std::cout << GREEN;
	queue_test::back_front_test(lib2);
	std::cout << RED;
	queue_test::back_front_test(my2);
	std::cout << BLUE <<  "          PUSH && POP TEST " << RESET << std::endl;
	std::queue<int> lib3;
	ft::queue<int> my3;
	std::cout << GREEN;
	queue_test::push_pop_test(lib3);
	std::cout << RED;
	queue_test::push_pop_test(my3);

	std::cout << BLUE <<  "          SWAP TEST " << RESET << std::endl;
	ft::queue<int> s1;
	s1.push(1);
	ft::queue<int> s2;
	s2.push(10);
	s2.push(9);
	s2.push(8);
	std::cout << RED << "before swap queue1 size: " << s1.size() << ",back: " << s1.back() << ",front: " << s1.front() << std::endl;
	std::cout << "before swap queue2 size: " << s2.size() << ",back: " << s2.back() << ",front: " << s2.front() << std::endl;
	swap(s1, s2);
	std::cout << std::endl;
	std::cout << "after  swap queue1 size: " << s1.size() << ",back: " << s1.back() << ",front: " << s1.front() << std::endl;
	std::cout << "after  swap queue2 size: " << s2.size() << ",back: " << s2.back() << ",front: " << s2.front() << RESET << std::endl;
	queue_test::operators();
	return (1);
}

