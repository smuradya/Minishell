/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:32:01 by smuradya          #+#    #+#             */
/*   Updated: 2023/01/31 14:47:39 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	home_error(t_env **env, char **args)
{
	t_env	*tmp;

	tmp = *env;
	if (tmp == 0)
	{
		printf ("Minishell: cd: HOME not set\n");
		return (0);
	}
	while (tmp != 0)
	{
		if (!ft_strcmp(tmp->key, "HOME"))
		{
			*args = ft_strdup(tmp->value);
			break ;
		}
	}
	tmp = tmp->next;
	return (1);
}

void	ft_cd(char **args, t_env **env)
{
	char	size[1024];
	t_env	*tmp;

	tmp = *env;
	(void)size[1024];
	// printf("\n%s\n", getenv("HOME"));
	// while (tmp)
	// {
	// 	if (ft_strcmp("OLDPWD",(tmp)->value))
	// 	{
	// 		if ((tmp)->value)
	// 			free(tmp->value);
	// 		tmp->value = ft_strdup(getcwd(size, 0));
	// 	}
	// 	tmp = tmp->next;
	// }
	if (!args[1] || (!ft_strcmp(args[1], "~")))
		chdir(getenv("HOME"));
	// else if ((getenv("HOME")))
	// 	home_error(&tmp, args);
	else if (!chdir(args[1]))
		;
	else
		printf("minishell: :cd :%s No such file or directory\n", args[1]);
}
