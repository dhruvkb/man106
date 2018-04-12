#include <iostream>

using namespace std;

void selectionSort(int *array, int length)
{
    int minIndex, minValue;
    for (int i = 0; i < length - 1; i++)
    {
        minValue = array[i];
        minIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < minValue)
            {
                minValue = array[j];
                minIndex = j;
            }
        }
        array[minIndex] = array[i];
        array[i] = minValue;
    }
}

void insertionSort(int *array, int length)
{
    int current, j;
    for (int i = 1; i < length; i++)
    {
        current = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > current)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = current;
    }
}

void printArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "\t" << array[i];
    }
}

int main()
{
    int array1[] = {64, 25, 12, 22, 11};
    int array2[] = {64, 25, 12, 22, 11};
    
    cout << "Unsorted array: ";
    printArray(array1, 5);
    cout << endl;

    selectionSort(array2, 5);
    cout << "Selection sorted: ";
    printArray(array2, 5);
    cout << endl;
    
    insertionSort(array2, 5);
    cout << "Insertion sorted: ";
    printArray(array2, 5);

    return 0;
}