/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:15:46 by smuradya          #+#    #+#             */
/*   Updated: 2023/01/27 18:45:34 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	next_node(char *key_name, t_env **env)
{
	t_env	*tmp;
	t_env	*delete;

	tmp = *env;
	//printf("\n{%s}\n", key_name);
	while (tmp->next)
	{
		if (tmp->next && ft_strcmp(key_name, tmp->next->key) == 0)
		{
			delete = tmp->next;
			if (!tmp->next->next)
				tmp->next = NULL;
			else
				tmp->next = tmp->next->next;
			free(delete);
		}
		if (tmp->next)
			tmp = tmp->next;
	}
}

int	unset_errors(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] >= '0' && arg[i] <= '9')
		return (1);
	while (i < ft_strlen(arg))
	{
		if ((arg[i] > 32 && arg[i] < 48)
			|| (arg[i] == 58) || arg[i] == 63 || arg[i] == 59
			|| (arg[i] > 99 && arg[i] < 97)
			|| (arg[i] > 122 && arg[i] < 127) || arg[i] == 64)
			return (1);
		i++;
	}
	return (0);
}

int	ft_unset(char **cmd, t_env **env)
{
	int	i;

	i = 0;
	if (!cmd[1])
		printf("\n");
	else
	{
		while (cmd[++i])
		{
			if (unset_errors(cmd[i]) == 0)
				next_node(cmd[i], env);
			else
			printf("minishell: unset: `%s': not a valid identifier\n", cmd[1]);
		}
	}
	return (0);
}
