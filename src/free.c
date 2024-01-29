/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:13:03 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/25 15:45:39 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_tokens(t_token *tokens)
{
	t_token	*temp;

	while (tokens != NULL)
	{
		temp = tokens->next;
		releaser(tokens->cmd);
		free(tokens->next_sep);
		if (tokens->fd_out > 0)
			close(tokens->fd_out);
		if (tokens->fd_in > 0)
			close(tokens->fd_in);
		free(tokens);
		tokens = temp;
	}
}

void	free_env(t_environ *env)
{
	t_environ	*temp;

	while (env != NULL)
	{
		temp = env->next;
		if (env->env_var[0])
			free(env->env_var);
		if (env->env_val[0])
			free(env->env_val);
		if (env->temp)
			releaser(env->temp);
		free(env);
		env = temp;
	}
	free(env);
}

void	free_export(t_export *exp)
{
	t_export	*temp;

	while (exp != NULL)
	{
		temp = exp->next;
		if (exp->env_val)
			free(exp->env_val);
		if (exp->env_var)
			free(exp->env_var);
		if (exp)
			free(exp);
		exp = temp;
	}
	if (exp)
		free(exp);
}

int	free_minishell(t_mini *mini)
{
	free_env(mini->env_test);
	if (mini->tokens)
		free_tokens(mini->tokens);
	free(mini->shlvl);
	free(mini);
	return (0);
}

void	free_child(t_mini *mini)
{
	if (mini->tokens)
		free_tokens(mini->tokens);
	free_env(mini->env_test);
	free(mini);
}
