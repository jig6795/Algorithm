// 2020.04.28
// Q15683
// 감시 -> 실패(너무 쉽게 생각한 느낌)

/* NxM 크기의 사무실에 K개의 CCTV가 있다.
.. 1 <= N,M <= 8
.. CCTV는 5가지 종류
.. 1) 한 방향 2) 서로 반대방향으로 두 방향
.. 3) 직각으로 두 방향 4) 세 방향 5) 네 방향
.. CCTV는 감시할 수 있는 방향의 칸 모두를 감시 가능
.. 이때, 벽 통과 X, CCTV는 통과 O, 사각지대 : 감시 X
.. ********** CCTV는 회전 가능 (단, 90도 방향, 가로&세로만) ****************
.. 지도에서 0: 빈 칸, 1~5: CCTV 번호, 6: 벽
.. 입력이 주어졌을 때, 사각 지대의 최소 크기를 구하라!
*/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 8

int map[MAX][MAX]; // 원래 지도
int copy_map[MAX][MAX]; // 복사한 지도
int temp_map[MAX][MAX]; // 임시 버퍼 지도
int N,M; // row, col

void showMap(int arr[MAX][MAX]) // 지도를 보여주는 함수
{
    cout << "--------------Map--------------" << '\n';
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

bool complete(void) // 더이상 감시할 구간이 없을 경우 종료
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(map[i][j] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void caseNumberOne(int _row, int _col) // 1번 CCTV 동작
{
    memcpy(temp_map,map,sizeof(map)); // 원본 저장
    int max_Nine = 0;
    int count = 0;
    //상
    for(int i=_row;i>=0;i--)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구
    //하
    for(int i=_row;i<N;i++)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구
    //좌
    for(int i=_col;i>=0;i--)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구
    //우
    for(int i=_col;i<M;i++)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }

    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
    }
    memcpy(map,temp_map,sizeof(map)); // 원본 복구
    memcpy(map,copy_map,sizeof(map)); // 마지막 가장 많은 감시 구역인 경우 복사
}

void caseNumberTwo(int _row, int _col) // 2번 CCTV 동작
{
    memcpy(temp_map,map,sizeof(map)); // 원본 저장
    int max_Nine = 0;
    int count = 0;
    //상하
    for(int i=_row;i>=0;i--)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }

    for(int i=_row;i<N;i++)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }

    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구

    // 좌우
    //좌
    for(int i=_col;i>=0;i--)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    //우
    for(int i=_col;i<M;i++)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }

    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
    }
    memcpy(map,temp_map,sizeof(map)); // 원본 복구
    memcpy(map,copy_map,sizeof(map)); // 마지막 가장 많은 감시 구역인 경우 복사
}

void caseNumberThree(int _row, int _col) // 3번 CCTV 동작
{
    memcpy(temp_map,map,sizeof(map)); // 원본 저장
    int max_Nine = 0;
    int count = 0;
    // 상좌
    for(int i=_row;i>=0;i--)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_col;i>=0;i--)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구

    // 상우
    for(int i=_row;i>=0;i--)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_col;i<M;i++)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구

    // 하좌
    for(int i=_row;i<N;i++)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_col;i>=0;i--)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구

    // 하우
    for(int i=_row;i<N;i++)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_col;i<M;i++)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
    }
    memcpy(map,temp_map,sizeof(map)); // 원본 복구
    memcpy(map,copy_map,sizeof(map)); // 마지막 가장 많은 감시 구역인 경우 복사
}

void caseNumberFour(int _row, int _col) // 4번 CCTV 동작
{
    memcpy(temp_map,map,sizeof(map)); // 원본 저장
    int max_Nine = 0;
    int count = 0;

    // 상좌우
    for(int i=_row;i>=0;i--)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_col;i>=0;i--)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    for(int i=_col;i<M;i++)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구
    
    // 하좌우
    for(int i=_row;i<N;i++)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_col;i>=0;i--)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    for(int i=_col;i<M;i++)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구

    // 상하좌
    for(int i=_row;i>=0;i--)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_row;i<N;i++)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_col;i>=0;i--)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
        max_Nine = count;
    }
    count = 0;
    memcpy(map,temp_map,sizeof(map)); // 원본 복구

    // 상하우
    for(int i=_row;i>=0;i--)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_row;i<N;i++)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            count += 1;
            map[i][_col] = 9;
        }
    }
    for(int i=_col;i<M;i++)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            count += 1;
            map[_row][i] = 9;
        }
    }
    if(max_Nine < count)
    {
        memcpy(copy_map,map,sizeof(map)); // 감시 가능 구역 표시
    }
    memcpy(map,temp_map,sizeof(map)); // 원본 복구
    memcpy(map,copy_map,sizeof(map)); // 마지막 가장 많은 감시 구역인 경우 복사
}

void caseNumberFive(int _row, int _col) // 5번 CCTV 동작
{
    //상,하,좌,우 확인
    //상
    for(int i=_row;i>=0;i--)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            map[i][_col] = 9;
        }
    }
    //하
    for(int i=_row;i<N;i++)
    {
        if(map[i][_col] == 6)
        {
            break;
        }
        else if(map[i][_col] == 0)
        {
            map[i][_col] = 9;
        }
    }
    //좌
    for(int i=_col;i>=0;i--)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            map[_row][i] = 9;
        }
    }
    //우
    for(int i=_col;i<M;i++)
    {
        if(map[_row][i] == 6)
        {
            break;
        }
        else if(map[_row][i] == 0)
        {
            map[_row][i] = 9;
        }
    }
}

void checkCCTVNum(int CCTV_Num, int _row, int _col) // CCTV 번호에 따라 동작 선택
{
    if(complete() == true)
    {
        switch(CCTV_Num)
        {
            case 5:
                caseNumberFive(_row, _col);
                break;
            case 4:
                caseNumberFour(_row, _col);
                break;
            case 3:
                caseNumberThree(_row, _col);
                break;
            case 2:
                caseNumberTwo(_row, _col);
                break;
            case 1:
                caseNumberOne(_row, _col);
                break;
            default:
                cout << "Error!" << '\n';
                break;
        }
    }
    else
    {
        return;
    }
}

void solve(void)
{
    int find_CCTV_Num = 5; // 찾고자 하는 CCTV 번호
    while(find_CCTV_Num != 0) // CCTV 5번부터 1번까지 차례대로 진행
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(map[i][j] == find_CCTV_Num) // CCTV를 찾았을 때
                {
                    checkCCTVNum(find_CCTV_Num,i,j);
                }
            }
        }
        find_CCTV_Num -= 1;
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 입력
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> map[i][j];
        }
    }
    solve();
    //showMap(map);
    // 사각지대 확인
    int nonVisibleCount = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(map[i][j] == 0)
            {
                nonVisibleCount += 1;
            }
        }
    }
    
    cout << nonVisibleCount << '\n';
    return 0;
}