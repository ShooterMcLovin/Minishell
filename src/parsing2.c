/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:42:45 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/24 12:29:04 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	pipe_check(char **cmds)
{
	int	cmd_no;
	int	trig;

	cmd_no = 0;
	trig = 0;
	if (cmds == NULL)
		return (0);
	while (cmds[cmd_no] && trig <= 1)
	{
		if (!ft_strncmp(cmds[cmd_no], "|", 2))
			trig++;
		else
			trig = 0;
		cmd_no++;
	}
	if (trig > 1)
		return (0);
	else
		return (1);
}

int	redir_check(char **cmds)
{
	int	i;
	int	j;
	int	trig;

	i = -1;
	j = -1;
	trig = 0;
	while (cmds[++i])
	{
		j = -1;
		while (cmds[i][++j])
		{
			if (cmds[i][j] == '>')
				trig++;
			else if (trig > 2)
				return (0);
			else
				trig = 0;
		}
	}
	if (trig > 2)
		return (0);
	else
		return (1);
}

int	redir_check2(char **cmds)
{
	int	i;
	int	j;
	int	trig;

	i = -1;
	j = -1;
	trig = 0;
	while (cmds[++i])
	{
		j = -1;
		while (cmds[i][++j])
		{
			if (cmds[i][j] == '<')
				trig++;
			else if (trig > 2)
				return (0);
			else
				trig = 0;
		}
	}
	if (trig > 2)
		return (0);
	else
		return (1);
}

int	redir_check3(char **cmds)
{
	int	i;

	i = 0;
	if (cmds == NULL)
		return (0);
	while (cmds[i])
	{
		if (is_sep(cmds[i]) && &cmds[i + 1] && is_sep(cmds[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(t_mini *mini)
{
	int	x;

	x = 0;
	if (pipe_check(mini->new_cmds) == 1 && redir_check(mini->new_cmds) == 1
		&& redir_check2(mini->new_cmds) == 1
		&& redir_check3(mini->new_cmds) == 1)
	{
		while (mini->new_cmds[x])
		{
			if ((is_sep(mini->new_cmds[x]) && (!mini->new_cmds[x + 1]
						|| !mini->new_cmds[x + 1][0]))
				|| (is_sep2(mini->new_cmds[x]) && mini->new_cmds[x + 1]
					&& (is_sep2(mini->new_cmds[x + 1]))))
			{
				syntax_error();
				return (0);
			}
			x++;
		}
		return (1);
	}
	else
		syntax_error();
	return (0);
}
