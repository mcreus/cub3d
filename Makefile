NAME	=	cub3D

CC		=	gcc
CFLAGS	=	-Wall -Wextra
MFLAGS	=	-lX11 -lXext
RM		=	rm -rf

LIBFT	=	./libft/libft.a
MLX		=	./minilibx-linux/libmlx.a

SRCS	=	main.c
OBJS	=	$(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@echo "\033[0;33m\COMPILING LIBFT\n"
	@$(MAKE) -C ./libft
	@echo "\033[1;32m\LIBFT CREATED\n"

$(MLX):
	@echo "\033[0;33m\COMPILING MLX\n"
	@$(MAKE) -C ./minilibx-linux
	@echo "\033[1;32m\MLX CREATED\n"

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "\033[0;33m\nCOMPILING CUB3D.....\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MFLAGS) -o $(NAME)
	@echo "\033[1;32m./cub3D created\n"

clean:
	@echo "\033[0;31mDELETING MLX files\nLIBFT files\nSO_long object...\n"
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@echo "033[1;32mDONE\n"

fclean: clean
	@echo "\033[0;31mDELETING CUB3D EXECUTABLE...."
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME)
	@echo "\033[1;32mDONE\n"

re: fclean all