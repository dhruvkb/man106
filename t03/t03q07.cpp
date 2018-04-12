#include <iostream>
#define MAX 50

using namespace std;

class Queue
{
  private:
    char *queue;
    int front, back;

  public:
    Queue()
    {
        queue = new char[MAX];
        front = -1;
        back = -1;
    }

    void add(char i)
    {
        back++;
        queue[back] = i;
    }

    char remove()
    {
        front++;
        return queue[front];
    }

    bool overflow()
    {
        return back == MAX - 1;
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
                cout << queue[i] << " ";
            }
            cout << "<- rear" << endl;
        }
    }
};

int main()
{
    Queue q;
    q.add('a');
    q.display();
    q.add('b');
    q.display();
    q.add('c');
    q.display();
    cout << "Removed: " << q.remove() << endl;
    q.display();
    cout << "Removed: " << q.remove() << endl;
    q.display();
    cout << "Removed: " << q.remove() << endl;
    q.display();
}