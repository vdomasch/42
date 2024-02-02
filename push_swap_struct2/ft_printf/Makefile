# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 14:41:54 by vdomasch          #+#    #+#              #
#    Updated: 2024/02/02 18:10:04 by vdomasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile
NAME			= libftprintf.a

#Directories
OBJ_DIR = objs

# Compiler and Flags
CC		= cc
FLAGS	= -Wall -Werror -Wextra

# Files
SRC_FILES	=	ft_printf.c		pf_char.c		pf_decimal.c		\
				pf_ptr.c		pf_str.c		pf_base.c
HEADER		=	ft_printf.h
OBJ_FILES	=	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY:	all clean fclean re	

# Rules
$(OBJ_DIR)/%.o: %.c	$(HEADER)
				$(CC) $(FLAGS) -c $< -o $@

all: 			$(OBJ_DIR) $(NAME)

$(NAME):		$(OBJ_FILES)
				ar rcs $(NAME) $(OBJ_FILES)	

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)	

clean:
	rm -rf $(OBJ_FILES) 
	rm -rf $(OBJ_DIR) 

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
