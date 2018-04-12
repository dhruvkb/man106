#include <iostream>

using namespace std;

void minHeapify(int *array, int length, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int temp;

    if (l < length && array[l] < array[smallest])
    {
        smallest = l;
    }
    if (r < length && array[r] < array[smallest])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;

        minHeapify(array, length, smallest);
    }
}

void printArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "\t" << array[i];
    }
}

void heapSort(int *array, int length)
{
    int temp;
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        minHeapify(array, length, i);
    }

    cout << "Heaped array:\t";
    printArray(array, length);
    cout << endl;

    for (int i = length - 1; i >= 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        minHeapify(array, i, 0);
    }
}

int main()
{
    int array[] = {64, 9, 12, 22, 11};

    cout << "Unsorted array: ";
    printArray(array, 5);
    cout << endl;

    heapSort(array, 5);
    cout << "Heap sorted:\t ";
    printArray(array, 5);

    return 0;
}