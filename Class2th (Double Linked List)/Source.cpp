#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:

	int size;

	struct Node;

	Node* head;
	Node* tail;

public:

	struct Node
	{
		T data;
		Node* next;
		Node* previous;
	};

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
		if (head != nullptr)
		{
			if (head == tail)
			{
				Node* deleteNode = new Node;
				deleteNode = head;
				head = nullptr;
				tail = head;
				delete deleteNode;
			}
			else
			{
				Node* deleteNode = new Node;
				deleteNode = head;
				deleteNode->next->previous = nullptr;
				head = head->next;
				delete deleteNode;
			}
		}
		else
		{
			cout << "Linked List is Empty" << endl;
		}

		size--;
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

	Node* Begin()
	{
		return head;
	}

	void Insert(Node* Position, T data)
	{
		if (head == nullptr)
		{
			PushBack(data);
		}
		else
		{
			Node* previousNode = Position;
			Node* nextNode = Position->next;

			if (nextNode == nullptr)
			{
				PushBack(data);
			}
			else if (previousNode->previous == nullptr)
			{
				PushFront(data);
			}
			else
			{
				Node* newNode = new Node;
				newNode->data = data;
				newNode->next = nextNode;
				newNode->previous = previousNode;
				previousNode->next = newNode;
				nextNode->previous = newNode;

				size++;
			}
		}
	}

	int& Size()
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

	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			PopFront();
		}
	}

};

int main()
{
	DoubleLinkedList<int> list;
	list.PushFront(10);
	list.PushFront(20);
	list.PushFront(30);
	list.Insert(list.Begin()->next, 40);
	list.Show();
	cout << "현재 리스트의 size는 : " << list.Size() << endl;
	return 0;
}
