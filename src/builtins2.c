/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:22:48 by siroulea          #+#    #+#             */
/*   Updated: 2024/01/23 13:19:48 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	has_equal_sign(char **var)
{
	int	var_wrd;
	int	var_char;

	var_wrd = 0;
	var_char = 0;
	if (!var)
		return (0);
	if (!(var[0][0] == 0) && !ft_isalpha(var[0][0]))
		return (0);
	while (var[var_wrd])
	{
		var_char = 0;
		while (var[var_wrd][var_char])
		{
			if (var[var_wrd][var_char] == '=')
				return (1);
			var_char++;
		}
		var_wrd++;
	}
	return (0);
}

t_environ	*new_env(char *var)
{
	t_mini		*mini;
	t_environ	*new_env;

	mini = get_data();
	new_env = init_item(var);
	mini->env_len++;
	new_env->next = NULL;
	return (new_env);
}

int	ft_export(t_mini *mini, char **var)
{
	if (!var || !var[0] || !var[0][0])
		return (export_no_input(mini));
	if (!check_export(var))
		return (0);
	init_export(mini, var);
	do_export(mini, var);
	return (0);
}

int	is_builtin(t_token *token)
{
	if (!ft_strncmp(token->cmd[0], "pwd", 3))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "PWD", 3))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "cd", 2))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "unset", 5))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "export", 6) && !token->cmd[1])
		return (1);
	else if (!ft_strncmp(token->cmd[0], "export", 6))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "env", 3))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "echo", 5))
		return (1);
	else
		return (0);
}

int	ft_builtins(t_token *token)
{
	t_mini	*mini;

	mini = get_data();
	if (!ft_strncmp(token->cmd[0], "cd", 2))
		ft_cd(mini, token);
	else if (!ft_strncmp(token->cmd[0], "unset", 5))
		ft_unset(token);
	else if (!ft_strncmp(token->cmd[0], "export", 6) && !token->cmd[1])
		ft_export(mini, NULL);
	else if (!ft_strncmp(token->cmd[0], "export", 6))
		ft_export(mini, &token->cmd[1]);
	else if (!ft_strncmp(token->cmd[0], "env", 3))
		ft_env(token);
	else
		return (0);
	return (1);
}
