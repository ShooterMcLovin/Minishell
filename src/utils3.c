/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:10:43 by siroulea          #+#    #+#             */
/*   Updated: 2024/01/23 14:11:17 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_char_sep(int c)
{
	if ((c == '|' || c == '>' || c == '<'))
		return (1);
	return (0);
}

int	has_pipe(t_mini *mini)
{
	t_token	*head;

	head = mini->tokens;
	while (head->next != NULL)
	{
		if (head->type == PIPE)
			return (1);
		head = head->next;
	}
	return (0);
}

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
