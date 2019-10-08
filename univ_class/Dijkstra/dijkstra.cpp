/*
  >> Dijkstra Algorithm - 최단경로를 찾는 알고리즘!
*/
#include <iostream>
#include <cstdio>

using namespace std;

#define VERTEX_NUM 5

struct vertex{
    int ver_num;
    int weight;
    struct vertex *next;
};

struct dijkstra{
    int found;
    int distance;
    int prev_vertex;
};

vertex *graph[VERTEX_NUM];
dijkstra dtable[VERTEX_NUM];

//vertex와 vertex를 이어주는 Edge들을 추가
void addEdge(int v1, int v2, int w, int doReverse)
{
    vertex *new_one = new vertex;
    vertex *cur = graph[v1];

    new_one->ver_num = v2;
    new_one->next = 0;
    new_one->weight = w;

    if(cur == 0) //v1에 아무것도 붙어있지 않은 상태
    {
        graph[v1] = new_one;
    }
    else         //v1에 이미 다른 vertex가 붙어있는 상태
    {
        while(cur->next != 0)
        {
            cur = cur->next;
        }
        cur->next = new_one;
    }
    
    if(doReverse == 1)
    {
        addEdge(v2,v1,w,0);
    }
}

//
// 최단거리가 알려지지 않은 vertex중에서 distance가 가장 짧은 vertex를 반환
// 모든 vertex의 최단거리가 알려졌을 경우 -1을 return
//
int findNextVertex()
{
    int smallest_distance = 99999;
    int smallest_vertex = -1;

    for(int i=0;i<VERTEX_NUM;i++)
    {
        if(dtable[i].found == 0 && dtable[i].distance < smallest_distance)
        {
            smallest_vertex = i;
            smallest_distance = dtable[i].distance;
        }
    }
    return smallest_vertex;
}

//table을 최신화시키는 함수
void updateDtable(int v)
{
    vertex *cur = graph[v];

    while(cur != 0)
    {
        //최단거리가 알려지지 않았고,
        //기존에 알려진 거리보다 v를 거칠 경우, 더 가까우면 dtable을 update
        if(dtable[cur->ver_num].found == 0 && dtable[cur->ver_num].distance > dtable[v].distance + cur->weight)
        {
            dtable[cur->ver_num].distance = dtable[v].distance + cur->weight;
            dtable[cur->ver_num].prev_vertex = v;
        }
        cur = cur->next;
    }
}

//dijkstra 함수
void doDijkstra(int v)
{
    int next_vertex = -1;

    dtable[v].distance = 0;

    while((next_vertex = findNextVertex()) != -1)
    {
        dtable[next_vertex].found = 1; //최단거리를 찾았다고 표시
        updateDtable(next_vertex);
    }

    for(int i=0;i<VERTEX_NUM;i++) //출력
    {
        printf("%d: %d %d %d \n",i,dtable[i].found,dtable[i].distance,dtable[i].prev_vertex);
    }
}

int main(void)
{
    addEdge(0,1,1,1);
    addEdge(0,2,3,1);
    addEdge(0,4,5,1);
    addEdge(1,2,2,1);
    addEdge(1,4,4,1);
    addEdge(2,3,7,1);
    addEdge(2,4,6,1);
    addEdge(3,4,8,1);

    //dtable을 초기화
    for(int i=0;i<VERTEX_NUM;i++)
    {
        dtable[i].found = 0;
        dtable[i].distance = 99999;
        dtable[i].prev_vertex = -1;
    }

    doDijkstra(0);

    return 0;
}