#include <iostream>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

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

class List
{
  public:
    ListNode *first;
    List()
    {
        first = nullptr;
    }

    void add(int data)
    {
        ListNode *n = new ListNode();
        n->data = data;
        n->next = first;
        first = n;
    }
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
    BinaryTree(List list)
    {
        ListNode *head = list.first;
        Queue q;

        root = new Node();
        root->data = head->data;
        q.push(root);

        head = head->next;
        while (head)
        {
            Node *parent = q.pop();
            Node *leftChild = nullptr, *rightChild = nullptr;
            leftChild = new Node();
            leftChild->data = head->data;
            q.push(leftChild);
            head = head->next;
            if (head)
            {
                rightChild = new Node();
                rightChild->data = head->data;
                q.push(rightChild);
                head = head->next;
            }

            parent->left = leftChild;
            parent->right = rightChild;
        }
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

    int minDepth(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            return 1;
        }

        if (!node->left)
        {
            return minDepth(node->right) + 1;
        }

        if (!node->right)
        {
            return minDepth(node->left) + 1;
        }

        return max(minDepth(node->left), minDepth(node->right)) + 1;
    }
};

int main()
{
    List list;
    list.add(3);
    list.add(5);
    list.add(7);
    list.add(9);
    list.add(8);
    list.add(6);
    list.add(4);
    list.add(2);
    list.add(1);

    BinaryTree btree(list);

    btree.preOrderTraversal();
    cout << endl;

    btree.levelOrderTraversal();
    cout << endl;

    cout << "Minimum depth: " << btree.minDepth(btree.getRoot()) << endl;

    return 0;
}