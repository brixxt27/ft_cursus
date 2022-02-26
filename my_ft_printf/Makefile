# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:02:51 by jayoon            #+#    #+#              #
#    Updated: 2022/02/27 00:31:21 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT_PATH	=	./libft
LIBFT		=	./libft/libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar
ARFLAGS	=	rcs

SRCS		=	./src/ft_case_c.c \
				./src/ft_case_upper_x.c \
				./src/ft_case_c.c \
				./src/ft_case_d_and_i.c \
				./src/ft_case_p.c \
				./src/ft_case_percent.c \
				./src/ft_case_s.c \
				./src/ft_case_u.c \
				./src/ft_case_lower_x.c \
				./src/ft_printf.c \
				./src/ft_printf_util.c \
				./src/ft_printf_util.c \
				./src/ft_printf.c

OBJS		=	$(SRCS:%.c=%.o)

$(NAME):	$(OBJS)
	$(MAKE) bonus -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all:	$(LIBFT) $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)
	
fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re libft
