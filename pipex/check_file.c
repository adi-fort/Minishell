/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_fileout(char *fileout, t_commands *commands)
{
	if (commands->redout == 1)
	{
		commands->fdout = open(fileout, O_TRUNC | O_RDWR | O_CREAT, 0666);
		if (commands->fdout < 0)
			msg_error(ERR_OUTFILE);
	}
	else if (commands->redout == 2)
	{
		commands->fdout = open(fileout, O_APPEND | O_RDWR | O_CREAT, 0666);
		if (commands->fdout < 0)
			msg_error(ERR_OUTFILE);
	}
	else if (commands->redout == 0)
		commands->fdout = dup(1);
}

void	check_filein(char *filein, t_commands *commands)
{
	if (commands->redin == 1)
	{
		if (access(filein, F_OK) == 0)
		{
			commands->fdin = open(filein, O_RDONLY);
			if (commands->fdin < 0)
				msg_error(ERR_INFILE);
			return ;
		}
		printf("zs: %s: %s\n", strerror(errno), filein);
		exit (0);
	}
	else if (commands->redin == 0)
		commands->fdin = dup(0);
	else if (commands->redin == 2)
		write(1, "<<\n", 3);
}

void	create_red(t_pipex *pipex)
{
	t_commands	*com;

	com = pipex->commands;
	while (com != 0)
	{
		check_fileout(com->fileout, com);
		check_filein(com->filein, com);
		com = com->next;
	}
}

void	close_red(t_pipex *pipex)
{
	t_commands	*com;

	com = pipex->commands;
	while (com != 0)
	{
		close(com->fdin);
		close(com->fdout);
		com = com->next;
	}
}