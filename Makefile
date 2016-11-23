cc = g++ -std=c++0x
deps = -lGL -lglfw -lSOIL
flags = -c -Wall
prof = -pg

all: primitives

primitives: main.o function_map.o
	$(cc) *.o -o main $(deps)

main.o: main.cpp
	$(cc) main.cpp -c -Wall

draw.o:	draw.* deps.hpp square.o circle.o
	$(cc) draw.cpp -c -Wall

function_map.o: function_map.cpp draw.o displacement.o
	$(cc) function_map.cpp -c -Wall

coordinate.o: types/coordinate.*
	$(cc) types/coordinate.cpp -c -Wall

rgbcolor.o: types/rgbcolor.*
	$(cc) types/rgbcolor.cpp -c -Wall

displacement.o:	types/displacement.*
	$(cc) types/displacement.cpp -c -Wall

square.o: geometry/square.* coordinate.o rgbcolor.o primitive.o
	$(cc) geometry/square.cpp -c -Wall primitive.o

circle.o: geometry/circle.* coordinate.o rgbcolor.o primitive.o
	$(cc) geometry/circle.cpp -c -Wall primitive.o

primitive.o: geometry/primitive.* coordinate.o rgbcolor.o
	$(cc) geometry/primitive.cpp -c -Wall

clean:
	rm *.o
	rm main
