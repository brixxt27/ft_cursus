NAME = a.out

ifndef DEBUG
CFLAGS = -Wall -Wextra -Werror
else
CFLAGS = -g3 -fsanitize=address
endif

SRCS = mini_serv.c

all:
	gcc ${CFLAGS} ${SRCS}
debug:
	make DEBUG=1
fclean:
	rm -rf ${NAME} ${NAME}.dSYM
re: fclean
	make all
.PHONY: all debug fclean re