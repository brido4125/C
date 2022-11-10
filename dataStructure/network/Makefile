CC = gcc
TARGET = server
OBJS = serverclient.o csapp.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

csapp.o :
	$(CC) -c csapp.c

serverclient.o :
	$(CC) -c serverclient.c

clean :
	rm -f $(OBJS) $(TARGET)
