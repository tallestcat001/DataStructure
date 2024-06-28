#include <iostream>

#define SIZE 10

using namespace std;

template<typename T>
class AdjacencyMatrix
{
private:
    int size; // 정점의 개수
    T vertex[SIZE]; // 정점의 집합
    int matrix[SIZE][SIZE]; // 인접 행렬
public:
    AdjacencyMatrix()
    {
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            vertex[i] = NULL;

            for (int j = 0; j < SIZE; j++)
            {
                matrix[i][j] = NULL;
            }
        }
    }

    void Insert(T data)
    {
        if (size >= SIZE)
        {
            cout << "AdjacencyMatrix OverFlow" << endl;
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
            cout << "AdjacencyMatrix is Empty" << endl;
        }
        else if (i >= size || j >= size)
        {
            cout << "Index Out Of Range" << endl;
        }
        else
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }

    void Show()
    {
        if (size <= 0)
        {
            cout << "AdjacencyMatrix is Empty" << endl;
        }
        else
        {
            cout << "    ";
            for (int i = 0; i < size; i++)
            {
                cout << vertex[i] << " ";
            }

            cout << endl;

            for (int i = 0; i < size; i++)
            {
                cout << vertex[i] << " : ";

                for (int j = 0; j < size; j++)
                {
                    cout << matrix[i][j] << " ";
                }

                cout << endl;
            }

        }
    }

};
int main()
{

#pragma region 그래프

    // 요소들이 서로 복잡하게 연결되어 있는 관계를 표현한는 자료구조 이며,
    // 정점과 간선들의 집합으로 이루어져 있음.


    // 정점(vertex)
    // 노드(node) 데이터가 저장되는 그래프의 기본 원소.

    // 간선(edge)
    // 노드들을 연결하는 선.

    // 인접 정점(adjacent vertex)
    // 간선으로 직접 연결된 정점.

    // 차수(degree)
    // 정점에 연결된 간선의 수.

    // 경로(path)
    // 정점들을 연결하는 간선들의 순서

#pragma endregion

#pragma region 인접 행렬

    // 정점들 간의 연결 관계를 2차원 배열로 표현하는 방식.
    // 정점의 개수가 v일때 v x v 크기의 2차원 배열을 사용.

    AdjacencyMatrix<char> am;

    am.Insert('A');
    am.Insert('B');
    am.Insert('C');
    am.Insert('D');

    am.Connect(0, 1);
    am.Connect(0, 2);
    am.Connect(2, 3);

    am.Show();

#pragma endregion

    return 0;
}