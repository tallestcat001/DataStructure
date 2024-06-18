#include <iostream>

#define SIZE 5

using namespace std;

template<typename T>
class LinerQueue
{
private:
    int rear;
    int front;
    int size;
    T container[SIZE];
public:
    LinerQueue()
    {
        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }

        rear = 0;
        front = 0;
        size = 0;
    }

    void Push(T data)
    {
        if (rear >= SIZE)
        {
            cout << "Queue OverFlow" << endl;
        }
        else
        {
            container[rear++] = data;
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
            container[front++] = NULL;
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

    int Size()
    {
        return size;
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
    LinerQueue<int> queue;
    queue.Push(10);
    queue.Push(20);
    queue.Push(30);
    queue.Push(40);
    queue.Push(50);

    cout << "Back의 값은 :" << queue.Back() << endl;

    cout << "Size의 크기는 : " << queue.Size() << endl;

    while (queue.Empty() == false)
    {
        cout << queue.Front() << endl;
        queue.Pop();
    }

    return 0;
}
