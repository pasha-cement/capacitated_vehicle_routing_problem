all: capacitated_vehicle_routing_problem

capacitated_vehicle_routing_problem: main.o construction.o input.o localsearch.o neighborhood.o solution.o perturbation.o
	g++ main.o construction.o input.o localsearch.o neighborhood.o solution.o perturbation.o -o capacitated_vehicle_routing_problem
	
main.o: main.cpp
	g++ main.cpp -c
	
construction.o: construction.cpp
	g++ construction.cpp -c

input.o: input.cpp
	g++ input.cpp -c

localsearch.o: localsearch.cpp
	g++ localsearch.cpp -c
	
neighborhood.o: neighborhood.cpp
	g++ neighborhood.cpp -c

solution.o: solution.cpp
	g++ solution.cpp -c

perturbation.o: perturbation.cpp
	g++ perturbation.cpp -c
