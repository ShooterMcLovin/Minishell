/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:20:47 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/10 18:54:16 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;
	size_t	dst_len;
	size_t	src_len;
	char	*str;

	if (!src || !dst)
		return (0);
	str = (char *)src;
	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(str);
	ret = 0;
	if (dstsize > dst_len)
		ret = src_len + dst_len;
	else
		ret = src_len + dstsize;
	while (str[i] && (dst_len + 1) < dstsize)
	{
		dst[dst_len] = str[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = 0;
	return (ret);
}
