#include <iostream>
#include <stdexcept>
#include <cstring>

#define MAX 50

using namespace std;

struct Node
{
    char data;
    Node *prev;
};

class Stackll
{
  private:
    Node *top;

  public:
    Stackll()
    {
        top = nullptr;
    }

    ~Stackll()
    {
        if (!isEmpty())
        {
            while (!isEmpty()) {
                cout << "Removed: " << pop() << endl;
            }
            cout << "Destructed" << endl;
        }
        else
        {
            cout << "Nothing to destroy" << endl;
        }
    }

    void push(char c)
    {
        Node *node = new Node;
        node->data = c;
        node->prev = top;
        top = node;
    }

    char pop()
    {
        if (!isEmpty())
        {
            Node *popped = top;
            char c = popped->data;
            top = popped->prev;
            delete popped;
            return c;
        }
        else
        {
            throw underflow_error("Empty stack");
        }
    }

    bool emptyStack()
    {
        return isEmpty();
    }

    bool isEmpty()
    {
        return (!top);
    }

    void print()
    {
        if (!isEmpty())
        {
            Node *trav;
            trav = top;
            cout << "top ->";
            while (trav)
            {
                cout << "\t" << trav->data;
                trav = trav->prev;
            }
            cout << endl;
        }
        else
        {
            cout << "Empty stack" << endl;
        }
    }
};

void reverseString(char *in, char *out)
{
    Stackll s;

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
    char str[MAX] = "racecar";
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