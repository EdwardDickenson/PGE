cc = g++ -std=c++0x
deps = -lGL -lglfw -lSOIL
flags = -c -Wall

all: primitives unit bench

clang: cc=clang++ -std=c++0x
clang: all

profile: flags = -c -Wall -pg
profile: all

optimize: flags = -c -Wall -O3
optimize: all

optimize-clang: cc=clang++ -std=c++0x
optimize-clang: flags = -c -Wall -O3
optimize-clang: all

primitives:	lib.o main.o function_map.o deps.hpp
	$(cc) $(deps) -o main main.o function_map.o lib.o

unit: tests.o unit.o lib.o deps.hpp
	$(cc) $(deps) -o unit/unit unit.o tests.o lib.o

bench: lib.o deps.hpp bench.o marks.o
	$(cc) $(deps) bench.o lib.o marks.o -o bench/bench

main.o: main.cpp deps.hpp
	$(cc) $(flags) main.cpp

function_map.o: function_map.cpp deps.hpp
	$(cc) $(flags) function_map.cpp

lib.o: draw.o types.o shapes.o
	ld -r types.o shapes.o draw.o -o lib.o
	rm types.o shapes.o draw.o

draw.o: draw.* deps.hpp
	$(cc) $(flags) draw.cpp

shapes.o: square.o circle.o primitive.o
	ld -r square.o circle.o primitive.o -o shapes.o
	rm square.o circle.o primitive.o

coordinate.o: types/coordinate.*
	$(cc) $(flags) types/coordinate.cpp

rgbcolor.o: types/rgbcolor.* types/rgbcolor.hpp
	$(cc) $(flags) types/rgbcolor.cpp

displacement.o:	types/displacement.*
	$(cc) $(flags) types/displacement.cpp

square.o: geometry/square.* types.o
	$(cc) $(flags) geometry/square.cpp

circle.o: geometry/circle.* types.o
	$(cc) $(flags) geometry/circle.cpp

types.o: coordinate.o rgbcolor.o displacement.o
	ld -r coordinate.o rgbcolor.o displacement.o -o types.o
	rm coordinate.o rgbcolor.o displacement.o

primitive.o: geometry/primitive.* coordinate.o rgbcolor.o
	$(cc) $(flags) geometry/primitive.cpp

unit.o: unit/unit.*
	$(cc) $(flags) unit/unit.cpp

tests.o: rgbconstructors.o rgbtostring.o rgbmutators.o coordinatetostring.o coordinateconstructors.o
	ld -r rgbconstructors.o rgbtostring.o rgbmutators.o coordinatetostring.o coordinateconstructors.o -o tests.o
	rm rgbconstructors.o rgbtostring.o rgbmutators.o coordinatetostring.o coordinateconstructors.o

rgbconstructors.o: unit/unit.* unit/rgbcolor/testrgbcolor.hpp unit/rgbcolor/rgbconstructors.cpp
	$(cc) $(flags) unit/rgbcolor/rgbconstructors.cpp

rgbtostring.o: unit/unit.* unit/rgbcolor/testrgbcolor.hpp unit/rgbcolor/rgbtostring.cpp
	$(cc) $(flags) unit/rgbcolor/rgbtostring.cpp

rgbmutators.o: unit/unit.* unit/rgbcolor/testrgbcolor.hpp unit/rgbcolor/rgbmutators.cpp
	$(cc) $(flags) unit/rgbcolor/rgbmutators.cpp

coordinatetostring.o: unit/unit.* unit/coordinate/testcoordinate.hpp unit/coordinate/coordinatetostring.cpp
	$(cc) $(flags) unit/coordinate/coordinatetostring.cpp

coordinateconstructors.o: unit/unit.* unit/coordinate/testcoordinate.hpp unit/coordinate/coordinateconstructors.cpp
	$(cc) $(flags) unit/coordinate/coordinateconstructors.cpp

bench.o: bench/bench.*
	$(cc) $(flags) bench/bench.cpp

marks.o: bench/coordinate/coord.*
	$(cc) $(flags) bench/coordinate/coord.cpp
	ld -r coord.o -o marks.o

clean:
	rm -rf *.o
	rm -rf main
	rm -rf unit/*.o
	rm -rf unit/results.csv
	rm -rf unit/unit
	rm -rf bench/*.o
	rm -rf bench/results.csv
	rm -rf bench/bench
