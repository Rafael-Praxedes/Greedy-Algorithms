#include "inputMatrix.hpp"

int BuildInputMatrix(vector< vector<int> > &matrix, string fileName)
{
	ifstream file;
	file.open(fileName);

	string sizeMatrix;

	int size, indexAux, aux;

	//----------------------------------//
	//----- Build Matrix from file -----//
	//----------------------------------//
	if(file.is_open()){

		getline(file, sizeMatrix);
		size = atoi(sizeMatrix.c_str());

		for(int i = 0; i < size; i++){
				
			vector<int> line;

			for(int j = 0; j < size; j++){
				
				if(i >= j){					
					line.push_back(0);
				}
				else{	
					file >> aux;
					line.push_back(aux);
				}
			}
			matrix.push_back(line);
		}

		//----------------------------------//
		//------- Matrix's complement ------//
		//----------------------------------//
		for (int i = 0; i < matrix.size(); ++i){
			for (int j = 0; j < matrix[i].size(); ++j){
				if(i > j)
					matrix[i][j] = matrix[j][i];
			}
		}
		//----------------------------------//
	}
	else{
		return -1;
	}
	file.close();
	//----------------------------------//

	return 0;
}

void WriteSmallestPathFile(string fileName, vector<int> &path, int solutionValue)
{
	ofstream file;
	file.open(fileName);

	if(file.is_open()){

		file << ">>>>>>>>>> Dijkstra's Algorithm <<<<<<<<<<" << endl;

		file << "\norigin: " << path[path.size() - 1] << endl;
		file << "destiny: " << path[0] << endl;
		
		file << "\n//---------- Path ----------//";
		file << "\n\t";

		for (int i = path.size() - 1; i >= 0; i--){
			file << path[i] << " ";
		}
		file << endl;
		file << "//--------------------------//" << endl;

		file << "\nSolution value: " << solutionValue << endl; 
	}
	else{
		cout << "Error to open output file!" << endl;
	}
}

void WriteMstFile(string fileName, string algorithm)
{
	ofstream file;
	file.open(fileName);

	int solutionValue = 0;

	if(file.is_open()){

		file << ">>>>>>>>>> " << algorithm << "'s Algorithm <<<<<<<<<<" << endl;
		
		file << "\n//---------- MST ----------//" << endl;

		for (int i = 0; i < vertices.size(); i++){
			file << "Vertex " << vertices[i].id << ":" << endl;
			file << "\t>>> Predecessor: " << vertices[i].previousVertexID << endl;
			file << "\t>>> Edge value: " << vertices[i].key << endl;

			solutionValue += vertices[i].key;
		}
		file << endl;
		file << "//--------------------------//" << endl;

		file << "\nSolution value: " << solutionValue << endl; 
	}
	else{
		cout << "Error to open output file!" << endl;
	}
}