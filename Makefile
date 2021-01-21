NAME			= cub3D
CC				= clang
RM				= rm -rf

CFLAGS			= -Wall -Werror -Wextra
MIFLAGS			= -I$(MLX_DIR) -I$(LIBFR_DIR)includes -L $(LIBFR_DIR) -lft -L $(MLX_DIR) -lmlx
IFLAGS			= -I$(INC_DIR)
FFLAGS			= -framework OpenGL -framework Appkit

SRC_DIR			= srcs/
INC_DIR			= includes/
MLX_DIR			= mlx/
LIBFT_DIR		= libft/
OBJ_DIR			= objs/

INC				= $(shell find $(INC_DIR) -type f -name "*.h")
SRC				= $(notdir $(shell find $(SRC_DIR) -type f -name "*.c"))
OBJ				= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
vpath			%.c $(shell find $(SRC_DIR) -type d)

_YELLOW         = \e[38;5;184m
_GREEN          = \e[38;5;46m
_RESET          = \e[0m
_INFO           = [$(_YELLOW)INFO$(_RESET)]
_SUCCESS        = [$(_GREEN)SUCCESS$(_RESET)]
_CLEAR          = \033[2K\c

all				: init $(NAME)
				@ echo "$(_SUCCESS) Compilation done"


bonus			: all

init			: 
				@ $(shell mkdir -p $(OBJ_DIR))
				@ $(MAKE) --silent -C $(LIBFT_DIR)
				@ echo "$(_INFO) Preparing to initialize mlx..."
				@ $(MAKE) --silent -C $(MLX_DIR)
				@ echo "$(_SUCCESS) mlx compiled !"

$(NAME)			: $(OBJ) $(INC)
				@ echo "$(_INFO) Intializing $(NAME)"
				@ $(CC) $(CLFAGS) -o $@ $< $(MIFLAGS) $(FFLAGS)

$(OBJ_DIR)/%.o	: %.c
				@ echo "\t$(_YELLOW)Compiling $(_RESET) $*.c\r\c"
				@ $(CC) $(CFLAGS) $(IFLAGS)
				@ echo "$(_CLEAR)"

clean			:
				@ echo "$(_INFO) Deleting object files and directories..."
				@ $(RM) $(OBJ_DIR)
				@ $(MAKE) clean --silent -C $(LIBFT_DIR)
				@ $(MAKE) clean --silent -C $(MLX_DIR)
				@ echo "$(_SUCCESS) Working directory cleaned"

fclean			: clean
				@ $(RM) $(NAME)

re				: fclean all

norme			:
				@ ~/.norminette/norminette.rb $(SRC_DIR)
				@ ~/.norminette/norminette.rb $(INC_DIR)

.SUFFIXES:		.c .o.h
.PHONY:			all clean fclean re
