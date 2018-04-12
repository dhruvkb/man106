#include <iostream>
#define MAX 50

using namespace std;

class Stack
{
  private:
    float *stack;
    int top;

  public:
    Stack()
    {
        top = -1;
        stack = new float[MAX];
    }

    void push(float f)
    {
        top++;
        stack[top] = f;
    }

    float pop()
    {
        float f = stack[top];
        top--;
        return f;
    }

    bool underflow()
    {
        return top == -1;
    }

    bool overflow()
    {
        return top == MAX - 1;
    }

    void print()
    {
        if (underflow())
        {
            cout << "Empty stack" << endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << stack[i] << " ";
            }
            cout << "<- top " << endl;
        }
    }
};

int main()
{
    cout << "All OK" << endl;
    return 0;
}