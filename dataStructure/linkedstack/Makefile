CC = gcc
TARGET = app.out
OBJS = exec.o linkedstack.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

linkedstack.o :
	$(CC) -c linkedstack.c

clean :
	rm -f $(OBJS) $(TARGET)
