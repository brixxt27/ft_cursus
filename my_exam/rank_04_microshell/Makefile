TARGET = microshell
SRCS =	main.c

ifdef ERR
else
	CFLAGS = -Wall -Wextra -Werror
endif

ifdef DEBUG
	CFLAGS += -g
endif

all:
	gcc ${CFLAGS} $(SRCS) -o ${TARGET}
err:
	make ERR=1
debug:
	make DEBUG=1
re:
	make fclean
	make
fclean:
	rm -rf ${TARGET} ${TARGET}.dSYM
.PHONY: debug fclean err
