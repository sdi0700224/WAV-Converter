# paths
MODULES = ../WAV-Converter
INCLUDE = ../WAV-Converter

# compiler
CC = gcc

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CFLAGS = -Wall -Werror -g -I$(INCLUDE)

# Αρχεία .o
OBJS = wavproc.o

# Το εκτελέσιμο πρόγραμμα
EXEC = wavproc

# Παράμετροι για δοκιμαστική εκτέλεση
ARGS = 

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) -lm

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)