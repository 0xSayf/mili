CC = cc 
#FLAGS  = -Wall -Wextra -Werror
CFILES = main.c ../utils/ft_split.c ft_checking.c my_split.c ../utils/creating_node.c ft_strdup.c
RD_DYNAMIC = -lreadline -lncurses
OFILES = $(CFILES:.c=.o)
NAME = minishell

all : $(NAME)

%.o : %.c minishell.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OFILES) $(LIBRARY)
	$(CC) $(FLAGS) $(OFILES) $(RD_DYNAMIC) -o $(NAME) -fsanitize=address 

clean : 
		rm -rf $(OFILES)

fclean	:
		rm -rf $(OFILES) $(NAME)

re : fclean all