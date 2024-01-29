/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 07:01:40 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/25 17:53:50 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*releaser(char **table)
{
	int	i;

	i = 0;
	if (table)
	{
		while (table[i])
		{
			free(table[i]);
			i++;
		}
		free(table);
	}
	return (NULL);
}

int	init_minishell(char **env)
{
	t_mini	*mini;

	mini = get_data();
	mini->env = env;
	mini->cmds = NULL;
	mini->new_cmds = NULL;
	g_errno = 0;
	set_env(mini, env);
	set_shlvl();
	update_env_part3(mini, "OLDPWD", "/");
	return (1);
}

void	run_minishell(t_mini *mini)
{
	t_token	*token;

	token = mini->tokens;
	init_signals(CHILD);
	exec_and_stuff(token);
	free_tokens(mini->tokens);
}

int	parsing_fail(int parsing, t_mini *mini)
{
	if (parsing == -1)
		ft_putendl_fd("exit", 2);
	free_minishell(mini);
	return (g_errno);
}

int	main(int ac, char **av, char **env)
{
	static t_mini	*mini;
	int				parsing;

	(void)av;
	if (ac > 1 || !env[0])
		return (launch_fail(env));
	mini = get_data();
	init_minishell(env);
	while (1)
	{
		init_signals(INTERACTIVE);
		mini->input = get_prompt(PROMPT);
		if (!is_empty(mini->input))
		{
			parsing = ft_parse(mini);
			if (parsing < 0)
				return (parsing_fail(parsing, mini));
			else if (parsing > 0)
				run_minishell(mini);
		}
	}
	return (g_errno);
}
