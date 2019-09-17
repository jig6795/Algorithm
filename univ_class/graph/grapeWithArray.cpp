//Array를 활용한 undirected Graph
#include <iostream>
using namespace std;

#define VERTEX_CNT 4 //vertex의 갯수

int graph[VERTEX_CNT][VERTEX_CNT]; //2차원 배열을 선언

void addEdge(int v1, int v2)
{
    //undirected graph이기 때문에 양방향으로 이어줘야 한다.
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}

//인접한 vertex가 무엇인지 출력
void showAdjacentVertex(int v)
{
    for(int i=0;i<VERTEX_CNT;i++)
    {
        if(graph[v][i] == 1)
        {
            cout << i << " is " << v << "'s adjacent vertex" << endl;
        }
    }
}

int main(void)
{
    addEdge(0,1); //vertex 0, 1을 이어주는 Edge 추가
    addEdge(0,2); //vertex 0, 2을 이어주는 Edge 추가

    showAdjacentVertex(0); //0에 인접한 vertex 출력

    return 0;
}