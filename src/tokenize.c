/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:52:40 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/24 12:15:59 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_file_exists(t_token *token)
{
	if (token->cmd && token->cmd[1] && ft_strncmp(token->cmd[0], "echo", 5))
	{
		if (token->cmd[1][0] != '-')
		{
			if (access(token->cmd[1], F_OK | X_OK) == 0)
				g_errno = 0;
			else
				g_errno = 1;
		}
	}
	return (g_errno);
}

void	set_var_tokens(t_mini *mini, t_token *tokens, int x, int wrd_no)
{
	tokens->cmd[wrd_no] = NULL;
	tokens->type = 0;
	tokens->token_no = x;
	mini->no_of_tokens = x;
	tokens->env = mini->env_test;
	tokens->fd_out = 0;
	tokens->fd_in = 0;
	tokens->mini = mini;
	tokens->next = NULL;
	tokens->pid = 0;
}

t_token	*init_tokens(t_mini *mini, int cmd_index, int x)
{
	t_token	*tokens;
	int		wrd_no;

	wrd_no = 0;
	tokens = malloc(sizeof(t_token));
	tokens->cmd = malloc(sizeof(char *) * 100);
	if (mini->new_cmds[cmd_index] && is_sep(mini->new_cmds[cmd_index]))
		tokens->cmd[wrd_no++] = ft_strdup(mini->new_cmds[cmd_index++]);
	while (!is_sep(mini->new_cmds[cmd_index]) && mini->new_cmds[cmd_index])
	{
		if (!has_quotes(mini->new_cmds[cmd_index]))
			tokens->cmd[wrd_no] = ft_strdup(mini->new_cmds[cmd_index]);
		else
			tokens->cmd[wrd_no] = ft_strdup2(mini->new_cmds[cmd_index]);
		wrd_no++;
		cmd_index++;
	}
	set_var_tokens(mini, tokens, x, wrd_no);
	return (tokens);
}
