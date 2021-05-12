/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <ssnowbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:18 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/23 14:14:51 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

#include <string>
#include <cassert>
#include <algorithm>
#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue

// #include <list>
// #include <map>
// #include <stack>
// #include <dequeue>
#include <queue>

#include <iostream>

#include "../containers/Queue/queue.hpp"
#include "../containers/list/list.hpp"
// #include <vector>

// using namespace std; // delete
// using namespace ft; // delete

void memberFunc_queue(int testNmb,  int testAll)
{
	int constructor = 0;
	int empty = 0;
	int size = 0;
	int front = 0;
	int back = 0;
	int push = 0;
	int pop = 0;

	if(testAll)
	{
		constructor = 1;
		empty = 1;
		size = 1;
		front = 1;
		back = 1;
		push = 1;
		pop = 1;	
	}
	if(constructor)
	{
		std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;
		std::cout << std::endl << "\x1b[33m" << "constructor test" << "\x1b[0m" << std::endl;
		
		std::deque<int> mydeck (3,100);        // deque with 3 elements
		std::list<int> mylist (2,200);         // list with 2 elements

		ft::queue<int> first;                 // empty queue
		ft::queue<int> second (mydeck);       // queue initialized to copy of deque

		ft::queue<int,std::list<int> > third; // empty queue with list as underlying container
		ft::queue<int,std::list<int> > fourth (mylist);

		std::queue<int> first2;                 // empty queue
		std::queue<int> second2 (mydeck);       // queue initialized to copy of deque

		std::queue<int,std::list<int> > third2; // empty queue with list as underlying container
		std::queue<int,std::list<int> > fourth2 (mylist);

		testFunc(testNmb++,  fourth2.size(), fourth.size(), "size");
		testFunc(testNmb++, fourth2.front(), fourth.front(), "front");
		testFunc(testNmb++, fourth2.back(), fourth.back(), "back");
		testFunc(testNmb++,  second2.size(), second.size(), "size");
		testFunc(testNmb++, second2.front(), second.front(), "front");
		testFunc(testNmb++, second2.back(), second.back(), "back");
		getchar();
		std::system("clear");
	}

	if(empty)
	{
		std::cout << std::endl << "\x1b[33m" << "empty" << "\x1b[0m" << std::endl;
		ft::queue<int> queueEmpty;
		std::queue<int> queueEmptySys;

		testFunc(testNmb++,  queueEmptySys.empty(), queueEmpty.empty(), "empty");

		for(int i = 1; i < 6; i++)
		{
			 queueEmpty.push(i);
			 queueEmptySys.push(i);
		}
		testFunc(testNmb++,  queueEmptySys.empty(), queueEmpty.empty(), "empty");
		
		getchar();
		std::system("clear");
	}
	
	if(push)
	{
		std::cout << std::endl << "\x1b[33m" << "push" << "\x1b[0m" << std::endl;
		ft::queue<int> queuePush;
		std::queue<int> queuePushSys;

		queuePush.push(21);
		queuePushSys.push(21);
		testFunc(testNmb++,  queuePushSys.size(), queuePush.size(), "size");
		testFunc(testNmb++, queuePushSys.front(), queuePush.front(), "front");
		testFunc(testNmb++, queuePushSys.back(), queuePush.back(), "back");

		getchar();
		std::system("clear");
	}

	if(pop)
	{
		std::cout << std::endl << "\x1b[33m" << "pop" << "\x1b[0m" << std::endl;
		ft::queue<int> queuePop;
		std::queue<int> queuePopSys;
		for(int i = 1; i < 6; i++)
		{
			 queuePop.push(i);
			 queuePopSys.push(i);
		}
		queuePop.pop();
		queuePopSys.pop();
		testFunc(testNmb++,  queuePopSys.size(), queuePop.size(), "size");
		testFunc(testNmb++, queuePopSys.front(), queuePop.front(), "front");
		testFunc(testNmb++, queuePopSys.back(), queuePop.back(), "back");
		getchar();
		std::system("clear");
	}
	
	if(size)
	{
		std::cout << std::endl << "\x1b[33m" << "size" << "\x1b[0m" << std::endl;
		ft::queue<int> queueSize;
		std::queue<int> queueSizeSys;
		for(int i = 1; i < 6; i++)
		{
			 queueSize.push(i);
			 queueSizeSys.push(i);
		}
		testFunc(testNmb++,  queueSizeSys.size(), queueSize.size(), "size");
		getchar();
		std::system("clear");
	}

	if(front)
	{
		std::cout << std::endl << "\x1b[33m" << "front" << "\x1b[0m" << std::endl;
		ft::queue<int> queueFront;
		std::queue<int> queueFrontSys;

		for(int i = 1; i < 6; i++)
		{
			 queueFront.push(i);
			 queueFrontSys.push(i);
		}
		testFunc(testNmb++,  queueFrontSys.size(), queueFront.size(), "size");
		testFunc(testNmb++,  queueFrontSys.front(), queueFront.front(), "front");

		getchar();
		std::system("clear");
	}

	if(back)
	{
		std::cout << std::endl << "\x1b[33m" << "back" << "\x1b[0m" << std::endl;
		ft::queue<int> queueBack;
		std::queue<int> queueBackSys;

		for(int i = 1; i < 6; i++)
		{
			 queueBack.push(i);
			 queueBackSys.push(i);
		}
		testFunc(testNmb++,  queueBackSys.size(), queueBack.size(), "size");
		testFunc(testNmb++,  queueBackSys.back(), queueBack.back(), "back");
		
		getchar();
		std::system("clear");
	}
}

void non_memberFunc_queue(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** OVERLOADES ***                          " << "\x1b[0m" << std::endl;
	std::list<int> queueSys_a ;

	queueSys_a.push_back(10);
	queueSys_a.push_back(20);
	queueSys_a.push_back(30);

	std::list<int> queueSys_b ;

	queueSys_b.push_back(10);
	queueSys_b.push_back(20);
	queueSys_b.push_back(30);

	std::list<int> queueSys_c;

	queueSys_c.push_back(30);
	queueSys_c.push_back(20);
	queueSys_c.push_back(10);

    ft::queue<int, std::list<int> > queue_a(queueSys_a);
    ft::queue<int, std::list<int> > queue_b(queueSys_b);
    ft::queue<int, std::list<int> > queue_c(queueSys_c);

	bool equality = (queue_a == queue_b);
	bool unequality = (queue_b != queue_c);
	bool less = (queue_b < queue_c);
	bool more = (queue_c > queue_b);
	bool lessAndEquality = (queue_a <= queue_b);
	bool moreAndEquality = (queue_a >= queue_b);


	bool equality2 = (queueSys_a == queueSys_b);
	bool unequality2 = (queueSys_b != queueSys_c);
	bool less2 = (queueSys_b < queueSys_c);
	bool more2 = (queueSys_c > queueSys_b);
	bool lessAndEquality2 = (queueSys_a <= queueSys_b);
	bool moreAndEquality2 = (queueSys_a >= queueSys_b);

	testFunc(testNmb++, equality, equality2, "a == b");
	testFunc(testNmb++, unequality, unequality2, "b != c");
	testFunc(testNmb++, less, less2, "b < c");
	testFunc(testNmb++, more, more2, "c > b");
	testFunc(testNmb++, lessAndEquality, lessAndEquality2, "a <= b");
	testFunc(testNmb++, moreAndEquality, moreAndEquality2, "a >= b");
}

void queue_test()
{
	std::cout << "\x1b[32m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|          QUEUE TESTING         |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	int testNmb = 0;
	int testAll = 1;

	memberFunc_queue(testNmb,  testAll);
	non_memberFunc_queue(testNmb);
	

}
