NAME = PmergeMe

CXX = c++
CXXFLAGS = -std=c++98 -pedantic
FLAGS = -Wall -Wextra -Werror

SOURCES = main.cpp PmergeMe.cpp
INCLUDES = PmergeMe.hpp

OBJDIR = .objects
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

DEPFILES = $(OBJECTS:.o=.d)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(FLAGS) $(CXXFLAGS) $(OBJECTS) -o $(NAME) -I.

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:%.cpp $(INCLUDES) | $(OBJDIR)
	$(CXX) $(FLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPFILES)

clean:
	rm -rf $(OBJDIR)

fclean:
	rm -rf $(OBJDIR) $(NAME) $(NAME2)

re:fclean all

.PHONY: all clean fclean re