#include <iostream>

using namespace std;

template<typename T>
class SingleLinkedList
{
private:
    int size;

    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;

public:
    SingleLinkedList()
    {
        size = 0;
        head = nullptr;
    }

    void PushFront(T data)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node* newnode = new Node;
            newnode->data = data;
            newnode->next = head;
            head = newnode;
        }

        size++;

    }

    void PopFront()
    {
        if (head != nullptr)
        {
            Node* deleteNode = head;
            head = deleteNode->next;
            delete deleteNode;
            size--;
        }
        else
        {
            cout << "Linked List is Empty" << endl;
        }
    }

    void PushBack(T data)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node* currentNode = head;
            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            Node* newNode = new Node;
            currentNode->next = newNode;
            newNode->data = data;
            newNode->next = nullptr;
        }
        size++;
    }

    void PopBack()
    {
        if (head != nullptr)
        {
            if (size == 1)
            {
                Node* deleteNode = head;
                head = deleteNode->next;
                delete deleteNode;
            }
            else
            {
                Node* deletNode = head;
                Node* previousNode = head;
                while (deletNode->next != nullptr)
                {
                    previousNode = deletNode;
                    deletNode = deletNode->next;
                }
                previousNode->next = deletNode->next;
                delete deletNode;
            }
            size--;
        }
        else
        {
            cout << "Linked List is Empty" << endl;
        }
    }

    void Show()
    {
        Node* currentNode = head;

        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }
    }

    ~SingleLinkedList()
    {
        if (head != nullptr)
        {
            while (head != nullptr)
            {
                PopBack();
            }

        }
    }

};

int main()
{
    SingleLinkedList<int> list;
    list.PushBack(10);
    list.PushBack(20);
    list.PushBack(30);
    list.PopBack();
    list.Show();

    return 0;
}
