/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:14:32 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/24 19:59:21 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_int_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_quit_handler2(int sig)
{
	(void)sig;
	kill(0, 0);
}

void	ft_int_handler2(int sig)
{
	(void)sig;
	rl_on_new_line();
	kill(0, 0);
}

void	ft_doc_sig_handle(int sig)
{
	(void)sig;
	ft_putendl_fd("\0", 1);
	exit(1);
}

void	init_signals(int mode)
{
	if (mode == INTERACTIVE)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &ft_int_handler);
	}
	else if (mode == CHILD)
	{
		signal(SIGQUIT, &ft_quit_handler2);
		signal(SIGINT, &ft_int_handler2);
	}
	else if (mode == HD_SIG)
	{
		signal(SIGINT, &ft_doc_sig_handle);
		signal(SIGQUIT, SIG_IGN);
	}
}
