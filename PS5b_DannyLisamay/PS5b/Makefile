CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ = GuitarString.o RingBuffer.o GuitarHero.o
DEPS =  
LIBS = -lboost_unit_test_framework -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window
EXE = test

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)