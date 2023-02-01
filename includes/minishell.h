/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:07:08 by anhakob2          #+#    #+#             */
/*   Updated: 2023/01/27 18:44:50 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils.h"
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <limits.h>

typedef struct s_data	t_data;
typedef struct s_list	t_list;
typedef struct s_node	t_node;
typedef char *			t_string;
typedef struct s_env	t_env;

struct s_list
{
	t_string	command;
	t_string	*args;
	int			in;
	int			out;
	t_string	*hd_word;
};

struct s_env
{
	char	*value;
	char	*key;
	t_env	*next;
	t_env	*head;
};

struct s_data
{
	char	*argument;
	int		exit_status;
	char	*command;
};

//char		**ft_split(char *str);
void		ft_cd(char **args, t_env **env);
void		ft_lstadd_back(t_env **lst, t_env *new);
void		my_env(t_env **env, char **arg);
void		print_env(t_env **env);
char		**ft_split_whit(char *str);
int			ft_strlen(const char *result);
void		ft_echo(char **arg);
int			ft_pwd(void);
void		ft_putendl_fd(char *str, int fd);
// long double	ft_atoi(const char *str);
int			my_exit(char **line, t_data *data);
int			ft_unset(char **cmd, t_env **env);
int			ft_strcmp(char *s1, char *s2);

#endif