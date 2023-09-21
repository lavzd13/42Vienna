NAME = libft.a
COLOUR_GREEN = '\033[0;32m'
COLOUR_RED = '\033[0;31m'
COLOUR_BLUE = '\033[0;34m'
END_COLOUR = '\033[0m'

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BSOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
AR = ar

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) -rcs $@ $?
	@echo $(COLOUR_GREEN)"🎉 Made libft.a successfully!🎉"$(END_COLOUR)

bonus: $(OBJECTS) $(BOBJECTS)
	@$(AR) -rcs $(NAME) $?
	@echo $(COLOUR_BLUE)"🎉 Added bonus to libft.a🎉"$(END_COLOUR)

%.o:%.c
	@$(CC) -c $(CFLAGS) $?
#	@echo $(COLOUR_GREEN)"$(CC) $(CFLAGS) -c $?"$(END_COLOUR)

clean:
	@rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	@rm -f $(NAME)
	@echo $(COLOUR_RED)"🗑Removed everything.🗑"$(END_COLOUR)

re: fclean all

.PHONY: all clean fclean re
