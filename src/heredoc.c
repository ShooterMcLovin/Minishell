/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:55:59 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/25 16:56:20 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**build_heredoc_cmd2(t_token *token)
{
	char	**cmd;
	int		i;
	int		cmd_no;
	t_mini	*mini;

	mini = get_data();
	i = 0;
	cmd_no = 0;
	token = mini->tokens;
	cmd = malloc(sizeof(char *) * 15);
	if (!ft_strncmp(token->cmd[i], "ls", 3) || !ft_strncmp(token->cmd[i],
			"echo", 5))
		cmd_no++;
	while (token->cmd[cmd_no])
		cmd[i++] = (token->cmd[cmd_no++]);
	cmd[i] = (".temp");
	cmd[i + 1] = NULL;
	return (cmd);
}

int	do_heredoc(t_token *token)
{
	char	**here_doc_cmd;
	char	*path;
	char	**env;
	t_mini	*mini;

	mini = get_data();
	if (token->token_no == 0 || (token->next && token->next->type != HEREDOC_T))
	{
		env = env_l_to_dbl_arr(token->env);
		path = get_path(mini->tokens);
		here_doc_cmd = build_heredoc_cmd2(token);
		if (token->next && (token->next->type == REDIR_IN
				|| token->next->type == REDIR_DBL))
			redir(mini->tokens);
		if ((path == NULL || execve(path, here_doc_cmd, env) < 0))
		{
			close(token->fd_hd);
		}
		if (here_doc_cmd != NULL)
			free(here_doc_cmd);
		releaser(env);
		free(path);
	}
	return (0);
}

void	get_heredoc_input(char *heredoc_input, char *delimiter, t_token *token)
{
	while (ft_strncmp(heredoc_input, delimiter, ft_strlen(delimiter) + 1))
	{
		heredoc_input = get_hd_prompt(HEREDOC);
		if (ft_strncmp(heredoc_input, delimiter, ft_strlen(delimiter) + 1))
			ft_putendl_fd(heredoc_input, token->fd_hd);
	}
}

int	heredoc(t_token *token)
{
	char	*delimiter;
	char	*heredoc_input;

	if (!token->next->cmd[0])
		return (syntax_error());
	heredoc_input = "temp";
	delimiter = (token->next->cmd[0]);
	token->fd_hd = open(".temp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	init_signals(HD_SIG);
	get_heredoc_input(heredoc_input, delimiter, token);
	close(token->fd_hd);
	if (token->next && token->next->type == PIPE)
		do_pipe3(token->next);
	else if (token->next && token->next->type == HEREDOC_T)
	{
		heredoc(token->next);
		return (1);
	}
	else
		do_heredoc(token);
	return (1);
}
