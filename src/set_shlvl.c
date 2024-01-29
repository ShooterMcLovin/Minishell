/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:15:35 by siroulea          #+#    #+#             */
/*   Updated: 2024/01/22 22:44:31 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	set_shlvl(void)
{
	char	*cur_shlvl;
	int		sh_lvl;
	char	*shlvl;
	char	*new_shlvl;
	t_mini	*mini;

	mini = get_data();
	shlvl = ft_strdup("SHLVL");
	cur_shlvl = get_env_part(mini, shlvl);
	if (cur_shlvl == NULL)
		return (0);
	sh_lvl = ft_atoi(cur_shlvl);
	sh_lvl++;
	new_shlvl = (ft_itoa(sh_lvl));
	update_env_part3(mini, shlvl, new_shlvl);
	new_shlvl = ft_free(new_shlvl);
	free(shlvl);
	return (1);
}

t_mini	*get_data(void)
{
	static t_mini	*mini;

	if (!mini)
	{
		mini = ft_calloc(1, sizeof(t_mini));
		if (!mini)
			return (NULL);
		return (mini);
	}
	return (mini);
}
