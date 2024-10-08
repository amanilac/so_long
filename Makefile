NAME = so_long
DEBUG_NAME = debug.out

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc/
DEP_DIR = deps/
LIB_DIR = libs

LIBFT_DIR = $(DEP_DIR)/libft
LIBFT = $(LIB_DIR)/libft.a
MLX_DIR = $(DEP_DIR)/MLX42
MLX = $(LIB_DIR)/libmlx42.a

SRC_NAMES =	main.c				\
			generate_map.c		\
			error.c				\
			map_utils.c			\
			parsing.c			\
			movement.c			\
			move_utils.c		\
			more_parsing.c		\
			path_utils.c		\

CC = cc
CC_EXT_SRCS = -L$(LIB_DIR) $(LIBFT) -lft -lmlx42 -lm -lglfw
FLAGS = -I$(INC_DIR) -Wall -Wextra -Werror -g
DEBUG_FLAGS = -I$(INC_DIR) -g -fsanitize=address

################################################################################

OBJS = $(SRC_NAMES:%.c=$(OBJ_DIR)/src/%.o)
OBJS_DEBUG = $(SRC_NAMES:%.c=$(OBJ_DIR)/debug/%.o)

.PHONY: all debug \
clean .clean fclean re

################################################################################

all: $(NAME)

$(OBJ_DIR)/debug/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(DEBUG_FLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(DEBUG_FLAGS) -c $< -o $@

$(OBJ_DIR)/src/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(FLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(FLAGS) -c $< -o $@

################################################################################

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR) bonus
	@mkdir -p $(LIB_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)

$(MLX_DIR):
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR)

$(MLX): $(MLX_DIR)
	@env cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@make --no-print-directory -C $(MLX_DIR)/build -j4
	@mkdir -p $(LIB_DIR)
	@cp $(MLX_DIR)/build/libmlx42.a $(MLX)

################################################################################

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(CC_EXT_SRCS) -o $(NAME)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)src done$(DEFAULT)"

################################################################################

$(DEBUG_NAME): $(LIBFT) $(MLX) $(OBJS_DEBUG)
	@$(CC) $(DEBUG_FLAGS) $(CC_EXT_SRCS) $(OBJS_DEBUG) -o $(DEBUG_NAME)
	@echo "$(GREY)$(NAME) $(DEBUG_NAME) $(DEFAULT)| $(GREEN)src done$(DEFAULT)"

debug: $(DEBUG_NAME)

################################################################################

.clean:
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(OBJ_DIR)"
	@rm -rf $(OBJ_DIR) .bonus .debug_bonus

clean: .clean
	@make --no-print-directory -C $(LIBFT_DIR) clean
	
fclean: .clean
	@make --no-print-directory -C $(LIBFT_DIR) fclean 
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(NAME), $(DEBUG_NAME), and $(LIB_DIR)"
	@rm -rf $(NAME) $(DEBUG_NAME) $(LIB_DIR)

re: fclean all

################################################################################

GREEN = \033[38;5;84m
RED = \033[38;5;9m
BLUE = \033[38;5;45m
PURPLE = \033[38;5;63m
PINK = \033[38;5;207m
PURPLE = \033[38;5;165m
BLACK = \033[38;5;0m
BG_WHITE = \033[48;5;15m
BG_GREEN = \033[48;5;84m
BG_RED = \033[48;5;9m
BG_PURPLE = \033[48;5;54m
GREY = \033[38;5;8m
BOLD = \033[1m
DEFAULT = \033[0m
CHECKMARK = \xE2\x9C\x93
