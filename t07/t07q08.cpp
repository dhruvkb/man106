#include <iostream>

using namespace std;

int binarySearch(int *array, int ll, int ul, int query)
{
    if (ul >= ll)
    {
        int mid = ll + (ul - ll) / 2;
        if (array[mid] == query)
        {
            return mid;
        }
        if (array[mid] > query)
        {
            return binarySearch(array, ll, mid - 1, query);
        }
        if (array[mid] < query)
        {
            return binarySearch(array, mid + 1, ul, query);
        }
    }
    return -1;
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
    int array[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int length = 8;

    cout << "Array: ";
    printArray(array, length);
    cout << endl;

    cout << "Index of 2: " << binarySearch(array, 0, length-1, 2) << endl;
    cout << "Index of 13: " << binarySearch(array, 0, length-1, 13) << endl;
    cout << "Index of 15: " << binarySearch(array, 0, length-1, 15) << endl;
    cout << "Index of 19: " << binarySearch(array, 0, length-1, 19) << endl;
    
    return 0;
}