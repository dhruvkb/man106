#include <iostream>
#include <cmath>

#define MAX 127

using namespace std;

class BinaryTree
{
  private:
    int *tree;
    int length;

  public:
    BinaryTree(int data)
    {
        tree = new int[MAX];
        for (int i = 0; i < MAX; i++)
        {
            tree[i] = -1;
        }
        tree[0] = data;
        length = 1;
    }

    int addNode(int parentIndex, char leftOrRight, int data)
    {
        int index;
        switch (leftOrRight)
        {
        case 'l':
            index = 2 * parentIndex + 1;
            break;
        case 'r':
            index = 2 * parentIndex + 2;
            break;
        }
        tree[index] = data;
        if (length < 2 * parentIndex + 3)
        {
            length = 2 * parentIndex + 3;
        }
        length = pow(2, ceil(log(length) / log(2))) - 1;
        return index;
    }

    void makeTree()
    {
        int two = addNode(0, 'l', 2);
        int three = addNode(0, 'r', 3);
        int four = addNode(two, 'l', 4);
        int five = addNode(two, 'r', 5);
        int six = addNode(three, 'r', 6);
    }

    void levelOrder()
    {
        for (int i = 0; i < length; i++)
        {
            if (tree[i] != -1)
            {

                cout << "\t" << tree[i];
            }
            else
            {
                cout << "\t_";
            }
        }
    }

    int search(int data)
    {
        for (int i = 0; i < length; i++)
        {
            if (data == tree[i])
            {
                return i;
            }
        }
        return -1;
    }

    int child(int index, char leftOrRight)
    {
        switch (leftOrRight)
        {
        case 'l':
            return tree[2 * index + 1];
        case 'r':
            return tree[2 * index + 2];
        }
    }
};

int main()
{
    BinaryTree btree(1);
    btree.makeTree();

    cout << "Level order: ";
    btree.levelOrder();
    cout << endl;

    cout << "Right child of 3: ";
    int child = btree.child(btree.search(3), 'r');
    if (child == -1)
    {
        cout << "_";
    }
    else
    {
        cout << child;
    }
    return 0;
}