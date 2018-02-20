#include <iostream>
#define SIZE 10

using namespace std;

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
            if (i % 4 == 3)
            {
                cout << endl;
            }
        }
    }
}

int main()
{
    int A[SIZE], B[SIZE], C[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        A[i] = 10 * (i + 1);
        B[i] = i + 1;
        C[i] = A[i] + B[i];
    }

    cout << "A: " << endl;
    printArray(A, SIZE);
    cout << "B: " << endl;
    printArray(B, SIZE);
    cout << "C: " << endl;
    printArray(C, SIZE);

    return 0;
}
