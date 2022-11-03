/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 10:36:36 by tcensier      #+#    #+#                 */
/*   Updated: 2022/11/03 10:37:16 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static size_t	ulong_len(long long n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= (unsigned long)base;
		len++;
	}
	return (len);
}

char	*unsigned_itoabase(long long n, char *set, int base)
{
	size_t	len;
	char	*result;

	len = ulong_len(n, base);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	result[len] = '\0';
	while (n)
	{
		result[len - 1] = set[(unsigned)n % base];
		n /= (unsigned long)base;
		len--;
	}
	return (result);
}
