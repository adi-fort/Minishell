/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERR_CMD "Command not found\n"
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"

typedef struct s_commands
{
	int					pid;
	int					redout; //>> > 0
	int					redin;
	int					fdin;
	int					fdout;
	char				*args;   // comando + arg + opzioni
	char				**cmd_args;
	char				*command;
	char				*filein;   //<FILE
	char				*fileout;  //>FILEOUT
	struct s_commands	*next;
}	t_commands;

typedef struct s_init
{
	int			stdin;
	int			stdout;
	char		**path;
	char		**envp;
	t_commands	*commands;
}	t_pipex;

//error.c
int		msg(char *err);
void	msg_error(char *err);
int		error(char *str, char *err);

//pipex_utils.c
void	path(char *envp[], t_pipex *pipex);
char	*get_cmd(char **paths, char *cmd);
void	save_io(t_pipex *pipex);

//pipex.c
void	exe(t_pipex *pipex);

//check_file.c
void	create_red(t_pipex *pipex);
void	close_red(t_pipex *pipex);

#endif
