#include <iostream>
#define MAX 50

using namespace std;

class Queue
{
  private:
    int *queue;
    int front, back;

  public:
    Queue()
    {
        queue = new int[MAX];
        front = -1;
        back = -1;
    }

    void add(int i)
    {
        back++;
        queue[back] = i;
    }

    int remove()
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
    q.add(1);
    q.display();
    q.add(2);
    q.display();
    q.add(3);
    q.display();
    cout << "Removed: " << q.remove() << endl;
    q.display();
    cout << "Removed: " << q.remove() << endl;
    q.display();
    cout << "Removed: " << q.remove() << endl;
    q.display();
}