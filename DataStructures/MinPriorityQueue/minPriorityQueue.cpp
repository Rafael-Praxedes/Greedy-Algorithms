#include "minPriorityQueue.hpp"

int Dad(int index)
{	
	if(index == 0)
		return index;
	if(index != 0 && !(index%2))
		return (index/2 - 1);
	else
		return index/2;
}

int LeftChild(int index)
{
    return 2*index + 1;
}

int RightChild(int index)
{
    return 2*index + 2;
}

void MinHeapify(vector< tuple<int, int> > &inputVector, int index, int heapSize)
{
    int leftChild = LeftChild(index);
    int rightChild = RightChild(index);

    int indexSmallElement = index; 

    if(leftChild < heapSize && get<1>(inputVector[leftChild]) < get<1>(inputVector[index])){
        indexSmallElement = leftChild;
    }
    if (rightChild < heapSize && get<1>(inputVector[rightChild]) < get<1>(inputVector[indexSmallElement])){
        indexSmallElement = rightChild;
    }
    
    if(indexSmallElement != index){
        tuple<int, int> aux = inputVector[index];
        
        //-------------------------------- Vertices setup --------------------------------// 
        vertices[get<0>(inputVector[index])- 1].positionOnPriorityQueue = indexSmallElement;
        vertices[get<0>(inputVector[indexSmallElement])- 1].positionOnPriorityQueue = index;
        //--------------------------------------------------------------------------------//

        inputVector[index] = inputVector[indexSmallElement];
        inputVector[indexSmallElement] = aux;

        MinHeapify(inputVector, indexSmallElement, heapSize);   
    }
}

void BuildMinHeap(vector< tuple<int, int> > &inputVector, int heapSize)
{
    for(int i = heapSize/2 - 1; i >= 0; i--){
        MinHeapify(inputVector, i, heapSize);
    } 
}

tuple<int, int> HeapMinimun(vector< tuple<int, int> > &inputVector)
{
    return inputVector[0];
}

void MinHeapInsert(vector< tuple<int, int> > &inputVector, tuple<int, int> element, int &heapSize)
{
    heapSize++;

    if(heapSize <= inputVector.size()){
        inputVector[heapSize - 1] = make_tuple(get<0>(element), INT_MAX);
        HeapDecreaseKey(inputVector, heapSize - 1, get<1>(element), heapSize);
    }
    else{
        heapSize--;
    }
}

tuple<int, int> HeapExtractMin(vector< tuple<int, int> > &inputVector, int &heapSize)
{
    tuple<int, int> min;

    if(heapSize < 1){
        return make_tuple(INT_MAX, INT_MAX);
    }

    //---------------------------- Vertices setup --------------------------// 
    vertices[get<0>(inputVector[heapSize-1])- 1].positionOnPriorityQueue = 0;
    //----------------------------------------------------------------------//

    min = inputVector[0];
    inputVector[0] = inputVector[heapSize-1];

    heapSize--;

    MinHeapify(inputVector, 0, heapSize);

    return min;
}

int HeapDecreaseKey(vector< tuple<int, int> > &inputVector, int position_element, int key, int heapSize)
{
    int dad = Dad(position_element);
    tuple<int, int> aux;

    if(key < get<1>(inputVector[position_element]) && position_element < heapSize){
        inputVector[position_element] = make_tuple(get<0>(inputVector[position_element]), key);

        while(position_element > 0 && get<1>(inputVector[dad]) > get<1>(inputVector[position_element])){
            aux = inputVector[dad];
            
            //------------------------------- Vertices setup -------------------------------// 
            vertices[get<0>(inputVector[dad])- 1].positionOnPriorityQueue = position_element;
            vertices[get<0>(inputVector[position_element])- 1].positionOnPriorityQueue = dad;
            //------------------------------------------------------------------------------//

            inputVector[dad] = inputVector[position_element];
            inputVector[position_element] = aux;

            position_element = dad;
            dad = Dad(position_element);
        }
    }

    return position_element;
}