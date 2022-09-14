CC = gcc
TARGET = app.out
OBJS = exec.o arraystack.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

arraystack.o :
	$(CC) -c arraystack.c

clean :
	rm -f $(OBJS) $(TARGET)
