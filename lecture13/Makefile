CC=       	gcc
CFLAGS= 	-Wall -g -std=gnu99
LDFLAGS=	
C_SOURCE=       $(wildcard *.c)
PROGRAMS=       $(C_SOURCE:.c=)

all:    $(PROGRAMS)

%:      %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean
