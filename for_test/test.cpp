#include "for_test.hpp"
//start test --------------------------------- list ----------------------------------
void		default_list_tests()
{
	PRINT_YLW("--- default Constructor ---\n")
	ft::list<int>	test;
	TEST_LIST

	PRINT_YLW("--- push_back")
	test.push_back(0);
	test.push_back(10);
	test.push_back(21);
	test.push_back(42);
	TEST_LIST

	PRINT_YLW("--- pop_back")
	test.pop_back();
	test.pop_back();
	TEST_LIST

	PRINT_YLW("--- push_front")
	test.push_front(21);
	test.push_front(42);
	TEST_LIST

	PRINT_YLW("--- pop_front")
	test.pop_front();
	test.pop_front();
	TEST_LIST
}

void		iteratirs_tests()
{
	PRINT_YLW("\n ---| iteratirs_tests |---");
	std::string						tmp[] = {"one", "two", "Three"};
	{
	PRINT_YLW("--- origin iterator")
	std::list<std::string>			test(tmp, tmp + 3);
	TEST_ITER("iterator                   ", test)
	PRINT_BLU("reverse iterator           ") printValues(test.rbegin(), test.rend());
	*test.begin() = "Laka";			TEST_ITER("*test.begin() = \"Laka\"     ", test)
	*(++test.begin()) = "Shaka";	TEST_ITER("*(++test.begin()) = \"Shaka\"", test)
	PRINT("\n --- reverse ---");
	*test.rbegin() = "BOOM";		PRINT_BLU("*test.rbegin() = \"BOOM\"    ")
											printValues(test.rbegin(), test.rend());
	
	PRINT_YLW(" --- my iterator")
	ft::list<std::string>			test_my(tmp, tmp + 3);
	TEST_ITER("iterator                   ", test_my)
	PRINT_BLU("reverse iterator           ") printValues(test_my.rbegin(), test_my.rend());
	*test_my.begin() = "Laka";		TEST_ITER("*test.begin() = \"Laka\"     ", test_my)
	*(++test_my.begin()) = "Shaka";	TEST_ITER("*(++test.begin()) = \"Shaka\"", test_my)
	PRINT("\n --- reverse ---");
	*test_my.rbegin() = "BOOM";		PRINT_BLU("*test.rbegin() = \"BOOM\"    ")
											printValues(test_my.rbegin(), test_my.rend());
	}
	{
	std::list<std::string> const				test(tmp, tmp + 3);
	ft::list<std::string> const					test_my(tmp, tmp + 3);
	PRINT_YLW(" --- const_iterator")
	std::list<std::string>::const_iterator		bit(test.begin());
	std::list<std::string>::const_iterator		eit = test.end();
	PRINT_BLU(" origin iterator ") printValues(bit, eit);
		// *test.begin() = "BOOM";		PRINT_BLU(" *bit = \"BOOM\" ") printValues(bit, eit);
		// *bit = "BOOM";		PRINT_BLU(" *bit = \"BOOM\" ") printValues(bit, eit); }
	ft::list<std::string>::const_iterator		bit_my(test_my.begin());
	ft::list<std::string>::const_iterator		eit_my = test_my.end();
	PRINT_BLU(" my iterator     ") printValues(bit_my, eit_my);
		// *test_my.begin() = "BOOM";	PRINT_BLU(" *bit_my = \"BOOM\" ") printValues(bit_my, eit_my);
		// *bit_my = "BOOM";	PRINT_BLU(" *bit_my = \"BOOM\" ") printValues(bit_my, eit_my); }

	PRINT_YLW(" --- reverse_const_iterator")
	std::list<std::string>::const_reverse_iterator		rbit(test.rbegin());
	std::list<std::string>::const_reverse_iterator		reit = test.rend();
	PRINT_BLU(" origin iterator ") printValues(rbit, reit);
		// *test.begin() = "BOOM";		PRINT_BLU(" *bit = \"BOOM\" ") printValues(bit, eit);
		// *bit = "BOOM";		PRINT_BLU(" *bit = \"BOOM\" ") printValues(bit, eit);
	ft::list<std::string>::const_reverse_iterator		rbit_my(test_my.rbegin());
	ft::list<std::string>::const_reverse_iterator		reit_my = test_my.rend();
	PRINT_BLU(" my iterator     ") printValues(rbit_my, reit_my);
		// *test_my.begin() = "BOOM";	PRINT_BLU(" *bit_my = \"BOOM\" ") printValues(bit_my, eit_my);
		// *bit_my = "BOOM";	PRINT_BLU(" *bit_my = \"BOOM\" ") printValues(bit_my, eit_my);
	}
	{
	PRINT_YLW(" --- const_iterator 2")
	std::list<int>	l1(5, 21);
	ft::list<int>	l2(5, 21);
	// std::list<int>	l1;
	// ft::list<int>	l2;

	std::list<int>::iterator		i1 = l1.begin();
	std::list<int>::const_iterator	ci1 = l1.begin();
	// std::list<int>::reverse_iterator		i1 = l1.rbegin();
	// std::list<int>::const_reverse_iterator	ci1 = l1.rbegin();
	PRINT("\nstd:\nlist_test --- " << *i1 << " - " << *ci1);
	*i1 = 5;
	// *ci1 = 10; // const
	ci1++;
	PRINT("list_test --- " << *i1 << " - " << *ci1);

	ft::list<int>::iterator			i2 = l2.begin();
	ft::list<int>::const_iterator	ci2 = l2.begin();
	// ft::list<int>::reverse_iterator			i2 = l2.rbegin();
	// ft::list<int>::const_reverse_iterator	ci2 = l2.rbegin();
	PRINT("\nft:\nlist_test --- " << *i2 << " - " << *ci2);
	*i2 = 5;
	// *ci2 = 10; // const
	ci2++;
	// i2.
	PRINT("list_test --- " << *i2 << " - " << *ci2);
	}
}

void		capacity_tests()
{
	PRINT_YLW("\n ---| capacity_tests |---");
	int				arr[] = {21, 42, 36, 76, 5, 0};
	ft::list<int>	test(arr, arr + 6);
	TEST_LIST

	PRINT_YLW("--- empty(no emtpy)")
	TEST_LIST
	PRINT(CLR_GRN "list is empty?" CLR_END);
	test.empty() == true ? PRINT("--> TRUE") : PRINT("--> FALSE");

	PRINT_YLW("--- empty(empty)")
	test.pop_front();
	test.pop_back();
	TEST_LIST
	PRINT(CLR_GRN "list is empty?" CLR_END);
	test.empty() == true ? PRINT("--> TRUE") : PRINT("--> FALSE");

	PRINT_YLW("--- size")
	PRINT(test.size());

	PRINT_YLW("--- max size")
	PRINT(test.max_size());
}

void		element_access_tests()
{
	PRINT_YLW("\n ---| element_access_tests |---")
	int				arr[] = {21, 42, 36, 76, 5, 0};
	ft::list<int>	test(arr, arr + 6);
	TEST_LIST

	PRINT_YLW("--- front")
	PRINT("-->" << test.front());

	PRINT_YLW("--- back")
	PRINT("-->" << test.back());
}

void		modifiers_tests()
{
	PRINT_YLW("\n ---| modifiers_tests |---")
	{
		PRINT_YLW("--- fill Constructors")
		PRINT(" --- create new 'test(5, 21)'");
		ft::list<int>	test(static_cast<size_t>(5), 21);
		TEST_LIST

		PRINT_YLW("--- test_copy")
		PRINT(" --- create new 'test_copy(test)'");
		ft::list<int>	test_copy(test);
		TEST(test_copy)

		PRINT_YLW("--- test_operator")
		PRINT(" --- create new 'test_operator(5, 42)'");
		ft::list<int>	test_operator(5, 42);
		TEST(test_operator)
		PRINT(" --- 'test_operator = test_copy'");
		test_operator = test_copy;
		TEST(test_operator)

		PRINT_YLW("--- resize")
		TEST_LIST
		PRINT(" --- 'resize(2)'");
		test.resize(2);
		TEST_LIST
		PRINT(" --- 'test.resize(4, 48)'");
		test.resize(4, 48);
		TEST_LIST
		PRINT(" --- 'test.resize(6)'");
		test.resize(6);
		TEST_LIST

		PRINT_YLW("--- swap")
		PRINT(" --- 'test' and 'test_copy'");
		TEST_LIST
		TEST(test_copy)
		PRINT("\n --- 'test.swap(test_copy)'");
		test.swap(test_copy);
		TEST_LIST
		TEST(test_copy)

		PRINT_YLW("--- erase")
		test.clear();
		TEST_LIST

		PRINT_YLW("--- wrong pop_back")
		test.pop_front();
		test.pop_back();
		TEST_LIST
	}
	PRINT(CLR_PRP "\n\n --- --- next test --- ---\n" CLR_END); //-----------
	{
		int				tmp[] = {21, 5, 21, 31, 21, 138, 1, 21};
		ft::list<int>	test(tmp, tmp + 8);

		PRINT_YLW("--- assign")
		ft::list<int>	test_copy;
		TEST(test_copy);
		test_copy.assign(test.begin(),test.end());
		PRINT_BLU("test_copy.assign(test.begin(),test.end())") TEST(test_copy);
		test_copy.assign(7,100);
		PRINT_BLU("test_copy.assign(7,100)") TEST(test_copy);

		PRINT_YLW("--- erase")
		TEST_LIST
		test.erase(++test.begin());
		PRINT_BLU("test.erase(++test.begin())") TEST_LIST
		test.erase(test.begin(), --test.end());
		PRINT_BLU("test.erase(test.begin(), --test.end())") TEST_LIST

		PRINT_YLW("--- insert")
		TEST_LIST
		PRINT_BLU("test.insert(test.begin(), 777)")
		std::cout << "insert return: " << *(test.insert(test.begin(), 777));
		TEST_LIST
		test.insert(test.begin(), 2, 44);
		PRINT_BLU("test.insert(test.begin(), 2, 44)") TEST_LIST
		ft::list<int>::iterator		it = ++(++(++test_copy.begin()));
		test.insert(++test.begin(), test_copy.begin(), it);
		PRINT_BLU("test.insert(++test.begin(), test_copy.begin(), it)") TEST_LIST
	}
	PRINT(CLR_PRP "\n\n --- --- next test --- ---\n" CLR_END); //-----------
	{
		PRINT_YLW("--- std::string test")
		std::string				tmp[] = {"a", "A", "B", "b", "c", "C", "D", "d"};
		ft::list<std::string>	test(tmp, tmp + 8);
		TEST_LIST
		
		PRINT(" --- sort");
		test.sort();
		printValues(test.begin(), test.end());
		
		PRINT(" --- sort(Compare comp)");
		test.sort(compare_nocase);
			printValues(test.begin(), test.end());

		PRINT_YLW("--- std::string test_copy")
		ft::list<std::string>	test_copy;
		test_copy.push_back("one");
		test_copy.push_back("two");
		test_copy.push_back("Three");
		TEST(test_copy)
	
		PRINT(" --- sort");
		test_copy.sort();
		printValues(test_copy.begin(), test_copy.end());
		
		PRINT(" --- sort(Compare comp)");
		test_copy.sort(compare_nocase);
		printValues(test_copy.begin(), test_copy.end());
	}
}

void		operations_tests()
{
	PRINT_YLW("\n---| operations_tests |---")
	{
		PRINT_YLW("--- splice")
		ft::list<int>				test, test_copy;
		ft::list<int>::iterator		it;
		for (int i=1; i<=4; ++i)
			test.push_back(i);
		for (int i=1; i<=3; ++i)
			test_copy.push_back(i*10);
		TEST_LIST TEST(test_copy)

		PRINT_BLU("test.splice(it, test_copy)")
		it = ++test.begin();
		test.splice(it, test_copy);
		TEST_LIST TEST(test_copy)

		PRINT_BLU("test.splice(it, test_copy)")
		test_copy.splice(test_copy.begin(),test, it);
		TEST_LIST TEST(test_copy)

		PRINT_BLU("test.splice(test.begin(), test, it, test.end())")
		it = test.begin();
		++(++(++it));
		test.splice(test.begin(), test, it, test.end());
		TEST_LIST
	}
	{
		PRINT_YLW("--- 'remove(21)'")
		int				tmp[] = {21, 5, 21, 31, 21, 138, 1, 21};
		ft::list<int>	test(tmp, tmp + 8);
		TEST_LIST
		test.remove(21);
		TEST_LIST
	}
	{
		PRINT_YLW("--- remove_if")
		int				tmp[] = {15, 36, 7, 17, 20, 39, 4, 1};
		ft::list<int>	test(tmp, tmp + 8);
		TEST_LIST
		test.remove_if (single_digit);
		TEST_LIST
		test.remove_if (is_odd());
		TEST_LIST
	}
	{
		PRINT_YLW("--- unique")
		double				tmp[] = { 12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25 };
		ft::list<double>	test(tmp, tmp + 10);
		std::list<double>	orig(tmp, tmp + 10);
		TEST(orig) TEST_LIST PRINT("");
		orig.sort();
		test.sort();
		TEST_ITER("orig", orig) TEST_ITER("test", test) PRINT("");
		orig.unique();
		test.unique();
		TEST_ITER("orig", orig) TEST_ITER("test", test) PRINT("");
		orig.unique(same_integral_part);
		test.unique(same_integral_part);
		TEST_ITER("orig", orig) TEST_ITER("test", test) PRINT("");
		orig.unique(is_near());
		test.unique(is_near());
		TEST_ITER("orig", orig) TEST_ITER("test", test) PRINT("");
	}
	{
		PRINT_YLW("--- merge")
		double				tmp1[] = {3.1, 2.2, 2,9};
		double				tmp2[] = {3.7, 7.1, 1.4};
		std::list<double>	first(tmp1, tmp1 + 3), second(tmp2, tmp2 + 3);
		ft::list<double>	f_my(tmp1, tmp1 + 3), s_my(tmp2, tmp2 + 3);

		first.sort();
		second.sort();
		f_my.sort();
		s_my.sort();
		TEST_ITER("first ", first)
		TEST_ITER("f_my  ", f_my)
		TEST_ITER("second", second)
		TEST_ITER("s_my  ", s_my)

		PRINT("");
		first.merge(second);
		f_my.merge(s_my);
		TEST_ITER("first ", first)
		TEST_ITER("f_my  ", f_my)
		TEST_ITER("second", second)
		TEST_ITER("s_my  ", s_my)

		PRINT("");
		second.push_back (2.1);
		first.merge(second,mycomparison);
		s_my.push_back (2.1);
		f_my.merge(s_my,mycomparison);
		TEST_ITER("first ", first)
		TEST_ITER("f_my  ", f_my)
		TEST_ITER("second", second)
		TEST_ITER("s_my  ", s_my)
	}
	{
		PRINT_YLW("--- sort")
		int				tmp[] = {21, 5, 31, 138, 1, 21};
		ft::list<int>	test(tmp, tmp + 8);
		TEST_LIST
		test.sort();
		TEST_LIST
	}
	{
		PRINT_YLW("--- reverse")
		ft::list<int>	test;
		for (int i=1; i<10; ++i) test.push_back(i);
		TEST_LIST
		test.reverse();
		TEST_LIST
	}
}

void		non_member_function_overloads()
{
	PRINT_YLW("\n---| non_member_function_overloads| ---")
	{
		PRINT_YLW("--- relational operators")
		int				arr1[] = {10, 20, 30};
		int				arr2[] = {30, 20, 10};
		std::list<int>	a(arr1, arr1 + 3);
		std::list<int>	b(arr1, arr1 + 3);
		std::list<int>	c(arr2, arr2 + 3);

		ft::list<int>	a_my(arr1, arr1 + 3);
		ft::list<int>	b_my(arr1, arr1 + 3);
		ft::list<int>	c_my(arr2, arr2 + 3);
		PRINT("a==b");
		if (a==b)		std::cout << "a and b are equal\n";
		if (a_my==b_my)	std::cout << "a and b are equal\n" << std::endl;
		PRINT("b!=c");
		if (b!=c)		std::cout << "b and c are not equal\n";
		if (b_my!=c_my)	std::cout << "b and c are not equal\n" << std::endl;
		PRINT("b<c");
		if (b<c)		std::cout << "b is less than c\n";
		if (b_my<c_my)	std::cout << "b is less than c\n" << std::endl;
		PRINT("c>b");
		if (c>b)		std::cout << "c is greater than b\n";
		if (c_my>b_my)	std::cout << "c is greater than b\n" << std::endl;
		PRINT("a<=b");
		if (a<=b)		std::cout << "a is less than or equal to b\n";
		if (a_my<=b_my)	std::cout << "a is less than or equal to b\n" << std::endl;
		PRINT("a>=b");
		if (a>=b)		std::cout << "a is greater than or equal to b\n";
		if (a_my>=b_my)	std::cout << "a is greater than or equal to b\n" << std::endl;
	}
	{
		PRINT_YLW("--- swap")
		std::list<int>	foo (3,100);
		std::list<int>	bar (5,200);

		ft::list<int>	f_my (3,100);
		ft::list<int>	b_my (5,200);

		std::swap(foo, bar);
		ft::swap(f_my, b_my);
		TEST_ITER("foo ", foo) TEST_ITER("f_my", f_my)
		TEST_ITER("bar ", bar) TEST_ITER("b_my", b_my)
	}
}
//end test ----------------------------------- list ----------------------------------

//start test --------------------------------- vector ---------------------------------
void		vector_base()
{
	PRINT_YLW("\n---| vector base tests | ---")
	// ------- origin vector ---------------
	std::vector<int>				tmp1;
	std::vector<std::vector<int> >	tmp1x;
	// ------- vector ft ---------------
	ft::vector<int>					tmp2;
	ft::vector<ft::vector<int> >	tmp2x;

	{
		PRINT_YLW("-- push_back");// ------- push_back ---------------
		
		PRINT_BLU("std")	
		tmp1.push_back(42);		TEST_VECTOR_HEAD(tmp1)	ENDL
		tmp1.push_back(21);		TEST_VECTOR_HEAD(tmp1)	ENDL
		tmp1.push_back(0);		TEST_VECTOR_HEAD(tmp1)	ENDL
		tmp1.push_back(1);		TEST_VECTOR_HEAD(tmp1)	ENDL
		tmp1.push_back(2);		TEST_VECTOR_HEAD(tmp1)	ENDL
		tmp1.push_back(3);		TEST_VECTOR_HEAD(tmp1)	ENDL
		TEST_VECTOR_VAL(tmp1)

		PRINT_BLU("\nft")
		tmp2.push_back(42);		TEST_VECTOR_HEAD(tmp2)	ENDL
		tmp2.push_back(21);		TEST_VECTOR_HEAD(tmp2)	ENDL
		tmp2.push_back(0);		TEST_VECTOR_HEAD(tmp2)	ENDL
		tmp2.push_back(1);		TEST_VECTOR_HEAD(tmp2)	ENDL
		tmp2.push_back(2);		TEST_VECTOR_HEAD(tmp2)	ENDL
		tmp2.push_back(3);		TEST_VECTOR_HEAD(tmp2)	ENDL
		TEST_VECTOR_VAL(tmp2)
	}
	{
		PRINT_YLW("-- operator* and iterator++");// ------- operator* and iterator++
		PRINT_BLU("std")		TEST_VECTOR(tmp1)
		PRINT_BLU("ft")			TEST_VECTOR(tmp2)
	}
	{
		PRINT_YLW("-- vector in vector");// ------- vector in vector ---------------
		
		PRINT_BLU("std")
		tmp1x.push_back(tmp1);
		TEST_VECTOR_HEAD(tmp1x)
		TEST_VECTOR_VAL(tmp1x[0])

		PRINT_BLU("ft")
		// tmp1x.push_back(tmp2);
		TEST_VECTOR_HEAD(tmp2x)
		// TEST_VECTOR_VAL(tmp2x[0])
	}
	{
		PRINT_YLW("\n-- pop_back");// ------- pop_back ---------------

		PRT_BLU("std")		TEST_VECTOR(tmp1)
		PRT_BLU("ft ")		TEST_VECTOR(tmp2)

		PRINT_BLU("3 pop_back")
		tmp1.pop_back();	tmp2.pop_back();
		tmp1.pop_back();	tmp2.pop_back();
		tmp1.pop_back();	tmp2.pop_back();
		PRT_BLU("std")		TEST_VECTOR(tmp1)
		PRT_BLU("ft ")		TEST_VECTOR(tmp2)

		PRINT_BLU("3 pop_back again")
		tmp1.pop_back();	tmp2.pop_back();
		tmp1.pop_back();	tmp2.pop_back();
		tmp1.pop_back();	tmp2.pop_back();
		PRT_BLU("std")		TEST_VECTOR(tmp1)
		PRT_BLU("ft ")		TEST_VECTOR(tmp2)
		// tmp1.pop_back(); // if len == 0 and pop_back again, len = 18446744073709551615
	}
	{
		PRINT_YLW("\n-- constructing vectors");// ------- constructing vectors ---------------
		
		PRINT_BLU("- ft")

		ft::vector<int> first;									// empty vector of ints
		ft::vector<int> second(4,100);							// four ints with value 100
		ft::vector<int> third(second.begin(),second.end());		// iterating through second
		ft::vector<int> fourth(third);							// a copy of third

		// // the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		PRT_BLU("1) empty vector of ints    ")		TEST_VECTOR(first)
		PRT_BLU("2) four ints with value 100")		TEST_VECTOR(second)
		PRT_BLU("3) iterating through second")		TEST_VECTOR(third)
		PRT_BLU("4) a copy of third         ")		TEST_VECTOR(fourth)
		PRT_BLU("5) from array {16,2,77,29} ")		TEST_VECTOR(fifth)
	}
	{
		ENDL	PRINT_BLU("- std")

		std::vector<int> first;									// empty vector of ints
		std::vector<int> second(4,100);							// four ints with value 100
		std::vector<int> third(second.begin(),second.end());		// iterating through second
		std::vector<int> fourth(third);							// a copy of third

		// // the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		PRT_BLU("1) empty vector of ints    ")		TEST_VECTOR(first)
		PRT_BLU("2) four ints with value 100")		TEST_VECTOR(second)
		PRT_BLU("3) iterating through second")		TEST_VECTOR(third)
		PRT_BLU("4) a copy of third         ")		TEST_VECTOR(fourth)
		PRT_BLU("5) from array {16,2,77,29} ")		TEST_VECTOR(fifth)
	}
	{
		PRINT_YLW("\n-- operator= / Assign content");// ------- operator= / Assign content ---------------

		std::vector<int> first (3,0);
		std::vector<int> second (5,0);

		ft::vector<int> ft_first (3,0);
		ft::vector<int> ft_second (5,0);

		PRINT_BLU("- create first(3,0)")
		PRT_BLU("std")		TEST_VECTOR(first)
		PRT_BLU("ft ")		TEST_VECTOR(ft_first)

		PRINT_BLU("- create second(5,0)")
		PRT_BLU("std")		TEST_VECTOR(second)
		PRT_BLU("ft ")		TEST_VECTOR(ft_second)

		PRINT_BLU("- second = first")
		second = first;
		ft_second = ft_first;
		PRT_BLU("std")		TEST_VECTOR(second)
		PRT_BLU("ft ")		TEST_VECTOR(ft_second)

		PRINT_BLU("- first = ft::vector<int>()")
		first = std::vector<int>();
		ft_first = ft::vector<int>();
		PRT_BLU("std")		TEST_VECTOR(first)
		PRT_BLU("ft ")		TEST_VECTOR(ft_first)

		PRINT_BLU("- add in second / first = second")
		second.push_back(21);
		second.push_back(42);
		ft_second.push_back(21);
		ft_second.push_back(42);
		first = second;
		ft_first = ft_second;
		PRT_BLU("std")		TEST_VECTOR(first)
		PRT_BLU("ft ")		TEST_VECTOR(ft_first)
	}
}
// void		iteratirs_vector()
// {
// 	PRINT_YLW("\n---| iteratirs_vector | ---")
// }
void		capacity_vector()
{
	PRINT_YLW("\n---| capacity_vector | ---")

	std::vector<int>				tmp;
	for (int i=1;i<10;i++)
		tmp.push_back(i);
	TEST_VECTOR(tmp)

	ft::vector<int>					ft_tmp;
	for (int i=1;i<10;i++)
		ft_tmp.push_back(i);
	TEST_VECTOR(ft_tmp)
	
	{
		PRINT(CLR_YLW "\n-- size" CLR_END);// ------- size ---------------
		PRT_BLU("std")	PRINT(tmp.size());
		PRT_BLU("ft ")	PRINT(ft_tmp.size());
	}
	{
		PRINT(CLR_YLW "\n-- max.size()" CLR_END);// ------- max.size() ---------------
		PRT_BLU("std")	PRINT("max_size - " << tmp.max_size());
		PRT_BLU("ft ")	PRINT("max_size - " << ft_tmp.max_size());
	}
	{
		PRINT(CLR_YLW "\n-- resize()" CLR_END);// ------- resize() ---------------

		PRT_BLU("std")		TEST_VECTOR(tmp)		
		PRT_BLU("ft ")		TEST_VECTOR(ft_tmp)

		PRINT_BLU("- resize(5)")
		PRT_BLU("std")		tmp.resize(5);			TEST_VECTOR(tmp)
		PRT_BLU("ft ")		ft_tmp.resize(5);		TEST_VECTOR(ft_tmp)

		PRINT_BLU("- resize(8,100)")
		PRT_BLU("std")		tmp.resize(8,100);		TEST_VECTOR(tmp)
		PRT_BLU("ft ")		ft_tmp.resize(8,100);	TEST_VECTOR(ft_tmp)

		PRINT_BLU("- resize(12)")
		PRT_BLU("std")		tmp.resize(12);			TEST_VECTOR(tmp)
		PRT_BLU("ft ")		ft_tmp.resize(12);		TEST_VECTOR(ft_tmp)
	}
	{
		PRINT(CLR_YLW "\n-- capacity" CLR_END);// ------- capacity ---------------
		PRT_BLU("std")	PRINT(tmp.capacity());
		PRT_BLU("ft ")	PRINT(ft_tmp.capacity());
	}
	{
		PRINT(CLR_YLW "\n-- empty vector" CLR_END);// ------- empty vector ---------------
		PRT_BLU("std")	PRINT(tmp.empty());
		PRT_BLU("ft ")	PRINT(ft_tmp.empty());

		PRINT_BLU("\n- clear()")
		tmp.clear();
		ft_tmp.clear();
		PRT_BLU("std")	PRINT(tmp.empty());
		PRT_BLU("ft ")	PRINT(ft_tmp.empty());
	}
	{
		PRINT(CLR_YLW "\n-- reserve" CLR_END);// ------- reserve ---------------
		std::vector<int>::size_type sz;

		std::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
		ENDL
		std::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}
		ENDL
	{
		ft::vector<int>::size_type sz;

		ft::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
		ENDL
		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}
}
void		element_access_vector()
{
	PRINT_YLW("\n---| element_access_vector | ---")
}
void		modifiers_vector()
{
	PRINT_YLW("\n---| modifiers_vector | ---")
}
void		non_member_function_overloads_vector()
{
	PRINT_YLW("\n---| non_member_function_overloads_vector | ---")
}
//end test ----------------------------------- vector ---------------------------------
