SOURCES = $(shell ls *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

LEXERS = $(shell ls *.l)
LEXERS_GEN = $(LEXERS:.l=-ll.o)
LEXERS_FLAGS = -Wall -std=c++11
PARSERS = $(shell ls *.y)
PARSERS_GEN = $(PARSERS:.y=-yy.o)
PARSERS_FLAGS -Wall -std=c++11

BINARY = compiler

CC = gcc
CFLAGS = -Wall -Werror -std=c++11
LD = g++
LDFLAGS =

all : $(BINARY) $(LEXERS_GEN) $(PARSERS_GEN) $(SOURCES)

run : all
	./$(BINARY)

clean :
	rm *.o *-yy.cpp *-yy.hpp *-ll.cpp *-ll.hpp $(BINARY)

$(BINARY) : $(OBJECTS)
	$(LD) $(LDFLAGS) -o $(BINARY) $(OBJECTS)

%-yy.cpp : %.y
	bison -d -o $@ $<

%-ll.cpp : %.l $(PARSERS_GEN)
	flex -o $@ $<

%-yy.o : %-yy.cpp
	$(CC) $(PARSERS_FLAGS) -c -o $@ $<

%-ll.o : %-ll.cpp $(PARSERS_GEN)
	$(CC) $(LEXERS_FLAGS) -c -o $@ $<

%.o : %.cpp $(LEXERS_GEN) $(PARSERS_GEN)
	$(CC) $(CFLAGS) -c -o $@ $<

