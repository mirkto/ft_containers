.PHONY: all clean re

NAME	= a.out
SRC		= *.cpp #ft_containers_tests-main/list_test.cpp
FLAGS	= -g -Wall -Werror -Wextra
CC		= clang++

all:
	$(CC) $(SRC) $(FLAGS)

$(NAME): $(SRC) Makefile
	$(CC) $(SRC) $(FLAGS)

clean:
	rm ./a.out

re: clean all
