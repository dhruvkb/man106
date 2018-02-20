#include <iostream>

using namespace std;

int main()
{
    int a[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = 0;
        }
    }

    int *p;
    p = &a[0][0];
    p++;

    if (p == &a[0][1])
    {
        cout << "Row major" << endl;
    }
    else if (p == &a[1][0])
    {
        cout << "Column major" << endl;
    }
    else
    {
        cout << "Unknown behavior" << endl;
    }

    return 0;
}
