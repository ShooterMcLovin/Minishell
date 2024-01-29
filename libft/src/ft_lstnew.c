/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 07:18:22 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/10 18:53:18 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

/*#include <stdio.h>
int	main(void)
{
	char name_1[] = "Boris";
	size_t number = 42;

	t_list *elem_1;

	elem_1 = ft_lstnew((void *)name_1);
	printf("%s ", (char *)elem_1->content);

	elem_1 = ft_lstnew((void *)number);
	printf("%d", (int)elem_1->content);
}*/
