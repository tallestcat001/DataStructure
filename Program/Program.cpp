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
        if (head = nullptr)
        {
            head = new Node;
            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node* newnode = new Node;
            newnode->next = head;
            newnode->data = data;
            head = newnode;
        }

        size++;

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
};

int main()
{
    SingleLinkedList<int> list;
    list.PushFront(10);
    list.PushFront(20);
    list.Show();
}
