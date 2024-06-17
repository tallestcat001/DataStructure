#include <iostream>

using namespace std;

template<typename T>
class CircleLinkedList
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

    CircleLinkedList()
    {
        size = 0;
        head = nullptr;
    }

    void PushBack(T data)
    {

        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }

        size++;

    }

    void PopBack()
    {
        Node* deleteNode = head;
        Node* currentNode = head;

        if (head != nullptr)
        {
            if (head == head->next)
            {
                head = nullptr;
                delete deleteNode;
            }
            else
            {
                for (int i = 0; i < size - 1; i++)
                {
                    currentNode = currentNode->next;
                }
                currentNode->next = head->next;
                head = currentNode;
                delete deleteNode;
            }

            size--;

        }
        else
        {
            cout << "Linked List is Empty" << endl;
        }
    }

    void PushFront(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;
            head->next = newNode;
        }

        size++;

    }

    void PopFront()
    {
        Node* deleteNode = head->next;

        if (head != nullptr)
        {
            if (head == head->next)
            {
                head = nullptr;
                delete deleteNode;
            }
            else
            {
                head->next = deleteNode->next;
                delete deleteNode;
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
        if (head != nullptr)
        {
            Node* currentNode = head->next;

            for (int i = 0; i < size; i++)
            {
                cout << currentNode->data << endl;
                currentNode = currentNode->next;
            }
        }
    }

    ~CircleLinkedList()
    {
        while (head != nullptr)
        {
            PopFront();
        }
    }

};

int main()
{
    CircleLinkedList<int> list;
    return 0;
}
