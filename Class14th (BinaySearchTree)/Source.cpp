#include <iostream>

using namespace std;

template<typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;

        Node* left;
        Node* right;
    };

    Node* root;

public:

    BinarySearchTree()
    {
        root = nullptr;
    }

    Node* Root()
    {
        return root;
    }

    Node* CreatNode(T data)
    {
        Node* newnode = new Node();

        newnode->data = data;

        newnode->left = nullptr;

        newnode->right = nullptr;

        return newnode;
    }

    void Insert(T data)
    {
        if (root == nullptr)
        {
            root = CreatNode(data);
        }
        else
        {
            Node* currentNode = root;

            while (currentNode != nullptr)
            {
                if (currentNode->data == data)
                {
                    return;
                }
                else if (currentNode->data > data)
                {
                    if (currentNode->left == nullptr)
                    {
                        currentNode->left = CreatNode(data);
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else
                {
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = CreatNode(data);
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }
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

    bool Find(T data)
    {
        Node* currentnode = root;

        if (currentnode == nullptr)
        {
            return false;
        }
        else
        {
            while (currentnode != nullptr)
            {
                if (currentnode->data == data)
                {
                    return true;
                }
                else
                {
                    if (currentnode->data > data)
                    {
                        currentnode = currentnode->left;
                    }
                    else
                    {
                        currentnode = currentnode->right;
                    }
                }
            }

            return false;

        }
    }

    void Destroy(Node* root)
    {
        if (root != nullptr)
        {
            Destroy(root->left);
            Destroy(root->right);
            delete root;
        }
    }

    ~BinarySearchTree()
    {
        Destroy(root);
    }

};

int main()
{
    BinarySearchTree<int> BST;



    BST.Insert(10);
    BST.Insert(7);
    BST.Insert(9);
    BST.Insert(4);
    BST.Insert(5);

    cout << BST.Find(9) << endl;

    BST.Inorder(BST.Root());

    return 0;
}