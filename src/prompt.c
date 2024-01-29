/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:21:40 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/24 10:55:43 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_prompt(char *prt)
{
	char	*line;
	t_mini	*mini;

	mini = get_data();
	line = readline(prt);
	while (line)
	{
		if (!is_empty(line))
			add_history(line);
		return (line);
	}
	ft_putendl_fd("exit", 2);
	if (mini)
	{
		free_env(mini->env_test);
		free(mini);
	}
	exit(g_errno);
	return (NULL);
}

char	*get_hd_prompt(char *prt)
{
	char	*line;
	t_mini	*mini;

	mini = get_data();
	line = readline(prt);
	while (line)
	{
		if (!is_empty(line))
			add_history(line);
		return (line);
	}
	g_errno = 1;
	if (mini->tokens->fd_hd)
		close(mini->tokens->fd_hd);
	free_minishell(mini);
	exit(g_errno);
	return (NULL);
}
