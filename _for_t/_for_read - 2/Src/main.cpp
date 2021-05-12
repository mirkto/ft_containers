//
// Created by Casie Carl on 12/9/20.
//

#include "../Includes/Test.h"
int 	main()
{
	std::string test;
	std::cin >> test;
	while (test != "exit")
	{
		if (test == "list")
			list_main();
		else if (test == "vector")
			vector_main();
		else if (test == "queue")
			queue_main();
		else if (test == "stack")
			stack_main();
		else if (test == "map")
			map_main();
		std::cin >> test;
	}
}