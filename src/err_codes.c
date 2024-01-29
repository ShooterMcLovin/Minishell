/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_codes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:13:38 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/29 09:50:35 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*check_cmd2(t_token *token)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;

	i = -1;
	allpath = ft_split(get_env_part(token->mini, "PATH"), ':');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, token->cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free(exec);
			releaser(allpath);
			g_errno = 0;
			return (0);
		}
		else
			free(exec);
	}
	path_part = ft_strjoin(allpath[i - 1], "/");
	releaser(allpath);
	return (path_part);
}

int	check_cmd(t_token *token)
{
	char	*path_part;
	char	*exec;

	path_part = check_cmd2(token);
	if (path_part == 0)
		return (0);
	exec = ft_strjoin(path_part, token->cmd[0]);
	if (access(exec, F_OK | X_OK) != 0)
		g_errno = 127;
	free(exec);
	free(path_part);
	return (g_errno);
}

int	update_error(t_mini *mini)
{
	t_token	*token;

	token = mini->tokens;
	if (get_env_part(mini, "PATH") == NULL)
	{
		g_errno = 127;
		return (127);
	}
	while (token)
	{
		if (token->token_no == 0 || g_errno == 0)
			set_error(token);
		token = token->next;
	}
	return (g_errno);
}

int	set_error(t_token *token)
{
	check_cmd(token);
	check_file_exists(token);
	return (g_errno);
}
