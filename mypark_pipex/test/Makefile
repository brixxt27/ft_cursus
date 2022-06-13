TESTS := test_parse_envp\
		 test_safe_alloc\
		 test_safe_close\
		 test_safe_dup2\
		 test_safe_open\
		 test_safe_write\
		 test_safe_read\
		 test_safe_execve\
		 test_alloc_pipes\
		 test_free_pipes
VPATH := $(shell ls -R ..)
SRCS :=	error.c\
		alloc_pipes.c\
		close_pipes.c\
		free_pipes.c\
		proc_append_file.c\
		proc_exe_cmd.c\
		proc_heredoc.c\
		proc_parent.c\
		proc_read_file.c\
		proc_write_file.c\
		set_proc_child.c\
		wait_child.c\
		safe_alloc.c\
		safe_close.c\
		safe_dup2.c\
		safe_open.c\
		safe_pipe.c\
		safe_read.c\
		safe_write.c\
		safe_execve.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strjoin.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strappend.c\
		free_words.c\
		parse_env.c\
		is_same.c
INCDIR := ../include
OBJS := $(SRCS:.c=.o)
OBJDIR := obj

all : $(OBJDIR) $(TESTS)

$(OBJDIR):
	mkdir $@

test_%: $(OBJDIR)/test_%.o $(addprefix $(OBJDIR)/, $(OBJS))
	$(CC) -o $@ $^

$(OBJDIR)/%.o: %.c
	$(CC) -c $< -o $@ -I$(INCDIR)

fclean: clean
	rm -f $(TESTS)

clean:
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: fclean clean re all
