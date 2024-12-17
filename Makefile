COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m
COLOUR_GRAY = \033[30m

SRC = libft/ft_isalpha.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isdigit.c \
	libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
	libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
	libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_split.c libft/lst_push.c libft/lst_cpy.c libft/lst_index_of.c \
	printf/helper00.c printf/ft_putunsigned.c printf/ft_convertbase.c printf/ft_printf.c printf/ft_putnbr_fd_i.c printf/printarray.c \
	main.c Instructions/Instruction1.c Instructions/Instruction2.c Instructions/Instruction3.c isSorted.c sort.c lst_cases.c libft/lst_sort.c


# FLAGS = -Wall -Wextra -Werror

CC = cc

NAME = push_swap

LIBFT = libft/libft.h

PRINTFLIB = printf/ft_printf.h

PUSH_SWAP = push_swap.h

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : Compiling $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(COLOUR_GREEN)		Linking done !$(COLOUR_END)"

%.o : %.c $(LIBFT) $(PRINTFLIB)
	@$(CC) $(FLAGS) -c $< -o $@

Compiling :
	@echo "$(COLOUR_GRAY)Linking ...$(COLOUR_END)"

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f push_swap

re : fclean all

.PHONY: clean