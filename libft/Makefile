NAME			= libft.a
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
IFLAGS			= -I$(INCS_PATH)
AR				= ar
ARFLAGS			= rcs
RM				= rm -rf

STR_SRCS_PATH	= string
MEM_SRCS_PATH	= memory
CHAR_SRCS_PATH	= char
FD_SRCS_PATH	= fd
NUM_SRCS_PATH	= numbers
BONUS_SRCS_PATH	= bonus
SRCS_PATH		= srcs
INCS_PATH		= includes

STR_SRCS_NAME	= $(addprefix $(STR_SRCS_PATH)/, ft_strcpy.c \
					ft_strdel.c \
					ft_strdup.c \
					ft_strequ.c \
					ft_strlen.c \
					ft_strncpy.c \
					ft_strnequ.c \
					ft_strnew.c \
					ft_substr.c \
					ft_strtrim.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strclr.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strcat.c \
					ft_strjoin.c \
					ft_strlcpy.c \
					ft_strndup.c \
					ft_split.c)
MEM_SRCS_NAME	= $(addprefix $(MEM_SRCS_PATH)/, ft_bzero.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c \
					ft_calloc.c)
CHAR_SRCS_NAME	= $(addprefix $(CHAR_SRCS_PATH)/, ft_tolower.c \
					ft_isdigit.c \
					ft_islower.c \
					ft_isupper.c \
					ft_isalpha.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_tolower.c \
					ft_isprint.c \
					ft_toupper.c)
FD_SRCS_NAME	= $(addprefix $(FD_SRCS_PATH)/, ft_putchar_fd.c \
					 ft_putstr_fd.c \
					 ft_putendl_fd.c \
					 ft_putnbr_fd.c)
NUM_SRCS_NAME	= $(addprefix $(NUM_SRCS_PATH)/, ft_abs.c)
BONUS_SRCS_NAME	= $(addprefix $(BONUS_SRCS_PATH)/, ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c)
INCS_NAME		= libft.h

INCS			= $(addprefix $(INCS_PATH)/, $(INCS_NAME))
SRCS			= $(addprefix $(SRCS_PATH)/, $(STR_SRCS_NAME) \
					$(MEM_SRCS_NAME) \
					$(CHAR_SRCS_NAME) \
					$(FD_SRCS_NAME) \
					$(NUM_SRCS_NAME))
BONUS			= $(addprefix $(SRCS_PATH)/, $(BONUS_SRCS_NAME))

OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS:.c=.o)

all				: $(NAME)

$(NAME)			: $(OBJS)
				$(AR) $(ARFLAGS) $@ $^

%.o				: %.c
				$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

bonus			: $(OBJS) $(BONUS_OBJS)
				$(AR) $(ARFLAGS) $(NAME) $^

clean			: 
				$(RM) $(OBJS) $(BONUS_OBJS) $(INCS:.h=.h.gch)

fclean			: clean
				$(RM) $(NAME)
				
re				: fclean all

.PHONY			: all re clean fclean
