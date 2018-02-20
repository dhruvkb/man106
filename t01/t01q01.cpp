#include <iostream>
#define SIZE 5

using namespace std;

int sumArray(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void sortArray(int *arr, int *ans, int size)
{
    for (int i = 0; i < size; i++)
    {
        ans[i] = arr[i];
    }
    int temp;
    for (int j = 0; j < size - 1; j++)
    {
        for (int k = 0; k < size - j - 1; k++)
        {
            if (ans[k] > ans[k + 1])
            {
                temp = ans[k + 1];
                ans[k + 1] = ans[k];
                ans[k] = temp;
            }
        }
    }
}

void reverseArray(int *arr, int *ans, int size)
{
    for (int i = 0; i < size; i++)
    {
        ans[i] = arr[size - i - 1];
    }
}

void printArray(int *arr, int size)
{
    if (size == 0)
    {
        cout << "Empty";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << "\t" << arr[i];
        }
    }
    cout << endl;
}

int main()
{
    int arr1[] = {4, 1, 8, 16, 2};
    int arr2[SIZE];
    sortArray(arr1, arr2, SIZE);
    int arr3[SIZE];
    reverseArray(arr1, arr3, SIZE);

    cout << "arr1: ";
    printArray(arr1, SIZE);

    cout << "Sum of arr1: ";
    cout << sumArray(arr1, SIZE) << endl;

    cout << "arr2: ";
    printArray(arr2, SIZE);

    cout << "arr3: ";
    printArray(arr3, SIZE);
    return 0;
}
