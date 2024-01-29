/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:09:09 by siroulea          #+#    #+#             */
/*   Updated: 2024/01/24 22:27:44 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	do_pipe2(t_token *token)
{
	pid_t	pid;

	if (pipe(token->p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		dup2_1(token);
		exec(token);
		free_minishell(token->mini);
		exit(0);
	}
	else
	{
		token->pid = pid;
		dup2_0(token);
		exec_and_stuff(token->next->next);
	}
}

void	child_do_pipe3(t_token *token)
{
	do_heredoc(token);
	free_minishell(token->mini);
	exit(0);
}

void	do_pipe3(t_token *token)
{
	pid_t	pid;

	if (pipe(token->p_fd) == -1)
		exit(0);
	pid = fork();
	if (!pid)
	{
		dup2_1(token);
		child_do_pipe3(token);
		exit(0);
	}
	else
	{
		dup2_0(token);
		waitpid(pid, NULL, 0);
		while (token->type != PIPE && token->next)
			token = token->next;
		exec_and_stuff(token->next);
	}
}
