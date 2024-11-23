CC = cc 
FLAGS  = -Wall -Wextra -Werror
CFILES = parsing/main.c parsing/ft_strdup.c parsing/my_split.c parsing/ft_checking.c \
utils/ft_utils.c utils/creat_and_rem_node.c utils/ft_split.c utils/utils2.c parsing/build_env.c \
parsing/ft_expand.c 

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