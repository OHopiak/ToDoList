CC = g++
CFLAGS  = -g # -Wall

default: todo

todo: Source.o DataParser.o User.o Task.o
	$(CC) $(CFLAGS) -o todo Source.o DataParser.o User.o Task.o
	$(RM) *.o *~

Source.o: Source.cpp DataParser.h NiceOut.h
	$(CC) $(CFLAGS) -c Source.cpp

DataParser.o: DataParser.cpp DataParser.h User.h
	$(CC) $(CFLAGS) -c DataParser.cpp

User.o: User.cpp User.h Task.h
	$(CC) $(CFLAGS) -c User.cpp

Task.o: Task.cpp Task.h Header.h
	$(CC) $(CFLAGS) -c Task.cpp

run:
	./todo

clean:
	$(RM) todo *.o *~
