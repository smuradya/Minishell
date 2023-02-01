/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:10:47 by anhakob2          #+#    #+#             */
/*   Updated: 2023/01/30 17:45:26 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	commands_runner(char *line, t_data *data, t_env **env, char **envp)
{	
	char	**argv;
	(void) envp;
	argv = ft_split(line, ' ');
	if (ft_strcmp(argv[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(argv[0], "env") == 0)
	{
		//my_env (env, envp);
		print_env(env);
	}
	else if (ft_strcmp(argv[0], "cd") == 0)
		ft_cd(argv, env);
	else if (ft_strcmp(argv[0], "unset") == 0)
	{
		//my_env (env, envp);
		ft_unset(argv, env);
	}
	else if (ft_strcmp(argv[0], "echo") == 0)
		ft_echo(argv);
	else if (ft_strcmp(argv[0], "exit") == 0)
		my_exit(argv, data);
	// else if (ft_strncmp(line, "cd", 3) == 0)
	return (0);
}

// clear && make && make clean && ./minishell
int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_data	*data;
	t_env	*env;

	(void)argc;
	(void)argv;

	data = malloc(sizeof(t_data));
	// if (argc != 1)
	// {
	// 	write (1, "ERROR\n", 6);
	// 	return (1);
	// }
	my_env(&env, envp);
	while (1)
	{
		rl_catch_signals = 0;
		line = readline("Minishell% ");
		add_history(line);
		if (!line)
		{
			write (1, "exit", 5);
			return (0);
		} 
		commands_runner(line, data, &env, envp);
		// data->argument = ft_strdup(&line[5]);
		// data->argument = ft_strdup(&line[4]);
		//ft_echo(data);
		//ft_pwd();
		// my_env(&env, envp);
		// print_env(&env);
		//ft_cd(data, &env);
		//if (ft_strcmp(argv[0], "env"))
		//argv = ft_split(line, ' ');
		//ft_unset(argv, &env);
		//ft_cd(data, &env);
		//print_env(&env);
		// if (!ft_strcmp(*argv, "exit"))
		//my_exit(argv, data);
		//parsing (line);
		//free (line);
	}
}
