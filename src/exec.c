/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 07:35:38 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/29 09:49:27 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_path(t_token *token)
{
	t_mini	*mini;
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;

	mini = get_data();
	i = -1;
	if (get_env_part(mini, "PATH") == NULL)
		return (NULL);
	allpath = ft_split(get_env_part(mini, "PATH"), ':');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, token->cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			releaser(allpath);
			return (exec);
		}
		else
			free(exec);
	}
	return (releaser(allpath));
}

void	exec_fail(t_token *token, char *path, char **env)
{
	free_child(token->mini);
	releaser(env);
	free(path);
	exit(g_errno);
}

int	exec(t_token *token)
{
	char	*path;
	char	**env;
	t_mini	*mini;

	mini = get_data();
	env = env_l_to_dbl_arr(mini->env_test);
	path = get_path(token);
	if (is_sep(token->cmd[0]))
		exec_fail(token, path, env);
	if (path == NULL || execve(path, token->cmd, env) < 0)
	{
		command_not_found(token->cmd[0]);
		exec_fail(token, path, env);
	}
	return (0);
}

void	wait_pids(t_token *token)
{
	t_token	*head;
	t_mini	*mini;

	(void)token;
	mini = get_data();
	head = mini->tokens;
	while (head)
	{
		if (head->pid)
		{
			waitpid(head->pid, NULL, 0);
		}
		head = head->next;
	}
}
