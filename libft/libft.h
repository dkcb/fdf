/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 15:29:12 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/27 18:37:49 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

void		ft_putstring(char *s);
void		ft_putstring_fd(char *s, int fd);
int			ft_isdigit(char c);
long		val(char *s);

#endif
