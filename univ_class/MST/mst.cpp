/*
>> mst(minimum spanning tree) - 최소한의 edge를 이용해서 vertex를 연결한 tree (undirected / weighted 모두 가능)
    > edge의 갯수 = vertex - 1
                                                    cf)spanning tree - vertex가 모두 연결되어 있는 tree
    > 구현
    1. edge를 오름차순으로 sort
    2. mst를 구성하는 edge들을 하나씩 추가 <BUT 이미 연결된 vertex를 다시 연결하는 edge는 skip>
        -> cycle이 생기지 않도록 만들어 주면 된다.

    > 이미 연결이 되어있는지 어떻게 판단??
    1. 배열을 하나 만들어서 vertex 번호에 해당하는 family 번호를 확인하는 것 (family 번호 = vertex 번호)
    2. edge가 연결이 되었을 때, 낮은 vertex의 번호로 family 번호를 수정
*/
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define VERTEX_NUM 5
#define EDGES_NUM 8

//vertex에 대한 구조체
struct vertex{
    int ver_num;
    int weight;
    struct vertex *next;
};

//edge에 대한 구조체
struct edge{
    int from;
    int to;
    int w;
};

struct vertex *graph[VERTEX_NUM];
struct edge edges[EDGES_NUM];   //edge 정보가 들어갈 구조체

//cycle을 방지하기 위한 detection array
//각 vertex에 대한 group정보를 담고있다.
//연결시, group이 같을 경우 cycle이 생길 수 있다.
int cycledetection[VERTEX_NUM] = {0,1,2,3,4};

//오름차순으로 정렬
bool compare(struct edge e1, struct edge e2)
{
    if(e1.w < e2.w)
    {
        return 1;
    }
    return 0;
}

//vertex와 vertex를 이어주는 Edge들을 추가
void addEdge(int v1, int v2, int w)
{
    struct vertex *new_one = new struct vertex;
    struct vertex *cur = graph[v1];

    new_one->ver_num = v2;
    new_one->next = 0;
    new_one->weight = w;

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
    return;
}

//Edge들을 weight를 기반으로 정렬
void sortEdge()
{
    int edges_index = 0;
    
    //정렬하기 위해 edge들을 배열에 추가
    for(int i=0;i<VERTEX_NUM;i++)
    {
        struct vertex *cur = graph[i];
        
        while(cur != 0)
        {
            edges[edges_index].from = i;
            edges[edges_index].to = cur->ver_num;
            edges[edges_index].w = cur->weight;
            edges_index += 1;
            cur = cur->next;
        }
    }

    //sort function을 이용한 quick 정렬
    sort(edges,edges+EDGES_NUM,compare);
}

//edge를 연결하는 경우, cycle이 생기지 않는 전제하에
//group을 작은 vertex 쪽으로 맞춰주는 함수
void putSameGroup(int e1, int e2)
{
    int g1 = cycledetection[e1];
    int g2 = cycledetection[e2];
    int bigger, smaller;

    if(g1 > g2)
    {
        bigger = g1;
        smaller = g2;
    }
    else
    {
        bigger = g2;
        smaller = g1;
    }

    //group이 만들어지는 경우, 큰 쪽을 모두 작은 쪽으로 만들어준다.
    for(int i=0;i<VERTEX_NUM;i++) 
    {
        if(cycledetection[i] == bigger)
        {
            cycledetection[i] = smaller;
        }
    }
}

void doMST() //MST 함수
{
    int mst_index = 0;

    for(int i=0;i<EDGES_NUM;i++)
    {
        //cycle이 생기지 않는 경우
        if(cycledetection[edges[i].from] != cycledetection[edges[i].to])
        {
            cout << "MST edge " << edges[i].from << "----" << edges[i].to << "(" << edges[i].w << ")" << endl;
            mst_index += 1;

            if(mst_index == VERTEX_NUM-1)
            {
                return;
            }
            putSameGroup(edges[i].from,edges[i].to);
        }
    }
}

int main(void)
{
    addEdge(0,1,1);
    addEdge(0,2,3);
    addEdge(0,4,5);
    addEdge(1,2,2);
    addEdge(1,4,4);
    addEdge(2,3,7);
    addEdge(2,4,6);
    addEdge(3,4,8);

    sortEdge();

    doMST();

    return 0;
}