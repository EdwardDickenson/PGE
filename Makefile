cc = g++ -std=c++0x
deps = -lGL -lglfw -lSOIL
flags = -c -Wall
prof = -pg

all: primitives unit

primitives: main.o function_map.o
	$(cc) -o main main.o function_map.o coordinate.o rgbcolor.o square.o circle.o draw.o primitive.o $(deps)

unit: unit.o
	$(cc) -o unit/unit unit.o coordinate.o rgbcolor.o square.o circle.o primitive.o $(deps)

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
	$(cc) geometry/square.cpp primitive.o -c -Wall

circle.o: geometry/circle.* coordinate.o rgbcolor.o primitive.o
	$(cc) geometry/circle.cpp -c -Wall

primitive.o: geometry/primitive.* coordinate.o rgbcolor.o
	$(cc) geometry/primitive.cpp -c -Wall

unit.o: unit/unit.cpp unit/unit.hpp unit/testrgb.hpp
	$(cc) unit/unit.cpp -c -Wall

clean:
	rm -rf *.o
	rm -rf main
	rm -rf unit/*.o
	rm -rf unit/results.csv
	rm -rf unit/unit
