TARGET = microshell
SRCS =	main.c

ifdef DEBUG
	CFLAGS += -g
endif
ifdef ERR
else
	CFLAGS = -Wall -Wextra -Werror
endif

NAME :
	gcc ${CFLAGS} $(SRCS) -o ${TARGET}

err:
	make ERR=1
debug:
	make DEBUG=1
fclean:
	rm -rf ${TARGET} ${microshell}.dSYM
.PHONY: debug fclean err
