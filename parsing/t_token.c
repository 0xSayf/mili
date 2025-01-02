#include "../includes/minishell.h"

int	is__space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void    handle_special_char(char    *line, int  *i, t_token **tokens)
{
    int k;

    k = *i;
    if (line[k] == '>')
	{
		if ( line[k+1]== '>')
		{
			add_token_to_list(tokens, ft_creat_node(">>"));
			k++;
		}
		else
			add_token_to_list(tokens, ft_creat_node(">"));
	}
	else if (line[k] == '<')
	{
		if (line[k+1] == '<')
		{
			add_token_to_list(tokens, ft_creat_node("<<"));
			k++;
		}
		else
			add_token_to_list(tokens, ft_creat_node("<"));
	}
	else if (line[k] == '|')
		add_token_to_list(tokens, ft_creat_node("|"));
	k++;
    *i = k;
}

char    *ft_go_handle_quotes(char    *line, int *i, t_token  **tokens)
{
    char    v;
    char    *str;
    size_t  count_q;
    int     s;
    int     len;
    int     j;

    s = *i;
    len = 0;
    count_q = 0;
    while(line[s])
    {
        if(!count_q && line[s] && (line[s] == 34 || line [s] == 39))
        {
            v = line[s];
            count_q++;
            s++;
        }
        while (line[s] && count_q != 2 && line[s] != v )
        {
            len++;
            s++;
        }
        count_q++;
        if(count_q == 2)
            count_q = 0;
        s++;
        if(line[s] == 32 || line[s] == '|')
            break;
    }
    *i = s;
    j = 0;
    str = malloc(len + 1);
    str[len] = '\0';
    count_q = 0;
    while (len)
    {
        if(!count_q && (line[*i - s] == 34 || line [*i - s] == 39))
        {
            v = line[*i - s];
            s--;
            count_q++;
        }
        while(len && line[*i - s] != v && count_q != 2)
        {
            str[j] = line[*i - s];
            j++;
            len--;
            s--;
        }
        count_q++;
        if(count_q == 2)
            count_q = 0;
        s--;
        if(line[*i - s] == 32 || line[*i - s] == '|')
            break;
    }
    return (str);
}

t_token *ft_token_init(char *line)
{
    int i;
    char    *str;
    t_token *tokens;

    tokens = NULL;
    i = 0;
    while (line[i])
    {
        while (is__space(line[i]))
		    i++;
        if(ft_strchr("><|", line[i]))
            handle_special_char(line,&i,&tokens);
        if(line[i] == 34 || line[i] == 39)
        {
            str = ft_go_handle_quotes(line,&i,&tokens);
            add_token_to_list(&tokens , ft_creat_node(str));
            free(str);
        }
        // else
        //     ft_simple_word(line,&i,);
        // i++;
    }
    return tokens;
}