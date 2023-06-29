NAME = a.out

ifndef DEBUG
	CXXFLAGS = -Wall -Wextra -Werror
else
	CXXFLAGS = -g3
endif

all:
	c++ ${CXXFLAGS} *.cpp
fclean:
	rm -rf a.out a.out.dSYM
re:
	make fclean
	make all
debug:
	make DEBUG=1
.PHONY: all fclean re debug