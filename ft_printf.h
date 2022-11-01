/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 14:26:33 by tcensier      #+#    #+#                 */
/*   Updated: 2022/10/28 17:21:11 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>


int		ft_printf(const char *, ...);

// type_handler.c
int		handle_char(char c);
int		handle_str(char *str);
int		handle_int(int n);
int		handle_hex(void *ptr, char c);
int 	handle_percent();

//num_utils.c
char	*hex_converter(unsigned long n, char *set);

#endif
