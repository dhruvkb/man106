#include <iostream>
#include <cstring>

#define MAX 50

using namespace std;

class Stack
{
  private:
    char *stack;
    int top;

  public:
    Stack()
    {
        top = -1;
        stack = new char[MAX];
    }

    void push(char c)
    {
        top++;
        stack[top] = c;
    }

    char pop()
    {
        char c = stack[top];
        top--;
        return c;
    }

    bool emptyStack()
    {
        return top == -1;
    }

    bool fullStack()
    {
        return top == MAX - 1;
    }

    void print()
    {
        if (emptyStack())
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

void reverseString(char *in, char *out)
{
    Stack s;

    int inLen = strlen(in);
    for (int i = 0; i < inLen; i++)
    {
        s.push(in[i]);
    }

    cout << "Intermediate stack: ";
    s.print();

    int pos = 0;
    while (!s.emptyStack())
    {
        out[pos] = s.pop();
        pos++;
    }
}

bool areStringsEqual(char *one, char *two)
{
    int oneLen = strlen(one), twoLen = strlen(two);
    if (oneLen != twoLen)
    {
        return false;
    }
    for (int i = 0; i < oneLen; i++)
    {
        if (one[i] != two[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[MAX] = "hello";
    char *rev = new char[MAX];

    cout << "String: " << str << endl;
    reverseString(str, rev);
    cout << "Reverse: " << rev << endl;

    if (areStringsEqual(str, rev))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not a palindrome";
    }

    return 0;
}