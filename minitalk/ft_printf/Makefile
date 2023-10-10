#-----EXECUTABLES-----
NAME = libftprintf.a
#-----LIBFT-----
LIBFT = libft
#-----SOURCES-----
SOURCES = ft_functions.c ft_printf.c ft_puthex.c ft_putptr.c
#-----OBJECTS-----
OBJECTS = $(SOURCES:.c=.o)
#-----COMMANDS-----
CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -I./libft
AR = ar
RM = rm
#-----COLORS-----
COLOUR_GREEN = '\033[0;32m'
COLOUR_RED = '\033[1;31m'
COLOUR_BLUE = '\033[0;34m'
COLOUR_ORANGE = '\033[38;5;208m'
BOLD = '\033[1m'
END_COLOUR = '\033[0m'
#-----CODE-----
all: $(NAME)

$(NAME): $(OBJECTS)
	@make --no-print-directory -C $(LIBFT)
	@echo " "
	@echo $(BOLD)$(COLOUR_ORANGE)"----Compiling ft_printf files now----"$(END_COLOUR)
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
