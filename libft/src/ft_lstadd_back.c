/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:36:23 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/10 18:52:59 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *neo)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = neo;
	else
	{
		temp = ft_lstlast(*(lst));
		temp->next = neo;
	}
}
