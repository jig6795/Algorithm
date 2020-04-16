// Q14502
// 연구소
// 실패

#include <iostream>
#include <cstring>

using namespace std;

int N,M;
int map[8][8];

void build_Wall(void) // 벽을 세운다.
{
    
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> map[i][j];
        }
    }

    build_Wall();

    return 0;
}