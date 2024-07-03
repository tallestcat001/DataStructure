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

    void Remove(T data)
    {
        Node* currentnode = root;
        Node* parentnode = nullptr;

        if (root == nullptr)
        {
            cout << "BinarySearchTree is Empty" << endl;
        }
        else
        {
            while (currentnode != nullptr && currentnode->data != data)
            {
                if (currentnode->data > data)
                {
                    parentnode = currentnode;
                    currentnode = currentnode->left;
                }
                else
                {
                    parentnode = currentnode;
                    currentnode = currentnode->right;
                }
            }

            if (currentnode == nullptr)
            {
                cout << "Data Not Found in the BinarySearchTree" << endl;
            }
            else if (currentnode->left = nullptr && currentnode->right == nullptr)
            {
                if (parentnode != nullptr)
                {
                    if (parentnode->left == currentnode)
                    {
                        parentnode->left = nullptr;
                    }
                    else
                    {
                        parentnode->right = nullptr;
                    }
                }
                else
                {
                    root = nullptr;
                }
            }
            else if (currentnode->left == nullptr || currentnode->right == nullptr)
            {
                Node* childnode = nullptr;

                if (currentnode->left != nullptr)
                {
                    childnode = currentnode->left;
                }
                else
                {
                    childnode = currentnode->right;
                }

                if (parentnode != nullptr)
                {
                    if (parentnode->left == currentnode)
                    {
                        parentnode->left = childnode;
                    }
                    else
                    {
                        parentnode->right = childnode;
                    }
                }
            }
            else
            {
                Node* childenode = currentnode->right;
                Node* tracenode = childenode;

                while (childenode->left != nullptr)
                {
                    tracenode = childenode;
                    childenode = childenode->left;
                }

                currentnode->data = childenode->data;

                tracenode->left = childenode->right;

                delete childenode;

                return;
            }

            delete currentnode;
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
    BST.Insert(15);
    BST.Insert(3);
    BST.Insert(9);

    BST.Inorder(BST.Root());

    return 0;
}