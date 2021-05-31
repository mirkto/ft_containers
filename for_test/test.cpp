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

void		iterators_tests()
{
	PRINT_YLW("\n ---| iterators_tests |---");
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

		std::vector<int> first;
		std::vector<int> second(4,100);
		std::vector<int> third(second.begin(),second.end());
		std::vector<int> fourth(third);

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

void		iterators_vector()
{
	

	ft::vector<int>					ft_tmp;

	PRINT_YLW("\n---| iterators_vector | ---")
	{
		PRINT(CLR_YLW "\n-- begin" CLR_END);// ------- begin ---------------
		PRT_BLU("std")
		std::vector<int>	tmp;
		for (int i=1; i<=5; i++)
			tmp.push_back(i);

		for (std::vector<int>::iterator it = tmp.begin() ; it != tmp.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		PRT_BLU("ft ")
		ft::vector<int>	tmp;
		for (int i=1; i<=5; i++)
			tmp.push_back(i);

		for (ft::vector<int>::iterator it = tmp.begin() ; it != tmp.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		PRINT(CLR_YLW "\n-- end" CLR_END);// ------- end ---------------
		PRT_BLU("std")
		std::vector<int>	tmp;
		for (int i=1; i<=5; i++)
			tmp.push_back(i);

		for (std::vector<int>::iterator it = tmp.begin() ; it != tmp.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		PRT_BLU("ft ")
		ft::vector<int>	tmp;
		for (int i=1; i<=5; i++)
			tmp.push_back(i);

		for (ft::vector<int>::iterator it = tmp.begin() ; it != tmp.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		PRINT(CLR_YLW "\n-- rbegin" CLR_END);// ------- rbegin ---------------
		PRT_BLU("std")
		std::vector<int>	tmp(5);
		int i=0;
		std::vector<int>::reverse_iterator		rit = tmp.rbegin();
		for (; rit!= tmp.rend(); ++rit)
			*rit = ++i;

		for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		PRT_BLU("ft ")
		ft::vector<int>	tmp(5);
		int i=0;
		ft::vector<int>::reverse_iterator		rit = tmp.rbegin();
		for (; rit!= tmp.rend(); ++rit)
			*rit = ++i;

		for (ft::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		PRINT(CLR_YLW "\n-- rend" CLR_END);// ------- rend ---------------
		PRT_BLU("std")
		std::vector<int>	tmp(5);
		std::vector<int>::reverse_iterator		rit = tmp.rbegin();
		int i=0;
		for (rit = tmp.rbegin(); rit!= tmp.rend(); ++rit)
			*rit = ++i;

		for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		PRT_BLU("ft ")
		ft::vector<int>	tmp(5);
		ft::vector<int>::reverse_iterator		rit = tmp.rbegin();
		int i=0;
		for (rit = tmp.rbegin(); rit!= tmp.rend(); ++rit)
			*rit = ++i;

		for (ft::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}

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
		PRINT_BLU("std")
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
	{
		PRINT_BLU("\nft")
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

	PRINT(CLR_YLW "\n-- operator[]" CLR_END);// ------- operator[] ---------------
	PRT_BLU("std")
	{
		std::vector<int> myvector (10);   // 10 zero-initialized elements

		std::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	PRT_BLU("ft ")
	{
		ft::vector<int> myvector (10);   // 10 zero-initialized elements

		ft::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	PRINT(CLR_YLW "\n-- at" CLR_END);// ------- at ---------------
	PRT_BLU("std")
	{
		std::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}
	PRT_BLU("ft ")
	{
		ft::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}
	PRINT(CLR_YLW "\n-- front" CLR_END);// ------- front ---------------
	PRT_BLU("std")
	{
		std::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}
	PRT_BLU("ft ")
	{
		ft::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}
	PRINT(CLR_YLW "\n-- back" CLR_END);// ------- back ---------------
	PRT_BLU("std")
	{
		std::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	PRT_BLU("ft ")
	{
		ft::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
}

void		modifiers_vector()
{
	PRINT_YLW("\n---| modifiers_vector | ---")
	PRINT(CLR_YLW "\n-- assign" CLR_END);// ------- assign ---------------
		{
		
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;

		ft::vector<int> ft_first;
		ft::vector<int> ft_second;
		ft::vector<int> ft_third;


		first.assign (7,100);		PRT_BLU("std")	TEST_VECTOR(first)
		ft_first.assign (7,100);	PRT_BLU("ft ")	TEST_VECTOR(ft_first)	ENDL

		std::vector<int>::iterator it;
		it=first.begin()+1;
		second.assign (it,first.end()-1);			PRT_BLU("std")	TEST_VECTOR(second)

		ft::vector<int>::iterator ft_it;
		ft_it=ft_first.begin()+1;
		ft_second.assign (ft_it,ft_first.end()-1);	PRT_BLU("ft ")	TEST_VECTOR(ft_second)	ENDL

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);		PRT_BLU("std")	TEST_VECTOR(third)
		ft_third.assign (myints,myints+3);	PRT_BLU("ft ")	TEST_VECTOR(ft_third)

	}
	// PRINT(CLR_YLW "\n-- push_back" CLR_END);// ------- push_back ---------------
	// {
	// 	std::vector<int>	myvector;
	// 	ft::vector<int>		ft_myvector;
	// 	int myint;

	// 	std::cout << "Please enter some integers (enter 0 to end):\n";

	// 	do {
	// 		std::cin >> myint;
	// 		myvector.push_back(myint);
	// 		ft_myvector.push_back(myint);
	// 	} while (myint);

	// 	PRT_BLU("std")		TEST_VECTOR(myvector)
	// 	PRT_BLU("ft ")		TEST_VECTOR(ft_myvector)
	// }
	PRINT(CLR_YLW "\n-- pop_back" CLR_END);// ------- pop_back ---------------
	{
		std::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		PRINT_BLU("std")
		TEST_VECTOR(myvector)
		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}
		std::cout << "The elements of myvector add up to " << sum << '\n';
		TEST_VECTOR(myvector)
	}
	{
		PRINT_BLU("ft")
		ft::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		TEST_VECTOR(myvector)
		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}
		std::cout << "The elements of myvector add up to " << sum << '\n';
		TEST_VECTOR(myvector)
	}
	PRINT(CLR_YLW "\n-- insert" CLR_END);// ------- insert ---------------
	{
		std::vector<int> myvector (3,100);
		std::vector<int>::iterator it;
		PRT_BLU("std")	TEST_VECTOR(myvector)

		ft::vector<int> ft_myvector (3,100);
		ft::vector<int>::iterator ft_it;
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL

		it = myvector.begin();
		it = myvector.insert(it, 200);
		PRT_BLU("std")	TEST_VECTOR(myvector)
		ft_it = ft_myvector.begin();
		ft_it = ft_myvector.insert(ft_it , 200);
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL

		myvector.insert (it,2,300);
		PRT_BLU("std")	TEST_VECTOR(myvector)
		ft_myvector.insert (ft_it,2,300);
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL

		// "it" no longer valid, get a new one:
		it = myvector.begin();
		PRT_BLU("std")	TEST_VECTOR(myvector)
		ft_it = ft_myvector.begin();
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL

		std::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());
		PRT_BLU("std")	TEST_VECTOR(myvector)
		ft::vector<int> ft_anothervector (2,400);
		ft_myvector.insert (ft_it+2,ft_anothervector.begin(),ft_anothervector.end());
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);
		PRT_BLU("std")	TEST_VECTOR(myvector)
		ft_myvector.insert (ft_myvector.begin(), myarray, myarray+3);
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL
	}
	PRINT(CLR_YLW "\n-- erase" CLR_END);// ------- erase ---------------
	{
		std::vector<int> myvector;
		ft::vector<int> ft_myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++)
			myvector.push_back(i);
		PRT_BLU("std")	TEST_VECTOR(myvector)
		for (int i=1; i<=10; i++)
			ft_myvector.push_back(i);
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL

		// erase the 6th element
		myvector.erase (myvector.begin()+5);
		PRT_BLU("std")	TEST_VECTOR(myvector)
		ft_myvector.erase (ft_myvector.begin()+5);
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);
		PRT_BLU("std")	TEST_VECTOR(myvector)
		ft_myvector.erase (ft_myvector.begin(),ft_myvector.begin()+3);
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL

		myvector.erase (myvector.begin()+2,myvector.begin()+4);
		PRT_BLU("std")	TEST_VECTOR(myvector)
		ft_myvector.erase (ft_myvector.begin()+2,ft_myvector.begin()+4);
		PRT_BLU("ft ")	TEST_VECTOR(ft_myvector)	ENDL
	}
		PRINT(CLR_YLW "\n-- swap" CLR_END);// ------- swap ---------------
	{
		PRINT_BLU("std")
		std::vector<int> foo (3,100);
		std::vector<int> bar (5,200);

		TEST_VECTOR(foo)	TEST_VECTOR(bar)
		PRINT_BLU("swap")	foo.swap(bar);
		TEST_VECTOR(foo)	TEST_VECTOR(bar)
		ENDL
	}
	{
		PRINT_BLU("ft ")
		ft::vector<int> foo (3,100);
		ft::vector<int> bar (5,200);

		TEST_VECTOR(foo)	TEST_VECTOR(bar)
		PRINT_BLU("swap")	foo.swap(bar);
		TEST_VECTOR(foo)	TEST_VECTOR(bar)
	}
	PRINT(CLR_YLW "\n-- clear" CLR_END);// ------- clear ---------------
	{
		PRINT_BLU("std")
		std::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
}

void		non_member_function_overloads_vector()
{
	PRINT_YLW("\n---| non_member_function_overloads_vector | ---")
	PRINT(CLR_YLW "\n-- relational operators" CLR_END);// ------- relational operators ---------------
	{
		PRINT_BLU("std")
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	{
		PRINT_BLU("ft ")
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	PRINT(CLR_YLW "\n-- swap" CLR_END);// ------- swap ---------------
	{
		// unsigned int i;
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}
//end test ----------------------------------- vector ---------------------------------

//start test --------------------------------- queue ---------------------------------
void		queue_base()
{
	PRINT_YLW("\n---| queue base tests | ---")
	PRINT(CLR_YLW "\n-- constructing queues" CLR_END);// ------- constructing queues ---------------
	{
		PRINT_BLU("std")
		std::deque<int> mydeck (3,100);        // deque with 3 elements
		std::list<int> mylist (2,200);         // list with 2 elements

		std::queue<int> first;                 // empty queue
		std::queue<int> second (mydeck);       // queue initialized to copy of deque

		std::queue<int,std::list<int> > third; // empty queue with list as underlying container
		std::queue<int,std::list<int> > fourth (mylist);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	{
		PRINT_BLU("ft ")
		std::deque<int> mydeck (3,100);
		std::list<int> mylist (2,200);

		ft::queue<int> first;
		ft::queue<int> second (mydeck);
		ft::queue<int,std::list<int> > third;
		ft::queue<int,std::list<int> > fourth(mylist);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	PRINT(CLR_YLW "\n-- empty" CLR_END);// ------- empty ---------------
	{
		PRINT_BLU("std")
		std::queue<int> myqueue;
		int sum (0);

		for (int i=1;i<=10;i++) myqueue.push(i);

		while (!myqueue.empty())
		{
			sum += myqueue.front();
			myqueue.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::queue<int> myqueue;
		int sum (0);

		for (int i=1;i<=10;i++) myqueue.push(i);

		while (!myqueue.empty())
		{
			sum += myqueue.front();
			myqueue.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	PRINT(CLR_YLW "\n-- size" CLR_END);// ------- size ---------------
	{
		PRINT_BLU("std")
		std::queue<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::queue<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	PRINT(CLR_YLW "\n-- front" CLR_END);// ------- front ---------------
	{
		PRINT_BLU("std")
		std::queue<int> myqueue;

		myqueue.push(77);
		myqueue.push(16);

		myqueue.front() -= myqueue.back();    // 77-16=61

		std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::queue<int> myqueue;

		myqueue.push(77);
		myqueue.push(16);

		myqueue.front() -= myqueue.back();

		std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
	}
	PRINT(CLR_YLW "\n-- back" CLR_END);// ------- back ---------------
	{
		PRINT_BLU("std")
		std::queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);   // this is now the back

		myqueue.back() -= myqueue.front();

		std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);   // this is now the back

		myqueue.back() -= myqueue.front();

		std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
	}
	PRINT(CLR_YLW "\n-- push/pop" CLR_END);// ------- push ---------------
	{
		PRINT_BLU("std")
		std::queue<int> myqueue;

		myqueue.push (4040);
		myqueue.push (42);
		myqueue.push (21);
		myqueue.push (0);
		myqueue.push (-4040);

		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.front();
			myqueue.pop();
		}
		ENDL
	}
	{
		PRINT_BLU("ft ")
		ft::queue<int> myqueue;

		myqueue.push (4040);
		myqueue.push (42);
		myqueue.push (21);
		myqueue.push (0);
		myqueue.push (-4040);

		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.front();
			myqueue.pop();
		}
		ENDL
	}
}

void		push_pop_queue()
{
	PRINT(CLR_YLW "\n-- push/pop" CLR_END);// ------- push/pop ---------------
	{
		std::queue<int> myqueue;
		ft::queue<int> ft_myqueue;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myqueue.push(myint);
			ft_myqueue.push(myint);
		} while (myint);

		PRINT_BLU("std")
		std::cout << "myqueue contains: ";
		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.front();
			myqueue.pop();
		}
		ENDL

		PRINT_BLU("ft ")
		std::cout << "myqueue contains: ";
		while (!ft_myqueue.empty())
		{
			std::cout << ' ' << ft_myqueue.front();
			ft_myqueue.pop();
		}
		ENDL
	}
}

void		non_member_function_overloads_queue()
{
	PRINT_YLW("\n---| non member function overloads queue | ---")
	PRINT(CLR_YLW "\n-- swap" CLR_END);// ------- swap ---------------
	{
		PRINT_BLU("std")
		std::queue<int> foo,bar;
		foo.push (10); foo.push(20); foo.push(30);
		bar.push (111); bar.push(222);

		swap(foo,bar);

		std::cout << "size of foo: " << foo.size() << '\n';
		std::cout << "size of bar: " << bar.size() << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::queue<int> foo,bar;
		foo.push (10); foo.push(20); foo.push(30);
		bar.push (111); bar.push(222);

		swap(foo,bar);

		std::cout << "size of foo: " << foo.size() << '\n';
		std::cout << "size of bar: " << bar.size() << '\n';
	}
	PRINT(CLR_YLW "\n-- relational operators" CLR_END);// ------- relational operators ---------------
	std::deque<int>		mydeck1(3,100);
	std::deque<int>		mydeck2(2,200);
	{
		PRINT_BLU("std")
		std::queue<int>		foo(mydeck1);
		std::queue<int>		bar(mydeck2);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	{
		PRINT_BLU("ft ")
		ft::queue<int>		foo(mydeck1);
		ft::queue<int>		bar(mydeck2);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
}
//end test ----------------------------------- queue ---------------------------------

//start test --------------------------------- stack ---------------------------------
void		stack_base()
{
	PRINT_YLW("\n---| stack base tests | ---")
	PRINT(CLR_YLW "\n-- constructing stack" CLR_END);// ------- constructing queues ---------------
	{
		PRINT_BLU("std")
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		std::stack<int> first;                    // empty stack
		std::stack<int> second (mydeque);         // stack initialized to copy of deque

		std::stack<int,std::vector<int> > third;  // empty stack using vector
		std::stack<int,std::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}

	{
		PRINT_BLU("ft ")
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack
		ft::stack<int> second (mydeque);         // stack initialized to copy of deque

		ft::stack<int,std::vector<int> > third;  // empty stack using vector
		ft::stack<int,std::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	PRINT(CLR_YLW "\n-- stack::empty" CLR_END);// ------- stack::empty ---------------
	{
		PRINT_BLU("std")
		std::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << "total: " << sum << '\n';
	}
	PRINT_BLU("ft ")
	{
		std::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << "total: " << sum << '\n';
	}
	PRINT(CLR_YLW "\n-- stack::size" CLR_END);// ------- stack::size ---------------
	{
		PRINT_BLU("std")
		std::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	PRINT(CLR_YLW "\n-- stack::top" CLR_END);// ------- stack::top ---------------
	{
		PRINT_BLU("std")
		std::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	PRINT(CLR_YLW "\n-- stack::push/pop" CLR_END);// ------- stack::push/pop ---------------
	{
		PRINT_BLU("std")
		std::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
}

void		push_pop_stack()
{
	PRINT(CLR_YLW "\n-- push/pop" CLR_END);// ------- push/pop ---------------
	{
		std::stack<int> myqueue;
		ft::stack<int> ft_myqueue;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myqueue.push(myint);
			ft_myqueue.push(myint);
		} while (myint);

		PRINT_BLU("std")
		std::cout << "myqueue contains: ";
		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.top();
			myqueue.pop();
		}
		ENDL

		PRINT_BLU("ft ")
		std::cout << "myqueue contains: ";
		while (!ft_myqueue.empty())
		{
			std::cout << ' ' << ft_myqueue.top();
			ft_myqueue.pop();
		}
		ENDL
	}
}

void		non_member_function_overloads_stack()
{
	PRINT_YLW("\n---| non member function overloads stack | ---")
	PRINT(CLR_YLW "\n-- swap" CLR_END);// ------- swap ---------------
	{
		PRINT_BLU("std")
		std::stack<int> foo,bar;
		foo.push (10); foo.push(20); foo.push(30);
		bar.push (111); bar.push(222);

		swap(foo,bar);

		std::cout << "size of foo: " << foo.size() << '\n';
		std::cout << "size of bar: " << bar.size() << '\n';
	}
	{
		PRINT_BLU("ft ")
		ft::stack<int> foo,bar;
		foo.push (10); foo.push(20); foo.push(30);
		bar.push (111); bar.push(222);

		swap(foo,bar);

		std::cout << "size of foo: " << foo.size() << '\n';
		std::cout << "size of bar: " << bar.size() << '\n';
	}
	PRINT(CLR_YLW "\n-- relational operators" CLR_END);// ------- relational operators ---------------
	std::deque<int>		mydeck1(3,100);
	std::deque<int>		mydeck2(2,200);
	{
		PRINT_BLU("std")
		std::stack<int>		foo(mydeck1);
		std::stack<int>		bar(mydeck2);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	{
		PRINT_BLU("ft ")
		ft::stack<int>		foo(mydeck1);
		ft::stack<int>		bar(mydeck2);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
}
//end test ----------------------------------- stack ---------------------------------

//start test --------------------------------- map ---------------------------------
void		map_base()
{
	PRINT_YLW("\n---| map base tests | ---")
	PRINT(CLR_YLW "\n-- constructing map" CLR_END);// ------- constructing queues ---------------
	{
		PRINT_BLU("std")
		std::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		std::map<char,int> second (first.begin(),first.end());
		std::map<char,int> third (second);
		std::map<char,int,classcomp> fourth;
		bool(*fn_pt)(char,char) = fncomp;
		std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
		PRINT("1 :" << first.begin()->second << "|");
		PRINT("2 :" << (*first.begin()).second << "|");

		ENDL
		std::map<char,std::string> test;
		PRT("size :" << test.size() << "|");
		test['a']="7";		PRT(" " << test.size() << "|");
		test['c']="21";		PRT(" " << test.size() << "|");
		test['e']="42";		PRT(" " << test.size() << "|");
		test['b']="13";		PRT(" " << test.size() << "|");
		test['d']="26";		PRINT(" " << test.size() << "|");
		std::map<char,std::string>::iterator		it = test.begin();
		std::map<char,std::string>::iterator		ite = test.end();
		int i = 0;
		for(; it != ite; ++it, ++i)
			PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		// PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		PRINT("---");
		for(--ite, --i, it = test.begin(); it != ite; --ite, --i)
			PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
	}
	{
		PRINT_BLU("ft ")
		// ft::map<char,int> first; // --- default
		// first.new_node('a',21);
		// // --- operator[]
		// first['a']=10;
		// first['b']=30;
		// first['c']=50;
		// first['d']=70;
		// // --- range
		// std::map<char,int> second (first.begin(),first.end());
		// // --- copy
		// std::map<char,int> third (second);
		// // --- class as Compare
		// std::map<char,int,classcomp> fourth;
		// // --- function pointer as Compare
		// bool(*fn_pt)(char,char) = fncomp;
		// std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
		{
		ENDL
		ft::map<char,int> test;
		PRT("size :" << test.size() << "|");
		test.mini_insert('a',7);		PRT(" " << test.size() << "|");
		test.mini_insert('c',21);		PRT(" " << test.size() << "|");
		test.mini_insert('e',42);		PRT(" " << test.size() << "|");
		test.mini_insert('b',13);		PRT(" " << test.size() << "|");
		test.mini_insert('d',26);		PRINT(" " << test.size() << "|");
		ft::map<char,int>::iterator		it = test.begin();
		ft::map<char,int>::iterator		ite = test.end();
		int i = 0;
		for(; it != ite; ++it, ++i)
			PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		// PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		PRINT("---");
		for(--ite, --i, it = test.begin(); it != ite; --ite, --i)
			PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		ENDL
		test.treeprint();
		}
		{
		ENDL
		PRINT("- balance -");
		// test.clear();
		ft::map<char,int> test;
		ft::map<char,int>::iterator		it, ite;
		PRT("size :" << test.size() << "|");
		test.balance_mini_insert('a',7);		PRT(" " << test.size() << "|");
		test.balance_mini_insert('c',21);		PRT(" " << test.size() << "|");
		test.balance_mini_insert('e',42);		PRT(" " << test.size() << "|");
		test.balance_mini_insert('b',13);		PRT(" " << test.size() << "|");
		test.balance_mini_insert('d',26);		PRINT(" " << test.size() << "|");
		it = test.begin();
		ite = test.end();
		int i = 0;
		for(; it != ite; ++it, ++i)
			PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		// PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		PRINT("---");
		for(--ite, --i, it = test.begin(); it != ite; --ite, --i)
			PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		ENDL
		test.treeprint();
		}
		{
		std::cout << "\n----Balance test----\n";
		ft::map<int, int> FT;
		std::map<int, int> STD;
		FT.balance_mini_insert(1, 0);
		FT.balance_mini_insert(10, 0);
		FT.balance_mini_insert(20, 0);
		STD.insert(std::make_pair(0, 0));
		STD.insert(std::make_pair(10, 0));
		STD.insert(std::make_pair(20, 0));
		for (int i = 1; i <= 5; i += 1)
		{
			// PRINT(-i << " " <<i+20);
			FT.balance_mini_insert(-i, i);
			FT.balance_mini_insert(i + 20, i);
			STD.insert(std::make_pair(-i, i));
			STD.insert(std::make_pair(i + 20, i));
		}
		FT.treeprint();
		}
		// std::cout << "\n----FIND----\n";
		// ft::map<int,int>::iterator		find_ft;
		// std::map<int,int>::iterator		find_std;
		// // S.erase(it);
		// find_std = STD.find(-5);	PRINT("std: " << find_std->first);
		// find_ft = FT.find(-5);	PRINT("ft : " << find_ft->first); ENDL
		// find_std = STD.find(-2);	PRINT("std: " << find_std->first);
		// find_ft = FT.find(-2);	PRINT("ft : " << find_ft->first); ENDL
		// find_std = STD.find(25);	PRINT("std: " << find_std->first);
		// find_ft = FT.find(25);	PRINT("ft : " << find_ft->first); ENDL
		// find_std = STD.find(21);	PRINT("std: " << find_std->first);
		// find_ft = FT.find(21);	PRINT("ft : " << find_ft->first); ENDL
		// find_std = STD.find(10);	PRINT("std: " << find_std->first);
		// find_ft = FT.find(10);	PRINT("ft : " << find_ft->first); ENDL
		// // find_std = Z.find(99);	PRINT("std: " << find_std->first);
		// // findS = S.find(99);	PRINT("ft : " << find_ft->first); ENDL
		// std::cout << "\n----CONST FIND----\n";
		// ft::map<int,int>::const_iterator		const_find_ft;
		// std::map<int,int>::const_iterator		const_find_std;
		// const_find_ft = FT.find(-5);	PRINT("ft : " << const_find_ft->first);
		// const_find_std = STD.find(-5);	PRINT("std: " << const_find_std->first); ENDL
		// // const_find_std = 5; // no viable overloaded '='
		// // const_find_ft = 5; // no viable overloaded '='
		// std::cout << "\n----ERASE----\n";
		// ft::map<int,int>::iterator		it, ite;
		// it = FT.begin();
		// ite = FT.end();
		// FT.treeprint();
		// FT.erase(++++++it);
		// FT.treeprint();
		// }
		// ft::map<char,int>::reverse_iterator		rit = test.rbegin();
		// ft::map<char,int>::reverse_iterator		rite = test.rend();
		// for(int i = 0; rit != rite; ++rit, ++i)
		// 	PRINT(i << ": "<< rit->second << "|");

		// PRINT("0 : '"<< it->first << "'/" << it->second << "|");// << test[0]);
		// ++it;
		// PRINT("1 : '"<< it->first << "'/" << it->second << "|");// << test[1]);
		// ++it;
		// PRINT("2 : '"<< it->first << "'/" << it->second << "|");// << test[2]);
		// ++it;
		// PRINT("3 : '"<< it->first << "'/" << it->second << "|");// << test[3]);
		// ++it;
		// PRINT("4 : '"<< it->first << "'/" << it->second << "|");// << test[4]);
	}
}

void		iterators_map()
{

}

void		capacity_map()
{

}

void		element_access_map()
{

}

void		modifiers_map()
{

}

void		map_observers()
{

}

void		map_operations()
{

}
//end test ----------------------------------- stack ---------------------------------

void		ft_fast_test()
{
	{
	std::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	first.merge(second);

	// (second is now empty)

	second.push_back (2.1);

	first.merge(second,mycomparison);

	std::cout << "first contains:";
	for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	}
	{
	ft::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	first.merge(second);

	// (second is now empty)

	second.push_back (2.1);

	first.merge(second,mycomparison);

	std::cout << "first contains:";
	for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	}
}