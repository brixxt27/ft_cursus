# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 17:04:13 by jayoon            #+#    #+#              #
#    Updated: 2022/06/22 17:40:32 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
# LFT_A = libft/libft.a
LIBFT_DIR = libft
# GNL_DIR = get_next_line
# GNL_SRCS = get_next_line.c\
			get_next_line_utils.c
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
				utils_pipex.c)\
SRCS_LIBFT =	$(addprefix $(LIBFT_DIR)/,\
				ft_add_slash_strjoin.c\
				ft_free_malloc.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_strjoin.c\
				ft_strlcpy.c\
				ft_strlen.c\
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
	OBJECTS = $(OBJS)
endif

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(DFLAGS) -I $(INC_DIR) -c $^ -o $@

$(NAME): $(OBJECTS) $(LFT_A)
	$(CC) $(CFLAGS) $(DFLAGS) -I $(INC_DIR) -o $@ $^

# $(LFT_A) :
# 	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(B_OBJS) $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

# bonus:
# 	@make VAR=1 all

.PHONY : all clean fclean re bonus
