CC = gcc
TARGET = app.out
OBJS = exec.o circularlist.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

exec.o :
	$(CC) -c exec.c

circularlist.o :
	$(CC) -c circularlist.c

clean :
	rm -f $(OBJS) $(TARGET)
