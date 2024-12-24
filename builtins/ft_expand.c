#include "../includes/minishell.h"

void	ft_export(char *line, t_env *env)
{
	int i;
	char *str;
	t_env *tmp;

	i = 0;
	if (!line || !env)
		return ;
	tmp = env;
	if (!finder(env, line[i + 1]))
	{
		tmp->next = ft_creat_env(ft_strdup(line[i + 1]));
		tmp = tmp->next;
	}
	else if (finder(env, line[i + 1]) && !find(env, line[i + 1]))
	{
		ft_go_del(&env, line[i + 1]);
		tmp = env;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_creat_env(ft_strdup(line[i + 1]));
		tmp = tmp->next;
	}
	i++;
}