CC = gcc
TARGET = app.out
OBJS = exec.o linkedqueue.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

linkedqueue.o :
	$(CC) -c linkedqueue.c

clean :
	rm -f $(OBJS) $(TARGET)
