NAME = containers

CC = -Wall -Wextra -Werror
INCLUDES = Includes

SRC = Src/list_test.cpp \
	  Src/main.cpp \
	  Src/map_test.cpp \
	  Src/queue_test.cpp \
	  Src/stack_test.cpp \
	  Src/vector_test.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	clang++ -I$(INCLUDES) $(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

%.o: %.c
	clang++ -I$(INCLUDES) -c -Wall -Wextra -Werror -c $< -o $@

fclean: clean
	rm -f $(NAME)

re: fclean all
