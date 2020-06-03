/*****************************************/
/* Rafael Maranhão Rego Praxedes         */
/*                                       */
/* 30/05/2020                            */
/*                                       */
/* Greedy Algorithms - Main Function     */
/*                                       */
/*****************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Algorithms/Dijkstra/dijkstra.hpp"
#include "Algorithms/Prim/prim.hpp"
#include "Algorithms/Kruskal/kruskal.hpp"
#include "InputMatrix/inputMatrix.hpp"

using namespace std;

int main(int argc, char** argv)
{
    vector< vector<int> > distanceMatrix;
    path_t pathObject;

    string inputFilePath = "In/" + string(argv[2]);
    string outputFilePath = "Out/" + string(argv[1]) + "/" + string(argv[2]);

    cout << ">>>>>>>>>>>>>>>>>>>> " << string(argv[2]) << " <<<<<<<<<<<<<<<<<<<<" << endl;

    cout << "Building the distance matrix..." << endl;
    
    if(BuildInputMatrix(distanceMatrix, inputFilePath) == -1){
        cout << "Error to open input file!" << endl;
        return -1;
    }

    if(string(argv[1]) == "Dijkstra"){
        cout << "Running the Dijkstra's algorithm..." << endl;
        pathObject = Dijkstra(distanceMatrix, 1, distanceMatrix.size());

        cout << "Writing the output file..." << endl;
        WriteSmallestPathFile(outputFilePath, pathObject.path, pathObject.solutionValue);
    }
    else if(string(argv[1]) == "Prim"){
        cout << "Running the Prim's algorithm..." << endl;
        Prim(distanceMatrix, 1);

        cout << "Writing the output file..." << endl;
        WriteMstFile(outputFilePath, "Prim");
    }
    else if(string(argv[1]) == "Kruskal"){
        cout << "Running the Kruskal's algorithm..." << endl;
        Kruskal(distanceMatrix);

        cout << "Writing the output file..." << endl;
        WriteMstFile(outputFilePath, "Kruskal");
    }
    else{
        cout << "Invalid algorithm!" << endl;
    }

    cout << "Finishing the program..." << endl;
    return 0;
}