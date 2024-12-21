CC = cc 
FLAGS  = -Wall -Wextra -Werror
CFILES = main.c utils/ft_strdup.c parsing/my_split.c parsing/ft_checking.c \
utils/ft_utils.c utils/creat_and_rem_node.c utils/ft_split.c utils/utils2.c parsing/build_env.c \
 parsing/build_cmd_node.c utils/creat_node_cmd.c parsing/ft_go.c parsing/handling.c \
parsing/handle_herdoc.c exec/execution0.c utils/freeing_cmd_node.c
RD_DYNAMIC = -lreadline -lncurses
OFILES = $(CFILES:.c=.o)
NAME = minishell

all : $(NAME)

%.o : %.c minishell.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OFILES) $(LIBRARY)
	$(CC) $(FLAGS) $(OFILES) $(RD_DYNAMIC) -o $(NAME)  -fsanitize=address

clean : 
		rm -rf $(OFILES)

fclean	:
		rm -rf $(OFILES) $(NAME)

re : fclean all