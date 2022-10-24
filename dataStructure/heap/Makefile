CC = gcc
TARGET = app.out
OBJS = exec.o arrayheap.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

arrayheap.o :
	$(CC) -c arrayheap.c

clean :
	rm -f $(OBJS) $(TARGET)
