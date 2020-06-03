#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <bits/stdc++.h>
#include "../../DataStructures/Edge/edge.hpp"
#include "../../DataStructures/Vertex/vertex.hpp"
#include <iostream>

using namespace std;

//Functions
extern void PrintEdges(vector<edge_t> edges);
extern bool CompareEdges(edge_t a1, edge_t a2);
extern void CreateVerticesVector(int numVertices);
extern int Find(vector<int> &verticesSubsets, int verticePosition);
extern void Union(vector<int> &verticesSubsets, int verticePosition_u, int verticePosition_v);
extern void Kruskal(vector< vector<int> > &distanceMatrix); 

#endif