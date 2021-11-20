# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkocob <dkocob@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/25 13:57:19 by dkocob        #+#    #+#                  #
#    Updated: 2021/11/20 20:24:00 by dkocob        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS			= fdf.c
NAME			= fdf
VPATH			= ./includes:./obj:./src:
OBJS			= $(SRCS:.c=.o)
CFLAGS			= -Lmlx -lmlx -framework OpenGL -framework AppKit

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

run:			$(NAME)
				./$(NAME)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus run
