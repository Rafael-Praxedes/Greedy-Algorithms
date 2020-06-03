#ifndef MIN_PRIORITY_QUEUE_H
#define MIN_PRIORITY_QUEUE_H

#include <vector>
#include <climits>
#include <iostream>
#include <bits/stdc++.h>
#include "../Vertex/vertex.hpp"

using namespace std;

//Functions
extern int Dad(int index);
extern int LeftChild(int index);
extern int RightChild(int index);
extern void MinHeapify(vector< tuple<int, int> > &inputVector, int index, int heapSize);
extern void BuildMinHeap(vector< tuple<int, int> > &inputVector, int heapSize);

extern tuple<int, int> HeapMinimun(vector< tuple<int, int> > &inputVector);
extern void MinHeapInsert(vector< tuple<int, int> > &inputVector, tuple<int, int> element, int &heapSize);
extern tuple<int, int> HeapExtractMin(vector< tuple<int, int> > &inputVector, int &heapSize);
extern int HeapDecreaseKey(vector< tuple<int, int> > &inputVector, int position_element, int key, int heapSize);

#endif