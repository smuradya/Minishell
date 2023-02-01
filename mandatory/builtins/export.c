/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:49:22 by smuradya          #+#    #+#             */
/*   Updated: 2023/02/01 15:38:12 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_env **env, char **arg)
{
	int		i;
	t_env	*node;
	char	**tmp;

	i = 0;
	node = malloc(sizeof(t_env));
	while (arg[i])
	{
		tmp = ft_split_whit(arg[i]);
		if (ft_strcmp(tmp[0], "OLDPWD") == 0)
			i++;
		else
		{
			node = malloc(sizeof(t_env));
			node->key = ft_strdup(tmp[0]);
			node->value = ft_strdup(tmp[1]);
			node->next = NULL;
			printf("node->key = %s\n", node->key);
			printf("node->key = %s\n", node->value);
			ft_lstadd_back(env, node);
			i++;
		}
		tmp = NULL;
	}
}

void	print_export(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!tmp->next)
			return ;
		ft_putstr_fd("declare -x ", 1);
		printf("%s=%s\n",tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
