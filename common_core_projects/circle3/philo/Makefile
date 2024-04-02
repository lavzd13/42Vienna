NAME = philo

CC = cc
FLAGS = -Wall -Werror -Wextra
CFLAGS = -g
INCLUDES = ./includes

SOURCES_DIR = ./sources
SOURCES = main.c utils.c check_args.c init.c thread.c routine.c exit.c monitor.c

OBJECTS_DIR = ./.objects
OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(SOURCES:.c=.o))

COLOUR_GREEN = '\033[0;32m'
COLOUR_RED = '\033[0;31m'
COLOUR_BLUE = '\033[0;34m'
END_COLOUR = '\033[0m'
BOLD = '\033[1m'
COLOUR_ORANGE = '\033[38;5;208m'


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(CFLAGS) -o $(NAME) $(OBJECTS) -I$(INCLUDES)

$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o:$(SOURCES_DIR)/%.c | $(OBJECTS_DIR)
	$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIR)

fclean:
	rm -rf $(OBJECTS_DIR) $(NAME)

re:fclean all

.PHONY: all clean fclean re
