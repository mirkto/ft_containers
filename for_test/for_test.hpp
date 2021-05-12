#ifndef FOR_TEST_HPP
# define FOR_TEST_HPP

# include <cmath>
// # include <iostream>
// # include <memory>
// # include <string>
// # include <cstddef>
// # include <limits>
// # include <typeinfo>
// # include <iterator>

# include <iterator>
# include "../utils/ft_header.hpp"
# include <list>
# include "../list/list.hpp"
# include <vector>
# include "../vector/vector.hpp"

//----------------------- for list -----------------------
# define TEST_VAL(x)	printValues(x.begin(), x.end());
# define TEST_SIZE(x)	PRINT(CLR_GRN "#print values: " CLR_END << "Size: " << x.size());
# define TEST_HB(x)		PRINT(CLR_GRN "|" CLR_END << "Head: " << x.front() << " | " << x.back() << " :Back");

# define TEST_LIST		TEST_SIZE(test)	TEST_HB(test)	TEST_VAL(test)
# define TEST(x)		TEST_SIZE(x)	TEST_HB(x)		TEST_VAL(x)

# define TEST_ITER(x,y)	PRT_BLU(x) TEST_VAL(y)

template < typename iterator >
void			printValues(iterator begin, iterator end)
{
	std::cout << CLR_GRN " \\" CLR_END "Tail -> ";
	while (begin != end)
		std::cout << *begin++ << " -> ";
	PRINT("Tail");
}
//----------------------- for vector -----------------------
# define TEST_VECTOR_VAL(x)		printVectorValues(x.begin(), x.end());
# define TEST_VECTOR_HEAD(x)	PRT( CLR_GRN "#" CLR_END << " len - " << x.size() << " | capacity - " << x.capacity() << " ");
# define TEST_VECTOR(x)			TEST_VECTOR_HEAD(x) TEST_VECTOR_VAL(x)

template < typename iterator >
void			printVectorValues(iterator begin, iterator end)
{
	std::cout << CLR_GRN "\\" CLR_END "First -> | ";
	while (begin != end)
		std::cout << *begin++ << " | ";
	PRINT("<- Last");
}

//----------------------- others --------------------------
//for list remove_if
bool		single_digit (const int& value)
{ return (value<10); }

struct is_odd {
	bool	operator()(const int& value)
	{	 return (value%2)==1;			}
};

//for list sort_comp
bool		compare_nocase (const std::string& first, const std::string& second)
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

//for list unique
bool		same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

struct is_near {
	bool	operator()(double first, double second)
	{	return (fabs(first-second)<5.0); }
};

//for list merge
bool		mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

#endif