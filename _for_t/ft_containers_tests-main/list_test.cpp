#include "containers_test.hpp"

struct myclass
{
	bool operator() (int i, int j)
	{
		return (i < j);
	}
} myobject;

// // compare only integral part:
bool mycomparison (double first, double second);
// {
// 	return ( (int(first) > int(second)));
// }

bool same_integral_part (double first, double second);
// {
// 	return ( int(first) == int(second) );
// }

// a predicate implemented as a function:
bool single_digit (const int& value);
// {
// 	return (value < 10);
// }

void				constructor(int testNmb, int testAll)
{
	int copy = 0;
	int constConstructor = 0;
	int reverseIterator = 0;
	int withIterator = 0;

	if (testAll)
	{
		copy = 1;
		constConstructor = 1;
		reverseIterator = 1;
		withIterator = 1;
	}

	std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;

	ft::list  <int> userList(10, 42);
	std::list <int> sysList(10, 42);

	testFunc(testNmb++, sysList.size(), userList.size(), "Constructor list(size, value)");

	std::list <int> :: iterator sysIterator = sysList.begin();
	ft::list <int> :: iterator userIterator = userList.begin();

	testFunc(testNmb++, *sysIterator, *userIterator, "Constructor list(size, value)");

	if (copy)
	{
		/*		COPY		*/
		ft::list  <int> userListCopy(userList);
		std::list <int> sysListCopy(sysList);
		testFunc(testNmb++, sysListCopy.size(), userListCopy.size(), "Constructor copy");
		
		sysIterator = sysListCopy.begin();
		userIterator = userListCopy.begin();
		
		testFunc(testNmb++, *sysIterator, *userIterator, "Constructor copy - value");

		userList.push_front(0);
		sysList.push_front(0);

		sysIterator = sysList.begin();
		userIterator = userList.begin();

		testFunc(testNmb++, *sysIterator, *userIterator, "Front value is");

		userList.push_back(50);
		sysList.push_back(50);

		sysIterator = sysList.end();
		userIterator = userList.end();

		sysIterator--;
		userIterator--;

		testFunc(testNmb++, *sysIterator, *userIterator, "Back value is");

		userList.pop_front();
		sysList.pop_front();

		sysIterator = sysList.begin();
		userIterator = userList.begin();

		testFunc(testNmb++, *sysIterator, *userIterator, "Front value is");

		userList.pop_back();
		sysList.pop_back();

		sysIterator = sysList.end();
		userIterator = userList.end();

		sysIterator--;
		userIterator--;

		testFunc(testNmb++, *sysIterator, *userIterator, "Back value is");
		getchar();
	}

	if (constConstructor)
	{
		std::system("clear");
		std::cout << std::endl << "\x1b[33m" << "                              *** CONST ***                          " << "\x1b[0m" << std::endl;

		const ft::list  <int> userListConst(5,4);
		const std::list <int> sysListConst(5,4);

		std::list <int>::const_iterator const_s_s = sysListConst.begin(); 
		ft::list <int>::const_iterator const_m_s = userListConst.begin();
		std::list <int>::const_iterator const_s_f  = sysListConst.end();
		ft::list <int>::const_iterator const_m_f = userListConst.end();

		testFunc(testNmb++, *const_s_s, *const_m_s, "Const test begin");

		testFunc(testNmb++, *const_s_f, *const_m_f, "Const test end");
		
		getchar();
	}
	
	if (reverseIterator)
	{
		std::cout << std::endl << "\x1b[33m" << "                              *** CONST REVERSE***                          " << "\x1b[0m" << std::endl;
		
		const ft::list  <int> userListConst1(7,2);
		const std::list <int> sysListConst1(7,2);

		testFunc(testNmb++, *(sysListConst1.rbegin()), *(userListConst1.rbegin()), "Const test rbegin");
		testFunc(testNmb++, *(sysListConst1.rend()), *(userListConst1.rend()), "Const test rend");

		getchar();
		std::system("clear");
	}

	if (withIterator)
	{
		std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR (ITERATOR, ITERATOR, ...) ***                          " << "\x1b[0m" << std::endl;

		userList.clear();
		sysList.clear();

		for(int i = 5; i < 9; i++)
		{
			userList.push_back(i);
			sysList.push_back(i);

		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListTest:", sysList);
		std::cout << std::endl;
		print_ft_list("userListTest:", userList);
		std::cout << std::endl;
		
		testFunc(testNmb++, sysList.size(), userList.size(), "Constructor with iterator list(size, value)");

		ft::list<int>::iterator itUserBegin = userList.begin();
		ft::list<int>::iterator itUserEnd = userList.end();

		std::list<int>::iterator itSysBegin = sysList.begin();
		std::list<int>::iterator itSysEnd = sysList.end();
		
		ft::list <int> newList(itUserBegin, itUserEnd);
		std::list <int> newListSys(itSysBegin, itSysEnd);

		testFunc(testNmb++, newListSys.size(), newList.size(), "Constructor with iterator list(size, value)");
		testFunc(testNmb++, *(newListSys.begin()), *(newList.begin()), "Constructor with iterator list(size, value)");

		getchar();
		std::system("clear");
	}
}

void				operEquall(int testNmb, int testAll)
{
	if (testAll)
	{
		std::cout << std::endl << "\x1b[33m" << "                         *** OPERATOR = ***                          " << "\x1b[0m" << std::endl;
	
		/* operator= 1 */
		std::cout << std::endl << "\x1b[33m" << "operator= 1" << "\x1b[0m" << std::endl;
		ft::list <int> userList;
		std::list <int> sysList;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 5; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}

		ft::list <int> userList2;
		std::list <int> sysList2;
		
		sysList2.clear();
		userList2.clear();

		for (int i = 10; i <= 19; i++)
		{
			sysList2.push_back(i);
			userList2.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList = sysList2;
		userList = userList2;

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");
		getchar();

		/* operator= 2 */
		std::cout << std::endl << "\x1b[33m" << "operator= 2" << "\x1b[0m" << std::endl;
		ft::list<int> first (3);      // list of 3 zero-initialized ints
		ft::list<int> second (5);     // list of 5 zero-initialized ints

		std::list<int> first2 (3);      // list of 3 zero-initialized ints
		std::list<int> second2 (5);     // list of 5 zero-initialized ints

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" first2:", first2);
		print_std_list(" second2:", second2);
		std::cout << std::endl;
		print_ft_list("first:", first);
		print_ft_list("second:", second);
		std::cout << std::endl;

		second = first;
		second2 = first2;

		testFunc(testNmb++,first.size(), first.size(), "first Size is (Operator=)");
		testFunc(testNmb++, second2.size(), second.size(), "second Size  is (Operator=)");

		/* operator= 3 */
		std::cout << std::endl << "\x1b[33m" << "operator= 3" << "\x1b[0m" << std::endl;
		ft::list<int> firstx (3, 7);      // list of 3 zero-initialized ints
		ft::list<int> secondx (5, 1);     // list of 5 zero-initialized ints

		std::list<int> first2x (3, 7);      // list of 3 zero-initialized ints
		std::list<int> second2x (5, 1);     // list of 5 zero-initialized ints

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" first2:", first2x);
		print_std_list(" second2:", second2x);
		std::cout << std::endl;
		print_ft_list("first:", firstx);
		print_ft_list("second:", secondx);
		std::cout << std::endl;

		secondx = firstx;
		second2x = first2x;

		testFunc(testNmb++,firstx.size(), firstx.size(), "first Size is (Operator=)");
		testFunc(testNmb++, second2x.size(), secondx.size(), "second Size  is (Operator=)");
	}
}

void				iterators(int testNmb, int testAll)
{
	int rbeginRend = 1;

	if (testAll)
	{
		rbeginRend = 1;
	}
	if (rbeginRend)
	{
		std::cout << std::endl << "\x1b[33m" << "                                 *** RBEGIN REND ***                          " << "\x1b[0m" << std::endl;
		
		ft::list <int> userList;
		std::list <int> sysList;
		
		for (int i = 1; i <= 9; ++i)
		{
			userList.push_back(i);
			sysList.push_back(i);
		}
		userList.push_back(7);
		sysList.push_back(7);
		
		testFunc(testNmb++, *(sysList.rbegin()), *(userList.rbegin()), "Operators reverse rbegin test *a");
		testFunc(testNmb++, *(sysList.rend()), *(userList.rend()), "Operators reverse rend test *a");

		getchar();
		std::system("clear");
	}
}

void				capacity(int testNmb, int testAll)
{
	int			empty = 0;
	int			size  = 0;
	int			maxSize = 0;

	if (testAll)
	{
		empty = 1;
		size = 1;
		maxSize = 1;
	}

	ft::list <int> testMyList;
	std::list <int> testOriginalList;

	if (empty)
	{
		std::cout << std::endl << "\x1b[33m" << "                                 *** EMPTY ***                          " << "\x1b[0m" << std::endl;
		
		testFunc(testNmb++, testMyList.empty(), testOriginalList.empty(), "Empty list - true");
		testFunc(testNmb++, testMyList.size(), testOriginalList.size(), "Size test free list");
	}

	if (size)
	{
		std::cout << std::endl << "\x1b[33m" << "                                 *** SIZE ***                          " << "\x1b[0m" << std::endl;
		
		testMyList.push_front(10);
		testOriginalList.push_front(10);
		testFunc(testNmb++, testMyList.size(), testOriginalList.size(), "Size test");

		testFunc(testNmb++, testMyList.empty(), testOriginalList.empty(), "Empty list - false");

		testMyList.push_back(11);
		testOriginalList.push_back(11);
		testFunc(testNmb++, testMyList.size(), testOriginalList.size(), "Size test free list");

		testMyList.push_front(9);
		testOriginalList.push_front(9);
		testFunc(testNmb++, testMyList.size(), testOriginalList.size(), "Size test free list");
		
		/*		Size of list CHAR		*/
		std::cout << std::endl << "\x1b[33m" << "Size of list CHAR" << "\x1b[0m" << std::endl;
		
		ft::list <char> userListChar;
		std::list <char> sysListChar;
		
		for (int i = 0; i < 33; i++)
		{
			sysListChar.push_back('a');			
			userListChar.push_back('a');
		}

		std::list <char> :: iterator sysIteratorChar = sysListChar.begin();
		ft::list <char> :: iterator userIteratorChar  = userListChar.begin();

		for (int i = 0; i < 33; i++)
		{
			sysIteratorChar++;
			userIteratorChar++;
		}
		testFunc(testNmb++, userListChar.size(), userListChar.size(), "Size is <char>");
		testFunc(testNmb++, *sysIteratorChar, *userIteratorChar, "Size of list <char>");
		getchar();
	}

	if (maxSize)
	{
		std::cout << std::endl << "\x1b[33m" << "                                 *** MAX SIZE ***                          " << "\x1b[0m" << std::endl;
		
		testMyList.clear();
		testOriginalList.clear();
		testFunc(testNmb++, testMyList.max_size(), testOriginalList.max_size(), "Max Size test");
	}	
}

void				elementAccess(int testNmb, int testAll)
{
	if (testAll)
	{
		std::cout << std::endl << "\x1b[33m" << "                              *** ELEMENT ACCESS ***                          " << "\x1b[0m" << std::endl;

		ft::list  <int> userList((size_t)10, 42);
		std::list <int> sysList((size_t)10, 42);

		userList.push_front(11111111);
		sysList.push_front(11111111);

		userList.push_back(22222222);
		sysList.push_back(22222222);
		
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");
		
		getchar();
	}
}

void				modifiers(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** MODIFIERS ***                          " << "\x1b[0m" << std::endl;


	int			assign = 0;
	int			push_front = 0;
	int			pop_front = 0;
	int			push_back = 0;
	int			pop_back = 0;
	int			insert = 0;
	int			erase = 0;
	int			swap = 0;
	int			resize = 0;

	if (testAll)
	{
		assign = 1;
		push_front = 1;
		pop_front = 1;
		push_back = 1;
		pop_back = 1;
		insert = 1;
		erase = 1;
		swap = 1;
		resize = 1;
	}

	ft::list  <int> userList((size_t)10, 42);
	std::list <int> sysList((size_t)10, 42);

	ft::list  <int> userList2((size_t)10, 42);
	std::list <int> sysList2((size_t)10, 42);

	std::list <int> :: iterator sysIterator = sysList.begin();
	ft::list <int> :: iterator userIterator = userList.begin();

	if (assign)
	{
		std::system("clear");
		/*		assign 1		*/
		std::cout << std::endl << "\x1b[33m" << "assign 1" << "\x1b[0m" << std::endl;
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" Sys Erase:", sysList);
		print_ft_list("User Erase:", userList);
		std::cout << std::endl;
		
		userList.assign(5, 21);
		sysList.assign(5, 21);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" Sys Erase:", sysList);
		print_ft_list("User Erase:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (assign 1)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (assign 1)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (assign 1)");
		// std::cout << std::endl;
		getchar();

		/*		assign 2		*/
		std::cout << std::endl << "\x1b[33m" << "assign 2" << "\x1b[0m" << std::endl;
		userList.push_front(111111);
		sysList.push_front(111111);

		userList.push_back(222222);
		sysList.push_back(222222);

		std::cout << "*** LIST FOR ASSIGN FUNC ***" << std::endl;
		print_std_list(" Sys Erase:", sysList);
		print_ft_list("User Erase:", userList);
		std::cout << std::endl;

		ft::list<int> newUserList;
		std::list<int> newSysList;

		newUserList.assign(8, 10);
		newSysList.assign(8, 10);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" Sys Erase:", newSysList);
		print_ft_list("User Erase:", newUserList);
		std::cout << std::endl;

		newUserList.assign(userList.begin(), userList.end());
		newSysList.assign(sysList.begin(), sysList.end());

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" Sys Erase:", newSysList);
		print_ft_list("User Erase:", newUserList);
		std::cout << std::endl;

		testFunc(testNmb++, newSysList.size(), newUserList.size(), "Size is");
		testFunc(testNmb++, newSysList.front(), newUserList.front(), "Front value is");
		testFunc(testNmb++, newSysList.back(), newUserList.back(), "Back value is");
		getchar();
	
		/*		assign 3		*/
		std::cout << std::endl << "\x1b[33m" << "assign3" << "\x1b[0m" << std::endl;
		int myints[] = { 1776, 7, 4 };

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" Sys assign:", newSysList);
		print_ft_list("User assign:", newUserList);
		std::cout << std::endl;
		
		newSysList.assign (myints, myints + 3);
		newUserList.assign(myints, myints + 3);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" Sys assign:", newSysList);
		print_ft_list("User assign:", newUserList);
		std::cout << std::endl;
		
		testFunc(testNmb++, newSysList.size(), newUserList.size(), "Size is");
		testFunc(testNmb++, newSysList.front(), newUserList.front(), "Front value is");
		testFunc(testNmb++, newSysList.back(), newUserList.back(), "Back value is");
		getchar();
	}

	std::system("clear");

	if (push_front || pop_front)
	{
		/*		pop_front and push_front		*/
		std::cout << std::endl << "\x1b[33m" << "pop_front and push_front" << "\x1b[0m" << std::endl;
	
		sysList.clear();
		userList.clear();

		sysList.push_front(1);			// 1 2 3
		userList.push_front(1);

		sysList.push_front(2);			// 1 2 3
		userList.push_front(2);

		sysList.push_front(3);			// 1 2 3
		userList.push_front(3);

		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;
	
		sysList.pop_front();
		userList.pop_front();

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (pop_front and push_front)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (pop_front and push_front)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (pop_front and push_front)");
		getchar();

		/*		pop_front and push_front(one element)		*/
		std::cout << std::endl << "\x1b[33m" << "pop_front and push_front (one element)" << "\x1b[0m" << std::endl;
		sysList.clear();
		userList.clear();

		sysList.push_front(1);
		userList.push_front(1);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" Sys Erase:", sysList);
		print_ft_list("User Erase:", userList);
		std::cout << std::endl;
	
		sysList.pop_front();
		userList.pop_front();

		// sysList.pop_front();
		// userList.pop_front();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" Sys Erase:", sysList);
		print_ft_list("User Erase:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (pop_front and push_front(one element))");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (pop_front and push_front(one element))");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (pop_front and push_front(one element))");
		getchar();
		std::system("clear");
	}

	std::system("clear");

	if (push_back || pop_back)
	{
		/*		pop_back and push_back		*/
		std::cout << std::endl << "\x1b[33m" << "pop_back and push_back" << "\x1b[0m" << std::endl;
	
		sysList.clear();
		userList.clear();

		sysList.push_back(1);			// 1 2 3
		userList.push_back(1);

		sysList.push_back(2);			// 1 2 3
		userList.push_back(2);

		sysList.push_back(3);			// 1 2 3
		userList.push_back(3);

		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;
	
		sysList.pop_back();
		userList.pop_back();

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (pop_back and push_back)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (pop_back and push_back)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (pop_back and push_back)");
		getchar();

		/*		pop_back and push_back(one element)		*/
		std::cout << std::endl << "\x1b[33m" << "pop_back and push_back (one element)" << "\x1b[0m" << std::endl;
		sysList.clear();
		userList.clear();

		sysList.push_back(1);
		userList.push_back(1);

		// sysList.push_back(2);
		// userList.push_back(2);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" Sys Erase:", sysList);
		print_ft_list("User Erase:", userList);
		std::cout << std::endl;
	
		sysList.pop_back();
		userList.pop_back();

		// sysList.pop_back();
		// userList.pop_back();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" Sys Erase:", sysList);
		print_ft_list("User Erase:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (pop_back and push_back(one element))");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (pop_back and push_back(one element))");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (pop_back and push_back(one element))");
		getchar();
		std::system("clear");
	}

	std::system("clear");

	if (insert)
	{
    	/*		insert 1		*/
		std::cout << std::endl << "\x1b[33m" << "insert 1" << "\x1b[0m" << std::endl;
		sysList.clear();
		userList.clear();

		sysList.assign(1, 100);
		userList.assign(1, 100);

		sysList.insert(sysList.begin(), 5);
		userList.insert(userList.begin(), 5);

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (insert 1)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (insert 1)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (insert 1)");
		getchar();
		
		/*		insert 2		*/
		std::cout << std::endl << "\x1b[33m" << "insert 2" << "\x1b[0m" << std::endl;
		sysList.clear();
		userList.clear();

		sysList.assign(1, 100);
		userList.assign(1, 100);

		sysList.insert(sysList.begin(), 3, 5);
		userList.insert(userList.begin(), 3, 5);

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (insert 2)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (insert 2)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (insert 2)");
		std::cout << std::endl;
		getchar();

		/*		insert 3		*/
		std::cout << std::endl << "\x1b[33m" << "insert 3" << "\x1b[0m" << std::endl;
		sysList.clear();
		userList.clear();

		for (int i = 5; i < 10; i++)
		{
			sysList.push_back(i);			
			userList.push_back(i);
		}

		sysList2.clear();
		userList2.clear();

		for (int i = 111; i < 115; i++)
		{
			sysList2.push_back(i);			
			userList2.push_back(i);
		}

		std::list <int> :: iterator sysIterator1 = sysList2.begin();
		ft::list <int> :: iterator userIterator1 = userList2.begin();

		std::list <int> :: iterator sysIteratorEnd = sysList2.end();
		ft::list <int> :: iterator userIteratorEnd = userList2.end();

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" Sys Erase:", sysList);
		print_ft_list("User Erase:", userList);
		std::cout << std::endl;

		std::list <int> :: iterator whereAddSys = sysList.begin();
		ft::list <int> :: iterator whereAddUser = userList.begin();

		whereAddSys++;
		whereAddUser++;

		whereAddSys++;
		whereAddUser++;

		sysList.insert(whereAddSys, sysIterator1, sysIteratorEnd);
		userList.insert(whereAddUser, userIterator1, userIteratorEnd);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" Sys Erase:", sysList);
		print_ft_list("User Erase:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (insert 2)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (insert 2)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (insert 2)");
		std::cout << std::endl;
		getchar();
		std::system("clear");
	}

	std::system("clear");

	if (erase)
	{
		std::cout << std::endl << "\x1b[33m" << "erase" << "\x1b[0m" << std::endl;

		/*		erase 1		*/
		sysList.clear();
		userList.clear();

		sysList.push_back(1);			// 1 2 3
		userList.push_back(1);

		sysList.push_back(2);			// 1 2 3
		userList.push_back(2);

		sysList.push_back(3);			// 1 2 3
		userList.push_back(3);

		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;
	
		sysIterator = sysList.erase(sysList.begin());
		userIterator = userList.erase(userList.begin());

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 1)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 1)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 1)");
		testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 1)");
		getchar();

		/*		erase 1.1		*/
		sysList.clear();
		userList.clear();

		sysList.push_back(1);			// 1 
		userList.push_back(1);

		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;
	
		sysIterator = sysList.erase(sysList.begin());
		userIterator = userList.erase(userList.begin());

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 1.1)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 1.1)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 1.1)");
		testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 1.1)");
		getchar();

		/*		erase 2		*/
		sysList.clear();
		userList.clear();

		sysList.push_back(1);			// 1 2 3
		userList.push_back(1);

		sysList.push_back(2);			// 1 2 3
		userList.push_back(2);

		sysList.push_back(3);			// 1 2 3
		userList.push_back(3);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;
	
		sysIterator = sysList.begin();
		userIterator = userList.begin();
	
		sysIterator = sysList.erase(sysList.begin(), sysIterator);
		userIterator = userList.erase(userList.begin(), userIterator);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2)");
		testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2)");
		getchar();

		/*		erase 2.0		*/
		sysList.clear();
		userList.clear();

		sysList.push_back(1);			// 1 2 3
		userList.push_back(1);

		sysList.push_back(2);			// 1 2 3
		userList.push_back(2);

		sysList.push_back(3);			// 1 2 3
		userList.push_back(3);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;
	
		sysIterator = sysList.begin();
		sysIterator++;

		userIterator = userList.begin();
		userIterator++;
	
		sysIterator = sysList.erase(sysList.begin(), sysIterator);
		userIterator = userList.erase(userList.begin(), userIterator);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2.0)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2.0)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2.0)");
		testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2.0)");
		getchar();

		/*		erase 2.1		*/
		sysList.clear();
		userList.clear();

		sysList.push_back(1);			// 1 2 3
		userList.push_back(1);

		sysList.push_back(2);			// 1 2 3
		userList.push_back(2);

		sysList.push_back(3);			// 1 2 3
		userList.push_back(3);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;
	
		sysIterator = sysList.begin();
		sysIterator++;
		sysIterator++;

		userIterator = userList.begin();
		userIterator++;
		userIterator++;
	
		sysIterator = sysList.erase(sysList.begin(), sysIterator);
		userIterator = userList.erase(userList.begin(), userIterator);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2.1)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2.1)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2.1)");
		testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2.1)");
		getchar();

		/*		erase 2.2		*/
		sysList.clear();
		userList.clear();

		sysList.push_back(1);			// 1 2 3
		userList.push_back(1);

		sysList.push_back(2);			// 1 2 3
		userList.push_back(2);

		sysList.push_back(3);			// 1 2 3
		userList.push_back(3);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;
	
		sysIterator = sysList.begin();
		sysIterator++;
		sysIterator++;
		sysIterator++;

		userIterator = userList.begin();
		userIterator++;
		userIterator++;
		userIterator++;
	
		sysIterator = sysList.erase(sysList.begin(), sysIterator);
		userIterator = userList.erase(userList.begin(), userIterator);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2.2)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2.2)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2.2)");
		testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2.2)");
		getchar();

		/*		erase 2.3		*/
		sysList.clear();
		userList.clear();

		sysList.push_back(5);			// 5 6 7
		userList.push_back(5);

		sysList.push_back(6);			// 5 6 7
		userList.push_back(6);

		sysList.push_back(7);			// 5 6 7
		userList.push_back(7);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;
	
		sysIterator = sysList.begin();
		sysIterator++;
		sysIterator++;
		sysIterator++;
		sysIterator++;

		userIterator = userList.begin();
		userIterator++;
		userIterator++;
		userIterator++;
		userIterator++;

		testFunc(testNmb++, *(sysList.begin()), *(userList.begin()), "First iterator is (erase 2.3)");
		testFunc(testNmb++, *sysIterator, *userIterator, "Last iterator is (erase 2.3)");
	
		sysIterator = sysList.erase(sysList.begin(), sysIterator);
		userIterator = userList.erase(userList.begin(), userIterator);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2.3)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2.3)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2.3)");
		testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2.3)");
		std::cout << std::endl;
		getchar();
		// std::system("clear");
	}

	std::system("clear"); 

	if (swap)
	{
		/*		swap 1		*/
		std::cout << std::endl << "\x1b[33m" << "swap" << "\x1b[0m" << std::endl;

		std::list <int> sysListSwap1;
		ft::list <int> userListSwap1;

		sysListSwap1.push_back(1);
		userListSwap1.push_back(1);
		
		sysListSwap1.push_back(2);
		userListSwap1.push_back(2);
		
		sysListSwap1.push_back(3);
		userListSwap1.push_back(3);

		std::list <int> sysListSwap2;
		ft::list <int> userListSwap2;

		sysListSwap2.push_back(4);
		userListSwap2.push_back(4);
		
		sysListSwap2.push_back(5);
		userListSwap2.push_back(5);
		
		sysListSwap2.push_back(6);
		userListSwap2.push_back(6);

		sysListSwap2.push_back(7);
		userListSwap2.push_back(7);
		
		sysListSwap2.push_back(8);
		userListSwap2.push_back(8);
		
		sysListSwap2.push_back(9);
		userListSwap2.push_back(9);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSwap1:", sysListSwap1);
		print_std_list(" SysListSwap2:", sysListSwap2);
		std::cout << std::endl;
		print_ft_list("UserListSwap1:", userListSwap1);
		print_ft_list("UserListSwap2:", userListSwap2);
		std::cout << std::endl;

		sysListSwap1.swap(sysListSwap2);
		userListSwap1.swap(userListSwap2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysListSwap1:", sysListSwap1);
		print_std_list(" SysListSwap2:", sysListSwap2);
		std::cout << std::endl;
		print_ft_list("UserListSwap1:", userListSwap1);
		print_ft_list("UserListSwap2:", userListSwap2);
		std::cout << std::endl;

		testFunc(testNmb++, sysListSwap1.size(), userListSwap1.size(), "Size is (swap)");
		testFunc(testNmb++, sysListSwap1.front(), userListSwap1.front(), "Front value is (swap)");
		testFunc(testNmb++, sysListSwap1.back(), userListSwap1.back(), "Back value is (swap)");

		testFunc(testNmb++, sysListSwap2.size(), userListSwap2.size(), "Size is (swap)");
		testFunc(testNmb++, sysListSwap2.front(), userListSwap2.front(), "Front value is (swap)");
		testFunc(testNmb++, sysListSwap2.back(), userListSwap2.back(), "Back value is (swap)");

		getchar();
		// std::system("clear");
	}

	std::system("clear");

	if (resize)
	{
		/*		resize 1		*/
		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
		
		sysList.clear();
		userList.clear();
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		sysList.resize(3, 9);
		userList.resize(3, 9);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (resize 1)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (resize 1)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (resize 1)");
		getchar();

		/*		resize 2		*/
		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
		
		sysList.clear();
		userList.clear();

		sysList.push_back(5);			// 5 6 7
		userList.push_back(5);

		sysList.push_back(6);			// 5 6 7
		userList.push_back(6);

		sysList.push_back(7);			// 5 6 7
		userList.push_back(7);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		sysList.resize(3, 9);
		userList.resize(3, 9);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (resize 2)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (resize 2)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (resize 2)");
		getchar();

		/*		resize 3		*/
		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
		
		sysList.clear();
		userList.clear();

		sysList.push_back(5);			// 5 6 7
		userList.push_back(5);

		sysList.push_back(6);			// 5 6 7
		userList.push_back(6);

		sysList.push_back(7);			// 5 6 7
		userList.push_back(7);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		sysList.resize(5, 9);
		userList.resize(5, 9);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (resize 3)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (resize 3)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (resize 3)");
		getchar();


		/*		resize 4		*/
		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
		
		sysList.clear();
		userList.clear();

		sysList.push_back(5);			// 5 6 7
		userList.push_back(5);

		sysList.push_back(6);			// 5 6 7
		userList.push_back(6);

		sysList.push_back(7);			// 5 6 7
		userList.push_back(7);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		sysList.resize(1, 9);
		userList.resize(1, 9);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (resize 4)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (resize 4)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (resize 4)");
		getchar();
	}
	
}

void				operations(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** OPERATIONS ***" << "\x1b[0m" << std::endl;

	int			splice = 0;	
	int			remove = 0;
	int			removeIf = 0;
	int			unique = 0;
	int			merge = 0;
	int			sort = 0;
	int			reverse = 0;

	if (testAll)
	{
		splice = 1;
		remove = 1;
		removeIf = 1;
		unique = 1;
		merge = 1;
		sort = 1;
		reverse = 1;
	}

	std::list <int> sysList;
	ft::list <int> userList;

	std::list <int> sysList2;
	ft::list <int> userList2;

	std::list <int> :: iterator sysIter;
	ft::list <int> :: iterator userIter = userList2.begin();

	std::list <int> :: iterator sysWhereAdd1;
	ft::list <int> :: iterator userWhereAdd1 = userList2.begin();

	if (splice)
	{
		/*		void splice (iterator position, list& x);		*/
		std::cout << std::endl << "\x1b[33m" << "splice" << "\x1b[0m" << std::endl;

		std::list <int> sysListSplice1;
		ft::list <int> userListSplice1;

		for (int i = 1; i <= 3; i++)
		{
			sysListSplice1.push_back(i);
			userListSplice1.push_back(i);
		}

		std::list <int> sysListSplice2;
		ft::list <int> userListSplice2;

		for (int i = 4; i <= 9; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		sysListSplice1.splice(sysListSplice1.begin(), sysListSplice2);
		userListSplice1.splice(userListSplice1.begin(), userListSplice2);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 1)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 1)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 1)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 1)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 1)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 1)");

		getchar();
		// std::system("clear");

		/*		void splice (iterator position, list& x, iterator i);		*/
		std::cout << std::endl << "\x1b[33m" << "splice 2" << "\x1b[0m" << std::endl;

			sysListSplice1.clear();
		userListSplice1.clear();

		for (int i = 1; i <= 4; i++)
		{
			sysListSplice1.push_back(555555);
			userListSplice1.push_back(555555);
		}

		sysListSplice2.clear();
		userListSplice2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		sysIter = sysListSplice2.begin();
		userIter = userListSplice2.begin();

		sysIter++;
		userIter++;

		sysWhereAdd1 = sysListSplice1.begin();
		userWhereAdd1 = userListSplice1.begin();

		sysWhereAdd1++;
		userWhereAdd1++;

		sysWhereAdd1++;
		userWhereAdd1++;

		sysListSplice1.splice(sysWhereAdd1, sysListSplice2, sysIter);
		userListSplice1.splice(userWhereAdd1, userListSplice2, userIter);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 2.1)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 2.1)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 2.1)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 2.1)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 2.1)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 2.1)");
		getchar();
		// std::system("clear");

		/*		void splice (iterator position, list& x, iterator i);		*/
		std::cout << std::endl << "\x1b[33m" << "splice 3" << "\x1b[0m" << std::endl;

		sysListSplice1.clear();
		userListSplice1.clear();

		for (int i = 1; i <= 4; i++)
		{
			sysListSplice1.push_back(555555);
			userListSplice1.push_back(555555);
		}

		sysListSplice2.clear();
		userListSplice2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		sysIter = sysListSplice2.begin();
		userIter = userListSplice2.begin();

		sysIter++;
		userIter++;

		sysWhereAdd1 = sysListSplice1.begin();
		userWhereAdd1 = userListSplice1.begin();

		sysWhereAdd1++;
		userWhereAdd1++;

		sysWhereAdd1++;
		userWhereAdd1++;

		sysListSplice1.splice(sysWhereAdd1, sysListSplice2, sysWhereAdd1);
		userListSplice1.splice(userWhereAdd1, userListSplice2, userWhereAdd1);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 2.2)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 2.2)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 2.2)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 2.2)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 2.2)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 2.2)");
		getchar();
		// std::system("clear");

		/*		void splice (iterator position, list& x, iterator i);		*/
		std::cout << std::endl << "\x1b[33m" << "splice" << "\x1b[0m" << std::endl;

		sysListSplice1.clear();
		userListSplice1.clear();

		for (int i = 1; i <= 4; i++)
		{
			sysListSplice1.push_back(555555);
			userListSplice1.push_back(555555);
		}

		sysListSplice2.clear();
		userListSplice2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		sysIter = sysListSplice2.begin();
		userIter = userListSplice2.begin();

		sysIter++;
		userIter++;

		sysWhereAdd1 = sysListSplice1.begin();
		userWhereAdd1 = userListSplice1.begin();

		sysWhereAdd1++;
		userWhereAdd1++;

		sysWhereAdd1++;
		userWhereAdd1++;

		sysListSplice1.splice(sysWhereAdd1, sysListSplice2, sysWhereAdd1++);
		userListSplice1.splice(userWhereAdd1, userListSplice2, userWhereAdd1++);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 2.3)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 2.3)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 2.3)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 2.3)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 2.3)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 2.3)");
		getchar();
		// std::system("clear");


		/*		void splice (iterator position, list& x, iterator first, iterator last);		*/
		std::cout << std::endl << "\x1b[33m" << "splice" << "\x1b[0m" << std::endl;

		sysListSplice1.clear();
		userListSplice1.clear();

		for (int i = 1; i <= 4; i++)
		{
			sysListSplice1.push_back(1000000);
			userListSplice1.push_back(1000000);
		}

		sysListSplice2.clear();
		userListSplice2.clear();

		for (int i = 10; i <= 20; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		std::list <int> :: iterator sysStart2 = sysListSplice2.begin();
		ft::list <int> :: iterator userStart2 = userListSplice2.begin();

		sysStart2++;
		userStart2++;

		std::list <int> :: iterator sysEnd2 = sysListSplice2.end();
		ft::list <int> :: iterator userEnd2 = userListSplice2.end();
		
		sysEnd2--;
		userEnd2--;

		std::list <int> :: iterator sysWhereAdd = sysListSplice1.begin();
		ft::list <int> :: iterator userWhereAdd = userListSplice1.begin();

		sysWhereAdd++;
		userWhereAdd++;

		sysWhereAdd++;
		userWhereAdd++;

		sysListSplice1.splice(sysWhereAdd, sysListSplice2, sysStart2, sysEnd2);
		userListSplice1.splice(userWhereAdd, userListSplice2, userStart2, userEnd2);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 3)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 3)");

		getchar();
		// std::system("clear");
    
    
    	/*		splice 1.1		*/
	std::cout << std::endl << "\x1b[33m" << "LENA splice 1.1" << "\x1b[0m" << std::endl;

	sysListSplice1.clear();
	userListSplice1.clear();

	for (int i = 1; i <= 3; i++)
	{
		sysListSplice1.push_back(i);
		userListSplice1.push_back(i);
	}

	sysListSplice2.clear();
	userListSplice2.clear();

	for (int i = 4; i <= 9; i++)
	{
		sysListSplice2.push_back(i);
		userListSplice2.push_back(i);
	}
    
    sysListSplice1.splice(sysListSplice1.begin(), sysListSplice2);
	userListSplice1.splice(userListSplice1.begin(), userListSplice2);
    
    
	testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 1.1)");
	testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 1.1)");
	testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 1.1)");

	testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 1.1)");
	testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 1.1)");
	testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 1.1)");

	getchar();
	std::system("clear");
	/*		splice 2		*/
	std::cout << std::endl << "\x1b[33m" << "splice2" << "\x1b[0m" << std::endl;

	sysListSplice1.clear();
	userListSplice1.clear();

	for (int i = 1; i <= 3; i++)
	{
		sysListSplice1.push_back(i);
		userListSplice1.push_back(i);
	}

	sysListSplice2.clear();
	userListSplice2.clear();

	for (int i = 4; i <= 9; i++)
	{
		sysListSplice2.push_back(i);
		userListSplice2.push_back(i);
	}
	ft::list<int>::iterator it = userListSplice2.begin();
	std::list<int>::iterator it_sys = sysListSplice2.begin();
	for (int i = 0; i < 3; i++)
	{
		it++;
		it_sys++;
	}

	// std::cout << "*** BEFORE ***" << std::endl;
	// print_std_list(" SysListSplice1:", sysListSplice1);
	// print_std_list(" SysListSplice2:", sysListSplice2);
	// std::cout<< "pointer SysListSplice2:"<< *it_sys<<std::endl;
	// std::cout << std::endl;
	// print_ft_list("UserListSplice1:", userListSplice1);
	// print_ft_list("UserListSplice2:", userListSplice2);
	// std::cout<< "pointer UserListSplice2:"<< *it<<std::endl;
	// std::cout << std::endl;

	sysListSplice1.splice(sysListSplice1.begin(), sysListSplice2, it_sys);
	userListSplice1.splice(userListSplice1.begin(), userListSplice2, it);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_std_list(" SysListSplice1:", sysListSplice1);
	// print_std_list(" SysListSplice2:", sysListSplice2);
	// std::cout << std::endl;
	// print_ft_list("UserListSplice1:", userListSplice1);
	// print_ft_list("UserListSplice2:", userListSplice2);
	// std::cout << std::endl;

	testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 2)");
	testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 2)");
	testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 2)");

	testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 2)");
	testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 2)");
	testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 2)");

	getchar();

	/*		splice 3		*/
	std::cout << std::endl << "\x1b[33m" << "splice3" << "\x1b[0m" << std::endl;

	sysListSplice1.clear();
	userListSplice1.clear();

	for (int i = 1; i <= 3; i++)
	{
		sysListSplice1.push_back(i);
		userListSplice1.push_back(i);
	}

	sysListSplice2.clear();
	userListSplice2.clear();

	for (int i = 4; i <= 9; i++)
	{
		sysListSplice2.push_back(i);
		userListSplice2.push_back(i);
	}
	
	it = userListSplice2.begin();
	it_sys = sysListSplice2.begin();
	for (int i = 0; i < 3; i++)
	{
		it++;
		it_sys++;
	}

	// std::cout << "*** BEFORE ***" << std::endl;
	// print_std_list(" SysListSplice1:", sysListSplice1);
	// print_std_list(" SysListSplice2:", sysListSplice2);
	// std::cout<< "pointer SysListSplice2:"<< *it_sys<<std::endl;
	// std::cout << std::endl;
	// print_ft_list("UserListSplice1:", userListSplice1);
	// print_ft_list("UserListSplice2:", userListSplice2);
	// std::cout<< "pointer UserListSplice2:"<< *it<<std::endl;
	// std::cout << std::endl;

	
	ft::list<int>::iterator it0 = userListSplice2.begin();
	std::list<int>::iterator it_sys0 = sysListSplice2.begin();

	sysListSplice1.splice(sysListSplice1.begin(), sysListSplice2,it_sys0, it_sys);
	userListSplice1.splice(userListSplice1.begin(), userListSplice2,it0, it);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_std_list(" SysListSplice1:", sysListSplice1);
   // print_std_list(" SysListSplice2:", sysListSplice2);
	// std::cout << std::endl;
	// print_ft_list("UserListSplice1:", userListSplice1);
	// print_ft_list("UserListSplice2:", userListSplice2);
	// std::cout << std::endl;

	testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 3)");
	testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 3)");
	testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 3)");

	testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 3)");
	testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 3)");
	testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 3)");

	getchar();

	/*		void splice (iterator position, list& x, iterator first, iterator last);		*/
		std::cout << std::endl << "\x1b[33m" << "splice incorrect" << "\x1b[0m" << std::endl;

		sysListSplice1.clear();
		userListSplice1.clear();

		for (int i = 1; i <= 4; i++)
		{
			sysListSplice1.push_back(1000000);
			userListSplice1.push_back(1000000);
		}

		sysListSplice2.clear();
		userListSplice2.clear();

		for (int i = 10; i <= 20; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		sysStart2 = sysListSplice2.begin();
		userStart2 = userListSplice2.begin();

		sysStart2++;
		userStart2++;

		sysEnd2 = sysListSplice2.end();
		userEnd2 = userListSplice2.end();
		
		sysEnd2--;
		userEnd2--;

		sysWhereAdd = sysListSplice1.begin();
		userWhereAdd = userListSplice1.begin();

		sysWhereAdd++;
		userWhereAdd++;

		sysWhereAdd++;
		userWhereAdd++;

		sysListSplice1.splice(sysWhereAdd, sysListSplice2, sysStart2, sysEnd2);
		userListSplice1.splice(userWhereAdd, userListSplice2, userStart2, userEnd2);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 3)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 3)");

		getchar();
		std::system("clear");
    
	}
	
	if (remove)
	{
		/*		remove 1		*/
		std::cout << std::endl << "\x1b[33m" << "remove 1" << "\x1b[0m" << std::endl;

		for (int i = -1; i <= 1; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}
		for (int i = 1; i <= 3; i++)
		{
			sysList.push_back(0);
			userList.push_back(0);

			sysList.push_front(0);
			userList.push_front(0);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.remove(0);
		userList.remove(0);

		sysList.remove(2);
		userList.remove(2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		getchar();
		// std::system("clear");
    
		/*		remove 1	*/
		std::cout << std::endl << "\x1b[33m" << "LENA remove 1" << "\x1b[0m" << std::endl;

		std::list <int> sysListRemove;
		ft::list <int> userListRemove;

		for (int i = 4; i <= 9; i++)
		{
			sysListRemove.push_back(i);
			userListRemove.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSplice2:", sysListRemove);
		std::cout << std::endl;
		print_ft_list("userListRemove:", userListRemove);
		std::cout << std::endl;
		sysListRemove.remove(6);
		userListRemove.remove(6);
		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListRemove:", sysListRemove);
		std::cout << std::endl;
		print_ft_list("userListRemove:", userListRemove);
		std::cout << std::endl;

		testFunc(testNmb++,sysListRemove.size(), userListRemove.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListRemove.front(), userListRemove.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListRemove.back(), userListRemove.back(), "Back value is (Splice 3)");

		getchar();
		std::system("clear");

		/*		remove 2		*/
		std::cout << std::endl << "\x1b[33m" << "remove 2" << "\x1b[0m" << std::endl;

		sysListRemove.clear();
		userListRemove.clear();

		for (int i = 4; i <= 9; i++)
		{
			sysListRemove.push_back(i);
			userListRemove.push_back(i);
		}

		sysListRemove.push_back(6);
		userListRemove.push_back(6);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSplice2:", sysListRemove);
		std::cout << std::endl;
		print_ft_list("userListRemove:", userListRemove);
		std::cout << std::endl;
		sysListRemove.remove(6);
		userListRemove.remove(6);
		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListRemove:", sysListRemove);
		std::cout << std::endl;
		print_ft_list("userListRemove:", userListRemove);
		std::cout << std::endl;

		testFunc(testNmb++,sysListRemove.size(), userListRemove.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListRemove.front(), userListRemove.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListRemove.back(), userListRemove.back(), "Back value is (Splice 3)");

		getchar();
		std::system("clear");

		/*		remove 3		*/
		std::cout << std::endl << "\x1b[33m" << "remove 3" << "\x1b[0m" << std::endl;

		sysListRemove.clear();
		userListRemove.clear();

		for (int i = 4; i <= 9; i++)
		{
			sysListRemove.push_back(i);
			userListRemove.push_back(i);
		}

		sysListRemove.push_back(10);
		userListRemove.push_back(10);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSplice2:", sysListRemove);
		std::cout << std::endl;
		print_ft_list("userListRemove:", userListRemove);
		std::cout << std::endl;
		sysListRemove.remove(6);
		userListRemove.remove(6);
		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListRemove:", sysListRemove);
		std::cout << std::endl;
		print_ft_list("userListRemove:", userListRemove);
		std::cout << std::endl;

		testFunc(testNmb++,sysListRemove.size(), userListRemove.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListRemove.front(), userListRemove.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListRemove.back(), userListRemove.back(), "Back value is (Splice 3)");

		getchar();
		std::system("clear");
	}

	if (removeIf)
	{
        /*		remove_if		*/
      std::cout << std::endl << "\x1b[33m" << "remove_if" << "\x1b[0m" << std::endl;

      std::list <int> sysListRemoveIf;
      ft::list <int> userListRemoveIf;

      for (int i = 0; i <= 15; i++)
      {
        sysListRemoveIf.push_back(i);
        userListRemoveIf.push_back(i);
      }

      std::cout << "*** BEFORE ***" << std::endl;
      print_std_list("sysListRemoveIf:", sysListRemoveIf);
      std::cout << std::endl;
      print_ft_list("userListRemoveIf:", userListRemoveIf);
      std::cout << std::endl;

      sysListRemoveIf.remove_if(single_digit);
      userListRemoveIf.remove_if(single_digit);

      std::cout << "*** AFTER ***" << std::endl;
      print_std_list(" sysListRemoveIf:", sysListRemoveIf);
      std::cout << std::endl;
      print_ft_list("userListRemoveIf:", userListRemoveIf);
      std::cout << std::endl;

      testFunc(testNmb++,sysListRemoveIf.size(), userListRemoveIf.size(), "Size is (remove_if)");
      testFunc(testNmb++, sysListRemoveIf.front(), userListRemoveIf.front(), "Front value is (remove_if)");
      testFunc(testNmb++, sysListRemoveIf.back(), userListRemoveIf.back(), "Back value is (remove_if)");

      getchar();
      std::system("clear");
	}

	if (unique)
	{
		/*		unique		*/
		std::cout << std::endl << "\x1b[33m" << "unique 1" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 10; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);

			sysList.push_back(i);
			userList.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is ");

		getchar();
		// std::system("clear");

		/*		unique		*/
		std::cout << std::endl << "\x1b[33m" << "unique 2" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 5; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);

			sysList.push_back(5);
			userList.push_back(5);

			sysList.push_back(i);
			userList.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		getchar();
		// std::system("clear");

		/*		unique		*/
		std::cout << std::endl << "\x1b[33m" << "unique 3" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 5; i < 10; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);

			sysList.push_back(i);
			userList.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		getchar();
		// std::system("clear");

		/*		unique		*/
		std::cout << std::endl << "\x1b[33m" << "unique 4" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is ");

		getchar();
		// std::system("clear");

		/*		unique	5	*/
		std::cout << std::endl << "\x1b[33m" << "unique 5" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 1; i++)
		{
			sysList.push_back(1);
			userList.push_back(1);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is ");

		getchar();
		std::system("clear");
    
		/*		unique	6	*/
		std::cout << std::endl << "\x1b[33m" << "unique 6" << "\x1b[0m" << std::endl;

		std::list <int> sysListUnique;
		ft::list <int> userListUnique;

		for (int i = 4; i <= 9; i++)
		{
			sysListUnique.push_back(i);
			userListUnique.push_back(i);
		}
		sysListUnique.push_back(9);
		userListUnique.push_back(9);
		sysListUnique.push_back(9);
		userListUnique.push_back(9);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListUnique:", sysListUnique);
		std::cout << std::endl;

		print_ft_list("userListUnique:", userListUnique);
		std::cout << std::endl;

		sysListUnique.unique();
		userListUnique.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListUnique:", sysListUnique);
		std::cout << std::endl;
		print_ft_list("userListUnique:", userListUnique);
		std::cout << std::endl;

		testFunc(testNmb++,sysListUnique.size(), userListUnique.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListUnique.front(), userListUnique.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListUnique.back(), userListUnique.back(), "Back value is (Splice 3)");

		getchar();
		std::system("clear");

		/*		unique	7	*/
		std::cout << std::endl << "\x1b[33m" << "unique 7" << "\x1b[0m" << std::endl;

		sysListUnique.clear();
		userListUnique.clear();

		for (int i = 4; i <= 9; i++)
		{
			sysListUnique.push_back(i);
			userListUnique.push_back(i);
		}
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListUnique:", sysListUnique);
		std::cout << std::endl;
		print_ft_list("userListUnique:", userListUnique);
		std::cout << std::endl;

		sysListUnique.unique();
		userListUnique.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListUnique:", sysListUnique);
		std::cout << std::endl;
		print_ft_list("userListUnique:", userListUnique);
		std::cout << std::endl;

		testFunc(testNmb++,sysListUnique.size(), userListUnique.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListUnique.front(), userListUnique.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListUnique.back(), userListUnique.back(), "Back value is (Splice 3)");


		/*		unique	8	*/
		std::cout << std::endl << "\x1b[33m" << "unique 8" << "\x1b[0m" << std::endl;

		sysListUnique.clear();
		userListUnique.clear();

		for (int i = 4; i <= 9; i++)
		{
			sysListUnique.push_back(i);
			userListUnique.push_back(i);

			sysListUnique.push_back(i);
			userListUnique.push_back(i);
		}

		sysListUnique.push_back(7);
		userListUnique.push_back(7);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListUnique:", sysListUnique);
		std::cout << std::endl;
		print_ft_list("userListUnique:", userListUnique);
		std::cout << std::endl;

		sysListUnique.unique(same_integral_part);
		userListUnique.unique(same_integral_part);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListUnique:", sysListUnique);
		std::cout << std::endl;
		print_ft_list("userListUnique:", userListUnique);
		std::cout << std::endl;

		testFunc(testNmb++,sysListUnique.size(), userListUnique.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListUnique.front(), userListUnique.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListUnique.back(), userListUnique.back(), "Back value is (Splice 3)");

		getchar();
		std::system("clear");
	}

	if (merge)
	{
		/*		merge		*/
		std::cout << std::endl << "\x1b[33m" << "merge 1" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.merge(sysList);
		userList.merge(userList);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList2.size(), userList2.size(), "Size is");
		testFunc(testNmb++, sysList2.front(), userList2.front(), "Front value is");
		testFunc(testNmb++, sysList2.back(), userList2.back(), "Back value is ");

		getchar();
		// std::system("clear");

		/*		merge 2		*/
		std::cout << std::endl << "\x1b[33m" << "merge 2" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		sysList2.clear();
		userList2.clear();

		for (int i = 5; i <= 15; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}

		for (int i = 1; i < 5; i++)
		{
			sysList2.push_back(3);
			userList2.push_back(3);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		print_std_list(" sysList:", sysList2);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		print_ft_list("userList:", userList2);
		std::cout << std::endl;

		sysList.merge(sysList2);
		userList.merge(userList2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList2.size(), userList2.size(), "Size is");
		testFunc(testNmb++, sysList2.front(), userList2.front(), "Front value is");
		testFunc(testNmb++, sysList2.back(), userList2.back(), "Back value is ");

		getchar();
		// std::system("clear");

		/*		merge 3		*/
		std::cout << std::endl << "\x1b[33m" << "merge 3" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		sysList2.clear();
		userList2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}
		for (int i = 1; i <= 15; i++)
		{
			sysList2.push_back(i);
			userList2.push_back(i);
		}
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		print_std_list(" sysList:", sysList2);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		print_ft_list("userList:", userList2);
		std::cout << std::endl;

		sysList.merge(sysList2);
		userList.merge(userList2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList2.size(), userList2.size(), "Size is");
		testFunc(testNmb++, sysList2.front(), userList2.front(), "Front value is");
		testFunc(testNmb++, sysList2.back(), userList2.back(), "Back value is ");

		getchar();
		// std::system("clear");

		/*		merge		*/
		std::cout << std::endl << "\x1b[33m" << "merge 4" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		sysList2.clear();
		userList2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}

		for (int i = 6; i >= -5; i--)
		{
			sysList2.push_back(i);
			userList2.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		print_std_list(" sysList:", sysList2);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		print_ft_list("userList:", userList2);
		std::cout << std::endl;

		sysList.merge(sysList2);
		userList.merge(userList2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList2.size(), userList2.size(), "Size is");
		testFunc(testNmb++, sysList2.front(), userList2.front(), "Front value is");
		testFunc(testNmb++, sysList2.back(), userList2.back(), "Back value is ");

		getchar();
		// std::system("clear");
    
		/*		merge	5	*/
		std::cout << std::endl << "\x1b[33m" << "LENA merge 5" << "\x1b[0m" << std::endl;

		std::list <int> sysListMerge;
		std::list <int> sysListMerge2;
		ft::list <int> userListMerge;
		ft::list <int> userListMerge2;

		for (int i = 0; i <= 4; i++)
			sysListMerge.push_back(i);

		for (int i =5 ; i <= 9; i++)
			sysListMerge2.push_back(i);
		
		for (int i = 0; i <= 4; i++)
			userListMerge.push_back(i);

		for (int i = 5; i <= 9; i++)
			userListMerge2.push_back(i);
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_std_list(" sysListMerge2:", sysListMerge2);
		std::cout << std::endl;

		print_ft_list("userListMerge:", userListMerge);
		print_ft_list(" userListMerge2:", userListMerge2);
		std::cout << std::endl;

		sysListMerge.merge(sysListMerge2);
		userListMerge.merge(userListMerge2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_ft_list("userListMerge:", userListMerge);
		std::cout << std::endl;

		testFunc(testNmb++,sysListMerge.size(), userListMerge.size(), "Size is (Merge)");
		testFunc(testNmb++, sysListMerge.front(), userListMerge.front(), "Front value is (Merge)");
		testFunc(testNmb++, sysListMerge.back(), userListMerge.back(), "Back value is (Merge)");

		getchar();
		std::system("clear");

		/*		merge 6			*/
		std::cout << std::endl << "\x1b[33m" << "merge 6" << "\x1b[0m" << std::endl;

		sysListMerge.clear();
		sysListMerge2.clear();
		userListMerge.clear();
		userListMerge2.clear();

		sysListMerge.push_back(4);
		sysListMerge.push_back(-5);
		sysListMerge.push_back(0);
		sysListMerge.push_back(45);
		sysListMerge.push_back(-50);
		
		sysListMerge2.push_back(11);
		sysListMerge2.push_back(0);
		sysListMerge2.push_back(3);
		sysListMerge2.push_back(10);
		sysListMerge2.push_back(-23);   // 4 -5 0 45 -50 11 0 3 10 -23

		userListMerge.push_back(4);
		userListMerge.push_back(-5);
		userListMerge.push_back(0);
		userListMerge.push_back(45);
		userListMerge.push_back(-50);
		
		userListMerge2.push_back(11);
		userListMerge2.push_back(0);
		userListMerge2.push_back(3);
		userListMerge2.push_back(10);
		userListMerge2.push_back(-23);   // 4 -5 0 45 -50 11 0 3 10 -23
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_std_list(" sysListMerge2:", sysListMerge2);
		std::cout << std::endl;

		print_ft_list("userListMerge:", userListMerge);
		print_ft_list(" userListMerge2:", userListMerge2);
		std::cout << std::endl;

		sysListMerge.merge(sysListMerge2);
		userListMerge.merge(userListMerge2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_ft_list("userListMerge:", userListMerge);
		std::cout << std::endl;

		testFunc(testNmb++,sysListMerge.size(), userListMerge.size(), "Size is (Merge)");
		testFunc(testNmb++, sysListMerge.front(), userListMerge.front(), "Front value is (Merge)");
		testFunc(testNmb++, sysListMerge.back(), userListMerge.back(), "Back value is (Merge)");

		getchar();
		// std::system("clear");

		/*		merge	3	*/
		std::cout << std::endl << "\x1b[33m" << "merge 7" << "\x1b[0m" << std::endl;

		sysListMerge.clear();
		sysListMerge2.clear();
		userListMerge.clear();
		userListMerge2.clear();

		for (int i = 0; i <= 4; i++)
		{
			sysListMerge.push_back(i);
			userListMerge.push_back(i);
		}

		for (int i = 5 ; i <= 9; i++)
		{
			sysListMerge2.push_back(i);
			userListMerge2.push_back(i);
		}
			
		sysListMerge2.push_back(9);
		userListMerge2.push_back(9);
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_std_list(" sysListMerge2:", sysListMerge2);
		std::cout << std::endl;

		print_ft_list("userListMerge:", userListMerge);
		print_ft_list(" userListMerge2:", userListMerge2);
		std::cout << std::endl;

		sysListMerge2.merge(sysListMerge);
		userListMerge2.merge(userListMerge);
		
		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_ft_list("userListMerge:", userListMerge);
		std::cout << std::endl;
		print_std_list(" sysListMerge:", sysListMerge2);
		print_ft_list("userListMerge:", userListMerge2);
		std::cout << std::endl;


		testFunc(testNmb++,sysListMerge.size(), userListMerge.size(), "Size is (Merge)");
		testFunc(testNmb++, sysListMerge.front(), userListMerge.front(), "Front value is (Merge)");
		testFunc(testNmb++, sysListMerge.back(), userListMerge.back(), "Back value is (Merge)");
		getchar();
		// std::system("clear");

		/*		merge	8	*/
		std::cout << std::endl << "\x1b[33m" << "merge 8" << "\x1b[0m" << std::endl;

		sysListMerge.clear();
		 sysListMerge2.clear();
		 userListMerge.clear();
		  userListMerge2.clear();

		for (int i = 0; i <= 4; i++)
		{
			sysListMerge.push_back(i);
			userListMerge.push_back(i);
		}

		for (int i = 5 ; i <= 9; i++)
		{
			sysListMerge2.push_back(i);
			userListMerge2.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_std_list(" sysListMerge2:", sysListMerge2);
		std::cout << std::endl;

		print_ft_list("userListMerge:", userListMerge);
		print_ft_list(" userListMerge2:", userListMerge2);
		std::cout << std::endl;

		sysListMerge2.merge(sysListMerge, myobject);
		userListMerge2.merge(userListMerge, myobject);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge2);
		print_ft_list("userListMerge:", userListMerge2);
		std::cout << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_ft_list("userListMerge:", userListMerge);
		std::cout << std::endl;

		testFunc(testNmb++,sysListMerge2.size(), userListMerge2.size(), "Size is (Merge)");
		testFunc(testNmb++, sysListMerge2.front(), userListMerge2.front(), "Front value is (Merge)");
		testFunc(testNmb++, sysListMerge2.back(), userListMerge2.back(), "Back value is (Merge)");

		getchar();
		// std::system("clear");

		/*		merge	9	*/
		std::cout << std::endl << "\x1b[33m" << "merge 9" << "\x1b[0m" << std::endl;

		sysListMerge.clear();
		 sysListMerge2.clear();
		 userListMerge.clear();
		  userListMerge2.clear();

		for (int i = 0; i <= 4; i++)
		{
			sysListMerge.push_back(i);
			userListMerge.push_back(i);
		}

		for (int i = 5 ; i <= 9; i++)
		{
			sysListMerge2.push_back(i);
			userListMerge2.push_back(i);
		}

		for (int i = -3 ; i <= 10; i++)
		{
			sysListMerge2.push_back(i);
			userListMerge2.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_std_list(" sysListMerge2:", sysListMerge2);
		std::cout << std::endl;

		print_ft_list("userListMerge:", userListMerge);
		print_ft_list(" userListMerge2:", userListMerge2);
		std::cout << std::endl;

		sysListMerge2.merge(sysListMerge, mycomparison);
		userListMerge2.merge(userListMerge, mycomparison);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListMerge:", sysListMerge2);
		print_ft_list("userListMerge:", userListMerge2);
		std::cout << std::endl;
		print_std_list(" sysListMerge:", sysListMerge);
		print_ft_list("userListMerge:", userListMerge);
		std::cout << std::endl;

		testFunc(testNmb++,sysListMerge2.size(), userListMerge2.size(), "Size is (Merge)");
		testFunc(testNmb++, sysListMerge2.front(), userListMerge2.front(), "Front value is (Merge)");
		testFunc(testNmb++, sysListMerge2.back(), userListMerge2.back(), "Back value is (Merge)");

		getchar();
		// std::system("clear");
	}

	if (sort)
	{
		/*		sort 1		*/
		std::cout << std::endl << "\x1b[33m" << "sort 1" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 5; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}

		sysList.push_back(100);
		userList.push_back(100);

		sysList.push_back(99);
		userList.push_back(99);

		for (int i = 105; i <= 110; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.sort();
		userList.sort();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		getchar();
		// std::system("clear");
    
    	/*		sort 2		*/
		std::cout << std::endl << "\x1b[33m" << "sort 2" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		sysList.push_back(5);
		userList.push_back(5);

		sysList.push_back(2);
		userList.push_back(2);

		sysList.push_back(100);
		userList.push_back(100);

		sysList.push_back(30);
		userList.push_back(30);

		sysList.push_back(10);
		userList.push_back(10);

		sysList.push_back(1);
		userList.push_back(1);
		
		sysList.push_back(6);
		userList.push_back(6);

		sysList.push_back(150);
		userList.push_back(150);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.sort();
		userList.sort();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		getchar();
		// std::system("clear");
    
		/*		sort 3		*/
		std::cout << std::endl << "\x1b[33m" << "LENA sort 3" << "\x1b[0m" << std::endl;
		std::list <int> sysListSort;
		ft::list <int> userListSort;
		
		sysListSort.push_back(4);
		sysListSort.push_back(-5);
		sysListSort.push_back(0);
		sysListSort.push_back(45);
		sysListSort.push_back(-50);
		sysListSort.push_back(11);
		sysListSort.push_back(0);
		sysListSort.push_back(3);
		sysListSort.push_back(10);
		sysListSort.push_back(-23);   // 4 -5 0 45 -50 11 0 3 10 -23

		userListSort.push_back(4);
		userListSort.push_back(-5);
		userListSort.push_back(0);
		userListSort.push_back(45);
		userListSort.push_back(-50);
		userListSort.push_back(11);
		userListSort.push_back(0);
		userListSort.push_back(3);
		userListSort.push_back(10);
		userListSort.push_back(-23);   // 4 -5 0 45 -50 11 0 3 10 -23
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListSort:", sysListSort);
		std::cout << std::endl;
		print_ft_list("userListSort:", userListSort);
		std::cout << std::endl;
		sysListSort.sort();
		userListSort.sort();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListSort:", sysListSort);
		std::cout << std::endl;
		print_ft_list("userListSort:", userListSort);
		std::cout << std::endl;

		testFunc(testNmb++,sysListSort.size(), userListSort.size(), "Size is (sort)");
		testFunc(testNmb++, sysListSort.front(),userListSort.front(), "Front value is (sort)");
		testFunc(testNmb++, sysListSort.back(), userListSort.back(), "Back value is (sort)");

		getchar();

		/*		sort 3		*/
		std::cout << std::endl << "\x1b[33m" << "sort 4 (compare)" << "\x1b[0m" << std::endl;		
		std::list <int> sysListSortComp;
		ft::list <int> userListSortComp;
		
		sysListSortComp.push_back(4);
		sysListSortComp.push_back(-5);
		sysListSortComp.push_back(0);
		sysListSortComp.push_back(45);
		sysListSortComp.push_back(-50);
		sysListSortComp.push_back(11);
		sysListSortComp.push_back(0);
		sysListSortComp.push_back(3);
		sysListSortComp.push_back(10);
		sysListSortComp.push_back(-23);   // 4 -5 0 45 -50 11 0 3 10 -23

		userListSortComp.push_back(4);
		userListSortComp.push_back(-5);
		userListSortComp.push_back(0);
		userListSortComp.push_back(45);
		userListSortComp.push_back(-50);
		userListSortComp.push_back(11);
		userListSortComp.push_back(0);
		userListSortComp.push_back(3);
		userListSortComp.push_back(10);
		userListSortComp.push_back(-23);   // 4 -5 0 45 -50 11 0 3 10 -23

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListSortComp:", sysListSortComp);
		print_ft_list("userListSort:Comp", userListSortComp);
		std::cout << std::endl;

		sysListSortComp.sort(myobject);
		userListSortComp.sort(myobject);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListSortComp:", sysListSortComp);
		print_ft_list("userListSortComp:", userListSortComp);
		std::cout << std::endl;

		testFunc(testNmb++,sysListSortComp.size(), userListSortComp.size(), "Size is (sort)");
		testFunc(testNmb++, sysListSortComp.front(),userListSortComp.front(), "Front value is (sort)");
		testFunc(testNmb++, sysListSortComp.back(), userListSortComp.back(), "Back value is (sort)");

		getchar();
  }

    if (reverse)
	{
		/*		reverse		*/
		std::cout << std::endl << "\x1b[33m" << "reverse 1" << "\x1b[0m" << std::endl;

		std::list <int> sysListReverse;
		ft::list <int> userListReverse;

		for (int i = 4; i <= 9; i++)
		{
			sysListReverse.push_back(i);
			userListReverse.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListReverse:", sysListReverse);
		print_ft_list("userListReverse:", userListReverse);
		std::cout << std::endl;

		sysListReverse.reverse();
		userListReverse.reverse();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListReverse:", sysListReverse);
		print_ft_list("userListReverse:", userListReverse);
		std::cout << std::endl;

		testFunc(testNmb++,sysListReverse.size(), userListReverse.size(), "Size is (Reverse)");
		testFunc(testNmb++, sysListReverse.front(), userListReverse.front(), "Front value is (Reverse)");
		testFunc(testNmb++, sysListReverse.back(), userListReverse.back(), "Back value is (Reverse)");

		getchar();
		std::system("clear");

		/*		reverse	2	*/
		std::cout << std::endl << "\x1b[33m" << "reverse 2" << "\x1b[0m" << std::endl;

		sysListReverse.clear();
		userListReverse.clear();

		for (int i = 4; i <= 9; i++)
		{
			sysListReverse.push_back(4);
			userListReverse.push_back(4);
		}
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListReverse:", sysListReverse);
		print_ft_list("userListReverse:", userListReverse);
		std::cout << std::endl;

		sysListReverse.reverse();
		userListReverse.reverse();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListReverse:", sysListReverse);
		print_ft_list("userListReverse:", userListReverse);
		std::cout << std::endl;

		testFunc(testNmb++,sysListReverse.size(), userListReverse.size(), "Size is (Reverse)");
		testFunc(testNmb++, sysListReverse.front(), userListReverse.front(), "Front value is (Reverse)");
		testFunc(testNmb++, sysListReverse.back(), userListReverse.back(), "Back value is (Reverse)");

		getchar();
		// std::system("clear");

		/*		reverse	3	*/
		std::cout << std::endl << "\x1b[33m" << "reverse 3" << "\x1b[0m" << std::endl;

		sysListReverse.clear();
		userListReverse.clear();

		for (int i = 4; i < 5; i++)
		{
			sysListReverse.push_back(4);
			userListReverse.push_back(4);
		}
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysListReverse:", sysListReverse);
		print_ft_list("userListReverse:", userListReverse);
		std::cout << std::endl;

		sysListReverse.reverse();
		userListReverse.reverse();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysListReverse:", sysListReverse);
		print_ft_list("userListReverse:", userListReverse);
		std::cout << std::endl;

		testFunc(testNmb++,sysListReverse.size(), userListReverse.size(), "Size is (Reverse)");
		testFunc(testNmb++, sysListReverse.front(), userListReverse.front(), "Front value is (Reverse)");
		testFunc(testNmb++, sysListReverse.back(), userListReverse.back(), "Back value is (Reverse)");

		getchar();
	// 	std::system("clear");
  }

}
  
  void				overloads(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                         *** OVERLOADES ***                          " << "\x1b[0m" << std::endl;

	std::list<int> Sys_a;
	std::list<int> Sys_b;
	std::list<int> Sys_c;
	std::list<int> Sys_d;
	std::list<int> Sys_f;

	ft::list<int> User_a;
  	ft::list<int> User_b;
  	ft::list<int> User_c;
	ft::list<int> User_d;
	ft::list<int> User_f;

	for (int i = 10; i < 40;)
	{
		Sys_a.push_back(i);
		Sys_b.push_back(i);
		User_a.push_back(i);
		User_b.push_back(i);
		i += 10;
	}

	for (int i = 30; i >= 10;)
	{
		Sys_c.push_back(i);
		User_c.push_back(i);
		i -= 10;
	}

	Sys_f.push_back(30);
	User_f.push_back(30);
	
	std::cout << "*** BEFORE ***" << std::endl;
	print_std_list(" Sys_a:", Sys_a);
	print_std_list(" Sys_b:", Sys_b);
	print_std_list(" Sys_c:", Sys_c);
	print_std_list(" Sys_d:", Sys_d);
	print_std_list(" Sys_f:", Sys_f);
	std::cout << std::endl;
	
	print_ft_list("User_a:", User_a);
	print_ft_list("User_b:", User_b);
	print_ft_list("User_c:", User_c);
	print_ft_list("User_d:", User_d);
	print_ft_list("User_f:", User_f);
	std::cout << std::endl;

	try
	{
		testFunc(testNmb++, (Sys_a == Sys_b), (User_a == User_b), "a == b");
		testFunc(testNmb++, (Sys_b == Sys_c), (User_b == User_c), "b == c");
		testFunc(testNmb++, (Sys_a == Sys_d), (User_a == User_d), "a == d");
		testFunc(testNmb++, (Sys_d == Sys_c), (User_d == User_c), "d == c");
		testFunc(testNmb++, (Sys_a == Sys_f), (User_a == User_f), "a == f");
		testFunc(testNmb++, (Sys_f == Sys_c), (User_f == User_c), "f == c");

		testFunc(testNmb++, (Sys_a != Sys_b), (User_a != User_b), "a != b");
		testFunc(testNmb++, (Sys_b != Sys_c), (User_b != User_c), "b != c");
		testFunc(testNmb++, (Sys_a != Sys_d), (User_a != User_d), "a != d");
		testFunc(testNmb++, (Sys_d != Sys_c), (User_d != User_c), "d != c");
		testFunc(testNmb++, (Sys_a != Sys_f), (User_a != User_f), "a != f");
		testFunc(testNmb++, (Sys_f != Sys_c), (User_f != User_c), "f != c");

		testFunc(testNmb++, (Sys_a < Sys_b), (User_a < User_b), "a < b");
		testFunc(testNmb++, (Sys_b < Sys_c), (User_b < User_c), "b < c");
		testFunc(testNmb++, (Sys_a < Sys_d), (User_a < User_d), "a < d");
		testFunc(testNmb++, (Sys_d < Sys_c), (User_d < User_c), "d < c");
		testFunc(testNmb++, (Sys_a < Sys_f), (User_a < User_f), "a < f");
		testFunc(testNmb++, (Sys_f < Sys_c), (User_f < User_c), "f < c");

		testFunc(testNmb++, (Sys_a > Sys_b), (User_a > User_b), "a > b");
		testFunc(testNmb++, (Sys_b > Sys_c), (User_b > User_c), "b > c");
		testFunc(testNmb++, (Sys_a > Sys_d), (User_a > User_d), "a > d");
		testFunc(testNmb++, (Sys_d > Sys_c), (User_d > User_c), "d > c");
		testFunc(testNmb++, (Sys_a > Sys_f), (User_a > User_f), "a > f");
		testFunc(testNmb++, (Sys_f > Sys_c), (User_f > User_c), "f > c");

		testFunc(testNmb++, (Sys_a <= Sys_b), (User_a <= User_b), "a <= b");
		testFunc(testNmb++, (Sys_b <= Sys_c), (User_b <= User_c), "b <= c");
		testFunc(testNmb++, (Sys_a <= Sys_d), (User_a <= User_d), "a <= d");
		testFunc(testNmb++, (Sys_d <= Sys_c), (User_d <= User_c), "d <= c");
		testFunc(testNmb++, (Sys_a <= Sys_f), (User_a <= User_f), "a <= f");
		testFunc(testNmb++, (Sys_f <= Sys_c), (User_f <= User_c), "f <= c");

		testFunc(testNmb++, (Sys_a >= Sys_b), (User_a >= User_b), "a >= b");
		testFunc(testNmb++, (Sys_b >= Sys_c), (User_b >= User_c), "b >= c");
		testFunc(testNmb++, (Sys_a >= Sys_d), (User_a >= User_d), "a >= d");
		testFunc(testNmb++, (Sys_d >= Sys_c), (User_d >= User_c), "d >= c");
		testFunc(testNmb++, (Sys_a >= Sys_f), (User_a >= User_f), "a >= f");
		testFunc(testNmb++, (Sys_f >= Sys_c), (User_f >= User_c), "f >= c");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	getchar();
}

/* extra */
void				operators(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                         *** VALUES AND OPERATORS ***                          " << "\x1b[0m" << std::endl;

	ft::list <int> userList;
	std::list <int> sysList;

	std::list <int> :: iterator sysData;
	ft::list <int> :: iterator userData = userList.begin(); // delete  = userList.begin()
	
	sysList.clear();
	userList.clear();

	for (int i = 1; i <= 5; i++)
	{
		sysList.push_back(i);
		userList.push_back(i);
	}

	sysData = sysList.begin();
	userData = userList.begin();

	testFunc(testNmb++, *sysData, *userData, "Operators test *a");

	sysData++;
	userData++;
	testFunc(testNmb++, *sysData, *userData, "Operators test a++");

	sysData--;
	userData--;
	testFunc(testNmb++, *sysData, *userData, "Operators test a--");

	sysData = sysList.begin();
	userData = userList.begin();
	testFunc(testNmb++, *sysData, *userData, "Operators test *a");

	sysData = sysList.begin();
	userData = userList.begin();
	sysData++;
	userData++;
	testFunc(testNmb++, *sysData, *userData, "Operators test a++");

	sysData++;
	userData++;
	testFunc(testNmb++, *sysData, *userData, "Operators test a++");

	sysData++;
	userData++;
	sysData++;
	userData++;
	testFunc(testNmb++, *sysData, *userData, "Operators test a++");

	ft::list <int> testMyList;
	std::list <int> testOriginalList;

	sysData = testOriginalList.begin();
	userData = testMyList.begin();
	sysData++;
	userData++;
	testFunc(testNmb++, *sysData, *userData, "Begin value test ++a");
	std::cout << "\x1b[31m" << "NO TEST" << "\x1b[0m" << std::endl;

	sysData = sysList.end();
	userData = userList.end();
	sysData--;
	userData--;
	testFunc(testNmb++, *sysData, *userData, "End value test a--");


	sysData = testOriginalList.end();
	userData = testMyList.end();
	sysData--;
	userData--;
	testFunc(testNmb++, *sysData, *userData, "End value test --a");
	std::cout << "\x1b[31m" << "NO TEST" << "\x1b[0m" << std::endl;
  
 
	ft::list <int> testMyList1;
	std::list <int> testOriginalList1;

	testMyList1.push_front(55);
	testOriginalList1.push_front(55);
			
	sysData = testOriginalList.end();
	userData = testMyList.end();
			
	sysData = testOriginalList.begin();
	userData = testMyList.begin();
	testFunc(testNmb++, *sysData, *userData, "End value test a=b");
	
	getchar();

}

void				list_test()
{
	int testNmb = 0;
	int testAll = 1;

	std::system("clear");
	
	std::cout << "\x1b[33m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|          LIST TESTING          |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	/*			Member functions			*/
	
	// constructor(testNmb, testAll);
	// // destructor(testNmb);						// need tests
  	// operEquall(testNmb, testAll);			
	// iterators(testNmb, testAll);
	capacity(testNmb, testAll);
	// elementAccess(testNmb, testAll);
	// modifiers(testNmb, testAll);
	// operations(testNmb, testAll);
	overloads(testNmb);

	/* extra */
	// operators(testNmb);		
}
