/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/05/18 12:36:24 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(char *envp[], t_pipex *pipex)
{
	path(envp, pipex);
	save_io(pipex);
	ft_create_envp(pipex, envp);
	create_red(pipex);
}

int	main(int argc, char **argv, char *envp[])
{
	char		*input;
	t_pipex		pipex;
	t_commands *command;
	t_commands *command2;

	(void)argc;
	(void)argv;
	ft_signal();
	command = malloc(sizeof(t_commands));
	command2 = malloc(sizeof(t_commands));
	command->redout = 0;
	command->redin = 0;
	command->filein = "";
	command->fileout = "";
	command->args = "ls -la";
	command->next = command2;
	command2->redout = 2;
	command2->redin = 0;
	command2->filein = "";
	command2->fileout = "out";
	command2->args = "wc -l";
	command2->next = 0;
	pipex.commands = command;
	init(envp, &pipex);
	exe(&pipex);
	close_red(&pipex);
	while (1)
	{
		input = readline("MiniShell> ");
		if (*input == 48)
			exit (0);
		using_history();
		add_history(input);
	}
	return (0);
}
