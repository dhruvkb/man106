#include <iostream>
#include <stdexcept>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
  private:
    Node *first;
    Node *last;
    int size;

  public:
    LinkedList()
    {
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    ~LinkedList()
    {
        if (!isEmpty()) {
            Node *next = first;
            do
            {
                Node *todelete = next;
                next = todelete->next;
                cout << "Removed: " << todelete->data << endl;
                delete todelete;
            } while (next);
            cout << "Destructed" << endl;
        } else {
            cout << "Nothing to destruct" << endl;
        }
    }

    void addToBeginning(int i)
    {
        Node *node = new Node;
        node->data = i;
        node->next = first;

        first = node;
        if (!last)
        {
            last = node;
        }
        size++;
    }

    void addToEnd(int i)
    {
        Node *node = new Node;
        node->data = i;

        // This block is different because
        // the list is 'next' oriented
        // rather than 'prev' oriented
        if (last)
        {
            last->next = node;
        }

        last = node;
        if (!first)
        {
            first = node;
        }
        size++;
    }

    void addRightOfIndex(int index, int i)
    {
        if (index >= size)
        {
            throw underflow_error("List not long enough");
        }
        else
        {
            Node *trav = first;
            for (int i = 0; i < index; i++)
            {
                trav = trav->next;
            }
            Node *node = new Node;
            node->data = i;
            node->next = trav->next;
            trav->next = node;
            size++;
        }
    }

    bool isEmpty() {
        return (size==0);
    }

    void print()
    {
        if (!isEmpty())
        {
            cout << "Size: " << size << endl;
            Node *trav = first;
            while (trav)
            {
                cout << "\t" << trav->data;
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
    LinkedList ll;
    ll.addToEnd(1);
    ll.print();
    ll.addToBeginning(2);
    ll.print();
    ll.addToBeginning(3);
    ll.print();
    ll.addToEnd(4);
    ll.print();
    ll.addToBeginning(5);
    ll.print();
    ll.addRightOfIndex(2, 6);
    ll.print();
    ll.addRightOfIndex(0, 7);
    ll.print();
    ll.addRightOfIndex(6, 8);
    ll.print();
    return 0;
}