/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_create_envp(t_pipex *pipex, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != 0)
		i++;
	pipex->envp = malloc((i + 1) * sizeof(char *));
	i = -1;
	while (envp[++i] != 0)
		pipex->envp[i] = ft_strdup(envp[i]);
	pipex->envp[i] = 0;
}

void	free_envp(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->envp[++i])
		free(pipex->envp[i]);
	free(pipex->envp);
}

void	ft_env(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->envp[++i])
	{
		write(1, pipex->envp[i], ft_strlen(pipex->envp[i]));
		write(1, "\n", 1);
	}
}
