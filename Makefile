NAME = libftprintf.a

SRC= ft_print_str.c \
ft_print_chr.c \
ft_print_ptr.c \
ft_print_percent.c \
ft_print_nbr.c \
ft_print_hex_lower.c \
ft_print_hex_upper.c \
ft_print_unsigned.c \
ft_printf.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = #-Wall -Wextra -Werror

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all