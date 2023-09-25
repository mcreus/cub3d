# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 15:02:00 by aperrein          #+#    #+#              #
#    Updated: 2023/09/25 23:24:58 by mcreus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

LIBFT = 	libft/libft.a

L = 		libft/

OBJ_DIR =	OBJ/

SRC_DIR =	SRC/

SRC	=	main.c conf_init.c conf_check.c error_conf.c utils.c \
		check_color.c mlx_alex.c raytracing_init.c moves.c

OBJ	=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

RM	=	rm -f

CFLAGS	=	-Wall -Wextra

all     :       $(OBJ_DIR) $(NAME)
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		gcc $(CFLAGS) -g -c $< -o $@

$(OBJ_DIR) :
		mkdir $(OBJ_DIR)

$(NAME)	:	$(OBJ) $(L)
		make -s -C libft/
		make -s -C minilibx
		gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) minilibx/libmlx.a -lX11 -lXext

clean	:
		$(RM) $(OBJ)
#		make clean -C libft/
#		make clean -C minilibx/

fclean	:	clean
		$(RM) $(NAME)
#		make fclean -C libft/

re 	:	fclean all
