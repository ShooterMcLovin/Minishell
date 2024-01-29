/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:59:47 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/24 12:28:53 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_mini_no_wrds(void)
{
	t_mini	*mini;
	int		no_words;

	no_words = 0;
	mini = get_data();
	while (mini->cmds[no_words])
		no_words++;
	mini->no_wrds = no_words;
}

char	**parse_mini_cmds(void)
{
	int		cmd_index;
	int		cmd_no;
	char	**new_cmds;
	t_mini	*mini;

	mini = get_data();
	set_mini_no_wrds();
	new_cmds = ft_calloc(mini->no_wrds + 1, sizeof(char *));
	if (!new_cmds)
		return (NULL);
	cmd_no = 0;
	cmd_index = -1;
	while (mini->cmds[++cmd_index])
	{
		if (has_dollar_sign(mini->cmds[cmd_index]) != 0
			|| (mini->cmds[cmd_index][0] == '$' && mini->cmds[cmd_index][1]
				&& mini->cmds[cmd_index][1] != '$'))
			new_cmds[cmd_no] = (dollar_sign(mini->cmds[cmd_index]));
		else
			new_cmds[cmd_no] = ft_strdup(mini->cmds[cmd_index]);
		cmd_no++;
	}
	return (new_cmds);
}

int	ft_parse(t_mini *mini)
{
	if (!check_valid_quotes(mini->input))
	{
		ft_putendl_fd("Invalid Input", 2);
		return (0);
	}
	mini->no_wrds = no_of_words(mini->input, 0, 0, 0) + 1;
	mini->cmds = mini_split(mini->input);
	if (!mini->cmds || mini->cmds == NULL)
		return (0);
	mini->new_cmds = parse_mini_cmds();
	if (!check_input(mini))
		return (0);
	releaser(mini->cmds);
	if (!tokeniser(mini))
		return (0);
	releaser(mini->new_cmds);
	if (!ft_strncmp(mini->tokens->cmd[0], "exit", 5))
		return (ft_exit(mini->tokens->cmd));
	return (1);
}
