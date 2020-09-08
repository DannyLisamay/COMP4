CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ = ps7.o 
DEPS =
LIBS = -lboost_regex -lboost_date_time -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXE = ps7

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(EXE)
