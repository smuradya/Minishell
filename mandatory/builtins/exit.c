/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:46:43 by smuradya          #+#    #+#             */
/*   Updated: 2023/01/24 21:16:59 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	out_of_range(t_data *data, char **line)
{
	printf ("%s", "exit");
	printf ("minishell: exit: %s: numeric argument required\n", line[1]);
	data->exit_status = 255;
	exit(data->exit_status);
}

int	is_numeric_char(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int	is_numeric_argument(char *argument)
{
	int		i;
	int		len;
	int		starts_with_minus;
	size_t	number_len;

	len = ft_strlen(argument);
	starts_with_minus = argument[0] == '-';
	if (starts_with_minus && len == 1)
		return (0);
	i = -1 + starts_with_minus;
	while (argument[++i])
		if (!is_numeric_char(argument[i]))
			return (0);
	i = -1 + starts_with_minus;
	while (argument[++i] == '0')
		;
	number_len = len - i;
	if (number_len > 19 || (number_len == 19
			&& (((ft_strcmp(argument + i, "9223372036854775808") < 0)
					&& starts_with_minus)
				|| ((ft_strcmp(argument + i, "9223372036854775807") < 0)
					&& !starts_with_minus))))
		return (0);
	return (1);
}

int	my_exit(char **line, t_data *data)
{
	long long	exit_status;

	if (line[1] == NULL)
	{
		printf ("exit\n");
		exit(0);
	}
	else if (!is_numeric_argument(line[1]))
	{
		return (out_of_range(data, line));
	}
	else if (line[2])
	{
		printf ("exit");
		printf ("minishell: exit: too many arguments\n");
		return (1);
	}
	else
	{
		printf ("exit\n");
		exit_status = ft_atoi(line[1]);
		exit (exit_status % 256);
	}
}
