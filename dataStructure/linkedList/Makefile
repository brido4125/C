CC = gcc
TARGET = app.out
OBJS = exec.o linkedlist.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

ALexec.o : 
	$(CC) -c exec.c

arrayList.o : 
	$(CC) -c linkedlist.c

clean :
	rm -f $(OBJS) $(TARGET)
