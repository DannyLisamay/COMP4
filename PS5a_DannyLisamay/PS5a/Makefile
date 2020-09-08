CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic 
OBJ = test.o RingBuffer.o
DEPS =  
LIBS =  
EXE = test

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)