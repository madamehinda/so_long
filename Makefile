# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hferjani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 14:18:35 by hferjani          #+#    #+#              #
#    Updated: 2022/11/16 16:26:47 by hferjani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##present :
##		@echo "\e[1;42m     SO LONG !    \e[0m"

#################################-ARGUMENTS-####################################

NAME	= 	so_long

FLAGS 	= 	-Wall -Werror -Wextra -g

CC 		= 	gcc

####################################-SOURCES-###################################

SRC		= 	main.c \
	 		parsing.c \
			parsing2.c\
			
####################################-OBJECTS-###################################

#OBJ_PATH	= obj
#OBJ		= $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJS		= $(SRC:.c=.o)

####################################-RULES-#####################################

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= Libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./so_long.h

all:  $(NAME)

#$(MLX):
#@echo "Making MiniLibX..."
#@make -sC $(MLX_PATH)

#$(LIBFT):
#@echo "Making libft..."
#@make -sC $(LIBFT_PATH)

${NAME}: ${OBJS}
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)
	@echo "Making so_long..."
	$(CC) $(FLAGS) $(OBJS) -L./Libft -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "so_long ready!"

RM		=  rm -f

%.o: %.c
#@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS)  -c $< -o $@ 


clean:
		$(RM) ${OBJS}
		make clean -C $(MLX_PATH)
		make clean -C $(LIBFT_PATH)

fclean:	clean
	@echo "spring cleaning..."
	@$(RM) ${NAME}

re: 		fclean all

.PHONY: 	all clean fclean re