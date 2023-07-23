NAME = a.out

CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS = -g3 -fsanitize=address
endif

ifdef TEST
	CFLAGS = 
endif

SRCS = mini_serv.c

all:
	gcc ${CFLAGS} ${SRCS}
debug:
	make DEBUG=1
test:
	make TEST=1
fclean:
	rm -rf ${NAME} ${NAME}.dSYM
re: fclean
	make all
.PHONY: all debug test fclean re