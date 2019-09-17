//SLL을 이용한 graph(with 구조체)
#include <iostream>
using namespace std;
#define VERTEX_CNT 4

struct Vertex{
    int ver_num; //vertex번호
    struct Vertex *next; //자신에게 인접한 vertex를 가리킨다.
};

struct Vertex *graph[VERTEX_CNT]; //각 vertex에 연결된 list를 저장

void addEdge(int v1, int v2)
{
    struct Vertex *new_one = new struct Vertex; //c에서 malloc과 같은 동적할당 new와 delete를 사용
    struct Vertex *cur = graph[v1];

    new_one->ver_num = v2;
    new_one->next = 0;

    if(cur == 0)
    {
        graph[v1] = new_one;
        return;
    }
    else
    {
        while(cur->next != 0)
        {
            cur = cur->next;
        }
        cur->next = new_one;
        return;
    }   
}

void showAdjacentVertex(int v)
{
    struct Vertex *cur = graph[v];

    while(cur != 0)
    {
        cout << cur->ver_num << " is " << v << "'s adjacent vertex" << endl;
        cur = cur->next;
    }
}

int main(void)
{
    //각각의 vertex에 edge를 연결해주어야 한다.
    addEdge(0,1);
    addEdge(1,0);
    addEdge(0,2);
    addEdge(2,0);

    showAdjacentVertex(0); //인접 vertex 출력

    return 0;
}