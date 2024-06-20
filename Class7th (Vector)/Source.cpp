#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
    int size;
    int capacity;
    T* container;
public:
    Vector()
    {
        size = 0;
        capacity = 0;
        container = nullptr;
    }

    void Resize(int Newsize)
    {
        capacity = Newsize;

        T* Newcontainer = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            Newcontainer[i] = NULL;
        }

        for (int i = 0; i < size; i++)
        {
            Newcontainer[i] = container[i];
        }

        if (container != nullptr)
        {
            delete[] container;
        }

        container = Newcontainer;
    }

    int& Size()
    {
        return size;
    }

    void PushBack(T data)
    {
        if (capacity <= 0)
        {
            Resize(1);
        }
        else if (size >= capacity)
        {
            Resize(capacity * 2);
        }

        container[size++] = data;
    }

    void PopBack()
    {
        if (size <= 0)
        {
            cout << "Vector is Empty" << endl;
        }
        else
        {
            container[--size] = NULL;
        }
    }

    void Reserve(int Newsize)
    {
        if (Newsize < capacity)
        {
            return;
        }

        Resize(Newsize);
    }

    T& operator [] (const int index)
    {
        return container[index];
    }

    ~Vector()
    {
        if (container != nullptr)
        {
            delete[] container;
        }
    }

};

int main()
{
    Vector<int> vector;
    vector.Reserve(10);
    vector.PushBack(10);
    vector.PushBack(20);
    vector.PushBack(30);
    vector.PopBack();

    for (int i = 0; i < vector.Size(); i++)
    {
        cout << vector[i] << endl;
    }

    return 0;
}
