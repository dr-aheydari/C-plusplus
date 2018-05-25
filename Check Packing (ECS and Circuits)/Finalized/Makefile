all: checkpack

checkpack: checkpack.o Domain.o Shape.o Point.o 
	g++ -g -Wall -o checkpack checkpack.o Domain.o Shape.o Point.o 

checkpack.o: checkpack.cpp Domain.h 
	g++ -g -Wall -c checkpack.cpp

Domain.o: Domain.cpp Domain.h Shape.h
	g++ -g -Wall -c Domain.cpp

Shape.o: Shape.cpp Shape.h Point.h
	g++ -g -Wall -c Shape.cpp

Point.o: Point.cpp Point.h
	g++ -g -Wall -c Point.cpp 

execs = checkpack

clean:
	rm -f $(execs) *.o
