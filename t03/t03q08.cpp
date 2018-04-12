#include <iostream>
#include <stdexcept>

#define MAX 3

using namespace std;

class Cqueue
{
  private:
    int *queue;
    int front, rear, count;

  public:
    Cqueue()
    {
        queue = new int[MAX];
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void insert(int i)
    {
        if (count != MAX)
        {
            queue[rear] = i;
            rear = (rear + 1) % MAX;
            count++;
        }
        else
        {
            throw overflow_error("Queue is full");
        }
    }

    int remove()
    {
        if (count != 0)
        {
            int item = queue[front];
            front = (front + 1) % MAX;
            count--;
            return item;
        }
        else
        {
            throw underflow_error("Queue is empty");
        }
    }

    int getCount()
    {
        return count;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "Empty queue" << endl;
            return;
        }
        cout << "front ->";
        for (int i = 0; i < count; i++)
        {
            cout << "\t" << queue[(front + i) % MAX];
        }
        cout << "\t <-rear" << endl;
    }
};

int main()
{
    Cqueue cq;
    cq.display();

    cq.insert(1);
    cq.display();

    cq.insert(2);
    cq.display();

    cq.insert(3);
    cq.display();

    cout << "Popping: " << cq.remove() << endl;
    cq.display();

    cq.insert(4);
    cq.display();

    return 0;
}