cc = g++ -std=c++0x
deps = -lGL -lglfw -lSOIL
flags = -c -Wall
prof = -pg

all: primitives unit

primitives: main.o function_map.o
	$(cc) -o main main.o function_map.o coordinate.o rgbcolor.o square.o circle.o draw.o primitive.o $(deps)

unit: unit.o
	$(cc) -o unit/unit unit.o coordinate.o rgbcolor.o square.o circle.o primitive.o rgbconstructors.o $(deps)

main.o: main.cpp
	$(cc) main.cpp $(flags)

function_map.o: function_map.cpp draw.o displacement.o
	$(cc) function_map.cpp $(flags)

draw.o:	draw.* deps.hpp square.o circle.o
	$(cc) draw.cpp $(flags)

coordinate.o: types/coordinate.*
	$(cc) types/coordinate.cpp $(flags)

rgbcolor.o: types/rgbcolor.*
	$(cc) types/rgbcolor.cpp $(flags)

displacement.o:	types/displacement.*
	$(cc) types/displacement.cpp $(flags)

square.o: geometry/square.* coordinate.o rgbcolor.o primitive.o
	$(cc) geometry/square.cpp $(flags)

circle.o: geometry/circle.* coordinate.o rgbcolor.o primitive.o
	$(cc) geometry/circle.cpp $(flags)

primitive.o: geometry/primitive.* coordinate.o rgbcolor.o
	$(cc) geometry/primitive.cpp $(flags)

unit.o: rgbconstructors.o unit/unit.*
	$(cc) unit/unit.cpp $(flags)

rgbconstructors.o: unit/rgbcolor/testrgbcolor.hpp unit/rgbcolor/rgbconstructors.cpp
	$(cc) unit/rgbcolor/rgbconstructors.cpp $(flags)

clean:
	rm -rf *.o
	rm -rf main
	rm -rf unit/*.o
	rm -rf unit/results.csv
	rm -rf unit/unit
