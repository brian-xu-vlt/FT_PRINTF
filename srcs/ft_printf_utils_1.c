/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 13:59:12 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

t_format	*ft_format_init(void)
{
	t_format	*new_format;

	new_format = (t_format*)malloc(sizeof(t_format) * 1);
	if (new_format == NULL)
		return (NULL);
	ft_memset(new_format->flag, '\0', 6);
	new_format->min_w = -1;
	new_format->pre = -1;
	ft_memset(new_format->spec, '\0', 3);
	new_format->conv = '\0';
	return (new_format);
}

void		ft_fill_spec(t_format *format, char c)
{
	int			i;

	i = 0;
	while (i <= 2)
	{
		if (format->spec[i] == 0)
		{
			format->spec[i] = c;
			return ;
		}
		i++;
	}
}

void		ft_fill_flag(t_format *format, char c)
{
	int			i;

	i = 0;
	while (i <= 4)
	{
		if (format->flag[i] == 0 && ft_char_set(c, format->flag) == 0)
		{
			format->flag[i] = c;
			return ;
		}
		i++;
	}
}

char		*ft_str_set(char *str, char *set)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	while (str[y] != '\0')
	{
		while (set[i] != '\0')
		{
			if (str[y] == set[i])
				return (str + y);
			i++;
		}
		i = 0;
		y++;
	}
	return (0);
}

char		ft_char_set(char c, char *set)
{
	int			i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (c);
		i++;
	}
	return (0);
}
