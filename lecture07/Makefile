SOURCE=		$(wildcard *.c)
TARGET=		$(SOURCE:.c=)

all:		$(TARGET)

%:		%.c
	gcc -Wall -std=gnu99 -g -o $@ $<

clean:
	rm -f $(TARGET)
