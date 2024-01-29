/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 08:06:25 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/23 12:34:12 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_env(t_token *token)
{
	t_mini	*mini;

	(void)token;
	mini = get_data();
	print_env(mini->env_test);
	return (1);
}

void	ft_envadd_back(t_environ **env, t_environ *neo)
{
	t_environ	*temp;

	if (*env == NULL)
		*env = neo;
	else
	{
		temp = ft_envlast(*(env));
		temp->next = neo;
	}
}

t_environ	*ft_envlast(t_environ *env)
{
	t_environ	*head;

	head = env;
	while (head)
	{
		if (head->next == NULL)
			return (head);
		head = head->next;
	}
	return (head);
}

int	env_size(t_environ *env)
{
	t_environ	*head;
	int			no_of_env_items;

	if (!env)
		return (0);
	no_of_env_items = 0;
	head = env;
	while (head)
	{
		no_of_env_items++;
		head = head->next;
	}
	return (no_of_env_items);
}

char	**env_l_to_dbl_arr(t_environ *env)
{
	t_environ	*head;
	int			no_of_env_items;
	int			env_item_no;
	char		**temp_env;
	char		*temp;

	env_item_no = 0;
	head = env;
	if (env == NULL || env->env_var == NULL)
		return (NULL);
	no_of_env_items = env_size(env);
	temp_env = malloc(sizeof(char *) * no_of_env_items + 1);
	if (!temp_env)
		return (NULL);
	while (head->next)
	{
		temp = ft_strjoin(head->env_var, "=");
		temp_env[env_item_no] = ft_strjoin(temp, head->env_val);
		env_item_no++;
		temp = ft_free(temp);
		head = head->next;
	}
	temp_env[env_item_no] = NULL;
	return (temp_env);
}
