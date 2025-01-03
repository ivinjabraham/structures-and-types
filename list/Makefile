CC = gcc
CFLAGS = -Wall -g

SRCS = example.c list.c
OBJS = $(SRCS:.c=.o)
TARGET = main

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
