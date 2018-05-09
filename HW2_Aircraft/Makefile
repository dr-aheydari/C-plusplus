all: maintenance testAircraft;

Aircraft.o: Aircraft.cpp Aircraft.h
	g++ -g -Wall -c -o Aircraft.o Aircraft.cpp
testAircraft.o: testAircraft.cpp Aircraft.cpp 
	g++ -g -Wall -c -o testAircraft.o testAircraft.cpp
maintenance.o: maintenance.cpp Aircraft.o
	g++ -g -Wall -c -o maintenance.o maintenance.cpp  
maintenance: maintenance.o Aircraft.o
	g++ -g -Wall -o maintenance maintenance.o Aircraft.o
testAircraft: testAircraft.o Aircraft.o
	g++ -g -Wall -o testAircraft testAircraft.o Aircraft.o
execs = maintenance testAircraft

clean:
	rm -f $(execs) *.o
