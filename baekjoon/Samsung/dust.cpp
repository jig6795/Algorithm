#include <iostream>

using namespace std;

const int MAX = 50;

int R, C, T; //행, 열, 시간
int room[MAX][MAX]; //방에 들어있는 미세먼지 정보
int add[MAX][MAX]; //미세먼지가 나뉘면서 들어오는 양
int room_cnt = 0; //확산되는 방의 갯수

//
// 미세먼지가 들어있는 양을 출력 - 확인용
//
void printRoom(void)
{
    cout << "----Room----" << endl;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout << room[i][j] << " ";
        }
        cout << endl;
    }
}

//
// 미세먼지의 나뉜 양을 새로운 배열에 추가시켜준다.
//
void addDust(int amount_of_dust,int _r,int _c)
{
    //상
    if(room[_r][_c-1] >= 0 && (_c-1) >= 0)
    {
        add[_r][_c-1] += amount_of_dust;
        room_cnt += 1;
    }
    //하
    if(room[_r][_c+1] >= 0 && (_c+1) < C)
    {
        add[_r][_c+1] += amount_of_dust;
        room_cnt += 1;
    }
    //좌
    if(room[_r-1][_c] >= 0 && (_r-1) >= 0)
    {
        add[_r-1][_c] += amount_of_dust;
        room_cnt += 1;
    }
    //우
    if(room[_r+1][_c] >= 0 && (_r+1) < R)
    {
        add[_r+1][_c] += amount_of_dust;
        room_cnt += 1;
    }

    room[_r][_c] -= amount_of_dust*room_cnt;
    room_cnt = 0;
}

//
// 먼지의 확산되는 양을 계산하여 추가
//
void spreadDust(void)
{
    int amount_dust = 0; //확산되는 미세먼지 양

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(room[i][j] == -1)
            {
                continue;
            }

            amount_dust = room[i][j] / 5;

            addDust(amount_dust,i,j);
        }
    }
}

//
// 1초 후 나뉜 미세먼지의 양을 계산
//
void sumDust(void)
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            room[i][j] += add[i][j];
        }
    }

    //add 배열 초기화
    for(int k=0;k<R;k++)
    {
        for(int l=0;l<C;l++)
        {
            add[k][l] = 0;
        }
    }
}

//
// 반 시계 방향 회전
//
void reverseClock(int first)
{
    int temp = 0;
    int temp_before = 0;
    //좌로 이동
    for(int i=0;i<C;i++)
    {
        if(i == 0)
        {
            temp = room[0][0];
            continue;
        }
        room[0][i-1] = room[0][i];
    }
    //아래로 이동
    for(int j=first-1;j>=0;j--)
    {
        if(j == first-1)
        {
            temp_before = 0;
            continue;
        }
        else if(j == 0)
        {
            room[j+1][0] = temp;
            break;
        }
        room[j+1][0] = room[j][0];
    }
    //우로 이동
    for(int k=C-1;k>=0;k--)
    {
        if(k == C-1)
        {
            temp = room[first][k];
            continue;
        }
        else if(k == 0)
        {
            room[first][k+1] = temp_before;
            break;
        }
        room[first][k+1] = room[first][k];
    }
    //위로 이동
    for(int l=0;l<first;l++)
    {
        if(l == first-1)
        {
            room[l][C-1] = temp;
            break;
        }
        room[l][C-1] = room[l+1][C-1];
    }
}

//
// 시계 방향 회전
//
void clock(int second)
{
    int temp = 0;
    int temp_before = 0;

    //우로 이동
    for(int i=C-1;i>=0;i--)
    {
        if(i == C-1)
        {
            temp = room[second][i];
        }
        else if(i == 0)
        {
            room[second][i+1] = temp_before;
            break;
        }  
        room[second][i+1] = room[second][i];
    }
    //아래로 이동
    for(int j=R-1;j>=second;j--)
    {
        if(j == R-1)
        {
            temp_before = room[j][C-1];
            continue;
        }
        else if(j == second)
        {
            room[j+1][C-1] = temp;
            break;
        }
        room[j+1][C-1] = room[j][C-1];
    }
    //좌로 이동
    for(int k=0;k<C;k++)
    {
        if(k == 0)
        {
            temp = room[R-1][k];
            continue;
        }
        else if(k == C-1)
        {
            room[R-1][k-1] = temp_before;
            break;
        }
        room[R-1][k-1] = room[R-1][k];
    }
    //위로 이동
    for(int l=second+1;l<R;l++)
    {
        if(l == second+1)
        {
            temp_before = 0;
            continue;
        }
        else if(l == R-1)
        {
            room[l-1][0] = temp;
            break;
        }
        room[l-1][0] = room[l][0];
    }
}

//
// 미세먼지를 회전시키는 함수
// < 미세먼지가 -1(공기 청정기)를 만나면 0이 된다 >
//
void rotation(void)
{
    int first_row = 0;
    int second_row = 0;

    //공기 청정기 위치
    for(int i=2;i<R;i++)
    {
        if(room[i][0] == -1)
        {
            first_row = i;
            second_row = i+1;
            break;
        }
    }

    //반 시계방향 회전
    reverseClock(first_row);

    //시계 방향 회전
    clock(second_row);
}

int main(void)
{
    int sum = 0; //미세먼지의 총합을 계산하기 위한 변수

    cin >> R >> C >> T;

    //방의 미세먼지 정보 입력
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin >> room[i][j];
        }
    }

    // 1초마다 각 cycle을 반복한다.
    for(int j=0;j<T;j++)
    {
        spreadDust();

        sumDust();

        rotation();
    }

    //미세먼지의 총합을 계산
    for(int r=0;r<R;r++)
    {
        for(int c=0;c<C;c++)
        {
            if(room[r][c] == -1)
            {
                continue;
            }
            sum += room[r][c];
        }
    }

    cout << sum << endl;

    return 0;
}