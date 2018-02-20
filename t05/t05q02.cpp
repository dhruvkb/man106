#include <iostream>
#include <stdexcept>

using namespace std;

struct Node
{
    char data;
    Node *prev;
};

class QueueLL
{
  private:
    Node *front;
    Node *back;

  public:
    QueueLL()
    {
        front = nullptr;
        back = nullptr;
    }

    ~QueueLL()
    {
        if (!isEmpty())
        {
            while(!isEmpty()) {
                cout << "Removed: " << remove() << endl;
            }
            cout << "Destructed" << endl;
        }
        else
        {
            cout << "Nothing to destruct" << endl;
        }
    }

    void add(char c)
    {
        Node *node = new Node;
        node->data = c;
        if (!isEmpty())
        {
            back->prev = node;
            back = node;
        }
        else
        {
            front = node;
            back = node;
        }
    }

    char remove()
    {
        if (!isEmpty())
        {
            Node *popped = front;
            char c = popped->data;
            front = popped->prev;
            if (popped == back)
            {
                back = nullptr;
            }
            delete popped;
            return c;
        }
        else
        {
            throw underflow_error("Empty queue");
        }
    }

    bool isEmpty()
    {
        return (!(front || back));
    }

    void print()
    {
        if (!isEmpty())
        {
            cout << "front ->";
            Node *trav = front;
            while (trav)
            {
                cout << "\t" << trav->data;
                trav = trav->prev;
            }
            cout << "\t<- back" << endl;
        }
        else
        {
            cout << "Empty queue" << endl;
        }
    }
};

int main()
{
    QueueLL q;
    q.print();
    q.add('a');
    q.print();
    q.add('b');
    q.print();
    q.add('c');
    q.print();
    cout << "Popped " << q.remove() << endl;
    q.print();
    cout << "Popped " << q.remove() << endl;
    q.print();
}