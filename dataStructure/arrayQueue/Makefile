CC = gcc
TARGET = app.out
OBJS = exec.o arrayqueue.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

arrayqueue.o :
	$(CC) -c arrayqueue.c

clean :
	rm -f $(OBJS) $(TARGET)
