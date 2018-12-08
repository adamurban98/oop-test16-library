CC=g++
CCFLAGS=-Wall -W --std=c++11

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $< -o $(basename $<).o

all: main.o item.o date.o
	$(CC) $(CCFLAGS) item.o date.o main.o  -o prog
	chmod a+x prog

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $< -o $(basename $<).o

test: item.o date.o main.o tester.o
	$(CC) $(CCFLAGS) item.o date.o main.o tester.o -o test
	chmod a+x test

clear: clear_o
	rm -f test prog

clear_o:
	rm -f *.o

default: all

run: main.bin
	./main.bin
