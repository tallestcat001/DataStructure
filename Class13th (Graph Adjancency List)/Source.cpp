#include <iostream>

#define SIZE 10

using namespace std;

template<typename T>
class AdjancencyList
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(T data, Node* link = nullptr)
        {
            this->data = data;
            next = link;
        }
    };

    int size;
    T vertex[SIZE];
    Node* list[SIZE];

public:
    AdjancencyList()
    {
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            vertex[i] = NULL;
            list[i] = NULL;
        }

    }

    void Insert(T data)
    {
        if (size >= SIZE)
        {
            cout << "AdjancencyLIst OverFlow" << endl;
        }
        else
        {
            vertex[size++] = data;
        }
    }

    void Connect(int i, int j)
    {
        if (size <= 0)
        {
            cout << "AdjancencyList Is Empty" << endl;
        }
        else if (i >= size || j >= size)
        {
            cout << "Index Out Of Range" << endl;
        }
        else
        {
            list[i] = new Node(vertex[j], list[i]);
            list[j] = new Node(vertex[i], list[j]);
        }
    }

    void Show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << vertex[i] << " : ";

            Node* currentnode = list[i];

            while (currentnode != nullptr)
            {
                cout << currentnode->data << " ";

                currentnode = currentnode->next;
            }

            cout << endl;
        }
    }

    ~AdjancencyList()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (list[i] != nullptr)
            {
                delete[] list[i];
            }
        }
    }

};

int main()
{

#pragma region 인접 리스트

    // 그래프의 각 정점에 인접한 정점들을 연결 리스트로 표현하는 방법.

    // 장점
    // 그래프의 모든 간선의 수를 o(v + e)로 표현 가능.

    // 단점
    // 두 정점을 연결하는 간선을 조회하거나 정점의 차수를 알기 위해서는 정점의 인접 리스트를 모두 탐색해야하므로,
    // 정점의 차수만큼의 시간이 필요.

    AdjancencyList<char> ad;

    ad.Insert('A');
    ad.Insert('B');
    ad.Insert('C');
    ad.Insert('D');

    ad.Connect(0, 1);
    ad.Connect(0, 2);
    ad.Connect(2, 3);

    ad.Show();

#pragma endregion


    return 0;
}