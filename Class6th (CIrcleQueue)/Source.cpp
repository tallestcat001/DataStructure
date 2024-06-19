#include <iostream>

#define SIZE 5

using namespace std;

template<typename T>
class CircleQueue
{
private:
    int rear;
    int front;
    int size;
    T container[SIZE];
public:
    CircleQueue()
    {
        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }

        rear = SIZE - 1;
        front = SIZE - 1;
        size = 0;
    }

    void Push(T data)
    {
        if (front == (rear + 1) % SIZE)
        {
            cout << "CircleQueue OverFlow" << endl;
        }
        else
        {
            rear = (rear + 1) % SIZE;
            container[rear] = data;
            size++;
        }
    }

    void Pop()
    {
        if (Empty())
        {
            cout << "CircleQueue is Empty" << endl;
        }
        else
        {
            front = (front + 1) % SIZE;
            container[front] = NULL;
            size--;
        }
    }

    int& Size()
    {
        return size;
    }

    T& Front()
    {
        return container[(front + 1) % SIZE];
    }

    bool Empty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

int main()
{
    CircleQueue<char> queue;
    queue.Push('A');
    queue.Push('B');
    queue.Push('C');
    queue.Push('D');

    while (queue.Empty() == false)
    {
        cout << queue.Front() << endl;
        queue.Pop();
    }

    queue.Push('E');
    queue.Push('F');

    while (queue.Empty() == false)
    {
        cout << queue.Front() << endl;
        queue.Pop();
    }

    return 0;
}
