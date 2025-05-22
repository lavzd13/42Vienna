NAME = Bureaucrat

CPP = c++
CPPFLAGS = -std=c++98
FLAGS = -Wall -Wextra -Werror

SOURCES = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
INCLUDES = Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

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
	rm -rf $(OBJDIR) $(NAME) *_shrubbery.txt

re: fclean all

.PHONY: all clean fclean re