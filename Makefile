# use CFLAGS argument to make for both c and c++, but enable warnings
override CFLAGS += -Wall
CXXFLAGS = ${CFLAGS}

programs := g89 c99 c++

run :: all
	${programs:%=./%;}

all :: ${programs}

clean ::
	${RM} ${programs}

.PHONY: run all clean

g89: main.c aux.c foo.c
	${LINK.c} -std=gnu89 -DDECL=extern  -o $@ $^

c99: main.c aux.c foo99.c
	${LINK.c} -std=c99 -DDECL=  -o $@ $^

c++: main.c aux.c
	${LINK.cc} -DDECL=  -o $@ $^
