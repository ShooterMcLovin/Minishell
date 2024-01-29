/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:18:36 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/25 16:51:04 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	syntax_error(void)
{
	t_mini	*mini;

	mini = get_data();
	ft_putstr_fd("Minishell: ", 2);
	ft_putendl_fd("syntax error", 2);
	releaser(mini->cmds);
	releaser(mini->new_cmds);
	g_errno = 258;
	return (258);
}

int	invalid_path(char *error)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(" : No such file or directory", 2);
	return (0);
}

int	command_not_found(char *error)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(" : command not found", 2);
	g_errno = 127;
	return (127);
}

int	is_a_directory(char *error)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(" : is a Directory", 2);
	g_errno = 126;
	return (126);
}

int	launch_fail(char **env)
{
	if (!env[0])
		ft_putendl_fd("Unable to launch Minishell", 2);
	return (0);
}
