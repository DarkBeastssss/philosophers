# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amecani <amecani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 16:02:48 by amecani           #+#    #+#              #
#    Updated: 2024/06/30 21:11:15 by amecani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher
LIBFT = includes/libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3

SOURCES =	main.c \
			utilities.c \
			libft_functions.c \
			libft_functions_2.c \
			initinilasiation.c \
			initinilasiation_2.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJECTS)

fclean: clean
	@rm -rf $(OBJECTS)
	@rm -rf $(NAME)

re: fclean all