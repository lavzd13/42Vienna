NAME = thisIsBrain

CPP = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SOURCES = main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJECTS)
	$(CPP) $(FLAGS) $(CPPFLAGS) -o $(NAME) $(OBJECTS)

%.o:%.cpp
	$(CPP) $(FLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all re clean fclean