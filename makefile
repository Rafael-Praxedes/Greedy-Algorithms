#Rafael Maranhão Rego Praxedes

#Makefile

all:greedy

greedy:dijkstra.o prim.o kruskal.o minPriorityQueue.o vertex.o edge.o inputMatrix.o main.o 
	g++ -std=c++11 dijkstra.o prim.o kruskal.o minPriorityQueue.o vertex.o edge.o inputMatrix.o main.o -o greedy-algorithms

dijkstra.o: Algorithms/Dijkstra/dijkstra.cpp
	g++ -std=c++11 -c Algorithms/Dijkstra/dijkstra.cpp

prim.o: Algorithms/Prim/prim.cpp
	g++ -std=c++11 -c Algorithms/Prim/prim.cpp

kruskal.o: Algorithms/Kruskal/kruskal.cpp
	g++ -std=c++11 -c Algorithms/Kruskal/kruskal.cpp

minPriorityQueue.o: DataStructures/MinPriorityQueue/minPriorityQueue.cpp
	g++ -std=c++11 -c DataStructures/MinPriorityQueue/minPriorityQueue.cpp

vertex.o: DataStructures/Vertex/vertex.cpp
	g++ -std=c++11 -c DataStructures/Vertex/vertex.cpp

edge.o: DataStructures/Edge/edge.cpp
	g++ -std=c++11 -c DataStructures/Edge/edge.cpp

inputMatrix.o: InputMatrix/inputMatrix.cpp
	g++ -std=c++11 -c InputMatrix/inputMatrix.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o dijkstra *~
	rm -f *.o prim *~
	rm -f *.o kruskal *~
	rm -f *.o minPriorityQueue *~
	rm -f *.o vertex *~
	rm -f *.o edge *~
	rm -f *.o inputMatrix *~
	rm -f *.o main *~
