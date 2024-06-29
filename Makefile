# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amecani <amecani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 16:02:48 by amecani           #+#    #+#              #
#    Updated: 2024/06/29 20:38:59 by amecani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher
LIBFT = includes/libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3

SOURCES =	main.c \
			utilities.c \
			libft_functions.c \
			initinilasiation.c

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