/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:09:10 by smuradya          #+#    #+#             */
/*   Updated: 2023/01/27 19:11:10 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	word_counter_new(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = 1;
	while (str[++i] && (str[i] == '='))
		;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if ((str[i] == '=') && str[i + 1] > 32)
			len++;
		i++;
	}
	return (len);
}

int	word_len_counter_new(char *str)
{
	int	len;

	len = -1;
	while (str[++len] && (str[len] != '='))
		;
	return (len);
}

void	fill_word_new(char *copy_to, char *copy_from)
{
	int	len;

	len = -1;
	while (copy_from[++len]
		&& (copy_from[len] != '='))
		copy_to[len] = copy_from[len];
	copy_to[len] = '\0';
}

char	**ft_split_whit(char *str)
{
	int		i;
	int		counter;
	int		word_count;
	int		word_len;
	char	**result;

	i = -1;
	counter = -1;
	word_count = word_counter_new(str);
	result = malloc(sizeof(char *) * (word_count + 1));
	while (++counter < word_count)
	{
		while (str[++i] && (str[i] == '='))
			;
		word_len = word_len_counter_new(str + i);
		result[counter] = malloc(word_len + 1);
		fill_word_new(result[counter], str + i);
		i += word_len;
	}
	result[word_count] = 0;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				result;
	int				i;

	i = 0;
	result = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] && str1[i] == str2[i])
		i++;
	if (str1[i] != str2[i])
		result = str1[i] - str2[i];
	{
		if (result > 0)
			return (1);
		else if (result == 0)
			return (0);
		else
			return (-1);
	}
}

// t_env	*remove_env(t_env **env)
// {
// 	t_env	*cur;
// 	t_node	*temp;

// 	cur = *env;
// 	if (!cur->head)
// 		return (NULL);
// 	temp = cur->head;
// 	cur->head = cur->head->next;
// 	temp->next = NULL;
// 	cur->count--;
// 	return (temp);
// }

// void	free_env(t_env **env)
// {
// 	t_env	*tmp;

// 	tmp = *env;
// 	while (tmp->next)
// 		free(remove_env(tmp));
// 	free(tmp);
// }
