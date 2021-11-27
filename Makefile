# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkocob <dkocob@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/25 13:57:19 by dkocob        #+#    #+#                  #
#    Updated: 2021/11/27 17:56:34 by dkocob        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

VPATH			= ./includes:./obj:./src:./gnl:./libft/:
SRCS			= main.c \
				fdf.c \
				map.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_digits_ft.c \
				frame.c
NAME			= fdf
OBJS			= $(patsubst %.c,obj/%.o,$(SRCS))
LFLAGS			= -Lmlx -lmlx -framework OpenGL -framework AppKit
CFLAGS			= #-Wall -Wextra #-Werror -g #-fsanitize=address

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(LFLAGS) $(OBJS) -o $(NAME)

obj/%.o:		%.c
				$(CC) -c $(CFLAGS) -o $@ $<

# obj/map.o:		src/map.c
# 				$(CC) -c $(CFLAGS) -o obj/map.o src/map.c

run:			$(NAME)
				./$(NAME)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus run
