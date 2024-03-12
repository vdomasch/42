# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 14:41:54 by vdomasch          #+#    #+#              #
#    Updated: 2024/03/12 16:52:04 by vdomasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################################
#									VARIABLE								#
#############################################################################

SRCS		:=	main.c				\
				check_map.c			\
				create_array.c		\
				generate_map.c		\
				movement.c			\
				monster_movement.c	\
				utils.c

SRCS_D		:=	bonus/

OBJS_D		:=	objs/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD		:=	so_long.h

CFLAGS		:=	-Wall -Wextra -Werror -g3

NAME		:=	so_long

#############################################################################
#										LIB									#
#############################################################################

LIB			:=	libft.a

LIB_D		:=	Libft/

LIB_H		:=	$(LIB_D)libft.h

LIB_A		:=	$(addprefix $(LIB_D), $(LIB))

#############################################################################
#									MINILIBX								#
#############################################################################

MLX			:=	libmlx.a

MLX_D		:=	minilibx-linux/

MLX_F		:=	-L$(MLX_D) -L/usr/lib -lmlx -lXext -lX11 -lm -lz

MLX_H		:=	$(MLX_D)mlx.h

MLX_A		:=	$(addprefix $(MLX_D), $(MLX))

#############################################################################
#										RULES								#
#############################################################################

all			:	lib
				@$(MAKE) -s $(NAME)

lib			:
				@$(MAKE) -s -C $(MLX_D)
				@$(MAKE) -s -C $(LIB_D)

$(NAME)		:	$(OBJS_D) $(OBJS) $(MLX_A) $(LIB_A) $(HEAD)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_A) $(MLX_F) $(LIB_A)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD) $(MLX_H) $(LIB_H)
				@$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)

#############################################################################
#									COMMANDS								#
#############################################################################

clean		:
				@$(RM) -r $(OBJS) $(OBJS_D)
				@$(MAKE) -s clean -C $(LIB_D)
				@$(MAKE) -s clean -C $(MLX_D)

fclean		:	clean
				@$(RM) $(NAME)
				@$(MAKE) -s fclean -C $(LIB_D)
				@$(MAKE) -s clean -C $(MLX_D)

re			:	fclean all

.PHONY: all bonus clean fclean re lib
