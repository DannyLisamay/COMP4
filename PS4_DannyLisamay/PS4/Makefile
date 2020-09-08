CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic 
OBJ = ED.o
DEPS =  
LIBS =  -lsfml-system
EXE = ED

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)