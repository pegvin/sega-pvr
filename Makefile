CC=gcc

all:
	$(CC) --std=c99 -Isrc/ -o segapvr src/main.c src/utils.c

.PHONY: clean

clean:
	$(RM) segapvr

