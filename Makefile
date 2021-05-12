.PHONY: all clean re

NAME	= a.out
SRC		= main.cpp for_test/*.cpp # ft_containers_tests-main/list_test.cpp
FLAGS	= -Wall -Werror -Wextra # -g
CC		= clang++

all:
	$(CC) $(SRC) $(FLAGS)

$(NAME): $(SRC) Makefile
	$(CC) $(SRC) $(FLAGS)

clean:
	rm ./a.out

re: clean all
