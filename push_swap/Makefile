# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:58:39 by vdomasch          #+#    #+#              #
#    Updated: 2024/03/14 08:43:07 by vdomasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################################
#									VARIABLE								#
#############################################################################

NAME				=	push_swap

HEADER_DIR			=	.
SRCS_DIR			=	srcs
OBJS_DIR			=	.objs

HEADERS				=	push_swap.h

SRCS				=	push_swap.c						\
						checks.c						\
						rules.c							\
						sorting_algorythm.c				\
						swaplist.c						\
						utils.c							\

OBJS				=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

LIB_D				=	Libft

#############################################################################
#									COMPILATION								#
#############################################################################

CC					=	cc
FLAGS				=	-Wall -Werror -Wextra -g3

#############################################################################
#										RULES								#
#############################################################################

all					:	lib $(NAME) 

lib					:
							@$(MAKE) -C $(LIB_D)

$(NAME)				:	$(OBJS_DIR) $(OBJS) $(HEADERS) $(LIB_D)/libft.a
							$(CC) $(FLAGS) $(OBJS) $(LIB_D)/libft.a -o $(NAME)
							
$(OBJS_DIR)/%.o		:	$(SRCS_DIR)/%.c $(HEADERS)
							$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)			:
							mkdir -p $(OBJS_DIR)

#############################################################################
#									COMMANDS								#
#############################################################################

clean				:
							rm -rf $(OBJS_DIR)
							$(MAKE) clean -C $(LIB_D)

fclean				:
							$(MAKE) clean
							rm -rf $(NAME)
							$(MAKE) fclean -C $(LIB_D)

re					:
							$(MAKE) fclean all

							
.PHONY: all clean fclean re lib