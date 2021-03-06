# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkocob <dkocob@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/25 13:57:19 by dkocob        #+#    #+#                  #
#    Updated: 2022/03/15 17:55:24 by dkocob        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

VPATH			= ./includes:./obj:./src:./gnl:./libft/:
SRCS			= main.c \
				fdf.c \
				map.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_digits_ft.c \
				ft_distance_to_char.c \
				ft_cnt_char.c \
				graphics.c \
				math.c \
				hooks.c
NAME			= fdf
OBJS			= $(patsubst %.c,obj/%.o,$(SRCS))
LFLAGS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -g -fsanitize=address -ofast
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address# 

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(LFLAGS) $(OBJS) -o $(NAME)

obj/%.o:		%.c
				mkdir -p obj
				$(CC) -c $(CFLAGS) -o $@ $<

run:			$(NAME)
				./$(NAME)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus run
