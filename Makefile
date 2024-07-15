# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artemkliuiev <artemkliuiev@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 23:02:02 by artemkliuie       #+#    #+#              #
#    Updated: 2024/07/15 23:36:16 by artemkliuie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_print.c ft_hex.c
LIBFTDIR = libft/
LIBFTOBJ = libft.a
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: libft_make $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFTDIR)$(LIBFTOBJ) $(NAME)
	ar rcs $(NAME) $(OBJS)

libft_make:
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && $(MAKE) clean

re: fclean $(NAME)

PHONY: all clean fclean re