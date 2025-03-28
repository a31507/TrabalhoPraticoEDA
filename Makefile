CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = estruturas.o main.o
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
