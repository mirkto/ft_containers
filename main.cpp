#include "utils/ft_header.hpp"

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


void		vector_test()
{
	PRINT_PRP("\n   ---| vector testing |---");
	vector_base();
	// iteratirs_vector();
	capacity_vector();
	// element_access_vector();
	// modifiers_vector();
	// non_member_function_overloads_vector();
}

void		ft_wait()
{
	PRINT("\n10 seconds to complete the test\n...");
	sleep(5);
	for (int i = 5; i != 1; sleep(1))
		PRINT(i-- << " seconds left");
	PRINT("1 second left");
	sleep(1);
}

void		ft_fast_test()
{

}

int			main()
{
	PRINT_PRP("\n ___---/ Start testing \\---___");
	list_test();
	vector_test();
	PRINT_PRP("\n   ---\\ End of testing /---\n");
	ft_fast_test();
	ft_wait();
	return 0; 
}