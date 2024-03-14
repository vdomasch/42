# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:58:39 by vdomasch          #+#    #+#              #
#    Updated: 2024/03/14 08:16:53 by vdomasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################################
#									VARIABLE								#
#############################################################################

NAME				=	so_long

HEADER_DIR			=	.
SRCS_DIR			=	srcs
OBJS_DIR			=	.objs

HEADERS				=	so_long.h

SRCS				=	so_long.c						\
					create_array.c					\
					check_map.c						\
					generate_map.c					\
					movement.c						\
					utils.c
					
OBJS				=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

LIB_D				=	Libft

#############################################################################
#									COMPILATION								#
#############################################################################

CC					=	cc
FLAGS				=	-Wall -Werror -Wextra -g3

#############################################################################
#										BONUS								#
#############################################################################

ifeq ($(BONUS),true)

	NAME			=	so_long_bonus
	
	SRCS_DIR		=	srcs_bonus

	SRCS			=	so_long_bonus.c						\
					create_array_bonus.c			\
					check_map_bonus.c				\
					generate_map_bonus.c			\
					movement_bonus.c				\
					monster_movement_bonus.c		\
					utils_bonus.c				
					
	OBJS			=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

endif

#############################################################################
#									MINILIBX								#
#############################################################################

MLX			:=	libmlx.a

MLX_D		:=	minilibx-linux/

MLX_F	:= -L ./minilibx-linux -lmlx -lXext -lX11

MLX_A		:=	$(addprefix $(MLX_D), $(MLX))

#############################################################################
#										RULES								#
#############################################################################

all					:	lib $(NAME) 

lib				:
							@$(MAKE) -C $(MLX_D)
							@$(MAKE) -C $(LIB_D)

$(NAME)				:	$(OBJS_DIR) $(OBJS) $(HEADERS) $(LIB_D)/libft.a $(MLX_A)
							$(CC) $(FLAGS) $(OBJS) $(LIB_D)/libft.a $(MLX_A) $(MLX_F) -o $(NAME)
							
$(OBJS_DIR)/%.o		:	$(SRCS_DIR)/%.c $(HEADERS)
							$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

$(OBJS_DIR)			:
							mkdir -p $(OBJS_DIR)

#############################################################################
#									COMMANDS								#
#############################################################################

clean				:
							rm -rf $(OBJS_DIR)
							$(MAKE) clean -C $(LIB_D)
							$(MAKE) clean -C $(MLX_D)

fclean				:
							$(MAKE) clean
							rm -rf $(NAME)
							$(MAKE)	fclean_bonus BONUS=true
							$(MAKE) fclean -C $(LIB_D)
							$(MAKE) clean -C $(MLX_D)

fclean_bonus		:		
							rm -rf $(NAME)

re					:
							$(MAKE) fclean all

bonus				:
							@$(MAKE) all BONUS=true
							
.PHONY: all clean fclean re lib bonus fclean_bonus