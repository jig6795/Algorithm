/*
  <BFS>
  1. queue에서 pop
  2. visited에 표시한다.
  3. 인접한 vertex들을 queue에 넣는다. 단, 이미 visited인 경우는 제외
  위의 과정을 반복하면서 queue가 empty가 되면 탐색 종료
*/
#include <iostream>
#include <vector>

using namespace std;

int vertex_num = 0; //vertex의 갯수
vector<int> graph; //vertex를 이어주는 edge의 2차원 배열을 표현할 1차원 벡터를 만들어줍니다.
int *queue; //동적으로 배열을 할당하기 위해 선언
//queue의 head, tail 변수
int head = 0;
int tail = 0;
int *visited;

//queue의 경우 circular이기 때문에 %연산을 해준다.
void enqueue(int v) //enqueue 함수 
{
    if((tail+1)%vertex_num == head)
    {
        cout << "Queue is full!" << endl;
        return;
    }
    queue[tail] = v;
    tail = (tail+1)%vertex_num;
}

int dequeue() //dequeue 함수
{
    int temp = -999;
    if(head != tail)
    {
        temp = queue[head];
        head = (head+1)%vertex_num;
    }
    return temp;
}

//2차원 배열의 원소들을 1차원 배열에 mapping시키는 방법 -> v1*VERTEX_NUM+v2
//이때 반대로 1차원에서 2차원으로 찾아가는 경우에는 몫(/)과 나머지(%)로 찾아가면 된다.
void addEdge(int v1,int v2) //2차원 배열의 좌표 값을 1차원 값으로 계산하여 edge를 표현
{
    graph[v1*vertex_num+v2] = 1;
    graph[v2*vertex_num+v1] = 1;
}

//DFS와 달리 tail까지 포함하지 않는 이유
//Stack의 경우, push를 진행할 때 top을 증가시키고 값을 대입하는 반면
//Queue의 경우, enqueue를 진행할 때는 값을 대입하고 tail을 증가시키기 때문이다.
int inQueue(int v)
{
    for(int i=head;i<tail;i++) 
    {
        if(queue[i] == v)
        {
            return 0;
        }
    }
    return 1;
}

void doBFS(int v)
{
    int cur_vertex;

    //Queue에 넣는다.
    enqueue(v);

    //Queue이 비어 있지 않다면
    while(1)
    {
        cur_vertex = dequeue();

        if(cur_vertex == -999)
        {
            cout << "BFS is finish!" << endl;
            return;
        }
        
        printf("%d\n",cur_vertex);
        //Queue에서 꺼내서 visited에 표시
        visited[cur_vertex] = 1;
        
        //인접한 vertex들을 찾아서 Queue에 enqueue
        for(int i=cur_vertex*vertex_num;i<cur_vertex*vertex_num+vertex_num;i++)
        {
            if(graph[i] == 1)
            {
                int adjacent_vertex = i - cur_vertex*vertex_num;

                if(visited[adjacent_vertex] == 0 && inQueue(adjacent_vertex) == 1)
                {
                    enqueue(adjacent_vertex);
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

    //queue, visited의 크기는 vertex의 갯수만큼만 만들어줍니다.
    queue = new int[vertex_num];
    visited = new int[vertex_num];

    doBFS(4);

    return 0;
}