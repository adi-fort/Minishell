/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:54:36 by adi-fort          #+#    #+#             */
/*   Updated: 2023/05/19 12:25:19 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handler(int signum)
{

	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
/*	else if (signum == SIGQUIT)
	{
		write(1, "exit\n", 5); 
		exit (1);
	}
	else if (signum == SIGABRT)
	{
		
	}*/
}

void	ft_signal(void)
{
	struct sigaction	signal;

	signal.sa_handler = &ft_handler;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
	sigaction(SIGABRT, &signal, NULL);
}
