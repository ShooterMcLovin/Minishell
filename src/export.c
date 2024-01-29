/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 08:01:37 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/23 14:04:01 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_export	*ft_exp(t_mini *mini, char *var)
{
	t_export	*export;

	(void)mini;
	export = malloc(sizeof(t_export));
	if (!export)
		return (NULL);
	export->temp = ft_split(var, '=');
	export->env_var = ft_strdup(export->temp[0]);
	if (var[ft_strlen(export->env_var)])
		export->env_val = ft_strdup(&var[ft_strlen(export->env_var) + 1]);
	else
		export->env_val = ft_strdup(" \0");
	export->next = NULL;
	releaser(export->temp);
	return (export);
}

int	check_export(char **var)
{
	int	x;
	int	ret;

	x = 0;
	ret = 1;
	if (!var || !var[0])
		return (0);
	while (var[x])
	{
		if ((var[x][0] == 0) || !ft_isalpha(var[x][0]))
		{
			ft_putstr_fd("Minishell: export: ", 2);
			ft_putstr_fd(var[x], 2);
			ft_putstr_fd(": not a valid identifier\n", 2);
			ret = 0;
		}
		x++;
	}
	return (ret);
}

void	init_export(t_mini *mini, char **var)
{
	t_export	*export_head;
	int			x;

	x = 0;
	mini->_export = ft_exp(mini, var[x]);
	export_head = mini->_export;
	while (var[++x])
	{
		mini->_export->next = ft_exp(mini, var[x]);
		mini->_export = mini->_export->next;
	}
	mini->_export->next = NULL;
	mini->_export = export_head;
}

int	export_no_input(t_mini *mini)
{
	t_environ	*head;

	head = mini->env_test;
	while (head)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(head->env_var, 1);
		ft_putstr_fd("=", 1);
		ft_putchar_fd(34, 1);
		ft_putstr_fd(head->env_val, 1);
		ft_putchar_fd(34, 1);
		ft_putstr_fd("\n", 1);
		head = head->next;
	}
	return (0);
}

void	do_export(t_mini *mini, char **var)
{
	int			x;
	char		*temp;
	t_environ	*head_new;
	t_export	*head;

	x = 0;
	head = mini->_export;
	while (head != NULL)
	{
		temp = get_env_part(mini, head->env_var);
		if (temp[0] != '\0')
		{
			update_env_part3(mini, head->env_var, head->env_val);
			x++;
		}
		else
		{
			head_new = new_env(var[x++]);
			ft_envadd_back(&mini->env_test, head_new);
		}
		head = head->next;
	}
	free_export(mini->_export);
}
