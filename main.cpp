#include <unistd.h>

// #include <iostream>
// #include <memory>
// #include <string>
// #include <cstddef>
// #include <limits>
// #include <typeinfo>
// #include <iterator>

#include "list/List.hpp"
#include <list>
#include <iterator>

#define CLR_GRN "\033[0;32m"
#define CLR_YLW "\033[0;33m"
#define CLR_BLU "\033[0;34m"
#define CLR_RED "\033[0;31m"
#define CLR_PRP "\033[0;35m"
#define CLR_END "\033[0m"

#define PRT(x) std::cout << CLR_BLU << x << CLR_END << " - ";
#define PRINT(x) std::cout << x << std::endl
#define TEST_SIZE(x) std::cout << "Size = " << x.size() << CLR_GRN " | " CLR_END;
#define TEST_HB(x) PRINT( "Head: " << x.front() << " - " << x.back() << " :Back" );
#define TEST_LIST TEST_SIZE(test) TEST_HB(test) printValues(test.begin(), test.end());
#define TEST(x) TEST_SIZE(x) TEST_HB(x) printValues(x.begin(), x.end());
#define TEST_ITER(x,y) PRT(x) printValues(y.begin(), y.end());

template < typename iterator >
void			printValues(iterator begin, iterator end)
{
	std::cout << CLR_GRN "All Values of list:" CLR_END "\nTail -> ";
	for (; begin != end; begin++)
		std::cout << *begin << " -> ";
	std::cout << "Tail" << std::endl;
}

// std::list<int>::iterator::pointer // iterator

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int	i = 0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

void		list_test()
{
	PRINT(CLR_PRP "\n ___---\\ List testing /---___" CLR_END); //-----------
	{
		PRINT(CLR_YLW "\n --- default Constructors ---\n" CLR_END);
		ft::List<int>	test;
			TEST_LIST
		PRINT(CLR_YLW "\n --- push_back ---" CLR_END);
		test.push_back(0);
		test.push_back(10);
		test.push_back(21);
		test.push_back(42);
			TEST_LIST

		PRINT(CLR_YLW "\n --- pop_back ---" CLR_END);
		test.pop_back();
		test.pop_back();
			TEST_LIST

		PRINT(CLR_YLW "\n --- push_front ---" CLR_END);
		test.push_front(21);
		test.push_front(42);
			TEST_LIST

		PRINT(CLR_YLW "\n --- pop_front ---" CLR_END);
		test.pop_front();
		test.pop_front();
			TEST_LIST

		PRINT(CLR_YLW "\n --- empty(no emtpy) ---" CLR_END);
			TEST_LIST
		PRINT(CLR_GRN "List is empty?" CLR_END);
		test.empty() == true ? PRINT("    TRUE") : PRINT("    FALSE");

		PRINT(CLR_YLW "\n --- empty(empty) ---" CLR_END);
		test.pop_front();
		test.pop_back();
			TEST_LIST
		PRINT(CLR_GRN "List is empty?" CLR_END);
		test.empty() == true ? PRINT("    TRUE") : PRINT("    FALSE");

		PRINT(CLR_YLW "\n --- max size ---" CLR_END);
		PRINT(test.max_size());
	}
PRINT(CLR_PRP "\n\n --- --- next test --- ---\n" CLR_END); //-----------
	{
		PRINT(CLR_YLW "\n --- fill Constructors ---" CLR_END);
		PRINT(" --- create new 'test(5, 21)' ---");
		ft::List<int>	test(5, 21);
			TEST_LIST

		PRINT(CLR_YLW "\n --- test_copy ---" CLR_END);
		PRINT(" --- create new 'test_copy(test)' ---");
		ft::List<int>	test_copy(test);
			TEST(test_copy)

		PRINT(CLR_YLW "\n --- test_operator ---" CLR_END);
		PRINT(" --- create new 'test_operator(5, 42)' ---");
		ft::List<int>	test_operator(5, 42);
			TEST(test_operator)
		PRINT(" --- 'test_operator = test_copy' ---");
		test_operator = test_copy;
			TEST(test_operator)

		PRINT(CLR_YLW "\n --- resize ---" CLR_END);
			TEST_LIST
		PRINT(" --- 'resize(2)' ---");
		test.resize(2);
			TEST_LIST
		PRINT(" --- 'test.resize(4, 48)' ---");
		test.resize(4, 48);
			TEST_LIST
		PRINT(" --- 'test.resize(6)' ---");
		test.resize(6);
			TEST_LIST

		PRINT(CLR_YLW "\n --- swap ---" CLR_END);
		PRINT(" --- 'test' and 'test_copy' ---");
			TEST_LIST
			TEST(test_copy)
		PRINT("\n --- 'test.swap(test_copy)' ---");
		test.swap(test_copy);
			TEST_LIST
			TEST(test_copy)

		PRINT(CLR_YLW "\n --- erase ---" CLR_END);
		test.clear();
			TEST_LIST

		PRINT(CLR_YLW "\n --- wrong pop_back ---" CLR_END);
		test.pop_front();
		test.pop_back();
			TEST_LIST
	}
PRINT(CLR_PRP "\n\n --- --- next test --- ---\n" CLR_END); //-----------
	{
		ft::List<int>	test;
		ft::List<int>	test_copy;

	PRINT(CLR_YLW "\n --- 'test.remove(21)' ---" CLR_END);
		test.push_back(21);
		test.push_back(5);
		test.push_back(21);
		test.push_back(31);
		test.push_back(21);
		test.push_back(138);
		test.push_back(1);
		test.push_back(21);
		test.push_front(21);
			TEST_LIST
		test.remove(21);
			TEST_LIST

	PRINT(CLR_YLW "\n --- sort ---" CLR_END);
		test.sort();
			TEST_LIST

	PRINT(CLR_YLW "\n --- assign ---" CLR_END);
		test_copy.assign(test.begin(),test.end());
			PRT("test_copy.assign(test.begin(),test.end())") TEST(test_copy);
		test_copy.assign(7,100);
			PRT("test_copy.assign(7,100)") TEST(test_copy);

	PRINT(CLR_YLW "\n --- erase ---" CLR_END);
		test.erase(++test.begin());
			TEST_LIST
		test.erase(test.begin(), --test.end());
			TEST_LIST
	}
// PRINT(CLR_PRP "\n\n --- --- next test --- ---\n" CLR_END); //-----------
	// {
	// PRINT(CLR_YLW "\n --- std::string test ---" CLR_END);
	// 	ft::List<std::string>	test;
	// 	test.push_back("a");
	// 	test.push_back("A");
	// 	test.push_back("B");
	// 	test.push_back("b");
	// 	test.push_back("c");
	// 	test.push_back("C");
	// 	test.push_back("D");
	// 	test.push_back("d");
	// 	test.size();
	// 		TEST_LIST
	// PRINT(CLR_YLW " --- sort ---" CLR_END);
	// 	test.sort();
	// 		printValues(test.begin(), test.end());
	// PRINT(CLR_YLW " --- sort(Compare comp) ---" CLR_END);
	// 	test.sort(compare_nocase);
	// 		printValues(test.begin(), test.end());

	// PRINT(CLR_YLW "\n --- std::string test_copy ---" CLR_END);
	// 	ft::List<std::string>	test_copy;
	// 	test_copy.push_back("one");
	// 	test_copy.push_back("two");
	// 	test_copy.push_back("Three");
	// 		TEST(test_copy)
	// PRINT(CLR_YLW " --- sort ---" CLR_END);
	// 	test_copy.sort();
	// 		printValues(test_copy.begin(), test_copy.end());
	// PRINT(CLR_YLW " --- sort(Compare comp) ---" CLR_END);
	// 	test_copy.sort(compare_nocase);
	// 		printValues(test_copy.begin(), test_copy.end());
	// }
// PRINT(CLR_PRP "\n\n --- --- testing iterator --- ---\n" CLR_END);
	// {
	// PRINT(CLR_YLW "\n --- origin iterator ---" CLR_END);
	// 	std::list<std::string>		test;
	// 	test.push_back("one");
	// 	test.push_back("two");
	// 	test.push_back("Three");
	// 		TEST_ITER("iterator",test)
	// 		PRT("reverse iterator") printValues(test.rbegin(), test.rend());
	// 	*test.begin() = "Laka";
	// 		TEST_ITER("*test.begin() = \"Laka\"",test)
	// 	*(++test.begin()) = "Shaka";
	// 		TEST_ITER("*(++test.begin()) = \"Shaka\"",test)
	// 	*test.rbegin() = "BOOM";
	// 		PRT("*test.rbegin() = \"BOOM\"") printValues(test.rbegin(), test.rend());
	// PRINT(CLR_YLW " --- my iterator ---" CLR_END);
	// 	ft::List<std::string>		test_my;
	// 	test_my.push_back("one");
	// 	test_my.push_back("two");
	// 	test_my.push_back("Three");
	// 		TEST_ITER("iterator",test_my)
	// 		PRT("reverse iterator") printValues(test_my.rbegin(), test_my.rend());
	// 	*test_my.begin() = "Laka";
	// 		TEST_ITER("*test.begin() = \"Laka\"",test_my)
	// 	*(++test_my.begin()) = "Shaka";
	// 		TEST_ITER("*(++test.begin()) = \"Shaka\"",test_my)
	// 	*test_my.rbegin() = "BOOM";
	// 		PRT("*test.rbegin() = \"BOOM\"") printValues(test_my.rbegin(), test_my.rend());
	// PRINT(CLR_YLW " --- const_iterator ---" CLR_END);
	// 	std::list<std::string>::const_iterator		bit(test.begin());
	// 	std::list<std::string>::const_iterator		eit = test.end();
	// 		PRT(" origin iterator ") printValues(bit, eit);
	// 	// ft::List<std::string>::const_iterator		bit_my(test_my.begin());
	// 	// ft::List<std::string>::const_iterator		eit_my = test_my.end();
	// 	// 	PRT(" my iterator ") printValues(bit_my, eit_my);
	// }
}
// ---------------------------------------------------------------------
void		ft_wait()
{
	PRINT("\n10 seconds to complete the test\n...");
	sleep(5);
	for (int i = 5; i != 1; sleep(1))
		PRINT(i-- << " seconds left");
	PRINT("1 second left");
	sleep(1);
}

int			main()
{
	list_test();
	ft_wait();
	PRINT(CLR_PRP "\n   --- \\End of testing/ ---\n" CLR_END);
	return 0; 
}