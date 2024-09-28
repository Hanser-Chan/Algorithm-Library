#include <iostream>

using std::cout, std::endl;

typedef struct node
{
    char data[10];
    struct node *left, *right;
} BTree;

BTree *initBTree()
{
    BTree *root = new BTree;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void insertBTree(BTree *root, char data[])
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL)
    {
        root->left = new BTree;
        strcpy(root->left->data, data);
        root->left->left = NULL;
        root->left->right = NULL;
    }
    else if (root->right == NULL)
    {
        root->right = new BTree;
        strcpy(root->right->data, data);
        root->right->left = NULL;
        root->right->right = NULL;
    }
    else
    {
        insertBTree(root->left, data);
    }
}

void inorderTraversal(BTree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

void printExpression(BTree *root, int d)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->data;
    }
    else
    {
        if (d > 1)
        {
            cout << "(";
        }
        printExpression(root->left, d + 1);
        cout << root->data;
        printExpression(root->right, d + 1);
        if (d > 1)
        {
            cout << ")";
        }
    }
}

int main()
{
    BTree *root = initBTree();
    char data[] = "test";
    insertBTree(root, data);
    inorderTraversal(root);
    return 0;
}
