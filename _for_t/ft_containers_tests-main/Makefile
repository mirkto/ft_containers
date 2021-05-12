# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 11:32:12 by gbroccol          #+#    #+#              #
#    Updated: 2021/04/02 13:28:54 by gbroccol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_containers

CC =		clang++

FLAGS =		-Wall -Werror -Wextra -g -std=c++98

# HEADER = /.

SRCS =		main.cpp \
			vector_test.cpp \
			list_test.cpp \
			map_test.cpp \
			# queue_test.cpp \
			# stack_test.cpp \

OBJ =		$(SRCS:.cpp=.o)

%.o: %.cpp
			$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
clean:
			rm -rf $(OBJ)
fclean:
			rm -rf $(OBJ) $(NAME)
re: fclean all

.PHONY: all clean fclean re