CC=		gcc
TARGET=		pc
CFLAGS=		-Wall -g -std=gnu99 -pthread 

all:		$(TARGET)

pc:		queue.c pc.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
