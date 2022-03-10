/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cnt_char.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:41:13 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/10 17:55:58 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	c_cnt(char *s, char c)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (s[i])
	{
		if (s[i] == c)
			i2++;
		i++;
	}
	return (i2);
}
