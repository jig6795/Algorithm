//SLL을 이용한 DFS
#include <iostream>
using namespace std;
#define VERTEX_NUM 5

//vertex를 위한 구조체
struct vertex{
    int ver_num; //vertex 번호
    struct vertex *next;
};

struct vertex *graph[VERTEX_NUM]; //자신과 연결되어 있는 vertex들을 이어붙일 배열
int visited[VERTEX_NUM]; //방문한 vertex를 표시하기 위한 배열
int stack[VERTEX_NUM];
int top = -1;

void push(int v) //push 함수
{
    if(top == VERTEX_NUM-1)
    {
        cout << "Stack is full!\n" << endl;
        return;
    }
    top += 1;
    stack[top] = v;
}

int pop() //pop 함수
{
    if(top == -1)
    {
        cout << "Stack is empty!\n" << endl;
        return -999;
    }
    int temp = stack[top];
    top -= 1;
    return temp;
}

void addEdge(int v1, int v2, int doReverse) //Edge를 연결해주는 함수
{
    struct vertex *new_one = new struct vertex;
    struct vertex *cur = graph[v1];

    new_one->ver_num = v2;
    new_one->next = 0;

    if(cur == 0) //현재 해당 vertex에 아무것도 연결이 안되어 있는 경우
    {
        graph[v1] = new_one;
    }
    else
    {
        while(cur->next != 0) //가장 마지막 vertex를 찾아가는 과정
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

int findNewVertex(int v) //인접한 vertex를 찾아주는 함수
{
    struct vertex *cur = graph[v];

    while(cur != 0)
    {
        if(visited[cur->ver_num] == 0)
        {
            return cur->ver_num;
        }
        cur = cur->next;
    }
    return -1; //방문을 완료한 경우
}

void doDFS(int v)
{
    cout << v << " is visited" << endl;
    push(v);
    visited[v] = 1;

    while(top != -1)
    {
        int next_vertex = -1;
        next_vertex = findNewVertex(stack[top]);

        if(next_vertex == -1)
        {
            pop();
        }
        else
        {
            cout << next_vertex << " is visited" << endl;
            push(next_vertex);
            visited[next_vertex] = 1;
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
    
    doDFS(0); //vertex 0에서 시작해서 DFS실행

    return 0;
}