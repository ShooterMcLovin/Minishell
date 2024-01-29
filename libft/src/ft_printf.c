/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:58:36 by alpicard          #+#    #+#             */
/*   Updated: 2022/12/12 16:42:17 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_args(va_list args, const char type)
{
	int	printed_char;

	printed_char = 0;
	if (type == 'c')
		printed_char += ft_printchar(va_arg(args, int));
	else if (type == 's')
		printed_char += ft_printstr(va_arg(args, char *));
	else if (type == 'p')
		printed_char += ft_printptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		printed_char += ft_printnbr_base(va_arg(args, int), BASE_LOW, 10);
	else if (type == 'u')
		printed_char += ft_printnbr(va_arg(args, unsigned int));
	else if (type == '%')
		printed_char += ft_printchar('%');
	else if (type == 'X')
		printed_char += ft_printnbr_base(va_arg(args, unsigned int), BASE_UP,
				16);
	else if (type == 'x')
		printed_char += ft_printnbr_base(va_arg(args, unsigned int), BASE_LOW,
				16);
	return (printed_char);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX", str[i + 1]) || str[i + 1] == 37)
				len += ft_args(args, str[i + 1]);
			else
				len += ft_printchar(str[i + 1]);
			i++;
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
