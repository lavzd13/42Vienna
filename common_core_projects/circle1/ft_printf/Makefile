NAME = libftprintf.a
LIBFT = libft
SOURCES = ft_functions.c ft_printf.c ft_puthex.c ft_putptr.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -I./libft
AR = ar
RM = rm
COLOUR_GREEN = '\033[0;32m'
COLOUR_RED = '\033[0;31m'
COLOUR_BLUE = '\033[0;34m'
END_COLOUR = '\033[0m'

all: $(NAME)

$(NAME): $(OBJECTS)
	@make --no-print-directory -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) -rcs $(NAME) $(OBJECTS)
	@echo $(COLOUR_GREEN)"🎉 Made libftprintf.a successfully!🎉"$(END_COLOUR)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
#	@echo $(COLOUR_GREEN)"$(CC) $(CFLAGS) -c $< -o $@"$(END_COLOUR)

clean:
	@$(RM) -rf $(OBJECTS)
	@make clean --no-print-directory -C $(LIBFT)
	@echo 🗑$(COLOUR_RED)" Removed all objects files."$(END_COLOUR)🗑

fclean:
	@$(RM) -rf $(OBJECTS)
	@make clean --no-print-directory -C $(LIBFT)
	@$(RM) -rf $(NAME)
	@$(RM) -rf $(LIBFT)/libft.a
	@echo 🗑 $(COLOUR_RED)"Removed everything."$(END_COLOUR)🗑

re: fclean all

.PHONY: all clean fclean re
