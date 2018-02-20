#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A[] = {10, 30, 40, 50, 70, 64, 43, 34, 56, 89};
    int B[] = {10, 50, 40, 78, 89, 23, 37, 57, 67};

    sort(begin(A), end(A));
    sort(begin(B), end(B));

    cout << "Symmetric difference: " << endl;

    int i = 0, j = 0;
    while (i < 10 && j < 9)
    {
        if (A[i] < B[j])
        {
            cout << "\t" << A[i];
            i++;
        }
        else if (A[i] > B[j])
        {
            cout << "\t" << B[j];
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    return 0;
}