
NAME = philo

SOURCES = main.c utils.c utils2.c init.c threads.c routine.c monitor.c
SOURCESDIR = ./sources

OBJECTSDIR = ./.objects
OBJECTS = $(addprefix $(OBJECTSDIR)/, $(SOURCES:.c=.o))

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -I.

$(OBJECTSDIR):
	mkdir -p $(OBJECTSDIR)

$(OBJECTSDIR)/%.o:$(SOURCESDIR)/%.c | $(OBJECTSDIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTSDIR)

fclean:
	rm -rf $(OBJECTSDIR) $(NAME)

re:fclean all

.PHONY: all clean fclean
