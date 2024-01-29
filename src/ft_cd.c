/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:06:43 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/22 22:42:43 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	display_error(char *cmd)
{
	ft_putstr_fd("Minishell: cd: ", 2);
	ft_putstr_fd(cmd, 2);
	if (access(cmd, F_OK | X_OK) == 0)
		ft_putendl_fd(": Not a directory", 2);
	else
		ft_putendl_fd(": No such file or directory", 2);
}

int	ft_cd(t_mini *mini, t_token *token)
{
	int		x;
	char	dir[100];

	x = 1;
	getcwd(dir, 100);
	if (!token->cmd[1] || !token->cmd[1][0])
	{
		x = chdir(get_env_part(mini, "HOME"));
		update_env_part3(mini, "OLDPWD", dir);
		getcwd(dir, 100);
		update_env_part3(token->mini, "PWD", dir);
	}
	else
	{
		x = chdir(token->cmd[1]);
		update_env_part3(mini, "OLDPWD", dir);
		if (x != 0)
			display_error(token->cmd[1]);
		getcwd(dir, 100);
		update_env_part3(token->mini, "PWD", dir);
	}
	return (x);
}
