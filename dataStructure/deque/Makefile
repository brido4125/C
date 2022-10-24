CC = gcc
TARGET = app.out
OBJS = exec.o deque.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

deque.o :
	$(CC) -c deque.c

clean :
	rm -f $(OBJS) $(TARGET)
