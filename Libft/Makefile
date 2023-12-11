# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 13:34:24 by vdomasch          #+#    #+#              #
#    Updated: 2023/11/20 15:27:52 by vdomasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

FILES		= ft_atoi.c		ft_isalnum.c	ft_isalpha.c	ft_isdigit.c	ft_isprint.c	\
			ft_isascii.c	ft_memcmp.c		ft_tolower.c	ft_toupper.c	ft_strncmp.c	\
			ft_itoa.c		ft_split.c		ft_strchr.c		ft_strdup.c		ft_strjoin.c	\
			ft_strmapi.c	ft_strnstr.c	ft_strrchr.c	ft_strtrim.c	ft_substr.c		\
			ft_bzero.c		ft_calloc.c		ft_memchr.c		ft_memcpy.c		ft_memmove.c	\
			ft_memset.c		ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	\
			ft_striteri.c	ft_strlcat.c	ft_strlcpy.c	ft_strlen.c

BONUS_FILES	= ft_lstnew_bonus.c		ft_lstadd_front_bonus.c		ft_lstsize_bonus.c		\
			ft_lstlast_bonus.c		ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c	\
			ft_lstiter_bonus.c		ft_lstclear_bonus.c			ft_lstmap_bonus.c

OBJS		= $(FILES:.c=.o)

BONUS_OBJS	= $(BONUS_FILES:.c=.o)

FLAGS		= -Wall -Werror -Wextra

CC			= cc 

HEADER		= libft.h

%.o:    	%.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	 $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS) $(BONUS_OBJS)

fclean: 	clean
		rm -rf $(NAME)

re:		fclean all

bonus:
		$(MAKE) $(NAME) FILES="$(BONUS_FILES) $(FILES)"

.PHONY:	all fclean clean re bonus
