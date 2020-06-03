#include "kruskal.hpp"

void PrintEdges(vector<edge_t> edges)
{
    for (int i = 0; i < edges.size(); i++){
        cout << "(" << edges[i].id_vertexU << ", " << edges[i].id_vertexV << ")" << ": " << edges[i].weight << endl;
    }
    cout << endl;
}

bool CompareEdges(edge_t a1, edge_t a2)
{
    return a1.weight < a2.weight;
}

void CreateVerticesVector(int numVertices)
{
    vertices.resize(numVertices);
    vertex_t vertex;

    vertices[0].id = mst_edges[0].id_vertexU;
    vertices[0].key = 0;
    vertices[0].previousVertexID = -1;

    for (int i = 0; i < mst_edges.size(); i++){
        vertex.id = mst_edges[i].id_vertexV;
        vertex.previousVertexID = mst_edges[i].id_vertexU;
        vertex.key = mst_edges[i].weight;

        vertices[i+1] = vertex;
    }
}

int Find(vector<int> &verticesSubsets, int verticePosition)
{
    if (verticesSubsets[verticePosition] == -1)
        return verticePosition;

    return Find(verticesSubsets, verticesSubsets[verticePosition]);
}

void Union(vector<int> &verticesSubsets, int verticePosition_u, int verticePosition_v)
{
    verticesSubsets[Find(verticesSubsets, verticePosition_u)] = Find(verticesSubsets, verticePosition_v); 
}

void Kruskal(vector< vector<int> > &distanceMatrix)
{
    vector<int> verticesSubsets(distanceMatrix.size(), -1);

    vector<edge_t> edges;
    edge_t edge;

    for (int i = 0; i < distanceMatrix.size(); i++){
        for (int j = 0; j < distanceMatrix[i].size(); j++){
            edge.id_vertexU = i + 1;
            edge.id_vertexV = j + 1;
            edge.weight = distanceMatrix[i][j];

            edges.push_back(edge);
        }
    }
    sort(edges.begin(), edges.end(), CompareEdges);

    for (int i = 0; i < edges.size(); i++){
        if(edges[i].id_vertexU != edges[i].id_vertexV && Find(verticesSubsets, edges[i].id_vertexU - 1) != Find(verticesSubsets, edges[i].id_vertexV - 1)){
            mst_edges.push_back(edges[i]);

            Union(verticesSubsets, edges[i].id_vertexU - 1, edges[i].id_vertexV - 1);
        }
    }

    CreateVerticesVector(distanceMatrix.size());
}