#include <iostream>
#define SIZE 10

using namespace std;

int partialSumArray(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            sum += arr[i];
        }
    }
    return sum;
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
    int A[] = {10, 20, 44, 23, -12, 34, -67, 45, -48, 78};

    cout << "A: ";
    printArray(A, SIZE);

    cout << "Partial sum of A: ";
    cout << partialSumArray(A, SIZE) << endl;

    cout << "Enter size of B: ";
    int size;
    cin >> size;

    cout << "Enter elements of B: ";
    int *B = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> B[i];
    }

    cout << "B: ";
    printArray(B, size);

    cout << "Partial sum of B: ";
    cout << partialSumArray(B, size) << endl;

    return 0;
}
