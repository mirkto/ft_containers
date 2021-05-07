#ifndef FOR_TESTS_HPP
# define FOR_TESTS_HPP

# include <unistd.h>
# include <cmath>

// # include <iostream>
// # include <memory>
// # include <string>
// # include <cstddef>
// # include <limits>
// # include <typeinfo>
// # include <iterator>

# include <iterator>
# include "list/list.hpp"
# include <list>
# include "vector/vector.hpp"
# include <vector>


# define CLR_GRN "\033[0;32m"
# define CLR_YLW "\033[0;33m"
# define CLR_BLU "\033[0;34m"
# define CLR_RED "\033[0;31m"
# define CLR_PRP "\033[0;35m"
# define CLR_END "\033[0m"

# define PRINT(x) std::cout << x << std::endl
# define PRINT_YLW(x) PRINT(CLR_YLW << x << CLR_END);
# define PRINT_PRP(x) PRINT(CLR_PRP << x << CLR_END);
# define PRINT_BLU(x) std::cout << CLR_BLU << x << CLR_END << ": ";

# define TEST_SIZE(x) std::cout << CLR_GRN "#print values: " CLR_END << "Size: " << x.size() << std::endl;
# define TEST_HB(x) std::cout << CLR_GRN "|" CLR_END << "Head: " << x.front() << " | " << x.back() << " :Back" << std::endl;

# define TEST_LIST TEST_SIZE(test) TEST_HB(test) printValues(test.begin(), test.end());
# define TEST(x) TEST_SIZE(x) TEST_HB(x) printValues(x.begin(), x.end());
# define TEST_ITER(x,y) PRINT_BLU(x) printValues(y.begin(), y.end());
# define TEST_VAL(y) printValues(y.begin(), y.end());

// for list test values
template < typename iterator >
void			printValues(iterator begin, iterator end)
{
	std::cout << CLR_GRN " \\" CLR_END "Tail -> ";
	while (begin != end)
		std::cout << *begin++ << " -> ";
	PRINT("Tail");
}

// for vector test values
template < typename iterator >
void			printVectorValues(iterator begin, iterator end)
{
	std::cout << CLR_GRN " \\" CLR_END "First -> | ";
	while (begin != end)
		std::cout << *begin++ << " | ";
	PRINT("<- Last");
}

//for list remove_if
bool		single_digit (const int& value)
{ return (value<10); }

struct is_odd {
	bool	operator() (const int& value)
	{ return (value%2)==1; }
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
	bool	operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

//for list merge
bool		mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

#endif