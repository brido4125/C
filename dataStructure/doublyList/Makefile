CC = gcc
TARGET = app.out
OBJS = exec.o doublylist.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

doublylist.o :
	$(CC) -c doublylist.c

clean :
	rm -f $(OBJS) $(TARGET)
