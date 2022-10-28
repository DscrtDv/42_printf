/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:16:31 by tcensier      #+#    #+#                 */
/*   Updated: 2022/10/28 17:21:49 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "printf.h"

void	ft_putstr(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write(1, str, len);
}
