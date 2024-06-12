#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
    int size;

	struct Node
	{
		T data;
		Node* next;
		Node* previous;
	};

	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode;
			newNode->next = head;
			head = newNode;
			newNode->data = data;
		}

		size++;
	}

	void PopFront()
	{
		if (haed != nullptr)
		{
			if (size == 1)
			{

			}
		}
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (tail == nullptr)
		{
			tail = newNode;
			head = tail;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}

		size++;
	}

	void PopBack()
	{
		if (tail != nullptr)
		{
			if (size == 1)
			{
				Node* deleteNode = tail;
				head = nullptr;
				tail = nullptr;
				delete deleteNode;
			}
			else
			{
				Node* deleteNode = tail;
				tail = tail->previous;
				tail->next = nullptr;
				delete deleteNode;
			}

		}
		else
		{
			cout << "Linked List is Empty" << endl;
		}

		size--;
	}

	int & size()
	{
		return size;
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
	DoubleLinkedList<int> list;
	list.PushFront(15);
	list.PushFront(25);
	list.PushFront(35);
	cout << "DoubleLinkedList의 size는 : " << list.size() << endl;
	list.Show();
    return 0;
}
