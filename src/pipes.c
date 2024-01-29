/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 07:34:54 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/24 10:35:47 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	dup2_0(t_token *token)
{
	close(token->p_fd[1]);
	dup2(token->p_fd[0], 0);
	close(token->p_fd[0]);
}

void	dup2_1(t_token *token)
{
	close(token->p_fd[0]);
	dup2(token->p_fd[1], 1);
	close(token->p_fd[1]);
}

void	child_do_pipe(t_token *token)
{
	dup2_1(token);
	if (token->type == ABS)
		absolute_path(token);
	else
		exec(token);
	free_minishell(token->mini);
	exit(0);
}

void	do_pipe(t_token *token)
{
	pid_t	pid;

	pipe(token->p_fd);
	pid = fork();
	if (pid == 0)
		child_do_pipe(token);
	else
	{
		token->pid = pid;
		dup2_0(token);
		set_error(token);
		exec_and_stuff(token->next);
	}
}

void	do_pipe_cat(t_token *token)
{
	pid_t	pid;

	if (is_empty(token->next->cmd[0]))
		return ;
	if (pipe(token->p_fd) == -1)
		exit(0);
	pid = fork();
	if (!pid)
	{
		dup2_0(token);
		exec_and_stuff2(token->next);
		exit(0);
	}
	else
	{
		token->pid = pid;
		dup2_1(token);
		child_do_pipe(token);
	}
}
