# compiler flags
CC=cc
CCFLAGS=-g -std=c99 -Wall -Werror
LDFLAGS=-pthread
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=HelloWorld

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

# compile all .c files into .o files
# % mathces all (like * in a command)
# $< is the source file (.c file)
%.o: %.c %.h
	$(CC) -c $(CCFLAGS) $<

%.o: %.c
	$(CC) -c $(CCFLAGS) $<

clean:
	rm -f *.o $(TARGET)
