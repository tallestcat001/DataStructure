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
            cout << "Queue OverFlow" << endl;
        }
        else
        {
            container[rear++ % SIZE] = data;
            size++;
        }
    }

    void Pop()
    {
        if (Empty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            container[front++ % SIZE] = NULL;
            size--;
        }
    }

    T& Front()
    {
        if (Empty())
        {
            exit(1);
        }
        else
        {
            return container[front];
        }
    }

    T& Back()
    {
        if (Empty())
        {
            exit(1);
        }
        else
        {
            return container[rear - 1];
        }
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
    CircleQueue<int> queue;
    queue.Push(10);
    queue.Push(20);
    queue.Push(30);
    queue.Push(40);

    while (queue.Empty() == false)
    {
        cout << queue.Front() << endl;
        queue.Pop();
    }
    
    queue.Push(50);
    cout << queue.Front() << endl;

    return 0;
}
