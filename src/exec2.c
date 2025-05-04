/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:09:24 by siroulea          #+#    #+#             */
/*   Updated: 2025/05/04 10:57:09 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	continue_child(t_token *token)
{
	if (token->type == ABS)
		absolute_path(token);
	else if (!ft_strncmp(token->cmd[0], "echo", 5))
		ft_echo(token);
	else if (!ft_strncmp(token->cmd[0], "pwd", 4))
		ft_pwd(token);
}

void	do_child_stuff(t_token *token)
{
	t_mini	*mini;
	t_token	*temp;

	temp = token;
	mini = get_data();
	if (token->type == REDIR_IN || token->type == REDIR_DBL)
	{
		child_redir_to(token);
		exec(temp);
	}
	else if (token->type == REDIR_OUT)
		redir2(token);
	else if (token->type == HEREDOC_T)
		heredoc(token);
	else if (token->type == PIPE && !ft_strncmp(mini->tokens->cmd[0], "cat", 4))
		do_pipe_cat(token);
	else if (token->type == PIPE || (token->next && !ft_strncmp(token->next_sep,
				"|", 1)))
		do_pipe(token);
	else if (token->type == ABS || (!ft_strncmp(token->cmd[0], "echo", 5))
		|| (!ft_strncmp(token->cmd[0], "pwd", 4)))
		continue_child(token);
	else
		exec(token);
	exit(free_minishell(mini));
}

void	continue_exec(t_token *token)
{
	if (token->next && token->next->type == REDIR_OUT)
		exec_and_stuff(token->next);
	if (token->next && token->next->next && (token->type == REDIR_IN
			|| token->type == REDIR_DBL))
	{
		while (token->type == REDIR_IN && token->next)
		{
			token = token->next;
		}
		if (token->next && ft_strncmp(token->next->cmd[0], "cat", 3) != 0
			&& ft_strncmp(token->next->cmd[0], "wc", 3) != 0)
			exec_and_stuff(token->next);
	}
}

void	exec_and_stuff(t_token *token)
{
	pid_t	pid;
	t_mini	*mini;
	
	mini = get_data();
	update_error(mini);
	
	if (token == NULL)
		return ;
	if (!ft_builtins(token))
	{
		pid = fork();
		if (pid == 0)
			do_child_stuff(token);
		else
		{
			waitpid(pid, NULL, 0);
			if (token->token_no > 0)
				wait_pids(token);
		}
		continue_exec(token);
	}
}

void	exec_and_stuff2(t_token *token)
{
	t_token	*head;

	head = token;
	if (!ft_builtins(head))
	{
		if (head->token_no > 0)
			wait_pids(head);
		do_child_stuff(head);
	}
	if (head->next && head->next->type == REDIR_OUT)
		exec_and_stuff2(head->next);
	if (head->next && head->next->next && (head->type == REDIR_IN
			|| head->type == REDIR_DBL))
	{
		exec_and_stuff2(head->next->next);
	}
}
