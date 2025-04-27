#include <iostream>
#include <vector>
#include <chrono>
#include <numeric> 
#include <string>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace std::chrono;
using namespace SortLibrary;

//function to measure the average execution time of bubble sort
double timesBubble(vector<int>& dataBubble, unsigned int numInteractions)
{
    vector<unsigned int> timesBubble;

    for (unsigned int i = 0; i < numInteractions; ++i)
    {
        auto startBubble = steady_clock::now();
        BubbleSort(dataBubble);
        auto stopBubble = steady_clock::now();
        auto durationBubble = duration_cast<microseconds>(stopBubble - startBubble);
        timesBubble.push_back(durationBubble.count());
    }

    double sumBubble = 0;
    for (auto value : timesBubble) {
        sumBubble += value;
    }
    
    return sumBubble / timesBubble.size();
}

//function to measure the average execution time of heap sort
double timesHeap(vector<int>& dataHeap, unsigned int numInteractions)
{
    vector<unsigned int> timesHeap;

    for (unsigned int i = 0; i < numInteractions; ++i)
    {
        auto startHeap = steady_clock::now();
        HeapSort(dataHeap);
        auto stopHeap = steady_clock::now();
        auto durationHeap = duration_cast<microseconds>(stopHeap - startHeap);
        timesHeap.push_back(durationHeap.count());
    }

    double sumHeap = 0;
    for (auto value : timesHeap) {
        sumHeap += value;
    }
    
    return sumHeap / timesHeap.size();
}

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

struct ClassObj{
    double value;

    
};

inline bool operator< (const ClassObj& lhs, const ClassObj& rhs) { return lhs.value < rhs.value; }

int main(int argc, char *argv[])
{

    for(int a = 0; a < argc; a++)
        cout << argv[a] << " ";
    cout << endl;

    size_t size = 10;
    if(argc > 1)
    {
        istringstream convert(argv[1]);
        convert >> size;
        cout << "use value: "  << size << endl;
    }
    else
        cerr << "use default value: "  << size << endl;


    unsigned int numInteractions = 10;

    
    vector<int> firstData(size);
    iota(firstData.begin(), firstData.end(), 0); 

   
    vector<int> firstDataBubble = firstData;
    vector<int> firstDataHeap = firstData;

    
    double AverageBubble = timesBubble(firstDataBubble, numInteractions);
    double AverageHeap = timesHeap(firstDataHeap, numInteractions);

   
    cout << "The average time for the bubble algorithm for a fully ordered vector is: " << AverageBubble << " microseconds" << endl;
    cout << "The average time for the heap algorithm for a fully ordered vector is: " << AverageHeap << " microseconds" << endl;

   
    vector<int> secondData(size);
    srand(time(nullptr));
    for (size_t i = 0; i < size; ++i) {
        secondData[i] = rand() % 1000; 
    }

   
    vector<int> secondDataBubble = secondData;
    vector<int> secondDataHeap = secondData;

   
    double secondAverageBubble = timesBubble(secondDataBubble, numInteractions);
    double secondAverageHeap = timesHeap(secondDataHeap, numInteractions);

  
    cout << "The average time for the bubble algorithm for a random vector is: " << secondAverageBubble << " microseconds" << endl;
    cout << "The average time for the heap algorithm for a random vector is: " << secondAverageHeap << " microseconds" << endl;

 
    vector<int> thirdData(size);
    iota(thirdData.begin(), thirdData.end(), 0);

    
    vector<int> dataPerturbed = thirdData;
    for (size_t i = 0; i < size; i++) {
        dataPerturbed[i] += int(rand()) % 10; 
    }

    vector<int> thirdDataBubble = dataPerturbed;
    vector<int> thirdDataHeap = dataPerturbed;

    
    double thirdAverageBubble = timesBubble(thirdDataBubble, numInteractions);
    double thirdAverageHeap = timesHeap(thirdDataHeap, numInteractions);

    
    cout << "The average time for the bubble algorithm for a slightly random vector is: " << thirdAverageBubble << " microseconds" << endl;
    cout << "The average time for the heap algorithm for a slightly random vector is: " << thirdAverageHeap << " microseconds" << endl;

    return 0;
}


