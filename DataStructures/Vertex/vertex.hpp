#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

using namespace std;

//Data
typedef struct{
    int id;
    int key;
    int previousVertexID;
    int positionOnPriorityQueue;
} vertex_t;

extern vector<vertex_t> vertices;

#endif