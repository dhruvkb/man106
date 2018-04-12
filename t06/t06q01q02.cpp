#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

struct QueueNode
{
    Node *data;
    QueueNode *prev;
};

class Queue
{
  private:
    QueueNode *front;
    QueueNode *back;

  public:
    Queue()
    {
        front = nullptr;
        back = nullptr;
    }

    void push(Node *n)
    {
        QueueNode *node = new QueueNode;
        node->data = n;
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

    Node *pop()
    {
        if (!isEmpty())
        {
            QueueNode *popped = front;
            Node *n = popped->data;
            front = popped->prev;
            if (popped == back)
            {
                back = nullptr;
            }
            delete popped;
            return n;
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
            QueueNode *trav = front;
            while (trav)
            {
                cout << "\t" << trav->data->data;
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

class BinaryTree
{
  private:
    Node *root;

  public:
    BinaryTree(int data)
    {
        root = new Node();
        root->data = data;
    }

    Node *getRoot()
    {
        return root;
    }

    Node *newNode(Node *parent, char leftOrRight, int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        switch (leftOrRight)
        {
        case 'l':
            parent->left = newNode;
            break;
        case 'r':
            parent->right = newNode;
            break;
        }
        return newNode;
    }

    void preOrderTraversal()
    {
        cout << "Preorder:" << endl;
        preOrder(root);
    }

    void preOrder(Node *node)
    {
        cout << "\t" << node->data;
        if (node->left)
        {
            preOrder(node->left);
        }
        if (node->right)
        {
            preOrder(node->right);
        }
    }

    void levelOrderTraversal()
    {
        cout << "Levelorder:" << endl;
        levelOrder(root);
    }

    void levelOrder(Node *node)
    {
        Queue q;
        Node *tempNode = node;
        while (tempNode)
        {
            cout << "\t" << tempNode->data;
            if (tempNode->left)
            {
                q.push(tempNode->left);
            }
            if (tempNode->right)
            {
                q.push(tempNode->right);
            };
            tempNode = nullptr;
            if (!q.isEmpty())
            {
                tempNode = q.pop();
            }
            else
            {
                tempNode = nullptr;
            }
        }
    }

    void makeTree()
    {
        Node *a = getRoot();
        Node *b = newNode(a, 'l', 2);
        Node *c = newNode(a, 'r', 3);
        Node *d = newNode(b, 'l', 4);
        Node *e = newNode(b, 'r', 5);
        Node *f = newNode(c, 'r', 6);
    }
};

int main()
{
    BinaryTree btree(1);
    btree.makeTree();

    btree.preOrderTraversal();
    cout << endl;

    btree.levelOrderTraversal();

    return 0;
}