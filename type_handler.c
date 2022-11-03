/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_handler.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 10:37:36 by tcensier      #+#    #+#                 */
/*   Updated: 2022/11/03 10:51:23 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	handle_char(char c)
{
	ft_putchar(c);
	return (1);
}

int	handle_str(char *str)
{
	if (!str)
		return (handle_str("(null)"));
	ft_putstr(str);
	return ((int) ft_strlen(str));
}

int	handle_int(int n)
{
	char	*str_itoa;
	int		len;

	str_itoa = ft_itoa(n);
	ft_putstr(str_itoa);
	len = (int) ft_strlen(str_itoa);
	free(str_itoa);
	return (len);
}

int	handle_unsigned(void *ptr, char c)
{
	long long		n;
	char			*result;
	int				len;

	len = 0;
	n = (long long) ptr;
	if (c == 'p')
	{
		if (!n)
			return (handle_str("0x0"));
		len += handle_str("0x");
		result = unsigned_itoabase(n, "0123456789abcdef", 16);
	}
	if (!n)
		return (handle_char('0'));
	else if (c == 'u')
		result = unsigned_itoabase((unsigned int)n, "0123456789", 10);
	else if (c == 'x')
		result = unsigned_itoabase((unsigned int)n, "0123456789abcdef", 16);
	else if (c == 'X')
		result = unsigned_itoabase((unsigned int)n, "0123456789ABCDEF", 16);
	len += handle_str(result);
	if (result)
		free(result);
	return (len);
}

int	handle_percent(void)
{
	ft_putchar('%');
	return (1);
}
