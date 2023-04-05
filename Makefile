CXXFLAGS = -O3 -g -Wall -Wpedantic -Wextra -Wshadow -Wunused -Wunused-parameter  -Wuninitialized -Werror -Wmisleading-indentation -Wconversion  -std=c++17

OBJS = test

test: Stack.h

all: ${OBJS}

.PHONY: clean all
clean:
	rm -f *.o ${OBJS} *~