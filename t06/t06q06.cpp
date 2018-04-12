#include <iostream>

using namespace std;

void maxHeapify(int *array, int length, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int temp;

    if (l < length && array[l] > array[largest])
    {
        largest = l;
    }
    if (r < length && array[r] > array[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        maxHeapify(array, length, largest);
    }
}

void heapSort(int *array, int length)
{
    int temp;
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        maxHeapify(array, length, i);
    }

    for (int i = length - 1; i >= 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        maxHeapify(array, i, 0);
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
    int array[] = {64, 25, 12, 22, 11};

    cout << "Unsorted array: ";
    printArray(array, 5);
    cout << endl;

    heapSort(array, 5);
    cout << "Heap sorted:\t ";
    printArray(array, 5);

    return 0;
}