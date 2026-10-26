CC=       	gcc
CFLAGS= 	-Wall -g -std=gnu99
LDFLAGS=
LIBRARY=        libmalloc0.so libmalloc1.so

all:    $(LIBRARY)

libmalloc%.so:     malloc%.c
	$(CC) -shared -fPIC $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(LIBRARY)

.PHONY: all clean
