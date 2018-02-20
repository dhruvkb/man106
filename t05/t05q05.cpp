#include <iostream>
#include <stdexcept>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class OrderedLinkedList
{
  private:
    Node *first;

  public:
    OrderedLinkedList()
    {
        first = nullptr;
    }

    ~OrderedLinkedList()
    {
        if (!isEmpty())
        {
            Node *next = first;
            do
            {
                Node *todelete = next;
                next = todelete->next;
                cout << "Removed: " << todelete->data << endl;
                delete todelete;
            } while (next);
            cout << "Destructed" << endl;
        }
        else
        {
            cout << "Nothing to destruct" << endl;
        }
    }

    void add(int i)
    {
        Node *node = new Node;
        node->data = i;
        if (isEmpty())
        {
            first = node;
        }
        else if (i < first->data)
        {
            node->next = first;
            first = node;
        }
        else
        {
            Node *trav = first;
            while (true)
            {
                if (trav->next)
                {
                    if (trav->next->data > i)
                    {
                        break;
                    }
                    else
                    {
                        trav = trav->next;
                    }
                }
                else
                {
                    break;
                }
            }
            node->next = trav->next;
            trav->next = node;
        }
    }

    bool isEmpty()
    {
        return (!first);
    }

    void print()
    {
        if (!isEmpty())
        {
            Node *trav = first;
            while (trav)
            {
                cout << trav->data << " ";
                trav = trav->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Empty list" << endl;
        }
    }
};

int main()
{
    OrderedLinkedList oll;
    oll.add(5);
    oll.add(2);
    oll.add(1);
    oll.add(3);
    oll.add(4);
    oll.print();
    return 0;
}