/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:37:02 by siroulea          #+#    #+#             */
/*   Updated: 2025/05/04 09:47:41 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	update_env_part2(t_mini *mini, char *part, char *_new)
{
	int			len;
	t_environ	*head;

	head = mini->env_test;
	len = ft_strlen(mini->env_test->env_var);
	while (mini->env_test && mini->env_test->env_var
		&& ft_strncmp(mini->env_test->env_var, part, len))
	{
		len = ft_strlen(mini->env_test->env_var);
		mini->env_test = mini->env_test->next;
	}
	if (mini->env_test && mini->env_test->env_val != NULL)
	{
		mini->env_test->env_val = ft_strdup(_new);
	}
	mini->env_test = head;
	return (1);
}

int	update_env_part3(t_mini *mini, char *part, char *_new)
{
	int			len;
	t_environ	*head;

	head = mini->env_test;
	len = ft_strlen(mini->env_test->env_var);
	while (mini->env_test && mini->env_test->env_var
		&& ft_strncmp(mini->env_test->env_var, part, len))
	{
		len = ft_strlen(mini->env_test->env_var);
		mini->env_test = mini->env_test->next;
	}
	if (mini->env_test && mini->env_test->env_val != NULL)
	{
		free(mini->env_test->env_val);
		mini->env_test->env_val = ft_strdup(_new);
	}
	mini->env_test = head;
	return (1);
}

char	*check_part(char *part)
{
	char	*good_part;
	int		i;

	i = 0;
	if (!part || !part[0])
		return (0);
	good_part = malloc(ft_strlen(part) + 1);
	if (!good_part)
		return (NULL);
	i = 0;
	while (part[i] && part[i] != '$' && part[i] != 34 && part[i] != 39)
	{
		good_part[i] = part[i];
		i++;
	}
	good_part[i] = 0;
	return (good_part);
}

char	*get_env_part(t_mini *mini, char *part)
{
	t_environ	*head;
	int			part_len;

	if (!part || !part[0])
		return (NULL);
	head = mini->env_test;
	while (head != NULL)
	{
		part_len = ft_strlen(mini->env_test->env_var);
		if (!ft_strncmp(head->env_var, part, part_len))
			return (head->env_val);
		head = head->next;
	}
	return ("");
}
