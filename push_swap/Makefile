# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 17:15:05 by vdomasch          #+#    #+#              #
#    Updated: 2024/03/12 19:24:25 by vdomasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR			=	.objs
SRCS_DIR			=	srcs
HEADER_DIR			=	.
HEADER	 			= 	push_swap.h

SRCS				=	$(SRCS_DIR)/push_swap.c						\
						$(SRCS_DIR)/checks.c						\
						$(SRCS_DIR)/rules.c							\
						$(SRCS_DIR)/sorting_algorythm.c				\
						$(SRCS_DIR)/swaplist.c						\
						$(SRCS_DIR)/utils.c							\
						$(SRCS_DIR)/ft_atoi.c						\
						$(SRCS_DIR)/ft_split.c						\
						$(SRCS_DIR)/ft_strncmp.c					\
						$(SRCS_DIR)/ft_isdigit.c					\

#ifeq ($(BONUS),true)
#
#SRCS_DIR			= 	bonus
#SRCS 				=	$(SRCS_DIR)/_bonus.c				\
#						
#
#HEADER_DIR			=	.
#HEADER_FILE		=	_bonus.h
#
#endif

OBJS				=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

CC					=	cc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra -g3

NAME				=	push_swap

all: $(NAME)

$(OBJS_DIR)/%.o: 	$(SRCS_DIR)/%.c $(HEADER_DIR)/$(HEADER)
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

$(NAME):			 $(OBJS)
					@$(CC) $(CFLAGS) $(OBJS) -o $@ -I $(HEADER_DIR)

clean:
					@$(RM) $(OBJS) rm -rf $(OBJS_DIR)

fclean:				clean
					@$(RM) $(NAME)

re:					fclean $(NAME)

#bonus: 
#					@$(MAKE) $(NAME) BONUS=true
	
.PHONY:				all clean fclean re bonus