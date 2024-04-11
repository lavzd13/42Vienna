NAME = ScavTrap

CPP = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -pedantic -std=c++98

SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJDIR = ./.objects
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
INCLUDES = ClapTrap.hpp ScavTrap.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CPP) $(FLAGS) $(CPPFLAGS) -o $(NAME) $(OBJECTS) -I.

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:%.cpp $(INCLUDES) | $(OBJDIR)
	$(CPP) $(FLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean:
	rm -rf $(OBJDIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re