cc = g++ -std=c++0x
deps = -lGL -lglfw -lSOIL
flags = -c -Wall

all: primitives unit bench

clang: cc=clang++
clang: all

profile: flags = -c -Wall -pg
profile: all

optimize: flags = -c -Wall -O3
optimize: all

optimize-clang: flags = -c -Wall -O3
optimize-clang: all

primitives:	lib.o main.o function_map.o deps.hpp
	$(cc) -o main main.o function_map.o lib.o $(deps)

unit: tests.o unit.o lib.o deps.hpp
	$(cc) -o unit/unit unit.o tests.o lib.o $(deps)

bench: lib.o deps.hpp
	$(cc) bench/bench.cpp -o bench/bench $(deps)

main.o: main.cpp deps.hpp
	$(cc) main.cpp $(flags)

function_map.o: function_map.cpp deps.hpp
	$(cc) function_map.cpp $(flags)

lib.o: draw.o types.o shapes.o
	ld -r types.o shapes.o draw.o -o lib.o

draw.o: draw.* deps.hpp
	$(cc) draw.cpp $(flags)

shapes.o: square.o circle.o primitive.o
	ld -r square.o circle.o primitive.o -o shapes.o

coordinate.o: types/coordinate.*
	$(cc) types/coordinate.cpp $(flags)

rgbcolor.o: types/rgbcolor.* types/rgbcolor.hpp
	$(cc) types/rgbcolor.cpp $(flags)

displacement.o:	types/displacement.*
	$(cc) types/displacement.cpp $(flags)

square.o: geometry/square.* types.o
	$(cc) geometry/square.cpp $(flags)

circle.o: geometry/circle.* types.o
	$(cc) geometry/circle.cpp $(flags)

types.o: coordinate.o rgbcolor.o displacement.o
	ld -r coordinate.o rgbcolor.o displacement.o -o types.o

primitive.o: geometry/primitive.* coordinate.o rgbcolor.o
	$(cc) geometry/primitive.cpp $(flags)

tests.o:	rgbconstructors.o rgbtostring.o rgbmutators.o coordinatetostring.o
	ld -r rgbconstructors.o rgbtostring.o rgbmutators.o -o tests.o coordinatetostring.o

unit.o: rgbconstructors.o rgbtostring.o rgbmutators.o unit/unit.*
	$(cc) unit/unit.cpp $(flags)

rgbconstructors.o: unit/unit.* unit/rgbcolor/testrgbcolor.hpp unit/rgbcolor/rgbconstructors.cpp
	$(cc) unit/rgbcolor/rgbconstructors.cpp $(flags)

rgbtostring.o: unit/unit.* unit/rgbcolor/testrgbcolor.hpp unit/rgbcolor/rgbtostring.cpp
	$(cc) unit/rgbcolor/rgbtostring.cpp $(flags)

rgbmutators.o: unit/unit.* unit/rgbcolor/testrgbcolor.hpp unit/rgbcolor/rgbmutators.cpp
	$(cc) unit/rgbcolor/rgbmutators.cpp $(flags)

coordinatetostring.o: unit/unit.* unit/coordinate/testcoordinate.hpp unit/coordinate/coordinatetostring.cpp
	$(cc) unit/coordinate/coordinatetostring.cpp $(flags)

clean:
	rm -rf *.o
	rm -rf main
	rm -rf unit/*.o
	rm -rf unit/results.csv
	rm -rf unit/unit
