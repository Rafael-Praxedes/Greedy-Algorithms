#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include "../../DataStructures/MinPriorityQueue/minPriorityQueue.hpp"
#include "../../DataStructures/Vertex/vertex.hpp"
#include <climits>

using namespace std;

//Data
typedef struct{
    vector<int> path;
    int solutionValue;
} path_t;

//Functions 
extern path_t Dijkstra(vector< vector<int> > &distanceMatrix, int origin, int destiny);
extern void InitializeSingleSource(int origin);
extern bool Relax(vector< vector<int> > &distanceMatrix, int vertexV_ID, int vertexU_ID);

#endif