/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 15:29:12 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/10 17:55:20 by dkocob        ########   odam.nl         */
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

size_t		c_cnt(char *s, char c);
size_t		dc(char *s, char c);
void		ft_putstring(char *s);
void		ft_putstring_fd(char *s, int fd);
int			ft_isdigit(char c);
int			ft_isdigit16(char c);
int			val(char *s);
int			val16(char *s);

#endif
