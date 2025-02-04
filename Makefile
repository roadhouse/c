CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDBLIBS = -lcurl

all: pointers strings shodan-client

shodan-client: shodan-client.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDBLIBS)

strings: strings.c
	$(CC) $(CFLAGS) -o $@ $^

pointers: pointers.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f pointers strings shodan-client
