/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digits_ft.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/21 20:46:31 by dkocob        #+#    #+#                 */
/*   Updated: 2021/12/16 22:12:32 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	val(char *s)
{
	int		i;
	int		pwr;
	int		res;
	int		neg;

	neg = 1;
	i = 0;
	res = 0;
	pwr = 1;
	while (s[i] && s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		i++;
	}
	i--;
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res + (s[i] - '0') * pwr;
		pwr = pwr * 10;
		i--;
	}
	return (res * neg);
}
