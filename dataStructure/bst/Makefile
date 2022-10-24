CC = gcc
TARGET = app.out
OBJS = exec.o binarysearchtree.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

binarysearchtree.o :
	$(CC) -c binarysearchtree.c

clean :
	rm -f $(OBJS) $(TARGET)
