#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include "../../DataStructures/MinPriorityQueue/minPriorityQueue.hpp"
#include "../../DataStructures/Vertex/vertex.hpp"
#include <climits>

using namespace std;

//Functions 
extern void Prim(vector< vector<int> > &distanceMatrix, int origin);
extern void InitializePrim(int origin);
extern bool RelaxPrim(vector< vector<int> > &distanceMatrix, int vertexV_ID, int vertexU_ID);

#endif