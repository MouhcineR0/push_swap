COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m
COLOUR_GRAY = \033[30m

LIBFT_SRC = libft/ft_isalpha.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isdigit.c \
	libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
	libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
	libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_split.c libft/lst_push.c libft/lst_cpy.c libft/lst_index_of.c \
	libft/lst_sort.c libft/ft_strcmp.c

PRINTF_SRC = printf/helper00.c printf/ft_putunsigned.c printf/ft_convertbase.c printf/ft_printf.c printf/ft_putnbr_fd_i.c printf/printarray.c \

SRC_PUSHSWAP = main.c Instructions/Instruction1.c Instructions/Instruction2.c Instructions/Instruction3.c isSorted.c sort.c lst_cases.c \
	lis.c handle_large.c handle_large0.c parse.c

BONUS  = bonus/getnextline/get_next_line.c bonus/checker.c Instructions/Instruction1.c Instructions/Instruction2.c Instructions/Instruction3.c \
		 isSorted.c sort.c lst_cases.c lis.c handle_large.c handle_large0.c parse.c

FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

CC = cc

NAME = push_swap

BONUS_NAME = checker

LIBFT = libft/libft.h

PRINTFLIB = printf/ft_printf.h

PUSH_SWAP = push_swap.h

# OBJ FILES
OBJS_PUSHSWAP = $(SRC_PUSHSWAP:.c=.o)

LIBFT_OBJS = $(LIBFT_SRC:.c=.o)

PRINTF_OBJS = $(PRINTF_SRC:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : Compiling $(OBJS_PUSHSWAP) $(LIBFT_OBJS) $(PRINTF_OBJS) $(PUSH_SWAP)
	@$(CC) $(FLAGS) $(OBJS_PUSHSWAP) $(LIBFT_OBJS) $(PRINTF_OBJS) -o $(NAME)
	@echo "$(COLOUR_GREEN)		Linking MANDATORY done !$(COLOUR_END)"

$(BONUS_NAME) : Compiling $(LIBFT_OBJS) $(PRINTF_OBJS) $(BONUS_OBJS)
	@$(CC) $(FLAGS) $(LIBFT_OBJS) $(PRINTF_OBJS) $(BONUS_OBJS) -o $(BONUS_NAME)
	@echo "$(COLOUR_GREEN)		Linking BONUS done !$(COLOUR_END)"

%.o : %.c $(LIBFT) $(PRINTFLIB) $(PUSH_SWAP)
	@$(CC) $(FLAGS) -c $< -o $@

Compiling :
	@echo "$(COLOUR_GRAY)Linking ...$(COLOUR_END)"

clean :
	rm -f $(OBJS_PUSHSWAP) $(BONUS_OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)

fclean : clean
	rm -f push_swap checker

re : fclean all

.PHONY: clean