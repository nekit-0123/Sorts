#include <iostream>
#include <vector>
#include "Sorts.h"
#include <random>


std::vector<int> randomVector(size_t size)
{
    std::vector<int> v(size);
    std::random_device r;
    std::generate(v.begin(), v.end(), [&]{return r();});
    return v;
}


int main()
{
    std::vector<int> array(randomVector(100));

    CBubbleSort<int> sortb;  
   // sortb.BubbleSort(array.data(), array.size());
   // sortb.CombSort(array.data(), array.size());
   // sortb.ShekerSort(array.data(), array.size());

    CJustSort<int> sortJ;  
   // sortJ.SelectionSort(array.data(), array.size());
   //sortJ.ShellSort(array.data(), array.size());
   //sortJ.InsertionSort(array.data(), array.size());

    CEfficient<int> sortE;  
   // sortE.QuickSort(array.data(), array.size());

    
    for (auto it: array)
        std::cout<<it<<" ";
}