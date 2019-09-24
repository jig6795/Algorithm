/*
  <DFS>
  1. stack에서 pop
  2. visited에 표시한다.
  3. 인접한 vertex들을 stack에 넣는다. 단, 이미 visited인 경우는 제외
  위의 과정을 반복하면서 stack이 empty가 되면 탐색 종료
*/
#include <iostream>
#include <vector>

using namespace std;

int vertex_num = 0; //vertex의 갯수
vector<int> graph; //vertex를 이어주는 edge의 2차원 배열을 표현할 1차원 벡터를 만들어줍니다.
int *stack; //동적으로 배열을 할당하기 위해 선언
int top = -1; //stack의 top변수
int *visited; //방문한 vertex에 대해 표시해주기 위한 배열

void push(int v) //push 함수
{
    if(top == vertex_num - 1)
    {
        cout << "Stack is full!" << endl;
        return;
    }
    top += 1;
    stack[top] = v;
}

int pop() //pop 함수
{
    if(top == -1)
    {
        return -999;
    }
    int temp = stack[top];
    top -= 1;
    return temp;
}

//2차원 배열의 원소들을 1차원 배열에 mapping시키는 방법 -> v1*VERTEX_NUM+v2
//이때 반대로 1차원에서 2차원으로 찾아가는 경우에는 몫(/)과 나머지(%)로 찾아가면 된다.
void addEdge(int v1,int v2) //2차원 배열의 좌표 값을 1차원 값으로 계산하여 edge를 표현
{
    graph[v1*vertex_num+v2] = 1;
    graph[v2*vertex_num+v1] = 1;
}

int inStack(int v) //stack에 들어있는지 확인하는 함수
{
    for(int i=0;i<=top;i++)
    {
        if(stack[i] == v)
        {
            return 0;
        }
    }
    return 1;
}

void doDFS(int v)
{
    int cur_vertex = 0;

    //시작 vertex를 stack에 넣어준다.
    push(v);

    //stack이 비어있지 않은 경우
    while(1)
    {
        cur_vertex = pop();

        if(cur_vertex == -999)
        {
            cout << "DFS is finish!" << endl;
            return;
        }

        cout << cur_vertex << endl;

        //stack에서 꺼낸 경우, 방문했음을 visited에 표시
        visited[cur_vertex] = 1;

        //인접한 vertex를 찾아 stack에 넣어준다.
        for(int i=cur_vertex*vertex_num;i<cur_vertex*vertex_num+vertex_num;i++) //반복은 항상 vertex_num만큼
        {
            //edge로 연결이 되어 있다면
            if(graph[i] == 1)
            {
                int adjacent_vertex = i - cur_vertex*vertex_num;

                //방문하지도 않은 상태이고 stack에도 없다면
                if(visited[adjacent_vertex] == 0 && inStack(adjacent_vertex) == 1)
                {
                    push(adjacent_vertex);
                }
            }
        }
    }
    return;
}

int main(void)
{
    cin >> vertex_num;

    //vertex^2만큼 벡터의 사이즈를 재조정합니다.
    //재조정한 크기 만큼 0으로 자동으로 채워집니다.
    graph.resize(vertex_num*vertex_num);

    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(4,2);
    addEdge(2,3);

    //stack, visited의 크기는 vertex의 갯수만큼만 만들어줍니다.
    stack = new int[vertex_num];
    visited = new int[vertex_num];

    doDFS(0);

    return 0;
}