// Q14502
// 연구소

#include <iostream>
#include <cstring>

using namespace std;

int N,M; // 가로, 세로
int map[8][8]; // 연구소 지도
int copy_map[8][8]; // 연구소 지도의 복사본
int wall_Count = 0; // 벽의 개수
int max_safe = 0; // 안전지대의 최대값
int safe_Count = 0;

// 상하좌우 확인
void checkUp(int row, int col);
void checkDown(int row, int col);
void checkLeft(int row, int col);
void checkRight(int row, int col);

void showMap(void) // 현재 연구소 상태를 표시
{
    cout << "Map is" << '\n';
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout << copy_map[i][j] << " ";
        }
        cout << '\n';
    }
}

void checkUp(int row, int col) // 바이러스가 위로 퍼져가는 현상
{
    for(int i=row;i>=0;i--)
    {
        if(copy_map[i][col] == 1)
        {
            return;
        }
        else if(copy_map[i][col] == 0)
        {
            copy_map[i][col] = 2;
            checkLeft(i,col);
            checkRight(i,col);
        }
    }
}

void checkDown(int row, int col) // 바이러스가 아래로 퍼져가는 현상
{
    for(int i=row;i<N;i++)
    {
        if(copy_map[i][col] == 1)
        {
            return;
        }
        else if(copy_map[i][col] == 0)
        {
            copy_map[i][col] = 2;
            checkLeft(i,col);
            checkRight(i,col);
        }
    }
}

void checkLeft(int row, int col) // 바이러스가 좌로 퍼져가는 현상
{
    for(int i=col;i>=0;i--)
    {
        if(copy_map[row][i] == 1)
        {
            return;
        }
        else if(copy_map[row][i] == 0)
        {
            copy_map[row][i] = 2;
            checkUp(row,i);
            checkDown(row,i);
        }
    }
}

void checkRight(int row, int col) // 바이러스가 우로 퍼져가는 현상
{
    for(int i=col;i<M;i++)
    {
        if(copy_map[row][i] == 1)
        {
            return;
        }
        else if(copy_map[row][i] == 0)
        {
            copy_map[row][i] = 2;
            checkUp(row,i);
            checkDown(row,i);
        }
    }
}

void check_Safe(void)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(copy_map[i][j] == 0)
            {
                safe_Count += 1;
            }
        }
    }

    if(safe_Count > max_safe)
    {
        max_safe = safe_Count;

        //showMap();
        //cout << "Max is " << max_safe << '\n';
    }
}

void checkVirusNum(void) // 바이러스가 퍼진 후의 안전지대 영역 확인
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(copy_map[i][j] == 2)
            {
                checkUp(i,j);
                checkDown(i,j);
                checkLeft(i,j);
                checkRight(i,j);
            }
        }
    }

    check_Safe();
    safe_Count = 0;
}

void build_Wall(void) // 벽을 세우는 함수
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            // 이미 존재하는 벽이거나 바이러스가 아니라면
            if(map[i][j] != 1 && map[i][j] != 2)
            {
                wall_Count += 1;
                map[i][j] = 1;

                if(wall_Count == 3)
                {
                    memcpy(copy_map,map,sizeof(map)); // 원본을 잃어버리지 않기 위함
                    checkVirusNum();
                    //showMap();
                    map[i][j] = 0;
                    wall_Count -= 1;
                }
                else
                { 
                    build_Wall();
                    map[i][j] = 0;
                }
            }
        }
    }
    wall_Count -= 1;
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

    cout << max_safe << '\n';

    return 0;
}