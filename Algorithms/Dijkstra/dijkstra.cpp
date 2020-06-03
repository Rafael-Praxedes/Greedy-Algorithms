#include "dijkstra.hpp"

path_t Dijkstra(vector< vector<int> > &distanceMatrix, int origin, int destiny)
{
    path_t pathObject;
    int solutionValue = 0;
    
    tuple<int, int> verticeTuple;

    int current_vertex_id;

    vertices.resize(distanceMatrix[0].size());

    vector< tuple<int, int> > priorityQueue(vertices.size());
    int priorityQueueSize = priorityQueue.size();

    InitializeSingleSource(origin);

    for (int i = 0; i < priorityQueue.size(); i++){
        priorityQueue[i] = make_tuple(vertices[i].id, vertices[i].key);
    }

    BuildMinHeap(priorityQueue, priorityQueueSize);

    while (priorityQueueSize > 0){
        verticeTuple = HeapExtractMin(priorityQueue, priorityQueueSize);

        for(int j = 0; j < distanceMatrix[get<0>(verticeTuple) - 1].size(); j++){
            if(Relax(distanceMatrix, j + 1, get<0>(verticeTuple)) == true){
                HeapDecreaseKey(priorityQueue, vertices[j].positionOnPriorityQueue, vertices[j].key, priorityQueueSize);   
            }
        }
    }
    
    current_vertex_id = destiny;

    while (current_vertex_id != origin){
        pathObject.path.push_back(current_vertex_id);
        solutionValue += distanceMatrix[current_vertex_id - 1][vertices[current_vertex_id - 1].previousVertexID - 1];
        
        current_vertex_id = vertices[current_vertex_id - 1].previousVertexID;
    }
    pathObject.path.push_back(origin);
    pathObject.solutionValue = solutionValue;
    
    return pathObject;
}

void InitializeSingleSource(int origin)
{
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].id = i + 1;
        vertices[i].previousVertexID = -1;
        vertices[i].positionOnPriorityQueue = i;

        if(i != origin - 1)
            vertices[i].key = INT_MAX;
    }
    vertices[origin - 1].key = 0;
}

bool Relax(vector< vector<int> > &distanceMatrix, int vertexV_ID, int vertexU_ID)
{
    if(vertices[vertexV_ID - 1].key > vertices[vertexU_ID - 1].key + distanceMatrix[vertexU_ID - 1][vertexV_ID - 1]){
        vertices[vertexV_ID - 1].key = vertices[vertexU_ID - 1].key + distanceMatrix[vertexU_ID - 1][vertexV_ID - 1];

        vertices[vertexV_ID - 1].previousVertexID = vertexU_ID;

        return true;
    }
    return false;
}