#-----EXECUTABLES-----
PROGRAM1 = server
PROGRAM2 = client
#-----FTPRINTF-----
FTPRINTF = ft_printf
#-----SOURCES-----
SOURCES1 = server.c
SOURCES2 = client.c clientutils.c
#UTILS = clientutils.c
#-----OBJECTS-----
OBJECTS2 = $(SOURCES2:.c=.o)
#-----COMMANDS-----
CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -I./ft_printf
RM = rm
#-----COLORS-----
FONT_GREEN = '\033[0;32m'
FONT_RESET = '\033[0m'
BOLD = '\033[1m'
FONT_ORANGE = '\033[38;5;208m'
#-----CODE-----
all: $(PROGRAM1) $(PROGRAM2)

$(PROGRAM1): $(SOURCES1)
	@make --no-print-directory -C $(FTPRINTF)
	@echo " "
	@echo $(BOLD)$(FONT_ORANGE)"----Compiling minitalk files now----"$(FONT_RESET)
	@$(CC) $(CFLAGS) -o $(PROGRAM1) $? -L./ft_printf -lftprintf
	@echo $(FONT_GREEN)"🎉 You made a server successfully!🎉"$(FONT_RESET)

$(PROGRAM2): $(OBJECTS2)
	@$(CC) $(CFLAGS) -o $(PROGRAM2) $(OBJECTS2) -L./ft_printf -lftprintf
	@echo $(FONT_GREEN)"🎉 You made a client successfully!🎉"$(FONT_RESET)
	@echo " "

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
#	@echo $(COLOUR_GREEN)"$(CC) $(CFLAGS) -c $< -o $@"$(END_COLOUR)

clean:
	@$(RM) -rf $(OBJECTS2)
	@make clean --no-print-directory -C $(FTPRINTF)

fclean:
	@$(RM) -rf $(PROGRAM1) $(PROGRAM2) $(OBJECTS2)
	@make fclean --no-print-directory -C $(FTPRINTF)

re: fclean all

.PHONY: all clean fclean re
