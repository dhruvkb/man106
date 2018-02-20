#include <iostream>
#include <stdexcept>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedListCircular
{
  private:
    Node *start;
    Node *end;

  public:
    LinkedListCircular()
    {
        start = nullptr;
        end = nullptr;
    }

    ~LinkedListCircular()
    {
        if (!isEmpty())
        {
            Node *trav;
            trav = start;
            while (true)
            {
                Node *todelete = trav;
                cout << "Removed: " << todelete->data << endl;
                delete todelete;
                trav = trav->next;
                if (trav == start)
                {
                    break;
                }
            }
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
        if (!isEmpty())
        {
            end->next = node;
        }
        else
        {
            start = node;
        }
        node->next = start;
        end = node;
    }

    bool isEmpty()
    {
        return (!start);
    }

    void print()
    {
        if (!isEmpty())
        {
            Node *trav;
            trav = start;
            while (true)
            {
                cout << "\t" << trav->data;
                trav = trav->next;
                if (trav == start)
                {
                    cout << "\tLooped";
                    break;
                }
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
    LinkedListCircular llc;
    llc.add(1);
    llc.print();
    llc.add(2);
    llc.print();
    llc.add(3);
    llc.print();
    llc.add(4);
    llc.print();
    return 0;
}