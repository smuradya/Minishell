/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:00:54 by smuradya          #+#    #+#             */
/*   Updated: 2023/02/01 20:03:30 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env	*ft_lstlast(t_env *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*list;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			list = ft_lstlast(*lst);
			list->next = new;
		}
	}
}

void	my_env(t_env **env, char **arg)
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
		// free(env);
		tmp = NULL;
	}
}

void	print_env(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!tmp->next)
			return ;
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
