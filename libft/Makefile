# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 18:08:18 by jayoon            #+#    #+#              #
#    Updated: 2021/11/23 22:28:11 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				  =	libft.a

SRCS				=	ft_bzero.c \
					  ft_memset.c \
					  ft_tolower.c \
					  ft_toupper.c \
					  ft_isalnum.c \
					  ft_isalpha.c \
					  ft_isascii.c \
					  ft_isdigit.c \
					  ft_isprint.c \
					  ft_strchr.c \
					  ft_strrchr.c \
					  ft_strncmp.c \
					  ft_strlen.c \
					  ft_strlcpy.c \
					  ft_strlcat.c

OBJS					= $(SRCS:.c=.o)

FLAGS					= -Wall -Wextra -Werror

all	:	$(NAME)

%.o	: %.c
	gcc $(FLAGS) -I libft.h -c -o $@ $< 

$(NAME)		:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	:
		rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

bonus	:	$(NAME)
		ar rc $(NAME) $(BNS_OBJS)

.PHONY	:	all clean fclean re bonus
