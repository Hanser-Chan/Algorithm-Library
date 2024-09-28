#include <iostream>

using std::cout, std::endl;

class BiTree
{
public:
    int weight;
    BiTree *left;
    BiTree *right;

    // 构造函数
    BiTree(int w) : weight(w), left(nullptr), right(nullptr) {}

    // 插入节点
    void insert(int w)
    {
        if (w < weight)
        {
            if (left == nullptr)
            {
                left = new BiTree(w);
            }
            else
            {
                left->insert(w);
            }
        }
        else
        {
            if (right == nullptr)
            {
                right = new BiTree(w);
            }
            else
            {
                right->insert(w);
            }
        }
    }

        // 递归法中序遍历
    static void inorderTraversalRecursive(BiTree *root)
    {
        if (root == nullptr)
            return;

        // 递归遍历左子树
        inorderTraversalRecursive(root->left);
        // 输出根节点
        cout << root->weight << " ";
        // 递归遍历右子树
        inorderTraversalRecursive(root->right);
    }

    // 计算WPL
    static int calculateWPL(BiTree *root, int depth = 1)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->weight * depth;
        else
            return calculateWPL(root->left) + calculateWPL(root->right);
    }
};

// main函数测试二叉树插入和中序遍历
int main()
{
    // 创建根节点
    BiTree *root = new BiTree(10);

    // 插入节点
    int arr[] = {6, 15, 3, 8, 20};
    for (int i = 0; i < 5; ++i)
    {
        root->insert(arr[i]);
    }

    // 进行中序遍历
    cout << "中序遍历树:\n ";
    BiTree::inorderTraversalRecursive(root);
    cout << endl;
    cout << "该树带权路径长:\n"
         << BiTree::calculateWPL(root) << endl;

    return 0;
}
