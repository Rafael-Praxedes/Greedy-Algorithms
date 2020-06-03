#ifndef EDGE_H
#define EDGE_H

#include <vector>

using namespace std;

//Data
typedef struct{
    int id_vertexU;
    int id_vertexV;
    int weight;
} edge_t;

extern vector<edge_t> mst_edges;

#endif