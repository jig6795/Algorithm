//실패 - 시간초과
//2차원 배열로 표현된 땅을 1차원으로 바꿔 표현한다면 시간 초과를 없앨 수 있을 것 같다.
#include <iostream>
#include <math.h>

using namespace std;

int N, L, R; //나라의 크기, 최저, 최대
int map[51][51]; //나라가 존재하는 땅
int move_human[51][51] = {0}; //이동이 가능하면 value, 불가능하면 0
int possible = 0;

//
// 한번 이동을 마치면 0으로 초기화
//
void initMoveHuman()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            move_human[i][j] = 0;
        }
    }
}

//
// 입력을 통해 인구 지도를 생성
//
void makeMap(void)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> map[i][j];
        }
    }
}

//
// 같은 연합인지 확인
//
void findSameDomain(int _value,int change)
{
    if(_value == 0)
    {
        return;
    }

    //같은 연합인 경우를 찾는다.
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(move_human[i][j] == _value)
            {
                move_human[i][j] = change;
            }
        }
    }
}

//
// 인구 이동이 가능한지 확인
//
void possibleCheck(int r, int c, int value)
{
    bool poss = false;

    //상
    if(abs(map[r][c] - map[r-1][c]) >= L && abs(map[r][c] - map[r-1][c]) <= R && (r-1) >= 0)
    {
        findSameDomain(move_human[r-1][c],value);
        move_human[r-1][c] = value;
        poss = true;
        possible = 1;
    }

    //하
    if(abs(map[r][c] - map[r+1][c]) >= L && abs(map[r][c] - map[r+1][c]) <= R && (r+1) < N)
    {
        findSameDomain(move_human[r+1][c],value);
        move_human[r+1][c] = value;
        poss = true;
        possible = 1;
    }

    //좌
    if(abs(map[r][c] - map[r][c-1]) >= L && abs(map[r][c] - map[r][c-1]) <= R && (c-1) >= 0)
    {
        findSameDomain(move_human[r][c-1],value);
        move_human[r][c-1] = value;
        poss = true;
        possible = 1;
    }

    //우
    if(abs(map[r][c] - map[r][c+1]) >= L && abs(map[r][c] - map[r][c+1]) <= R && (c+1) < N)
    {
        findSameDomain(move_human[r][c+1],value);
        move_human[r][c+1] = value;
        poss = true;
        possible = 1;
    }

    if(poss) //변경이 있는 경우, 자신도 바꾼다.
    {
        move_human[r][c] = value;
    }
}

//
// 인구를 모든 나라에 동등하게 나눈다.
//
void cal(int _sum, int _cnt, int __index)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(move_human[i][j] == __index)
            {
                map[i][j] = _sum / _cnt;
            }
        }
    }
}

//
// 인구 이동에 대한 계산
//
void calAmountOfHuman(int _index)
{
    int sum = 0;
    int cnt = 0;
    for(int k=_index;k>0;k--)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(move_human[i][j] == k)
                {
                    sum += map[i][j];
                    cnt += 1;
                }
            }
        }
        cal(sum, cnt, k);
        sum = 0;
        cnt = 0;
    }
}

//
// 인구 이동을 했는지 확인
//
bool checkMove()
{
    int index= 1;

    //모든 나라를 확인하면서 주변의 국가와 인구 이동이 가능한지 확인한다.
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            possibleCheck(i,j,index);
            index += 1;
        }
    }

    calAmountOfHuman(index);

    if(possible == 1)
    {
        possible = 0;
        return true;
    }
    return false;
}

int main(void)
{
    cin >> N >> L >> R;
    int count = 0;

    makeMap();

    while(checkMove())
    {
        count += 1;

        initMoveHuman();
    }

    cout << count << endl;

    return 0;
}