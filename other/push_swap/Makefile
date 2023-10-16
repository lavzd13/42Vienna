# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 19:58:52 by jlomic            #+#    #+#              #
#    Updated: 2023/10/15 14:27:12 by jlomic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----EXECUTABLES-----
NAME = push_swap
#-----SOURCES-----
SOURCES = push_swap.c swap.c push.c rotate.c reverse.c utils.c algosmall.c algomedium.c algobig.c bigutils.c
#-----OBJECTS-----
OBJECTS = $(SOURCES:.c=.o)
#-----FTPRINTF-----
FT_PRINTF = ft_printf
#-----COMMANDS-----
CC = cc
CFLAGS = -g -Wall -Werror -Wextra -I. -I./ft_printf
RM = rm
#-----COLORS-----
COLOUR_GREEN = '\033[0;32m'
COLOUR_RED = '\033[1;31m'
COLOUR_BLUE = '\033[0;34m'
COLOUR_ORANGE = '\033[38;5;208m'
BOLD = '\033[1m'
END_COLOUR = '\033[0m'
#-----CODE-----
all: $(NAME)

$(NAME): $(OBJECTS)
	@make --no-print-directory -C $(FT_PRINTF)
	@echo " "
	@echo $(BOLD)$(COLOUR_ORANGE)"----Compiling push_swap files now----"$(END_COLOUR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L./ft_printf -lftprintf
	@echo $(COLOUR_GREEN)"🎉 You made push_swap successfully!🎉"$(END_COLOUR)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean --no-print-directory -C $(FT_PRINTF)
	@$(RM) -rf $(OBJECTS)

fclean:
	@make fclean --no-print-directory -C $(FT_PRINTF)
	@$(RM) -rf $(NAME) $(OBJECTS)

re:fclean all

.PHONY: all clean fclean re
