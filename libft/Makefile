# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 18:08:18 by jayoon            #+#    #+#              #
#    Updated: 2021/12/02 00:05:34 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c \
	   ft_memset.c \
	   ft_memcmp.c \
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
	   ft_strlcat.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_memcpy.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I

EXE = a.out

##ifdef BONUS
##	OBJS = $(OBJ) $(OBJ_BONUS)
##else
##	OBJS = $(OBJ)
##endif

all : $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS) $(INCLUDE) libft.h -c -o $@ $< 

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS) $(BNS_OBJS)

fclean : clean
	rm -f $(NAME) $(EXE)

re : fclean all

bonus : $(NAME)
	ar rc $(NAME) $(BNS_OBJS)

.PHONY : all clean fclean re bonus
