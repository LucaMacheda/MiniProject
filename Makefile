CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = main.c Stack/stack.c Queue/queue.c Deque/deque.c
OUT = airport

all:
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)