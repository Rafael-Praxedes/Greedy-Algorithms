#ifndef INPUTMATRIX_H
#define INPUTMATRIX_H

#include <iostream>
#include <fstream>
#include <string> 
#include <vector> 
#include <stdio.h>
#include <stdlib.h>

#include "../DataStructures/Vertex/vertex.hpp"

using namespace std;

//Functions
extern int BuildInputMatrix(vector< vector<int> > &matrix, string fileName);
extern void WriteSmallestPathFile(string fileName, vector<int> &path, int solutionValue);
extern void WriteMstFile(string fileName, string algorithm);

#endif 