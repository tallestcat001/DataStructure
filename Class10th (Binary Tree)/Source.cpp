#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* CreatNode(int data, Node* left, Node* right)
{
    Node* newNode = new Node;

    newNode->data = data;

    newNode->left = left;

    newNode->right = right;

    return newNode;
}

void Preorder(Node* root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(Node* root)
{
    if (root != nullptr)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void Postorder(Node* root)
{
    if (root != nullptr)
    {
        if (root != nullptr)
        {
            Postorder(root->left);
            Postorder(root->right);
            cout << root->data << " ";
        }
    }
}

int main()
{
    Node* node7 = CreatNode(7, nullptr, nullptr);
    Node* node6 = CreatNode(6, nullptr, nullptr);
    Node* node5 = CreatNode(5, nullptr, nullptr);
    Node* node4 = CreatNode(4, nullptr, nullptr);
    Node* node3 = CreatNode(3, node6, node7);
    Node* node2 = CreatNode(2, node4, node5);
    Node* node1 = CreatNode(1, node2, node3);

    Preorder(node1);
    cout << endl;
    Inorder(node1);
    cout << endl;
    Postorder(node1);

    return 0;
}
