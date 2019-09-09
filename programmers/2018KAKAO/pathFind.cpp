#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int x;
    int y;
    int value;
    Node *left = NULL;
    Node *right = NULL;
    Node(int x, int y, int value)
    {
        this->x = x;
        this->y = y;
        this->value = value;
    }
};

vector<int> v1;
vector<int> v2;
bool com(vector<int> &a, vector<int> &b)
{
    return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
}

vector<int> preorder(Node *node)
{
    if (node != NULL)
    {
        v1.push_back(node->value);
        preorder(node->left);
        preorder(node->right);
    }
    return v1;
}

vector<int> postorder(Node *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        v2.push_back(node->value);
    }
    return v2;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    for (int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i].push_back(i + 1);
    sort(nodeinfo.begin(), nodeinfo.end(), com);
    Node *root = new Node(nodeinfo[0][0], nodeinfo[0][1], nodeinfo[0][2]);

    for (int i = 1; i < nodeinfo.size(); i++)
    {
        Node *pNode = root;
        Node *nNode = new Node(nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2]);
        while (1)
        {
            if (pNode->x > nNode->x)
            {
                if (pNode->left == NULL)
                {
                    pNode->left = nNode;
                    break;
                }
                else
                {
                    pNode = pNode->left;
                    continue;
                }
            }
            else
            {
                if (pNode->right == NULL)
                {
                    pNode->right = nNode;
                    break;
                }
                else
                {
                    pNode = pNode->right;
                    continue;
                }
            }
        }
    }

    answer.push_back(preorder(root));
    answer.push_back(postorder(root));
    return answer;
}

int main(void)
{
    vector<vector<int>> nodeinfo = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
    solution(nodeinfo);
    return 0;
}