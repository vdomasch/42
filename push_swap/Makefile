# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 14:41:54 by vdomasch          #+#    #+#              #
#    Updated: 2024/02/12 15:12:30 by vdomasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile
NAME			= push_swap

# Compiler and Flags
CC		= cc
FLAGS	= -Wall -Werror -Wextra

# Files
SRC_FILES	=	push_swap.c push_swap_outils.c
OBJ_FILES	=	$(FILES:.c=.o)
HEADER		=	push_swap.h
DLIB		=	Libft/
DPRINT		=	ft_printf/

.PHONY:	all clean fclean re	

# Rules
%.o: 		%.c	$(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

all: 			$(NAME)

$(NAME):		$(OBJ_FILES)
				$(MAKE) -C $(DLIB)
				$(MAKE) -C $(DPRINT)
				$(CC) $^ $(FLAGS) $(DLIB)/libft.a $(DPRINT)/libftprintf.a -o $(NAME)

clean:
	rm -rf $(OBJ_FILES)
	cd $(DLIB) && make clean
	cd $(DPRINT) && make clean

fclean:	clean
	rm -rf $(NAME)
	cd $(DLIB) && make fclean
	cd $(DPRINT) && make fclean

re:	fclean $(MAKE) all
