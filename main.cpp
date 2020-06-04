#include <iostream>
#include <vector>
#include "Sorts.h"
#include <random>
#include <time.h>

std::vector<int> randomVector(size_t size)
{
    std::vector<int> v(size);
    std::random_device r;
    std::generate(v.begin(), v.end(), [&]{return r();});
    return v;
}

int main(void)
{
    std::vector<int> array(randomVector(10000));

    clock_t time;
    time = clock();

    CBubbleSort<int> sortb;  
    //sortb.BubbleSort(array.data(), array.size());
    //sortb.CombSort(array.data(), array.size());
    //sortb.ShekerSort(array.data(), array.size());

    CJustSort<int> sortJ;  
   // sortJ.SelectionSort(array.data(), array.size());
   //sortJ.ShellSort(array.data(), array.size());
   //sortJ.InsertionSort(array.data(), array.size());

    CEfficient<int> sortE;  
    //sortE.QuickSort(array.data(), array.size());
    //sortE.MergeSort(array.data(), array.size());
    //sortE.CountingSort(array.data(), array.size());

    time = clock() - time;
    std::cout << (double)time/CLOCKS_PER_SEC;
}


/*
    Count = 10000

    BubbleSort = 0.38 sec
    CombSort = 0.0021 sec
    ShekerSort = 0.33 sec 

    SelectionSort = 0.003 sec
    ShellSort = 0.002 sec
    InsertionSort = 0.09 sec

    QuickSort = 10.5 sec // xmm 
    MergeSort = 0.004 sec
*/