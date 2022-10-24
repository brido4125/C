CC = gcc
TARGET = app.out
OBJS = exec.o bintree.o bintreetraversalrec.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

bintree.o :
	$(CC) -c bintree.c

bintreetraversalrec.o :
	$(CC) -c bintreetraversalrec.c

clean :
	rm -f $(OBJS) $(TARGET)
