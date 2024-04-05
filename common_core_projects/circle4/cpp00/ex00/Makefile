NAME = megaphone

CPP = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SOURCES = megaphone.cpp

OBJECTS = $(SOURCES:.cpp=.opp)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CPP) $(FLAGS) $(CPPFLAGS) -o $(NAME) $(OBJECTS)

%.opp:%.cpp
	$(CPP) $(FLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean:
	rm -rf $(NAME) $(OBJECTS)

re: fclean all

.PHONY: clean fclean re all
