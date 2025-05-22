NAME = Serializer

CPP = c++
CPPFLAGS = -std=c++98
FLAGS = -Wall -Wextra -Werror

SOURCES = main.cpp Serializer.cpp
INCLUDES = Serializer.hpp

OBJDIR = ./.objects
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CPP) $(FLAGS) $(CPPFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:%.cpp $(INCLUDES) | $(OBJDIR)
	$(CPP) $(FLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean:
	rm -rf $(OBJDIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re