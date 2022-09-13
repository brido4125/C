CC = gcc
TARGET = app.out
OBJS = ALexec.o arrayList.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

ALexec.o : 
	$(CC) -c ALexec.c

arrayList.o : 
	$(CC) -c arrayList.c 

clean :
	rm -f $(OBJS) $@
