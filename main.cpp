#include "utils/ft_header.hpp"

void		list_test()
{
	PRINT_PRP("\n   ---| list testing |---");
	default_list_tests();
	iterators_tests();
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
	iterators_vector();
	capacity_vector();
	element_access_vector();
	modifiers_vector();
	non_member_function_overloads_vector();
}

void		queue_test()
{
	PRINT_PRP("\n   ---| queue testing |---");
	queue_base();
	// push_pop_queue();
	non_member_function_overloads_queue();
}

void	stack_test()
{
	PRINT_PRP("\n   ---| stack testing |---");
	stack_base();
	// push_pop_stack();
	non_member_function_overloads_stack();
}

void	map_test()
{
	PRINT_PRP("\n   ---| map testing |---");
	map_base();
	iterators_map();
	capacity_map();
	element_access_map();
	modifiers_map();
	map_observers();
	map_operations();
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

int			main()
{
	PRINT_PRP("\n ___---/ Start testing \\---___");
	list_test();
	vector_test();
	queue_test();
	stack_test();
	map_test();
	PRINT_PRP("\n   ---\\ End of testing /---\n");
	// ft_fast_test();
	ft_wait();
	return 0; 
}