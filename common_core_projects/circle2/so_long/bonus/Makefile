# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomke <lomke@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 21:02:04 by lomke             #+#    #+#              #
#    Updated: 2023/12/08 23:10:43 by lomke            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----EXECUTABLE-----
NAME = so_long_bonus
#-----SOURCES-----
SOURCES = so_long_bonus.c checkmap.c checkshapenwalls.c checkpath.c play.c playutils.c playutils2.c moving.c sprite.c spriteutils.c
#-----OBJECTS-----
OBJECTS = $(SOURCES:.c=.o)
#-----LIBFT-----
LIBFT = libft
#-----COMMANDS-----
CC = cc
RM = rm
FLAGS = -g -Wall -Werror -Wextra
#-----COLORS-----
COLOUR_GREEN = '\033[0;32m'
COLOUR_RED = '\033[0;31m'
COLOUR_BLUE = '\033[0;34m'
END_COLOUR = '\033[0m'
BOLD = '\033[1m'
COLOUR_ORANGE = '\033[38;5;208m'
#-----CODE-----
all: $(NAME)

$(NAME): $(OBJECTS)
	@make --no-print-directory -C $(LIBFT)
	@echo " "
	@echo $(BOLD)$(COLOUR_ORANGE)"----Compiling so_long_bonus files now-----"$(END_COLOUR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -L./libft -lft -lmlx -lXext -lX11 -lm
	@echo $(BOLD)$(COLOUR_GREEN)"🎉 Made so_long_bonus game successfully!🎉"$(END_COLOUR)
	@echo " "

%.o:%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean --no-print-directory -C $(LIBFT)
	@$(RM) -rf $(OBJECTS)
	@echo 🗑 $(COLOUR_RED)" Removed all objects files."$(END_COLOUR)🗑

fclean:
	@make fclean --no-print-directory -C $(LIBFT)
	@$(RM) -rf $(NAME) $(OBJECTS)
	@echo 🗑 $(COLOUR_RED)" Removed everything."$(END_COLOUR)🗑

re:fclean all

.PHONY: all clean fclean re
