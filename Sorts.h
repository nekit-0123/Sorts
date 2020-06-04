#include <iostream>
#include <algorithm>


// Вид пузырьковых сортировок 
// Space O(1)

template <class T>
class CBubbleSort
{
public:
    CBubbleSort()
    {}
    ~CBubbleSort()
    {}


/* Case
 Best: O(n)
 Worst: O(n^2)
 Average: O(n^2)
 */
    void BubbleSort(T* array, long size)
    {
        bool flag = true;
        for (long i = 0; i < size; i++)
        {
            flag = false;
            for (long j = 0; j < size - (i + 1); j++)
            {
                if (array[j] > array[j + 1])
                {
                    std::swap(array[j], array[j + 1]);
                    flag = true;
                }
            }
            if (!flag)
                break;
        }
    }

/* Case
 Best: O(n)
 Worst: O(n^2)
 Average: O(n^2)
 */
    void ShekerSort(T* array, long size)
    {
        long left = 0, right = size - 1;
        bool flag = true;

        while ((left < right) && flag)
        {
            flag = false;

            for (long i = left; i < right; i++)
            {
                if (array[i] > array[i + 1])
                {
                    std::swap(array[i], array[i + 1]);
                    flag = true;
                }
            }
            right--;
            for (long i = right; i > left; i--)
            {
                if (array[i - 1] > array[i])
                {
                    std::swap(array[i - 1], array[i]);
                    flag = true;
                }
            }
            left++;
        }
    }

/* Case
 Best: O(n log(n))
 Worst: O(n^2 / 2^p) p -> increment
 Average: O(n^2)
 */
    void CombSort(T* array, long size)
    {
        long jump = size;
        bool flag = true;

        while (jump > 1 || flag)
        {
            flag = false;
            if (jump > 1)
                jump = jump / 1.3;

            for (long i = 0; i + jump < size; i++)
            {
                if (array[i] > array[i + jump])
                {
                    std::swap(array[i], array[i + jump]);
                    flag = true;
                }
            }
        }
    }
};

// Вид простых сортировок 
// Space O(n) основной, O(1) вспомогательной

template <class T>
class CJustSort
{
public:
    CJustSort()
    {}
    ~CJustSort()
    {}

/* Case
 Best: O(n^2)
 Worst: O(n^2) 
 Average: O(n^2)
 */
    void SelectionSort(T *array, long size)
    {
        long min_dx(0);
        for (long i = 0; i < size - 1; i++)
        {
            min_dx = i;

            for (long j = i + 1; j < size; j++)
            {
                if (array[min_dx] > array[j])
                    min_dx = j;
            }
            std::swap(array[min_dx], array[i]);
        }
    }

/* Case
 Best: O(n)
 Worst: O(n^3/2) 
 Average: O(n^3/2)
 */
    void ShellSort(T *array, long size)
    {
        for(long step = size/2; step > 0; step /=2)
        {
            for (long i = step; i< size; ++i)
            {
                for (long j = i - step; j >=0 && array[j] >= array[j+step]; j -= step)
                    std::swap(array[j], array[j+step]);
            }
        }
    }

/* Case
 Best: O(n) + O(1)
 Worst: O(n^2) 
 Average: O(n^2)
 */
    void InsertionSort(T *array, long size)
    {
        for(long i = 1; i < size; ++i)
        {
            T key = array[i];
            long j = i - 1;

            while(j>=0 && array[j]> key)
            {
                array[j+1] =  array[j];
                --j; 
            }
            array[j+1] = key;
        }
    }

};

// Вид эффективных сортировок 
// Space O(n)

template <class T>
class CEfficient
{
public:
    CEfficient()
    {}
    ~CEfficient()
    {}

/* Case
 Best: O(n) 
 Worst: O(n^2) 
 Average: O(n log(n))
 */
    void QuickSort(T *array, long size)
    {
        long i = 0, j = size;
        long p = array[size >> 1];

        while (i <= j)
        {
            while (array[i] < p)
                i++;
            while (array[j] > p)
                j--;

            if (i <= j)
            {
                std::swap(array[i], array[j]);
                i++;
                j--;
            }

            if (j > 0)
                QuickSort(array, j);
            if (size > i)
                QuickSort(array + i, size - i);
        }
    }
};
