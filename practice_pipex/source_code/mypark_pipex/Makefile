NAME := pipex
TEST := pipex_test
SRCS :=	pipex.c\
		error/error.c\
		pipe/alloc_pipes.c\
		pipe/close_pipes.c\
		pipe/free_pipes.c\
		proc/proc_append_file.c\
		proc/proc_exe_cmd.c\
		proc/proc_heredoc.c\
		proc/proc_parent.c\
		proc/proc_read_file.c\
		proc/proc_write_file.c\
		proc/set_proc_child.c\
		proc/wait_child.c\
		safe/safe_alloc.c\
		safe/safe_close.c\
		safe/safe_dup2.c\
		safe/safe_open.c\
		safe/safe_pipe.c\
		safe/safe_write.c\
		safe/safe_read.c\
		safe/safe_execve.c\
		utils/ft_putstr_fd.c\
		utils/ft_split.c\
		utils/ft_strjoin.c\
		utils/ft_strlcpy.c\
		utils/ft_strlen.c\
		utils/ft_strncmp.c\
		utils/ft_strappend.c\
		utils/free_words.c\
		utils/parse_env.c\
		utils/is_same.c
INCS :=	include/error.h\
		include/pipe.h\
		include/pipex.h\
		include/proc.h\
		include/safe.h\
		include/utils.h
SRCS_TEST :=	$(SRCS)
INCS_TEST :=	$(INCS)\
				include/test.h
INCDIR := include
OBJS := $(SRCS:.c=.o)
OBJDIR := obj
OBJS_TEST := $(SRCS_TEST:.c=.o)
VPATH := $(shell ls -R)
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

test: $(TEST)

$(NAME): $(OBJDIR) $(addprefix $(OBJDIR)/, $(notdir $(OBJS)))
	$(CC) $(OBJDIR)/*.o -o $@ $(CFLAGS)

$(TEST): $(OBJDIR) $(addprefix $(OBJDIR)/, $(notdir $(OBJS_TEST)))
	$(CC) $(OBJDIR)/*.o -o $@ $(CFLAGS)

$(OBJDIR):
	mkdir $@

$(OBJDIR)/%.o: %.c
	$(CC) -c -o $@ $^ -I$(INCDIR) $(CFLAGS)

fclean: clean
	rm -f $(NAME) $(TEST)

clean:
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all re fclean clean test
