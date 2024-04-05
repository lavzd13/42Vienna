NAME = phonebook

CPP = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SOURCES = contacts.cpp phonebook.cpp main.cpp

OBJDIR = ./.objects
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CPP) $(FLAGS) $(CPPFLAGS) -o $(NAME) $(OBJECTS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:%.cpp | $(OBJDIR)
	$(CPP) $(FLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean:
	rm -rf $(OBJDIR) $(NAME)

re: fclean all

.PHONY: all re clean fclean