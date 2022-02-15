# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:02:51 by jayoon            #+#    #+#              #
#    Updated: 2022/02/15 16:18:45 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_FATH)/libft.a

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar
ARFLAGS	=	rcs

SRCS		=	./src/

OBJS		=	$(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_PATH)

all:	$(LIBFT) $(NAME)

$(NAME):	$(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)
	
fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
re:	fclean all

.PHONY:	all clean fclean re libft
