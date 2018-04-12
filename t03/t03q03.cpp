#include <iostream>
#define MAX 6

using namespace std;

class TwoStack
{
  private:
    int *stack;
    int topOne, bottomTwo;

  public:
    TwoStack()
    {
        stack = new int[MAX];
        topOne = -1;
        bottomTwo = MAX;
    }

    void push(int stackChoice, int val)
    {
        switch (stackChoice)
        {
        case 1:
            topOne++;
            stack[topOne] = val;
            break;
        case 2:
            bottomTwo--;
            stack[bottomTwo] = val;
            break;
        }
    }

    int pop(int stackChoice)
    {
        int val;
        switch (stackChoice)
        {
        case 1:
            val = stack[topOne];
            topOne--;
            break;
        case 2:
            val = stack[bottomTwo];
            bottomTwo++;
            break;
        }
        return val;
    }

    bool isEmpty(int stackChoice)
    {
        switch (stackChoice)
        {
        case 1:
            return topOne == -1;
        case 2:
            return bottomTwo == MAX;
        }
    }

    bool isFull()
    {
        return topOne + 1 == bottomTwo;
    }

    void print()
    {
        if (isEmpty(1))
        {
            cout << "Stack1 is empty" << endl;
        }
        else
        {
            cout << "Stack1: ";
            for (int i = 0; i <= topOne; i++)
            {
                cout << stack[i] << " ";
            }
            cout << "<- top" << endl;
        }
        if (isEmpty(2))
        {
            cout << "Stack2 is empty" << endl;
        }
        else
        {
            cout << "Stack2: ";
            for (int j = MAX - 1; j >= bottomTwo; j--)
            {
                cout << stack[j] << " ";
            }
            cout << "<- top" << endl;
        }
    }
};

int main()
{
    TwoStack ts;
    ts.print();
    ts.push(1, 1);
    ts.push(1, 2);
    ts.push(1, 3);
    ts.print();
    ts.push(2, 3);
    ts.push(2, 2);
    ts.push(2, 1);
    ts.print();
    cout << "Full? " << ts.isFull();
}