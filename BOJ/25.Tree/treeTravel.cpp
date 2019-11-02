//https://www.acmicpc.net/problem/1991
#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    char value;
    NODE *left;
    NODE *right;
};

int n;
NODE root;
NODE *searchNode(NODE *start, char value);
void preOrder(NODE *node);
void inOrder(NODE *node);
void postOrder(NODE *node);

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char p, l, r;
        cin >> p >> l >> r;
        if (p == 'A')
        {
            root.value = p;
            NODE *leftChild = new NODE;
            NODE *rightChild = new NODE;
            if (l != '.')
            {
                leftChild->value = l;
                root.left = leftChild;
            }
            if (r != '.')
            {
                rightChild->value = r;
                root.right = rightChild;
            }
        }
        else
        {
            NODE *parent = searchNode(&root, p);
            NODE *leftChild = new NODE;
            NODE *rightChild = new NODE;
            parent->left = NULL, parent->right = NULL;

            if (l != '.')
            {
                leftChild->value = l;
                parent->left = leftChild;
            }
            if (r != '.')
            {
                rightChild->value = r;
                parent->right = rightChild;
            }
        }
    }

    preOrder(&root);
    cout << '\n';
    inOrder(&root);
    cout << '\n';
    postOrder(&root);
    cout << '\n';
    return 0;
}

NODE *searchNode(NODE *node, char value)
{
    if (node != NULL)
    {
        if (node->value == value)
        {
            return node;
        }
        else
        {
            NODE *t = searchNode(node->left, value);
            if (t != NULL)
            {
                return t;
            }

            return searchNode(node->right, value);
        }
    }
    return NULL;
}

void preOrder(NODE *node)
{
    if (node != NULL)
        cout << node->value;
    if (node->left != NULL)
        preOrder(node->left);
    if (node->right != NULL)
        preOrder(node->right);
}

void inOrder(NODE *node)
{
    if (node->left != NULL)
        inOrder(node->left);
    if (node != NULL)
        cout << node->value;
    if (node->right != NULL)
        inOrder(node->right);
}

void postOrder(NODE *node)
{
    if (node->left != NULL)
        postOrder(node->left);
    if (node->right != NULL)
        postOrder(node->right);
    if (node != NULL)
        cout << node->value;
}