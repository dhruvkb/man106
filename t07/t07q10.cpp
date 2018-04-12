#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
  private:
    Node *root;

  public:
    BST(int data)
    {
        root = new Node();
        root->data = data;
    }

    ~BST()
    {
        deleteRecursive(root);
    }

    void deleteRecursive(Node *node)
    {
        if (node->left)
        {
            deleteRecursive(node->left);
        }
        if (node->right)
        {
            deleteRecursive(node->right);
        }
        cout << "Deleting: " << node->data << endl;
        delete node;
    }

    Node *search(int query)
    {
        return searchRecursive(root, query);
    }

    Node *searchRecursive(Node *node, int query)
    {
        if (!root)
        {
            return nullptr;
        }
        if (root->data == query)
        {
            return root;
        }
        if (root->data > query)
        {
            return searchRecursive(root->left, query);
        }
        else
        {
            return searchRecursive(root->right, query);
        }
    }

    Node *insert(int data)
    {
        return insertRecursive(root, data);
    }

    Node *insertRecursive(Node *node, int data)
    {
        if (!node)
        {
            Node *newNode = new Node();
            newNode->data = data;
            return newNode;
        }

        if (data < node->data)
        {
            node->left = insertRecursive(node->left, data);
        }
        else
        {
            node->right = insertRecursive(node->right, data);
        }

        return node;
    }

    void inOrderTraversal()
    {
        return inOrder(root);
    }

    void inOrder(Node *node)
    {
        if (node->left)
        {
            inOrder(node->left);
        }
        cout << "\t" << node->data;
        if (node->right)
        {
            inOrder(node->right);
        }
    }
};

int main()
{
    BST bst(50);
    bst.insert(20);
    bst.insert(70);
    bst.insert(15);
    bst.insert(65);
    bst.insert(60);
    bst.insert(80);

    cout << "Sorted inorder traversal: ";
    bst.inOrderTraversal();
    cout << endl;

    return 0;
}