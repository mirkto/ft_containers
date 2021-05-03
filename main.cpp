#include "for_tests.hpp"

void				list_test();

//start test ----------------------------------------------------------------
void		default_list_tests()
{
	PRINT_YLW("\n --- default Constructor ---\n")
	ft::list<int>	test;
	TEST_LIST

	PRINT_YLW("\n --- push_back ---")
	test.push_back(0);
	test.push_back(10);
	test.push_back(21);
	test.push_back(42);
	TEST_LIST

	PRINT_YLW("\n --- pop_back ---")
	test.pop_back();
	test.pop_back();
	TEST_LIST

	PRINT_YLW("\n --- push_front ---")
	test.push_front(21);
	test.push_front(42);
	TEST_LIST

	PRINT_YLW("\n --- pop_front ---")
	test.pop_front();
	test.pop_front();
	TEST_LIST
}

void		iteratirs_tests()
{
	PRINT_YLW("\n\n --- iteratirs_tests ---\n");
	std::string						tmp[] = {"one", "two", "Three"};
	{
	PRINT_YLW("\n --- origin iterator ---")
	std::list<std::string>			test(tmp, tmp + 3);
	TEST_ITER("iterator                   ", test)
	PRINT_BLU("reverse iterator           ") printValues(test.rbegin(), test.rend());
	*test.begin() = "Laka";			TEST_ITER("*test.begin() = \"Laka\"     ", test)
	*(++test.begin()) = "Shaka";	TEST_ITER("*(++test.begin()) = \"Shaka\"", test)
	PRINT("\n --- reverse ---");
	*test.rbegin() = "BOOM";		PRINT_BLU("*test.rbegin() = \"BOOM\"    ")
											printValues(test.rbegin(), test.rend());
	
	PRINT_YLW(" --- my iterator ---")
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
	PRINT_YLW(" --- const_iterator ---")
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

	PRINT_YLW(" --- reverse_const_iterator ---")
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
}

void		capacity_tests()
{
	PRINT_YLW("\n\n --- capacity_tests---\n");
	int				arr[] = {21, 42, 36, 76, 5, 0};
	ft::list<int>	test(arr, arr + 6);
	TEST_LIST

	PRINT_YLW("\n --- empty(no emtpy) ---")
	TEST_LIST
	PRINT(CLR_GRN "list is empty?" CLR_END);
	test.empty() == true ? PRINT("--> TRUE") : PRINT("--> FALSE");

	PRINT_YLW("\n --- empty(empty) ---")
	test.pop_front();
	test.pop_back();
	TEST_LIST
	PRINT(CLR_GRN "list is empty?" CLR_END);
	test.empty() == true ? PRINT("--> TRUE") : PRINT("--> FALSE");

	PRINT_YLW("\n --- size ---")
	PRINT(test.size());

	PRINT_YLW("\n --- max size ---")
	PRINT(test.max_size());
}

void		element_access_tests()
{
	PRINT_YLW("\n --- element_access_tests ---")
	int				arr[] = {21, 42, 36, 76, 5, 0};
	ft::list<int>	test(arr, arr + 6);
	TEST_LIST

	PRINT_YLW("\n --- front ---")
	PRINT("-->" << test.front());

	PRINT_YLW("\n --- back ---")
	PRINT("-->" << test.back());
}

void		modifiers_tests()
{
	PRINT_YLW("\n --- modifiers_tests ---")
	{
		PRINT_YLW("\n --- fill Constructors ---")
		PRINT(" --- create new 'test(5, 21)' ---");
		ft::list<int>	test(static_cast<size_t>(5), 21);
		TEST_LIST

		PRINT_YLW("\n --- test_copy ---")
		PRINT(" --- create new 'test_copy(test)' ---");
		ft::list<int>	test_copy(test);
		TEST(test_copy)

		PRINT_YLW("\n --- test_operator ---")
		PRINT(" --- create new 'test_operator(5, 42)' ---");
		ft::list<int>	test_operator(5, 42);
		TEST(test_operator)
		PRINT(" --- 'test_operator = test_copy' ---");
		test_operator = test_copy;
		TEST(test_operator)

		PRINT_YLW("\n --- resize ---")
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

		PRINT_YLW("\n --- swap ---")
		PRINT(" --- 'test' and 'test_copy' ---");
		TEST_LIST
		TEST(test_copy)
		PRINT("\n --- 'test.swap(test_copy)' ---");
		test.swap(test_copy);
		TEST_LIST
		TEST(test_copy)

		PRINT_YLW("\n --- erase ---")
		test.clear();
		TEST_LIST

		PRINT_YLW("\n --- wrong pop_back ---")
		test.pop_front();
		test.pop_back();
		TEST_LIST
	}
	PRINT(CLR_PRP "\n\n --- --- next test --- ---\n" CLR_END); //-----------
	{
		int				tmp[] = {21, 5, 21, 31, 21, 138, 1, 21};
		ft::list<int>	test(tmp, tmp + 8);

		PRINT_YLW("\n --- assign ---")
		ft::list<int>	test_copy;
		TEST(test_copy);
		test_copy.assign(test.begin(),test.end());
		PRINT_BLU("test_copy.assign(test.begin(),test.end())") TEST(test_copy);
		test_copy.assign(7,100);
		PRINT_BLU("test_copy.assign(7,100)") TEST(test_copy);

		PRINT_YLW("\n --- erase ---")
		TEST_LIST
		test.erase(++test.begin());
		PRINT_BLU("test.erase(++test.begin())") TEST_LIST
		test.erase(test.begin(), --test.end());
		PRINT_BLU("test.erase(test.begin(), --test.end())") TEST_LIST

		PRINT_YLW("\n --- insert ---")
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
		PRINT_YLW("\n --- std::string test ---")
		std::string				tmp[] = {"a", "A", "B", "b", "c", "C", "D", "d"};
		ft::list<std::string>	test(tmp, tmp + 8);
		TEST_LIST
		
		PRINT(" --- sort ---");
		test.sort();
		printValues(test.begin(), test.end());
		
		PRINT(" --- sort(Compare comp) ---");
		test.sort(compare_nocase);
			printValues(test.begin(), test.end());

		PRINT_YLW("\n --- std::string test_copy ---")
		ft::list<std::string>	test_copy;
		test_copy.push_back("one");
		test_copy.push_back("two");
		test_copy.push_back("Three");
		TEST(test_copy)
	
		PRINT(" --- sort ---");
		test_copy.sort();
		printValues(test_copy.begin(), test_copy.end());
		
		PRINT(" --- sort(Compare comp) ---");
		test_copy.sort(compare_nocase);
		printValues(test_copy.begin(), test_copy.end());
	}
}

void		operations_tests()
{
	PRINT_YLW("\n --- operations_tests ---")
	{
		PRINT_YLW("\n --- splice ---")
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
		PRINT_YLW("\n --- 'remove(21)' ---")
		int				tmp[] = {21, 5, 21, 31, 21, 138, 1, 21};
		ft::list<int>	test(tmp, tmp + 8);
		TEST_LIST
		test.remove(21);
		TEST_LIST
	}
	{
		PRINT_YLW("\n --- remove_if ---")
		int				tmp[] = {15, 36, 7, 17, 20, 39, 4, 1};
		ft::list<int>	test(tmp, tmp + 8);
		TEST_LIST
		test.remove_if (single_digit);
		TEST_LIST
		test.remove_if (is_odd());
		TEST_LIST
	}
	{
		PRINT_YLW("\n --- unique ---")
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
		PRINT_YLW("\n --- merge ---")
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
		PRINT_YLW("\n --- sort ---")
		int				tmp[] = {21, 5, 31, 138, 1, 21};
		ft::list<int>	test(tmp, tmp + 8);
		TEST_LIST
		test.sort();
		TEST_LIST
	}
	{
		PRINT_YLW("\n --- reverse ---")
		ft::list<int>	test;
		for (int i=1; i<10; ++i) test.push_back(i);
		TEST_LIST
		test.reverse();
		TEST_LIST
	}
}

void		non_member_function_overloads()
{
	PRINT_YLW("\n --- non_member_function_overloads ---")
	{
		PRINT_YLW("\n --- relational operators ---")
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
		PRINT_YLW("\n --- swap ---")
		std::list<int>	foo (3,100);
		std::list<int>	bar (5,200);

		ft::list<int>	f_my (3,100);
		ft::list<int>	b_my (5,200);

		std::swap(foo, bar);
		ft::swap(f_my, b_my);
		TEST_ITER("foo: ", foo) TEST_ITER("f_my:", f_my)
		TEST_ITER("bar: ", bar) TEST_ITER("b_my:", b_my)
	}
}

void		list_test()
{
	PRINT_PRP("\n   ---| list testing |---");
	default_list_tests();
	iteratirs_tests();
	capacity_tests();
	element_access_tests();
	modifiers_tests();
	operations_tests();
	non_member_function_overloads();
}

//end test ---------------------------------------------------------------------
void		ft_wait()
{
	PRINT("\n10 seconds to complete the test\n...");
	sleep(5);
	for (int i = 5; i != 1; sleep(1))
		PRINT(i-- << " seconds left");
	PRINT("1 second left");
	sleep(1);
}

void		ft_test()
{
	std::list<int>	tmp1;
	ft::list<int>	tmp2;
	PRINT("org - " << tmp1.max_size() << "\nmy  - " << tmp2.max_size());
}

int			main()
{
	PRINT_PRP("\n ___---/ Start testing \\---___");
	list_test();
	PRINT_PRP("\n   ---\\ End of testing /---\n");
	// ft_test();
	ft_wait();
	return 0; 
}