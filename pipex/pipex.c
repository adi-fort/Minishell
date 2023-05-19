/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec(t_pipex *pipex, int *fd, int *pip, t_commands *commands)
{
	if (commands->redout == 0 && commands->next == 0)
		dup2(pipex->stdout, 1);
	else if (commands->redout != 0)
		dup2(commands->fdout, 1);	
	else
		dup2(pip[1], 1);
	close(pip[1]);
	close(pip[0]);
	commands->cmd_args = ft_split(commands->args, ' ');
	commands->command = get_cmd(pipex->path, commands->cmd_args[0]);
		if (!commands->command)
		{
			msg(ERR_CMD);
			exit(1);
		}
	dup2(*fd, 0);
	close(*fd);
	execve(commands->command, commands->cmd_args, pipex->envp);
	return (error("error: cannot execute ", commands->command));
}

void	close_parent(int *tmp, int *fd)
{
	close(*tmp);
	close(fd[1]);
	*tmp = fd[0];
}
void	wait_process(int *tmp, t_commands *wp)
{
	close(*tmp);
	while (wp != 0)
	{
		if (wp->pid != -1)
		{
			waitpid(wp->pid, 0, 0);
		}
		wp = wp->next;
	}
}

void	exe(t_pipex *pipex)
{
	int			tmp;
	int			fd[2];
	t_commands  *wp;
	t_commands	*commands;

	tmp = dup(pipex->commands->fdin);

	wp = pipex->commands;
	commands = pipex->commands;
	while (commands != 0)
	{
		pipe(fd);

		commands->pid = fork();
		if (!commands->pid)
			exec(pipex, &tmp, fd, commands);
		else
			close_parent(&tmp, fd);
		commands = commands->next;
	}
	wait_process(&tmp, wp);
}