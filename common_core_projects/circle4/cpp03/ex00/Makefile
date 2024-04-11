NAME = clapTrap

CPP = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -pedantic -std=c++98

SOURCES = main.cpp ClapTrap.cpp
INCLUDES = ClapTrap.hpp

OBJDIR = ./.objects
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECTS) $(DEPENDECIES)
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