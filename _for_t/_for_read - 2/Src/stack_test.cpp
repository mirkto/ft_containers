#include <vector>
#include <stack>
#include "../Includes/stack.hpp"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

namespace stack_test
{
	template<typename T>
	void empty_test(T &stack)
	{
		std::cout << "Default constructor was called" << std::endl;
		std::cout << "stack is " << (stack.empty() ? "empty" : "not empty") << std::endl;
		for (int i = 1; i <= 3; i++)
			stack.push(i);
		std::cout << "push 3 elems" << std::endl;
		std::cout << "stack is " << (stack.empty() ? "empty" : "not empty") << RESET <<  std::endl;
	}

	template<typename T>
	void size_test(T &stack)
	{
		std::cout << "Default constructor was called" << std::endl;
		std::cout << "size: " << stack.size() << '\n';
		std::cout << "push 5 elements" << std::endl;
		for (int i = 0; i < 5; i++)
			stack.push(i);
		std::cout << "size: " << stack.size() << '\n';
		std::cout << "pop one element" << std::endl;
		stack.pop();
		std::cout << "size: " << stack.size() << RESET << '\n';
	}

	template<typename T>
	void top_test(T &stack)
	{
		std::cout << "push 10 11 12" << std::endl;
		for (int i = 10; i < 13; i++)
			stack.push(i);
		std::cout << "top: " << stack.top() << std::endl;
	}

	template<typename T>
	void push_pop_test(T &stack)
	{
		std::cout << "push 3 2 1" << std::endl;
		for (int i = 3; i > 0; i--)
			stack.push(i);
		std::cout << "while container is not empty pop()" << std::endl;
		while (!stack.empty())
		{
			std::cout << "top: " << stack.top() << std::endl;
			stack.pop();
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
		std::stack<int> a1;
		std::stack<int> a2;
		std::stack<int> a3;
		ft::stack<int> b1;
		ft::stack<int> b2;
		ft::stack<int> b3;
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
	int stack_main()
	{
		std::stack<int> lib;
		ft::stack<int> my;
		std::cout << BLUE <<  "          SIZE TEST " << RESET << std::endl;
		std::cout << GREEN;
		stack_test::size_test(lib);
		std::cout << RED;
		stack_test::size_test(my);
		std::cout << BLUE <<  "          EMPTY TEST " << RESET << std::endl;
		std::stack<int> lib1;
		ft::stack<int> my1;
		std::cout << GREEN;
		stack_test::empty_test(lib1);
		std::cout << RED;
		stack_test::empty_test(my1);
		std::cout << BLUE <<  "          TOP TEST " << RESET << std::endl;
		std::cout << GREEN;
		stack_test::top_test(lib1);
		std::cout << RED;
		stack_test::top_test(my1);
		std::cout << BLUE <<  "          PUSH && POP TEST " << RESET << std::endl;
		std::stack<int> lib2;
		ft::stack<int> my2;
		std::cout << GREEN;
		stack_test::push_pop_test(lib2);
		std::cout << RED;
		stack_test::push_pop_test(my2);

		std::cout << BLUE <<  "          SWAP TEST " << RESET << std::endl;
		ft::stack<int> s1;
		s1.push(1);
		ft::stack<int> s2;
		s2.push(10);
		s2.push(9);
		s2.push(8);
		std::cout << RED << "before swap stack1 size: " << s1.size() << ",top: " << s1.top() << std::endl;
		std::cout << "before swap stack2 size: " << s2.size() << ",top: " << s2.top() << std::endl;
		swap(s1, s2);
		std::cout << std::endl;
		std::cout << "after  swap stack1 size: " << s1.size() << ",top: " << s1.top() << std::endl;
		std::cout << "after  swap stack2 size: " << s2.size() << ",top: " << s2.top() << RESET << std::endl;
		stack_test::operators();
		return (1);
	}


