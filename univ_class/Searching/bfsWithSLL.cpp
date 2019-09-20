//BFS with SLL
#include <iostream>
using namespace std;

#define VERTEX_NUM 5

struct vertex{
    int ver_num; //vertex의 번호
    struct vertex *next; //다음 vertex
};

struct vertex *graph[VERTEX_NUM]; //자신과 연결되어 있는 vertex들을 이어붙일 배열
int visited[VERTEX_NUM]; //방문한 vertex를 표시하기 위한 배열
int queue[VERTEX_NUM];
int head = 0;
int tail = 0;

void enqueue(int v) //enqueue 함수
{
    if((tail+1)%VERTEX_NUM == head) //가득찬 경우
    {
        return;
    }
    queue[tail] = v;
    tail = (tail+1)%VERTEX_NUM;
}

int dequeue()
{
    int temp = -1; 
    if(tail != head) //비어 있지 않다면
    {
        temp = queue[head];
        head = (head+1)%VERTEX_NUM;
    }
    return temp;
}

void addEdge(int v1, int v2, int doReverse)
{
    struct vertex *new_one = new struct vertex;
    struct vertex *cur = graph[v1];

    new_one->ver_num = v2;
    new_one->next = 0;

    if(cur == 0)
    {
        graph[v1] = new_one;
    }
    else
    {
        while(cur->next != 0)
        {
            cur = cur->next;
        }
        cur->next = new_one;
    }

    //양쪽 vertex에 모두 연결을 해줘야 하기 때문에 재귀함수를 이용해서 연결
    if(doReverse == 1)
    {
        addEdge(v2, v1, 0);
    }

    return;
}

int findNewVertex(int v)
{
    struct vertex *cur = graph[v];

    while(cur != 0)
    {
        if(visited[cur->ver_num] == 0)
        {
            enqueue(cur->ver_num);
        }
        cur = cur->next;
    }

    return -1;
}

void doBFS(int v)
{
    enqueue(v);

    while(head != tail)
    {
        int temp = dequeue();

        if(visited[temp] == 0)
        {
            cout << temp << " is visited" << endl;
            visited[temp] = 1;
            findNewVertex(temp);
        }
    }
    return;
}

int main(void)
{
    addEdge(0,1,1);
    addEdge(0,2,1);
    addEdge(0,4,1);
    addEdge(1,2,1);
    addEdge(2,3,1);
    addEdge(2,4,1);
    addEdge(3,4,1);

    doBFS(0); //vertex 0에서 시작해서 BFS실행

    return 0;
}