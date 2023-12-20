NAME = fdf
NAME_BONUS = fdf_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = src/color.c src/control.c src/draw.c src/fdf.c src/ft_atoi_base.c \
		src/matrix.c src/read_file.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

SRC_BONUS = src_bonus/color_bonus.c src_bonus/control_bonus.c src_bonus/draw_bonus.c src_bonus/fdf_bonus.c src_bonus/ft_atoi_base_bonus.c \
		src_bonus/matrix_bonus.c src_bonus/menu_bonus.c src_bonus/read_file_bonus.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
FT_PRINTF_PATH = ./ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

MINILIBX_PATH = ./minilibx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(FT_PRINTF) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx
	@echo "\033[32mBuilt Completed! \033[35mKKANYILM\033[0m"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(SRC_BONUS) $(FT_PRINTF) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx
	@echo "\033[32mBonus Built Completed! \033[35mKKANYILM\033[0m"

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_PATH)

$(MINILIBX):
	@make -C $(MINILIBX_PATH) all

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(MINILIBX_PATH) clean
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)
	@echo "CLEANED!"

fclean:
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean
	@make -C $(MINILIBX_PATH) clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)
	@echo "FCLEANED!"

re: fclean all

.PHONY: all clean fclean re libft bonus
