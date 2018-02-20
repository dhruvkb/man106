#include <iostream>
#define M 2
#define N 3

using namespace std;

void elemCol(int **arr, int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "\t" << arr[j][i];
        }
    }
    cout << endl;
}

void elemRow(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "\t" << arr[i][j];
        }
    }
    cout << endl;
}

void addrCol(int **arr, int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "\t" << &arr[j][i];
        }
    }
    cout << endl;
}

void addrRow(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "\t" << &arr[i][j];
        }
    }
    cout << endl;
}

int main()
{
    int **A = new int *[M];
    for (int i = 0; i < M; i++)
    {
        A[i] = new int[N];
    }

    cout << "Enter elements of " << M << "x" << N << " matrix: " << endl;
    for (int r = 0; r < M; r++)
    {
        for (int c = 0; c < N; c++)
        {
            cin >> A[r][c];
        }
    }

    cout << "Elem col-wise:";
    elemCol(A, M, N);
    cout << "Elem row-wise:";
    elemRow(A, M, N);
    cout << "Addr col-wise:";
    addrCol(A, M, N);
    cout << "Addr row-wise:";
    addrRow(A, M, N);

    return 0;
}
