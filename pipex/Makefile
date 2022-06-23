# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 17:04:13 by jayoon            #+#    #+#              #
#    Updated: 2022/06/23 13:53:56 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT_DIR = libft
SRCS_DIR = srcs
INC_DIR = include
SRCS =			$(addprefix $(SRCS_DIR)/,\
				allocate_memory.c\
				check_error.c\
				control_fds.c\
				do_it_child.c\
				do_it_parent.c\
				main.c\
				make_pipex.c\
				parse.c\
				process.c\
				utils_pipex.c)
SRCS_LIBFT =	$(addprefix $(LIBFT_DIR)/,\
				ft_add_slash_strjoin.c\
				ft_free_malloc.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_strjoin.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_strncmp.c)
# B_SRCS = $(addprefix $(SRCS_DIR)/,\
# 		main_bonus.c\
# 		process_bonus.c\
# 		init_info_bonus.c\
# 		here_doc_bonus.c)\
# 		$(addprefix $(GNL_DIR)/,$(GNL_SRCS))
OBJS = $(SRCS:.c=.o)
OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)
# B_OBJS = $(B_SRCS:.c=.o)

ifdef VAR
	OBJECTS = $(B_OBJS) $(OBJS_LIBFT)
else
	OBJECTS = $(OBJS) $(OBJS_LIBFT)
endif

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(DFLAGS) -I $(INC_DIR) -c $^ -o $@

$(NAME): $(OBJECTS) $(LFT_A)
	$(CC) $(CFLAGS) $(DFLAGS) -I $(INC_DIR) -o $@ $^


clean:
	rm -f $(OBJS) $(B_OBJS) $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME)

re:
	make clean
	make all

# bonus:
# 	@make VAR=1 all

.PHONY : all clean fclean re bonus
