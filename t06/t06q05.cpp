#include <iostream>

using namespace std;

int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

int quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int part = partition(array, low, high);
        quickSort(array, low, part - 1);
        quickSort(array, part + 1, high);
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

    quickSort(array, 0, 4);
    cout << "Quick sorted: ";
    printArray(array, 5);

    return 0;
}