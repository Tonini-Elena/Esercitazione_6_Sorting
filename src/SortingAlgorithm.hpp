#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

//function that implements bubble sort
template<typename T>
void BubbleSort(std::vector<T>& data)
{
    size_t BubbleSize = data.size();
    size_t last = BubbleSize;
    bool inverted = true;

    while (inverted) {
        inverted = false;
        for (size_t i = 1; i < BubbleSize; i++) {
            if (data[i-1] > data[i]) {
                std::swap(data[i-1], data[i]);
                inverted = true;
                last = i;
            }
        }
      
        BubbleSize = last;
    }
}

//function that resets heap to maintain its structure
template <typename T>
void FixHeap(vector<T>& v, size_t Data, size_t currentNode) {
    size_t majorNode = currentNode;
    size_t leftNode = 2 * currentNode + 1;
    size_t rightNode = 2 * currentNode + 2;

    if (leftNode < Data && v[leftNode] > v[majorNode])
        majorNode = leftNode;

    if (rightNode < Data && v[rightNode] > v[majorNode])
        majorNode = rightNode;

    if (majorNode != currentNode) {
        swap(v[currentNode], v[majorNode]);
        FixHeap(v, Data, majorNode);
    }
}

//function that implements heap sort
template <typename T>
void HeapSort(vector<T>& data) {
    size_t HeapSize = data.size();

    for (size_t i = HeapSize / 2 - 1; i != size_t(-1); --i) {
        FixHeap(data, HeapSize, i);
    }

    for (size_t i = HeapSize - 1; i > 0; --i) {
        swap(data[0], data[i]);
        FixHeap(data, i, 0);
    }
}


}



