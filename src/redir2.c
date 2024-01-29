/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:45:24 by siroulea          #+#    #+#             */
/*   Updated: 2024/01/25 15:52:02 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	child_redir_to(t_token *token)
{
	t_mini	*mini;

	mini = get_data();
	redir(token);
}

void	redir2(t_token *token)
{
	t_mini	*mini;

	mini = get_data();
	token->fd_in = open(token->next->cmd[0], O_RDWR, O_RDONLY, 0777);
	if (token->fd_in <= 0)
	{
		ft_putstr_fd("No such file dumbass\n", 2);
		free_minishell(mini);
		exit(0);
	}
	else
	{
		dup2(token->fd_in, 0);
		close(token->fd_in);
		if (token->next->next)
			do_pipe2(token);
		else
			exec(token);
	}
}
