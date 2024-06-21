# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amecani <amecani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 16:02:48 by amecani           #+#    #+#              #
#    Updated: 2024/06/17 15:06:06 by amecani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher
LIBFT = includes/libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3

SOURCES =	main.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C includes/libft

$(NAME): $(OBJECTS) | $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C includes/libft clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C includes/libft fclean
	@rm -rf $(OBJECTS)
	@rm -rf $(NAME)

re: fclean all