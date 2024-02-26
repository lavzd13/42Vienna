#-------------EXECUTABLE--------------#
NAME = philo
FNAME = philof
#-------------SOURCES-----------------#

SOURCES = main.c utils.c init.c threads.c monitor.c routine.c threadutils.c
SOURCESDIR = ./sources

#-------------OBJECTS-----------------#

OBJECTSDIR = ./.objects
OBJECTS = $(addprefix $(OBJECTSDIR)/, $(SOURCES:.c=.o))

#-------------FLAGS-------------------#

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread
FSANITIZE = -fsanitize=thread

#------------COLORS-------------------#

COLOUR_GREEN = '\033[0;32m'
COLOUR_RED = '\033[0;31m'
COLOUR_BLUE = '\033[0;34m'
END_COLOUR = '\033[0m'
BOLD = '\033[1m'
COLOUR_ORANGE = '\033[38;5;208m'

#------------CODE---------------------#

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo " "
	@echo $(BOLD)$(COLOUR_ORANGE)"----Compiling philos files now-----"$(END_COLOUR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -I.
	@echo $(BOLD)$(COLOUR_GREEN)"🎉 Made philosophers successfully!🎉"$(END_COLOUR)
	@echo " "

$(OBJECTSDIR):
	@mkdir -p $(OBJECTSDIR)

$(OBJECTSDIR)/%.o:$(SOURCESDIR)/%.c | $(OBJECTSDIR)
	@$(CC) $(FLAGS) -c $< -o $@

fsanitize: $(OBJECTS) $(FNAME)

$(FNAME): $(OBJECTS)
	@echo " "
	@echo $(BOLD)$(COLOUR_ORANGE)"----Compiling philos files now-----"$(END_COLOUR)
	@$(CC) $(FLAGS) $(FSANITIZE) -o $(FNAME) $(OBJECTS) -I.
	@echo $(BOLD)$(COLOUR_GREEN)"🎉 Made philosophers successfully!🎉"$(END_COLOUR)
	@echo " "

clean:
	@rm -rf $(OBJECTSDIR)
	@echo " "
	@echo 🗑$(COLOUR_RED)" Removed all objects files."$(END_COLOUR)🗑
	@echo " "

fclean:
	@rm -rf $(OBJECTSDIR) $(NAME) $(FNAME)
	@echo " "
	@echo 🗑$(COLOUR_RED)" Removed everything."$(END_COLOUR)🗑
	@echo " "

re:fclean all

.PHONY: all clean fclean
