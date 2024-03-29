#############################################################################
#									VARIABLE								#
#############################################################################

NAME_CLIENT			=	client

NAME_SERVER			=	server

HEADER_DIR			=	.
SRCS_DIR			=	srcs
OBJS_DIR			=	.objs

HEADERS				=	minitalk.h

SRCS_CLIENT			=	client.c			\
						utils.c

SRCS_SERVER			=	server.c			\
						utils.c

OBJS_CLIENT			=	$(SRCS_CLIENT:%.c=$(OBJS_DIR)/%.o)

OBJS_SERVER			=	$(SRCS_SERVER:%.c=$(OBJS_DIR)/%.o)

#############################################################################
#									COMPILATION								#
#############################################################################

CC					=	cc
FLAGS				=	-Wall -Werror -Wextra -g3

#############################################################################
#										RULES								#
#############################################################################

all					:	$(OBJS_DIR) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT)		:	$(OBJS_CLIENT) $(HEADERS)
							$(CC) $(FLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER)		:	$(OBJS_SERVER) $(HEADERS)
							$(CC) $(FLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)
							
$(OBJS_DIR)/%.o		:	$(SRCS_DIR)/%.c $(HEADERS)
							$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)			:
							mkdir -p $(OBJS_DIR)	

#############################################################################
#									COMMANDS								#
#############################################################################

clean				:
							rm -rf $(OBJS_DIR)

fclean				:
							$(MAKE) clean
							rm -rf $(NAME_CLIENT)
							rm -rf $(NAME_SERVER)

re					:
							$(MAKE) fclean all

							
.PHONY: all clean fclean re lib