﻿#include <iostream>

using namespace std;

int main()
{

#pragma region 인접 리스트

    // 그래프의 각 정점에 인접한 정점들을 연결 리스트로 표현하는 방법.

    // 장점
    // 그래프의 모든 간선의 수를 o(v + e)로 표현 가능.

    // 단점
    // 두 정점을 연결하는 간선을 조회하거나 정점의 차수를 알기 위해서는 정점의 인접 리스트를 모두 탐색해야하므로,
    // 정점의 차수만큼의 시간이 필요.

#pragma endregion


    return 0;
}