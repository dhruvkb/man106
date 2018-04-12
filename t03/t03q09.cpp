#include <iostream>
#define MAX 3

using namespace std;

class Deque
{
  private:
    int *deque;
    int front, back;

  public:
    Deque()
    {
        deque = new int[MAX];
        front = -1;
        back = -1;
    }

    void add(int sideChoice, int i)
    {
        if (overflow())
        {
            cout << "Overflow!" << endl;
            return;
        }
        switch (sideChoice)
        {
        case 1:
            deque[((front % MAX) + MAX) % MAX] = i;
            front--;
            break;
        case 2:
            back++;
            deque[((back % MAX) + MAX) % MAX] = i;
            break;
        }
    }

    int remove(int sideChoice)
    {
        if (underflow())
        {
            cout << "Underflow!" << endl;
            return NULL;
        }
        int val;
        switch (sideChoice)
        {
        case 1:
            front++;
            val = deque[((front % MAX) + MAX) % MAX];
        case 2:
            val = deque[((back % MAX) + MAX) % MAX];
            back--;
        }
        return val;
    }

    bool overflow()
    {
        int diff = back - front;
        return diff == MAX or diff == -MAX;
    }

    bool underflow()
    {
        return front == back;
    }

    void display()
    {
        if (underflow())
        {
            cout << "Empty queue" << endl;
        }
        else
        {
            cout << "front -> ";
            for (int i = front + 1; i <= back; i++)
            {
                cout << deque[((i % MAX) + MAX) % MAX] << " ";
            }
            cout << "<- rear" << endl;
        }
    }
};

int main()
{
    Deque d;

    d.display();
    d.add(1, 1);
    d.display();
    d.add(1, 2);
    d.display();
    d.add(2, 3);
    d.display();
    d.add(1, 4);
    d.display();

    cout << "Removed: " << d.remove(2) << endl;
    d.display();
    cout << "Removed: " << d.remove(2) << endl;
    d.display();
    cout << "Removed: " << d.remove(1) << endl;
    d.display();
    cout << "Removed: " << d.remove(1) << endl;
    d.display();

    return 0;
}