# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:33:46 by bedos-sa          #+#    #+#              #
#    Updated: 2023/11/17 13:05:37 by bedos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.c bonus

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBS) -O3 -g3 

LIBS = ./include
OBJ_DIR = build/

RM = rm -f
FILES = main.c input_error.c one_philo.c free_all.c data.c get_time.c \
		sleep.c think.c eat.c check_death.c ft_atoi.c ft_calloc.c ft_isdigit.c \
		ft_strlen.c ft_memset.c
		
OBJS = $(FILES:.c=.o)

all: mkdir_obj $(NAME)

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

mkdir_obj:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJS))
	@$(CC) $(addprefix $(OBJ_DIR), $(OBJS)) $(FLAGS) -o $(NAME) -pthread
	@echo "\033[0;32mSUCCESS!\033[0m"

run: all
	./$(NAME)

hel: all
	valgrind --tool=helgrind ./$(NAME) 2 1000 60 60

val:
	valgrind --quiet --leak-check=full --show-leak-kinds=all ./$(NAME) 2 500 60 60

bonus: all

clean:
	@$(RM) $(addprefix $(OBJ_DIR), $(OBJS))
	@echo "\033[0;36mBUILD DIRECTORY CLEAN!\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mBINARY DESTROYED!\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus run val
