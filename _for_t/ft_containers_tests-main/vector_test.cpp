/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:04:46 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/05 21:49:52 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector/vector.hpp"
#include "containers_test.hpp"

#include <string>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

void				constructor_vector(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;

	if (testAll)
	{
		/* default constructor */
		std::cout << std::endl << "\x1b[33m" << "default constructor" << "\x1b[0m" << std::endl;	
		ft::vector <int> vectorConstrUserFree;
		std::vector <int> vectorConstrSysFree;

		testFunc(testNmb++, vectorConstrSysFree.size(), vectorConstrUserFree.size(),  "vector size()");

		/* simple constructor */
		std::cout << std::endl << "\x1b[33m" << "simple constructor" << "\x1b[0m" << std::endl;	
		ft::vector<int> vUser(4, 100);
		std::vector <int> vSys(4, 100);

		std::cout << "*** PRINT VECTOR ***" << std::endl;
		print_std_vector(" Sys Erase:", vSys);
		print_ft_vector("User Erase:", vUser);
		std::cout << std::endl;

		ft::vector<int>::iterator itUser = vUser.begin();
		std::vector<int>::iterator itSys = vSys.begin();

		ft::vector<int>::iterator itUser2 = vUser.end();
		std::vector<int>::iterator itSys2 = vSys.end();

		testFunc(testNmb++, *itSys, *itUser, "vector begin()");
		// testFunc(testNmb++, *itSys2, *itUser2, "vector end()"); // trash
		itUser2--;
		itSys2--;
		testFunc(testNmb++, *itSys2, *itUser2, "vector end()");
		testFunc(testNmb++, vUser.size(), vSys.size(),  "vector size()");
		getchar();


		/* copy constructor */
		// std::cout << std::endl << "\x1b[33m" << "copy constructor" << "\x1b[0m" << std::endl;
		// ft::vector  <int> vUserCopy(vUser);
		// std::vector <int> vSysCopy(vSys);

		// std::cout << "*** PRINT COPY CONSTRUCTOR ***" << std::endl;
		// print_std_vector(" Sys Erase:", vSysCopy);
		// print_ft_vector("User Erase:", vUserCopy);
		// std::cout << std::endl;
		
		// testFunc(testNmb++, vSysCopy.size(), vUserCopy.size(), "Constructor copy");
		
		// std::vector<int>::iterator itConstrCopySys = sysVectorCopy.begin();
		// ft::vector<int>::iterator itConstrCopy = userVectorCopy.begin();
		
		
		// testFunc(testNmb++, *itConstrCopySys, *itConstrCopy, "Constructor copy - value");

		// itConstrCopySys =  sysVectorCopy.end();
		// itConstrCopySys--;
		// itConstrCopy =  userVectorCopy.end();
		// itConstrCopy--;

		// std::cout << std::endl << "\x1b[33m" << "constructor InputIterator" << "\x1b[0m" << std::endl;

		
		// itConstrCopySys = sysVectorCopy.begin();
		// itConstrCopy = userVectorCopy.begin();

		// std::vector  <int>::iterator itConstrCopySys2 = sysVectorCopy.end();
		// ft::vector  <int>::iterator itConstrCopy2 = userVectorCopy.end();

		// ft::vector  <int> userVectorInputIt(itConstrCopy,itConstrCopy2);
		// std::vector <int> sysVectorInpuIt(itConstrCopySys, itConstrCopySys2);
		
		// testFunc(testNmb++, sysVectorCopy.size(), userVectorCopy.size(), "Constructor InputIterator");
		// testFunc(testNmb++, *itConstrCopySys, *itConstrCopy, "Constructor InputIterator - value");

		// itConstrCopySys =  sysVectorCopy.end();
		// itConstrCopySys--;
		// itConstrCopy =  userVectorCopy.end();
		// itConstrCopy--;
		
		// testFunc(testNmb++, *itConstrCopySys, *itConstrCopy, "Back value is");
		// getchar();
		// std::system("clear");
	}
	system("clear");
}

void				iterators_vector(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** ITERATORS ***                          " << "\x1b[0m" << std::endl;
	
	int			begin = 0;
	int			end = 0;
	int			rbegin = 0;
	int			rend = 0;
	int			const_begin = 0;
	int			const_end = 0;
	int			const_rbegin = 0;
	int			const_rend = 0;

	if (testAll)
	{
		begin = 1;
		end = 1;
		rbegin = 1;
		rend = 1;
		const_begin = 1;
		const_end = 1;
		const_rbegin = 1;
		const_rend = 1;
	}

	testNmb++;
	
	//***************************CONST BEGIN AND CONST END************************//
	if(const_begin && const_end)
	{
		std::cout << std::endl << "\x1b[33m" << "const begin and const end" << "\x1b[0m" << std::endl;

		const ft::vector  <int> userVectorConst(5,4);
		const std::vector <int> sysVectorConst(5,4);

		std::vector <int>::const_iterator const_s_s = sysVectorConst.begin(); 
		ft::vector <int>::const_iterator const_m_s = userVectorConst.begin();
		std::vector <int>::const_iterator const_s_f;
		const_s_f  = sysVectorConst.end();
		const_s_f--;
		ft::vector <int>::const_iterator const_m_f;
		const_m_f = userVectorConst.end();
		const_m_f--;

		testFunc(testNmb++, *const_s_s, *const_m_s, "Const test begin");
		testFunc(testNmb++, *const_s_f, *const_m_f, "Const test end");
		
		testFunc(testNmb++, sysVectorConst.size(), userVectorConst.size(), "size");
		testFunc(testNmb++, sysVectorConst.capacity(), userVectorConst.capacity(), "capacity");
		
		getchar();
	}
	
	//***************************CONST RBEGIN AND CONST REND************************//
	if(const_rbegin && const_rend)
	{
		const ft::vector  <int> userVectorConst(5,4);
		const std::vector <int> sysVectorConst(5,4);
		
		std::cout << std::endl << "\x1b[33m" << "const rbegin and const rend" << "\x1b[0m" << std::endl;

		std::vector <int>::const_reverse_iterator constr_s_s = sysVectorConst.rbegin(); 
		constr_s_s++;
		ft::vector <int>::const_reverse_iterator constr_m_s = userVectorConst.rbegin();
		constr_m_s++;
		std::vector <int>::const_reverse_iterator constr_s_f;
		constr_s_f  = sysVectorConst.rend();
		constr_s_f--;
		ft::vector <int>::const_reverse_iterator constr_m_f;
		constr_m_f = userVectorConst.rend();
		constr_m_f--;

		testFunc(testNmb++, *constr_s_s, *constr_m_s, "Const reverse test begin");
		testFunc(testNmb++, *constr_s_f, *constr_m_f, "Const reverse test end");
		getchar();
	}
	
	//***************************BEGIN AND END************************//
	if(begin && end)
	{
		std::cout << std::endl << "\x1b[33m" << "begin and end" << "\x1b[0m" << std::endl;

		ft::vector  <int> userVectorSimple(5,4);
		std::vector <int> sysVectorSimple(5,4);

		std::vector <int>::iterator simple_s_s = sysVectorSimple.begin(); 
		ft::vector <int>::iterator simple_m_s = userVectorSimple.begin();
		
		std::vector <int>::iterator simple_s_f;
		simple_s_f  = sysVectorSimple.end();
		simple_s_f--;
		
		ft::vector <int>::iterator simple_m_f;
		simple_m_f = userVectorSimple.end();
		simple_m_f--;

		testFunc(testNmb++, *simple_s_s, *simple_m_s, "test begin");
		testFunc(testNmb++, *simple_s_f, *simple_m_f, "test end");
		getchar();
	}

	//***************************REVERSE BEGIN AND END************************//
	if(rbegin && rend)
	{
		std::cout << std::endl << "\x1b[33m" << "reverse begin and end" << "\x1b[0m" << std::endl;
		
		ft::vector  <int> userVect(1, 4);
		std::vector <int> sysVect(1, 4);
		
		sysVect.resize(2, 5);
		userVect.resize(2, 5);
		
		sysVect.resize(4, 10);
		userVect.resize(4, 10);

		sysVect.resize(5, 11);
		userVect.resize(5, 11);

		testNmb = compareClasses(testNmb++, sysVect, userVect);

		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testFunc(testNmb++, *(sysVect.rbegin()), *(userVect.rbegin()), "rbegin");
		
		std::vector <int>::reverse_iterator simpler_s_f = sysVect.rend();
		ft::vector <int>::reverse_iterator simpler_m_f = userVect.rend();
		
		simpler_s_f--;
		simpler_m_f--;		

		testFunc(testNmb++, *simpler_s_f, *simpler_m_f, "rend");
		getchar();
	}
	system("clear");
}

void				capacity_vector(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** CAPACITY ***                          " << "\x1b[0m" << std::endl;
	
	int			size = 0;
	int			max_size = 0;
	int			resize = 0;
	int			capacity = 0;
	int			empty = 0;
	int			reserve = 0;


	if (testAll)
	{
		size = 1;
		max_size = 1;
		resize = 1;
		capacity = 1;
		empty = 1;
		reserve = 1;
	}

	//***************************SIZE************************//
	if(size)
	{
		std::cout << std::endl << "\x1b[33m" << "size" << "\x1b[0m" << std::endl;

		ft::vector  <int> userVectorSimple(7,4);
		std::vector <int> sysVectorSimple(7,4);

		testFunc(testNmb++, sysVectorSimple.size(), userVectorSimple.size(), "size");
		getchar();
	}

	//***************************MAX_SIZE************************//
	if(max_size)
	{
		ft::vector  <int> userVectorSimple(7,4);
		std::vector <int> sysVectorSimple(7,4);

		std::cout << std::endl << "\x1b[33m" << "max_size" << "\x1b[0m" << std::endl;
		testFunc(testNmb++, sysVectorSimple.max_size(), userVectorSimple.max_size(), "max_size");
		getchar();
	}

	//***************************RESIZE************************//
	if(resize)
	{
		/* resize */
		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
		
		ft::vector  <int> userVectorResize(3, 4);
		std::vector <int> sysVectorResize(3, 4);

		testFunc(testNmb++, sysVectorResize.size(), userVectorResize.size(), "size before");
		testFunc(testNmb++, sysVectorResize.capacity(), userVectorResize.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysVectorResize, userVectorResize);
		
		userVectorResize.resize(5, 7);
		sysVectorResize.resize(5, 7);

		testFunc(testNmb++, sysVectorResize.size(), userVectorResize.size(), "size after");
		testFunc(testNmb++, sysVectorResize.capacity(), userVectorResize.capacity(), "capacity after");
		testNmb = compareClasses(testNmb++, sysVectorResize, userVectorResize);
		
		getchar();
		system("clear");

		/* resize */
		std::cout << std::endl << "\x1b[33m" << "resize 2" << "\x1b[0m" << std::endl;
		
		testFunc(testNmb++, sysVectorResize.size(), userVectorResize.size(), "size after");
		testNmb = compareClasses(testNmb++, sysVectorResize, userVectorResize);
		
		userVectorResize.assign(10, 2);
		sysVectorResize.assign( 10, 2);

		testFunc(testNmb++, sysVectorResize.size(), userVectorResize.size(), "size before");
		testNmb = compareClasses(testNmb++, sysVectorResize, userVectorResize);

		userVectorResize.resize(5);
		sysVectorResize.resize(5);

		testFunc(testNmb++, sysVectorResize.size(), userVectorResize.size(), "size after");
		testNmb = compareClasses(testNmb++, sysVectorResize, userVectorResize);
		getchar();
		system("clear");
	}
	
	//***************************CAPACITY************************//
	if(capacity)
	{
		ft::vector  <int> userVectorSimple(7,4);
		std::vector <int> sysVectorSimple(7,4);

		std::cout << std::endl << "\x1b[33m" << "capacity" << "\x1b[0m" << std::endl;
		testFunc(testNmb++, sysVectorSimple.capacity(), userVectorSimple.capacity(), "capacity");
		getchar();
	}
	
	//***************************EMPTY************************//
	if(empty)
	{
		std::cout << std::endl << "\x1b[33m" << "empty" << "\x1b[0m" << std::endl;
	
		ft::vector  <int> userVectorSimple(7,4);
		std::vector <int> sysVectorSimple(7,4);

		ft::vector  <int> userVectorSimple1;
		std::vector <int> sysVectorSimple1;
		
		testFunc(testNmb++, sysVectorSimple1.empty(), userVectorSimple1.empty(), "vector empty");
		testFunc(testNmb++, sysVectorSimple.empty(), userVectorSimple.empty(), "vector no empty");
		getchar();
	}
	
	//***************************RESERVE************************// //ДЕЛАТЬ!!!!!!!!!
	if(reserve)
	{
		std::cout << std::endl << "\x1b[33m" << "reserve" << "\x1b[0m" << std::endl;
	
		ft::vector  <int> userVectorReserve(7, 4);
		std::vector <int> sysVectorReserve(7, 4);

		testFunc(testNmb++, sysVectorReserve.size(), userVectorReserve.size(), "size");
		testFunc(testNmb++, sysVectorReserve.capacity(), userVectorReserve.capacity(), "capacity");

		userVectorReserve.reserve(3);
		sysVectorReserve.reserve(3);
		testFunc(testNmb++, sysVectorReserve.size(), userVectorReserve.size(), "size (reserve 3)");
		testFunc(testNmb++, sysVectorReserve.capacity(), userVectorReserve.capacity(), "capacity (reserve 3)");

		userVectorReserve.reserve(20);
		sysVectorReserve.reserve(20);
		testFunc(testNmb++, sysVectorReserve.size(), userVectorReserve.size(), "size (reserve 20)");
		testFunc(testNmb++, sysVectorReserve.capacity(), userVectorReserve.capacity(), "capacity (reserve 20)");

		userVectorReserve.reserve(0);
		sysVectorReserve.reserve(0);
		testFunc(testNmb++, sysVectorReserve.size(), userVectorReserve.size(), "size (reserve 0)");
		testFunc(testNmb++, sysVectorReserve.capacity(), userVectorReserve.capacity(), "capacity (reserve 0)");
		testNmb = compareClasses(testNmb++, sysVectorReserve, userVectorReserve);

		// print_std_vector("System array:", sysVectorReserve);
		// print_ft_vector("  User array:", userVectorReserve);
		
		getchar();
	}
	system("clear");
}

void				elementAccess_vector(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** ELEMENT ACCESS ***                          " << "\x1b[0m" << std::endl;
	
	int			Operator = 0;
	int			at = 0;
	int			front = 0;
	int			back = 0;


	if (testAll)
	{
		Operator = 1;	 
		at = 1;
		front = 1;
		back = 1;
	}
	
	//***************************OPERATOR []************************//
	if(Operator)
	{
		std::cout << std::endl << "\x1b[33m" << "operator []" << "\x1b[0m" << std::endl;

		ft::vector  <int> userVectorOperator(5,4);
		std::vector <int> sysVectorOperator(5,4);

		std::string name;

		for(size_t i = 0; i < sysVectorOperator.size(); i++)
		{
			name = "check arr[" + std::to_string(i);
			name = name + "]";
			testFunc(testNmb++, userVectorOperator[i], sysVectorOperator[i], name);
		}
		testFunc(testNmb++, sysVectorOperator.size(), userVectorOperator.size(), "size");
		testFunc(testNmb++, sysVectorOperator.capacity(), userVectorOperator.capacity(), "capacity");
		
		getchar();
	}

	//***************************AT************************//
	if(at)
	{
		try
		{
			std::cout << std::endl << "\x1b[33m" << "at" << "\x1b[0m" << std::endl;

			ft::vector  <int> userVectorAt;
			std::vector <int> sysVectorAt;

			for(size_t i = 0; i < 10; i++)
			{
				 userVectorAt.push_back(i);
				 sysVectorAt.push_back(i);
			}
			
			testFunc(testNmb++, userVectorAt.at(5), sysVectorAt.at(5), ".at(5)");
			// testFunc(testNmb++, userVectorAt.at(30), sysVectorAt.at(30), ".at(30) - wrong"); // раскомментить когда надо
		}
		catch(const std::exception& e)
		{
			std::cout << "EXCEPTOIN: Out of Range error:" <<std::cerr << e.what() << '\n';
		}
		
		try
		{
			std::cout << std::endl << "\x1b[33m" << "at const" << "\x1b[0m" << std::endl;

			const ft::vector  <int> userVectorAt(5, 4);
			const std::vector <int> sysVectorAt(5, 4);

			testFunc(testNmb++, userVectorAt.at(4), sysVectorAt.at(4), ".at(5)");
			// testFunc(testNmb++, userVectorAt.at(30), sysVectorAt.at(30), ".at(30) - wrong"); // раскомментить когда надо
		}
		catch(const std::exception& e)
		{
			std::cout << "EXCEPTOIN: Out of Range error:" <<std::cerr << e.what() << '\n';
		}
		getchar();
	}
	
	//***************************FRONT************************//
	if(front)
	{
		ft::vector  <int> userVectorFront;
		std::vector <int> sysVectorFront;
		
		/* front */
		std::cout << std::endl << "\x1b[33m" << "front" << "\x1b[0m" << std::endl;

		for(size_t i = 1; i < 10; i++)
		{
			userVectorFront.push_back(i);
			sysVectorFront.push_back(i);
		}
		testFunc(testNmb++, sysVectorFront.front(), userVectorFront.front(), "front");
	
		/* front */
		std::cout << std::endl << "\x1b[33m" << "front empty" << "\x1b[0m" << std::endl;

		userVectorFront.clear();
		sysVectorFront.clear();
		testFunc(testNmb++, sysVectorFront.front(), userVectorFront.front(), "front");

		/* front */
		std::cout << std::endl << "\x1b[33m" << "front const" << "\x1b[0m" << std::endl;

		userVectorFront.clear();
		sysVectorFront.clear();

		for(size_t i = 1; i < 10; i++)
		{
			userVectorFront.push_back(i);
			sysVectorFront.push_back(i);
		}
		testFunc(testNmb++, sysVectorFront.front(), userVectorFront.front(), "front");

		/* front */
		std::cout << std::endl << "\x1b[33m" << "front const empty" << "\x1b[0m" << std::endl;

		userVectorFront.clear();
		sysVectorFront.clear();
		
		testFunc(testNmb++, sysVectorFront.front(), userVectorFront.front(), "front");
		getchar();
	}
	
	//***************************BACK************************//
	if(back)
	{
		/* back */
		std::cout << std::endl << "\x1b[33m" << "back" << "\x1b[0m" << std::endl;

		ft::vector  <int> userVect;
		std::vector <int> sysVect;

		for(size_t i = 1; i < 10; i++)
		{
			userVect.push_back(i);
			sysVect.push_back(i);
		}

		testFunc(testNmb++, sysVect.size(), userVect.size(), "size (push back 5))");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity (push back 5))");
		testNmb = compareClasses(testNmb++, sysVect, userVect);
		testFunc(testNmb++, sysVect.back(), userVect.back(),  "back");
		testFunc(testNmb++, sysVect.back() - 1, userVect.back() - 1,  "back - 1");
		testFunc(testNmb++, sysVect.back() - 2, userVect.back() - 2,  "back - 2");
		getchar();

		/* back const */
		std::cout << std::endl << "\x1b[33m" << "back const" << "\x1b[0m" << std::endl;

		userVect.clear();
		sysVect.clear();

		for(size_t i = 1; i < 10; i++)
		{
				userVect.push_back(i);
				sysVect.push_back(i);
		}

		testFunc(testNmb++, sysVect.back() - 1, userVect.back() - 1, "back const");
		getchar();
	}
	system("clear");
}

void				modifiers_vector(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** MODIFIERS ***                          " << "\x1b[0m" << std::endl;
	testNmb++;
	//***************************ASSIGN************************//

	int			assign = 0;
	int			push_back = 0;
	int			pop_back = 0;
	int			insert = 0;	
	int			erase = 1;
	int			swap = 0;
	int			clear = 0;

	ft::vector  <int> userVect;
	std::vector <int> sysVect;

	std::vector <int>::iterator itSys; 
	ft::vector <int>::iterator itUser;

	std::string nameSize;
	std::string nameCapacity;

	if (testAll)
	{
		// assign = 1;
		// push_back = 1;
		// pop_back = 1;
		// insert = 1;	
		erase = 1;
		// swap = 1;
		// clear = 1;
	}
	
	//***************************ASSIGN************************//
	if(assign)
	{
		std::cout << std::endl << "\x1b[33m" << "assign 1" << "\x1b[0m" << std::endl;
		
		ft::vector  <int> userVectorAssign;
		std::vector <int> sysVectorAssign;

		for(int i = 0; i < 10; i++)
		{
			sysVectorAssign.push_back(i);
			userVectorAssign.push_back(i);
		}

		testFunc(testNmb++, sysVectorAssign.size(), userVectorAssign.size(), "size");
		testFunc(testNmb++, sysVectorAssign.capacity(), userVectorAssign.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign, userVectorAssign);

		sysVectorAssign.assign(5, 42);
		userVectorAssign.assign(5, 42);
		
		testFunc(testNmb++, sysVectorAssign.size(), userVectorAssign.size(), "size");
		testFunc(testNmb++, sysVectorAssign.capacity(), userVectorAssign.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign, userVectorAssign);
		getchar();
		system("clear");
		
		/* assign 2 */
		std::cout << std::endl << "\x1b[33m" << "assign 2" << "\x1b[0m" << std::endl;
		
		userVectorAssign.clear();
		sysVectorAssign.clear();
		
		sysVectorAssign.assign(1, 42);
		userVectorAssign.assign(1, 42);

		testFunc(testNmb++, sysVectorAssign.size(), userVectorAssign.size(), "size");
		testFunc(testNmb++, sysVectorAssign.capacity(), userVectorAssign.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign, userVectorAssign);
		getchar();
		system("clear");

		/* assign 3 */
		std::cout << std::endl << "\x1b[33m" << "assign 3 InputIterator" << "\x1b[0m" << std::endl;

		userVectorAssign.clear();
		sysVectorAssign.clear();

		for(int i = 99; i > 97; i--)
		{
			sysVectorAssign.push_back(i);
			userVectorAssign.push_back(i);
		}

		ft::vector  <int> userVectorAssign2;
		std::vector <int> sysVectorAssign2;

		for(int i = 1; i < 15; i++)
		{
			sysVectorAssign2.push_back(i);
			userVectorAssign2.push_back(i);
		}
		
		testFunc(testNmb++, sysVectorAssign2.size(), userVectorAssign2.size(), "size");
		testFunc(testNmb++, sysVectorAssign2.capacity(), userVectorAssign2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign2, userVectorAssign2);

		sysVectorAssign2.assign(sysVectorAssign.begin(), sysVectorAssign.end());
		userVectorAssign2.assign(userVectorAssign.begin(),userVectorAssign.end());

		testFunc(testNmb++, sysVectorAssign2.size(), userVectorAssign2.size(), "size");
		testFunc(testNmb++, sysVectorAssign2.capacity(), userVectorAssign2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign2, userVectorAssign2);

		getchar();
		system("clear");

		/* assign InputIterator */
		std::cout << std::endl << "\x1b[33m" << "assign 4 InputIterator" << "\x1b[0m" << std::endl;

		userVectorAssign.clear();
		sysVectorAssign.clear();

		testFunc(testNmb++, sysVectorAssign2.size(), userVectorAssign2.size(), "size");
		testFunc(testNmb++, sysVectorAssign2.capacity(), userVectorAssign2.capacity(), "capacity");

		sysVectorAssign2.assign(sysVectorAssign.begin(), sysVectorAssign.end());
		userVectorAssign2.assign(userVectorAssign.begin(),userVectorAssign.end());

		testFunc(testNmb++, sysVectorAssign2.size(), userVectorAssign2.size(), "size");
		testFunc(testNmb++, sysVectorAssign2.capacity(), userVectorAssign2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign2, userVectorAssign2);

		getchar();
		system("clear");

		/* assign InputIterator */
		std::cout << std::endl << "\x1b[33m" << "assign 5 InputIterator empty" << "\x1b[0m" << std::endl;

		sysVectorAssign2.push_back(5);
		userVectorAssign2.push_back(5);

		testFunc(testNmb++, sysVectorAssign2.size(), userVectorAssign2.size(), "size");
		testFunc(testNmb++, sysVectorAssign2.capacity(), userVectorAssign2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign2, userVectorAssign2);
		
		sysVectorAssign2.assign(sysVectorAssign2.begin(), sysVectorAssign2.end());
		userVectorAssign2.assign(userVectorAssign2.begin(),userVectorAssign.end());

		testFunc(testNmb++, sysVectorAssign2.size(), userVectorAssign2.size(), "size");
		testFunc(testNmb++, sysVectorAssign2.capacity(), userVectorAssign2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign2, userVectorAssign2);

		getchar();
		system("clear");

		/* assign InputIterator */
		std::cout << std::endl << "\x1b[33m" << "assign 6 InputIterator" << "\x1b[0m" << std::endl;

		sysVectorAssign2.clear();
		userVectorAssign2.clear();

		testFunc(testNmb++, sysVectorAssign2.size(), userVectorAssign2.size(), "size");
		testFunc(testNmb++, sysVectorAssign2.capacity(), userVectorAssign2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign2, userVectorAssign2);
		
		sysVectorAssign2.assign(sysVectorAssign2.begin(), sysVectorAssign2.end());
		userVectorAssign2.assign(userVectorAssign2.begin(),userVectorAssign.end());

		testFunc(testNmb++, sysVectorAssign2.size(), userVectorAssign2.size(), "size");
		testFunc(testNmb++, sysVectorAssign2.capacity(), userVectorAssign2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign2, userVectorAssign2);

		getchar();
		system("clear");

		/* assign InputIterator */
		std::cout << std::endl << "\x1b[33m" << "assign 7 InputIterator empty" << "\x1b[0m" << std::endl;

		userVectorAssign.clear();
		sysVectorAssign.clear();

		userVectorAssign2.clear();
		sysVectorAssign2.clear();

		sysVectorAssign2.assign(sysVectorAssign.begin(), sysVectorAssign.end());
		userVectorAssign2.assign(userVectorAssign.begin(),userVectorAssign.end());

		testFunc(testNmb++, sysVectorAssign2.size(), userVectorAssign2.size(), "size");
		testFunc(testNmb++, sysVectorAssign2.capacity(), userVectorAssign2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorAssign2, userVectorAssign2);

		getchar();
		system("clear");
	}

	//***************************PUSH_BACK************************//
	if(push_back)
	{
		std::cout << std::endl << "\x1b[33m" << "push_back" << "\x1b[0m" << std::endl;
		
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size before");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		sysVect.push_back(5);
		userVect.push_back(5);

		testFunc(testNmb++, sysVect.size(), userVect.size(), "size (push back 5))");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity (push back 5))");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		for	(int i = 0; i < 5; i++)
		{

			nameSize = "size (push back - " + std::to_string(i);
			nameCapacity = "capacity (push back - " + std::to_string(i);
			
			sysVect.push_back(i);
			userVect.push_back(i);

			testFunc(testNmb++, sysVect.size(), userVect.size(), nameSize);
			testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), nameCapacity);
		}
		sysVect.push_back(25);
		userVect.push_back(25);
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		getchar();
		system("clear");
	}

	//***************************POP_BACK************************//
	if(pop_back)
	{
		std::cout << std::endl << "\x1b[33m" << "pop_back" << "\x1b[0m" << std::endl;

		userVect.clear();
		sysVect.clear();

		sysVect.push_back(5);
		userVect.push_back(5);
		for	(int i = 0; i < 5; i++)
		{
			sysVect.push_back(i);
			userVect.push_back(i);
		}
		sysVect.push_back(25);
		userVect.push_back(25);
		
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size before");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		for	(int i = 0; i < 3; i++)
		{
			sysVect.pop_back();
			userVect.pop_back();
		}

		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);
		
		for	(int i = 0; i < 4; i++)
		{
			sysVect.pop_back();
			userVect.pop_back();
		}

		testFunc(testNmb++, sysVect.size(), userVect.size(), "size OK ");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity OK ");

		sysVect.pop_back();
		userVect.pop_back();
		
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size TRASH");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity TRASH");

		for	(int i = 5; i < 10; i++)
		{
			sysVect.push_back(i);
			userVect.push_back(i);
		}

		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		getchar();
		system("clear");
	}

	//***************************INSERT************************//
	if(insert)
	{
		std::cout << std::endl << "\x1b[33m" << "iterator insert (iterator position, const value_type& val)" << "\x1b[0m" << std::endl;
		
		ft::vector  <int> userV;
		std::vector <int> sysV;

		for(int i = 0; i < 2; i++)
		{
			sysV.push_back(i);
			userV.push_back(i);
		}

		testFunc(testNmb++, sysV.size(), userV.size(), "size before");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysV, userV);

		// sysV.insert(sysV.begin(), 12); // если begin не верный
	
		testFunc(testNmb++, *(sysV.insert(sysV.begin(), 12)), *(userV.insert(userV.begin(), 12)), "Return value");
		
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysV, userV);
		getchar();
		system("clear");

		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert 2" << "\x1b[0m" << std::endl;

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size before");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysV, userV);

		itSys  = sysV.begin(); 
		itUser = userV.begin();

		itSys++;
		itUser++;

		testFunc(testNmb++, *(sysV.insert(itSys, 9)), *(userV.insert(itUser, 9)), "Return value");
		
		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysV, userV);
		getchar();
		system("clear");
	
		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert 3" << "\x1b[0m" << std::endl;

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size before");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysV, userV);
		
		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, *(sysV.insert(sysV.end(), 5555555)), *(userV.insert(userV.end(), 5555555)), "Return value");
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysV, userV);
		getchar();
		system("clear");
	
		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert 4 (into clear vector)" << "\x1b[0m" << std::endl;
		
		userV.clear();
		sysV.clear();
		
		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size before");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysV, userV);

		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, *(sysV.insert(sysV.begin(), 12)), *(userV.insert(userV.begin(), 12)), "Return value");
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysV, userV);
		getchar();
		system("clear");

		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert 5 void insert (iterator position, size_type n, const value_type& val)" << "\x1b[0m" << std::endl;
			
		userV.clear();
		sysV.clear();

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size before");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysV, userV);

		userV.insert(userV.begin(), 2, 42);
		sysV.insert(sysV.begin(), 2, 42);

		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysV, userV);
		getchar();
		system("clear");

		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert 6" << "\x1b[0m" << std::endl;
				
		userV.clear();
		sysV.clear();

		for(int i = 0; i < 5; i++)
		{
			sysV.push_back(i);
			userV.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size before");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysV, userV);

		userV.insert(userV.begin(), 2, 42);
		sysV.insert(sysV.begin(), 2, 42);

		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysV, userV);
		getchar();
		system("clear");

		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert 7" << "\x1b[0m" << std::endl;
				
		userV.clear();
		sysV.clear();

		for (int i = 0; i < 5; i++)
		{
			sysV.push_back(i);
			userV.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size before");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysV, userV);

		userV.insert(userV.end(), 1, 55);
		sysV.insert(sysV.end(), 1, 55);

		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysV, userV);
		getchar();
		system("clear");

		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert 8" << "\x1b[0m" << std::endl;
				
		userV.clear();
		sysV.clear();

		for (int i = 0; i < 5; i++)
		{
			sysV.push_back(i);
			userV.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size before");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysV, userV);

		userV.insert(userV.end(), 0, 55);
		sysV.insert(sysV.end(), 0, 55);

		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysV, userV);
		getchar();
		system("clear");

		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert 9" << "\x1b[0m" << std::endl;
		
		for (int i = 0; i < 5; i++)
		{
			sysV.push_back(i);
			userV.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size before");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysV, userV);

		itSys = sysV.begin(); 
		itUser = userV.begin();
		
		for(int i = 0; i < 2; i++)
		{
			itSys++;
			itUser++;
		}

		userV.insert(itUser, 2, 8);
		sysV.insert(itSys, 2, 8);

		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testFunc(testNmb++, sysV.capacity(), userV.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysV, userV);
		getchar();
		system("clear");

		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert InputIterator" << "\x1b[0m" << std::endl;
			
		userV.clear();
		sysV.clear();
		
		for(int i = 0; i < 5; i++)
		{
			sysV.push_back(i);
			userV.push_back(i);
		}

		std::cout << "*** TO INSERT  ***" << std::endl;
		testNmb = compareClasses(testNmb++, sysV, userV);

		ft::vector  <int> userVect2 (2, 10);
		std::vector <int> sysVect2 (2, 10);

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysVect2.size(), userVect2.size(), "size");
		testNmb = compareClasses(testNmb++, sysVect2, userVect2);

		userVect2.insert(userVect2.begin(), userV.begin(), userV.end());
		sysVect2.insert(sysVect2.begin(), sysV.begin(), sysV.end());
		
		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, sysVect2.size(), userVect2.size(), "size");
		testNmb = compareClasses(testNmb++, sysVect2, userVect2);
		
		getchar();
		system("clear");		

		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert InputIterator 2" << "\x1b[0m" << std::endl;
			
		userV.clear();
		sysV.clear();
		
		for(int i = 0; i < 5; i++)
		{
			sysV.push_back(i);
			userV.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testNmb = compareClasses(testNmb++, sysV, userV);

		userV.insert(userV.begin(), userV.begin(), userV.end());
		sysV.insert(sysV.begin(), sysV.begin(), sysV.end());
		
		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, sysV.size(), userV.size(), "size");
		testNmb = compareClasses(testNmb++, sysV, userV);
		
		getchar();
		system("clear");
		
	}

	//***************************ERASE************************//
	if(erase)
	{
		/* erase */
		std::cout << std::endl << "\x1b[33m" << "erase 1" << "\x1b[0m" << std::endl;
		ft::vector  <int> userVect;
		std::vector <int> sysVect;

		for(int i = 0; i < 10; i++)
		{
			sysVect.push_back(i);
			userVect.push_back(i);
		}

		itSys = sysVect.begin(); 
		itUser = userVect.begin();

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size before");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		std::cout << "*** ERASE FIRST ELEMENT ***" << std::endl;
		testFunc(testNmb++, *sysVect.erase(itSys), *userVect.erase(itUser), "Return value");
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		getchar();
		system("clear");
		
		/* erase */
		std::cout << std::endl << "\x1b[33m" << "erase 2" << "\x1b[0m" << std::endl;
		
		itSys = sysVect.begin(); 
		itUser = userVect.begin();

		itSys++;
		itUser++;

		itSys++;
		itUser++;

		itSys++;
		itUser++;

		std::cout << "*** ERASE MIDDLE ELEMENT ***" << std::endl;
		testFunc(testNmb++, *sysVect.erase(itSys), *userVect.erase(itUser), "Return value");
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);
		getchar();
		system("clear");

		/* erase */
		std::cout << std::endl << "\x1b[33m" << "erase 3" << "\x1b[0m" << std::endl;

		itSys = sysVect.end(); 
		itUser = userVect.end();

		itSys--;
		itUser--;
		
		std::cout << "*** ERASE LAST ELEMENT ***" << std::endl;
		testFunc(testNmb++, *sysVect.erase(itSys), *userVect.erase(itUser), "Return value");
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);
		getchar();
		system("clear");

		/* erase */
		std::cout << std::endl << "\x1b[33m" << "erase 4" << "\x1b[0m" << std::endl;
		
		userVect.clear();
		sysVect.clear();

		for(int i = 0; i < 10; i++)
		{
			sysVect.push_back(i);
			userVect.push_back(i);
		}

		itSys = sysVect.begin(); 
		itUser = userVect.begin();

		for(int i = 0; i < 9; i++)
		{
			itSys++;
			itUser++;
		}

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		testFunc(testNmb++, *sysVect.erase(itSys), *userVect.erase(itUser), "Return value");

		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		getchar();
		system("clear");

		/* erase */
		std::cout << std::endl << "\x1b[33m" << "erase 5 one element" << "\x1b[0m" << std::endl;
		
		userVect.clear();
		sysVect.clear();

		for(int i = 0; i < 1; i++)
		{
			sysVect.push_back(i);
			userVect.push_back(i);
		}

		itSys = sysVect.begin(); 
		itUser = userVect.begin();

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, *sysVect.erase(itSys), *userVect.erase(itUser), "Return value");
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		getchar();
		system("clear");

		/* erase */
		std::cout << std::endl << "\x1b[33m" << "erase 6" << "\x1b[0m" << std::endl;
		std::cout << std::endl << "iterator erase (iterator first, iterator last)" << std::endl;
		
		userVect.clear();
		sysVect.clear();

		for(int i = 0; i < 10; i++)
		{
			sysVect.push_back(i);
			userVect.push_back(i);
		}

		itSys = sysVect.begin(); 
		itUser = userVect.begin();

		std::vector <int>::iterator itSys2 = sysVect.end(); 
		ft::vector <int>::iterator itUser2 = userVect.end();
		itSys2--;
		itUser2--;

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size before");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity before");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		std::cout << "*** ERASE FIRST ELEMENT ***" << std::endl;
		
		testFunc(testNmb++, *sysVect.erase(itSys, itSys2), *userVect.erase(itUser, itUser2), "Return value");
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		getchar();
		system("clear");

		
		/* erase */
		std::cout << std::endl << "\x1b[33m" << "erase 7" << "\x1b[0m" << std::endl;
		std::cout << std::endl << "iterator erase (iterator first, iterator last)" << std::endl;
		userVect.clear();
		sysVect.clear();

		for(int i = 0; i < 10; i++)
		{
			sysVect.push_back(i);
			userVect.push_back(i);
		}

		itSys = sysVect.begin(); 
		itUser = userVect.begin();

		itSys2 = sysVect.begin(); 
		itUser2 = userVect.begin();

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, *sysVect.erase(itSys, itSys2), *userVect.erase(itUser, itUser2), "position iterators");
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		getchar();
		system("clear");

		/* erase */
		std::cout << std::endl << "\x1b[33m" << "erase 8" << "\x1b[0m" << std::endl;
		std::cout << std::endl << "iterator erase (iterator first, iterator last)" << std::endl;
		userVect.clear();
		sysVect.clear();

		for(int i = 0; i < 10; i++)
		{
			sysVect.push_back(i);
			userVect.push_back(i);
		}

		itSys = sysVect.begin(); 
		itUser = userVect.begin();

		itSys2 = sysVect.begin();
		itSys2++;
		itUser2 = userVect.begin();
		itUser2++;

		std::cout << "*** BEFORE ***" << std::endl;
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);
		
		std::cout << "*** AFTER ***" << std::endl;
		testFunc(testNmb++, *sysVect.erase(itSys, itSys2), *userVect.erase(itUser, itUser2), "position iterators");
		testFunc(testNmb++, sysVect.size(), userVect.size(), "size");
		testFunc(testNmb++, sysVect.capacity(), userVect.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVect, userVect);

		getchar();
		system("clear");
	}
	
	//***************************SWAP************************//
	if(swap)
	{
		std::cout << std::endl << "\x1b[33m" << "swap" << "\x1b[0m" << std::endl;

		ft::vector  <int> userVectorSwap;
		ft::vector  <int> userVectorSwap2;
		
		std::vector <int> sysVectorSwap;
		std::vector <int> sysVectorSwap2;
		
		for(int i = 0; i < 5; i++)
		{
			userVectorSwap.push_back(i);   //0 1 2 3 4
			sysVectorSwap.push_back(i);
		}

		for(int i = 5; i < 10; i++)
		{
			userVectorSwap2.push_back(i);  //5 6 7 8 9
			sysVectorSwap2.push_back(i);
		}

		std::cout << "*** BEFORE 1 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap.size(), userVectorSwap.size(), "size");
		testFunc(testNmb++, sysVectorSwap.capacity(), userVectorSwap.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap, userVectorSwap);

		std::cout << "*** BEFORE 2 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap2.size(), userVectorSwap2.size(), "size");
		testFunc(testNmb++, sysVectorSwap2.capacity(), userVectorSwap2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap2, userVectorSwap2);

		userVectorSwap.swap(userVectorSwap2);
		sysVectorSwap.swap(sysVectorSwap2);
		
		std::cout << "*** AFTER 1 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap.size(), userVectorSwap.size(), "size");
		testFunc(testNmb++, sysVectorSwap.capacity(), userVectorSwap.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap, userVectorSwap);

		std::cout << "*** AFTER 1 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap2.size(), userVectorSwap2.size(), "size");
		testFunc(testNmb++, sysVectorSwap2.capacity(), userVectorSwap2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap2, userVectorSwap2);
		getchar();
		system("clear");

		std::cout << std::endl << "\x1b[33m" << "swap 2" << "\x1b[0m" << std::endl;

		userVectorSwap.clear();
		userVectorSwap2.clear();
		sysVectorSwap.clear();
		sysVectorSwap2.clear();
		
		for(int i = 0; i < 5; i++)
		{
			userVectorSwap.push_back(i);   //0 1 2 3 4
			sysVectorSwap.push_back(i);
		}		

		std::cout << "*** BEFORE 1 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap.size(), userVectorSwap.size(), "size");
		testFunc(testNmb++, sysVectorSwap.capacity(), userVectorSwap.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap, userVectorSwap);

		std::cout << "*** BEFORE 2 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap2.size(), userVectorSwap2.size(), "size");
		testFunc(testNmb++, sysVectorSwap2.capacity(), userVectorSwap2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap2, userVectorSwap2);

		userVectorSwap.swap(userVectorSwap2);
		sysVectorSwap.swap(sysVectorSwap2);
		
		std::cout << "*** AFTER 1 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap.size(), userVectorSwap.size(), "size");
		testFunc(testNmb++, sysVectorSwap.capacity(), userVectorSwap.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap, userVectorSwap);

		std::cout << "*** AFTER 1 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap2.size(), userVectorSwap2.size(), "size");
		testFunc(testNmb++, sysVectorSwap2.capacity(), userVectorSwap2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap2, userVectorSwap2);
		getchar();
		system("clear");

		/* swap */
		std::cout << std::endl << "\x1b[33m" << "swap empty" << "\x1b[0m" << std::endl;

		userVectorSwap.clear();
		userVectorSwap2.clear();
		sysVectorSwap.clear();
		sysVectorSwap2.clear();

		std::cout << "*** BEFORE 1 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap.size(), userVectorSwap.size(), "size");
		testFunc(testNmb++, sysVectorSwap.capacity(), userVectorSwap.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap, userVectorSwap);

		std::cout << "*** BEFORE 2 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap2.size(), userVectorSwap2.size(), "size");
		testFunc(testNmb++, sysVectorSwap2.capacity(), userVectorSwap2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap2, userVectorSwap2);

		userVectorSwap.swap(userVectorSwap2);
		sysVectorSwap.swap(sysVectorSwap2);
		
		std::cout << "*** AFTER 1 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap.size(), userVectorSwap.size(), "size");
		testFunc(testNmb++, sysVectorSwap.capacity(), userVectorSwap.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap, userVectorSwap);

		std::cout << "*** AFTER 1 ***" << std::endl;
		testFunc(testNmb++, sysVectorSwap2.size(), userVectorSwap2.size(), "size");
		testFunc(testNmb++, sysVectorSwap2.capacity(), userVectorSwap2.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorSwap2, userVectorSwap2);
		getchar();
		system("clear");
	}
	
	//***************************CLEAR************************//
	if(clear)
	{
		std::cout << std::endl << "\x1b[33m" << "clear" << "\x1b[0m" << std::endl;
		ft::vector  <int> userVectorClear(7, 4);
		std::vector <int> sysVectorClear(7, 4);
		
		testFunc(testNmb++, sysVectorClear.size(), userVectorClear.size(), "size");
		testFunc(testNmb++, sysVectorClear.capacity(), userVectorClear.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorClear, userVectorClear);

		userVectorClear.clear();
		sysVectorClear.clear();

		testFunc(testNmb++, sysVectorClear.size(), userVectorClear.size(), "size");
		testFunc(testNmb++, sysVectorClear.capacity(), userVectorClear.capacity(), "capacity");
		testNmb = compareClasses(testNmb++, sysVectorClear, userVectorClear);

		getchar();
	}
	system("clear");
}

void				allocator_vector(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** ALLOCATOR ***                          " << "\x1b[0m" << std::endl;
	
	testNmb++;

	if (testAll)
	{
		// std::vector<int> sysalloc;
		// std::vector<int> myalloc;
		// int * sys;
		// int * my;
		// unsigned int i;

		// // allocate an array with space for 5 elements using vector's allocator:
		// sys =sysalloc.get_allocator().allocate(5);
		// my =  myalloc.get_allocator().allocate(5);

		// // construct values in-place on the array:
		// for (i=0; i<5; i++) sysalloc.get_allocator().construct(&sys[i],i);
		// for (i=0; i<5; i++) myalloc.get_allocator().construct(&my[i],i);

		// std::cout << "The allocated array contains system:";
		// for (i=0; i<5; i++) std::cout << ' ' << sys[i];

		// std::cout << "The allocated array contains my:";
		// for (i=0; i<5; i++) std::cout << ' ' << my[i];

		
		
		// std::cout << '\n';
		// testFunc(testNmb++,  my[0],  sys[0], "alloc[0]");

		// getchar();
		// 	system("clear");
	}
	
	system("clear");
}

// void				overloads_vector(int testNmb)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                         *** OVERLOADES ***                          " << "\x1b[0m" << std::endl;

// 	std::vector<int> Sys_a;
// 	std::vector<int> Sys_b;
// 	std::vector<int> Sys_c;
// 	std::vector<int> Sys_d;
// 	std::vector<int> Sys_f;

// 	ft::vector<int> User_a;
//   	ft::vector<int> User_b;
//   	ft::vector<int> User_c;
// 	ft::vector<int> User_d;
// 	ft::vector<int> User_f;

// 	for (int i = 10; i < 40;)
// 	{
// 		Sys_a.push_back(i);
// 		Sys_b.push_back(i);
// 		User_a.push_back(i);
// 		User_b.push_back(i);
// 		i += 10;
// 	}

// 	for (int i = 30; i >= 10;)
// 	{
// 		Sys_c.push_back(i);
// 		User_c.push_back(i);
// 		i -= 10;
// 	}

// 	Sys_f.push_back(30);
// 	User_f.push_back(30);
	
// 	std::cout << "*** BEFORE ***" << std::endl;
// 	print_std_vector(" Sys_a:", Sys_a);
// 	print_std_vector(" Sys_b:", Sys_b);
// 	print_std_vector(" Sys_c:", Sys_c);
// 	print_std_vector(" Sys_d:", Sys_d);
// 	print_std_vector(" Sys_f:", Sys_f);
// 	std::cout << std::endl;
	
// 	print_ft_vector("User_a:", User_a);
// 	print_ft_vector("User_b:", User_b);
// 	print_ft_vector("User_c:", User_c);
// 	print_ft_vector("User_d:", User_d);
// 	print_ft_vector("User_f:", User_f);
// 	std::cout << std::endl;

// 	try
// 	{
// 		testFunc(testNmb++, (Sys_a == Sys_b), (User_a == User_b), "a == b");
// 		testFunc(testNmb++, (Sys_b == Sys_c), (User_b == User_c), "b == c");
// 		testFunc(testNmb++, (Sys_a == Sys_d), (User_a == User_d), "a == d");
// 		testFunc(testNmb++, (Sys_d == Sys_c), (User_d == User_c), "d == c");
// 		testFunc(testNmb++, (Sys_a == Sys_f), (User_a == User_f), "a == f");
// 		testFunc(testNmb++, (Sys_f == Sys_c), (User_f == User_c), "f == c");

// 		testFunc(testNmb++, (Sys_a != Sys_b), (User_a != User_b), "a != b");
// 		testFunc(testNmb++, (Sys_b != Sys_c), (User_b != User_c), "b != c");
// 		testFunc(testNmb++, (Sys_a != Sys_d), (User_a != User_d), "a != d");
// 		testFunc(testNmb++, (Sys_d != Sys_c), (User_d != User_c), "d != c");
// 		testFunc(testNmb++, (Sys_a != Sys_f), (User_a != User_f), "a != f");
// 		testFunc(testNmb++, (Sys_f != Sys_c), (User_f != User_c), "f != c");

// 		testFunc(testNmb++, (Sys_a < Sys_b), (User_a < User_b), "a < b");
// 		testFunc(testNmb++, (Sys_b < Sys_c), (User_b < User_c), "b < c");
// 		testFunc(testNmb++, (Sys_a < Sys_d), (User_a < User_d), "a < d");
// 		testFunc(testNmb++, (Sys_d < Sys_c), (User_d < User_c), "d < c");
// 		testFunc(testNmb++, (Sys_a < Sys_f), (User_a < User_f), "a < f");
// 		testFunc(testNmb++, (Sys_f < Sys_c), (User_f < User_c), "f < c");

// 		testFunc(testNmb++, (Sys_a > Sys_b), (User_a > User_b), "a > b");
// 		testFunc(testNmb++, (Sys_b > Sys_c), (User_b > User_c), "b > c");
// 		testFunc(testNmb++, (Sys_a > Sys_d), (User_a > User_d), "a > d");
// 		testFunc(testNmb++, (Sys_d > Sys_c), (User_d > User_c), "d > c");
// 		testFunc(testNmb++, (Sys_a > Sys_f), (User_a > User_f), "a > f");
// 		testFunc(testNmb++, (Sys_f > Sys_c), (User_f > User_c), "f > c");

// 		testFunc(testNmb++, (Sys_a <= Sys_b), (User_a <= User_b), "a <= b");
// 		testFunc(testNmb++, (Sys_b <= Sys_c), (User_b <= User_c), "b <= c");
// 		testFunc(testNmb++, (Sys_a <= Sys_d), (User_a <= User_d), "a <= d");
// 		testFunc(testNmb++, (Sys_d <= Sys_c), (User_d <= User_c), "d <= c");
// 		testFunc(testNmb++, (Sys_a <= Sys_f), (User_a <= User_f), "a <= f");
// 		testFunc(testNmb++, (Sys_f <= Sys_c), (User_f <= User_c), "f <= c");

// 		testFunc(testNmb++, (Sys_a >= Sys_b), (User_a >= User_b), "a >= b");
// 		testFunc(testNmb++, (Sys_b >= Sys_c), (User_b >= User_c), "b >= c");
// 		testFunc(testNmb++, (Sys_a >= Sys_d), (User_a >= User_d), "a >= d");
// 		testFunc(testNmb++, (Sys_d >= Sys_c), (User_d >= User_c), "d >= c");
// 		testFunc(testNmb++, (Sys_a >= Sys_f), (User_a >= User_f), "a >= f");
// 		testFunc(testNmb++, (Sys_f >= Sys_c), (User_f >= User_c), "f >= c");

// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	getchar();
	
// 	std::cout << std::endl << "\x1b[33m" << "                         *** SWAP ***                          " << "\x1b[0m" << std::endl;
	
// 	std::vector<int> SysV (3,100);
// 	std::vector<int> SysV2 (5,200);

// 	ft::vector<int> UserV (3,100);
// 	ft::vector<int> UserV2 (5,200);
// 	std::cout << "*** BEFORE ***" << std::endl;
// 	print_std_vector("  SysV:", SysV);
// 	print_std_vector(" SysV2:", SysV2);

// 	print_ft_vector("  UserV:", UserV);
// 	print_ft_vector(" UserV2:", UserV2);

// 	std::cout << "*** AFTER ***" << std::endl;
// 	print_std_vector("  SysV:", SysV);
// 	print_std_vector(" SysV2:", SysV2);

// 	print_ft_vector("  UserV:", UserV);
// 	print_ft_vector(" UserV2:", UserV2);

// 	ft::vector<int>::iterator itSwapUser = UserV.end();
// 	itSwapUser--;
// 	std::vector<int>::iterator itSwapSys = SysV.end();
// 	itSwapSys--;

//   	testFunc(testNmb++, SysV.size(), UserV.size(), "size");
// 	testFunc(testNmb++, *SysV.begin(), *UserV.begin(), "begin");
// 	testFunc(testNmb++, *SysV.end(), *UserV.end(), "end");

// 	testFunc(testNmb++, SysV2.size(), UserV2.size(), "size");
// 	testFunc(testNmb++, *SysV2.begin(), *UserV2.begin(), "begin");
// 	testFunc(testNmb++, *itSwapSys, *itSwapUser, "end");

// }



void				vector_test()
{
	int testNmb = 0;
	int testAll = 0;

	system("clear");
	
	std::cout << "\x1b[33m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|         VECTOR TESTING         |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	/*			Member functions			*/
	constructor_vector(testNmb, testAll);				// -
	iterators_vector(testNmb, testAll);					// +
	capacity_vector(testNmb, testAll);					// +
	elementAccess_vector(testNmb, testAll);				// +
	modifiers_vector(testNmb, testAll);					// + 
	// allocator_vector(testNmb, testAll);				// get_allocator
	// overloads_vector(testNmb, testAll);
}

