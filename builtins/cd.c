#include "../includes/minishell.h"

void	ft_cd_help(t_env *env)
{
	t_env	*tmp;
	int		status;

	if (!env)
		return ;
	while (tmp)
	{
		if (ft_strncmp("HOME", env, 4) == 0)
			break ;
		tmp = tmp->next;
	}
	status = chdir((tmp->var[5]));
	if (status == -1)
	{
		perror("No Working Dir");
		return ;
	}
}

void	*ft_cd(t_env *env, char *str)
{
	t_env *tmp;
	int status;

	if (!env)
		return (NULL);
	tmp = NULL;
	tmp = env;
	if (!str)
		ft_cd_help(tmp);
	else
	{
		status = chdir(str);
		if (status == -1)
		{
			perror("No Working Dir");
			return (NULL);
		}
	}
}