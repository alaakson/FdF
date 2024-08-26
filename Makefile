NAME = fdf

CC = cc
CFLAGS = -Werror -Wextra -Wall -I$(PRINTF_DIR)/headers -I$(LIBFT_DIR)/headers

MLX_DIR = minilibx-linux
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

MLX = $(MLX_DIR)/libmlx_Linux.a
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/ft_printf.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -lXext -lX11 -lm

SRC = commands.c \
		fdf.c	\
		render.c	\
		utlis.c		\
		main.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	@echo "Object files cleaned!"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "All cleaned up!"

re: fclean all

.PHONY: all clean fclean re