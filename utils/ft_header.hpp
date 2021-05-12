#ifndef FT_HEADER_HPP
# define FT_HEADER_HPP

# include <unistd.h>
# include <iostream>
# include <stdexcept>

# define CLR_GRN "\033[0;32m"
# define CLR_YLW "\033[0;33m"
# define CLR_BLU "\033[0;34m"
# define CLR_RED "\033[0;31m"
# define CLR_PRP "\033[0;35m"
# define CLR_END "\033[0m"

# define ENDL			std::cout << std::endl;
# define PRT(x)			std::cout << x
# define PRINT(x)		std::cout << x << std::endl
# define PRINT_YLW(x)	PRINT("\n " << CLR_YLW << x << CLR_END);
# define PRINT_PRP(x)	PRINT("\n " << CLR_PRP << x << CLR_END << "\n");
# define PRT_BLU(x)		PRT(CLR_BLU << x << ": " << CLR_END);
# define PRINT_BLU(x)	PRINT(CLR_BLU << x << ":" << CLR_END);

void	list_test();
void		default_list_tests();
void		iteratirs_tests();
void		capacity_tests();
void		element_access_tests();
void		modifiers_tests();
void		operations_tests();
void		non_member_function_overloads();


void	vector_test();
void		vector_base();
// void		iteratirs_vector();
void		capacity_vector();
// void		element_access_vector();
// void		modifiers_vector();
// void		non_member_function_overloads_vector();

// void	stack_test();
// void	queue_test();
// void	map_test();

#endif