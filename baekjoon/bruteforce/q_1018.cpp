// Q1018
// 체스판 다시 칠하기

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 50;
string chess[MAX];

string whiteFirst[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string blackFirst[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"    
};

int countWhiteFirst(int y, int x)
{
    int cnt = 0;
    //y,x에서 +8까지 바꿔야하는 수를 count.
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            if (chess[i][j] != whiteFirst[i-y][j-x])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int countBlackFirst(int y, int x)
{
    int cnt = 0;
    //y,x에서 +8까지 바꿔야하는 수를 count.
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            if (chess[i][j] != blackFirst[i-y][j-x])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,N;
    cin >> M >> N;

    for(int i=0;i<M;i++)
    {
        cin >> chess[i];
    }

    int result = 99999999;
    for (int i = 0; i+7 < M; i++)
    {
        for (int j = 0; j+7 < N; j++)
        {
            result = min(result, min(countWhiteFirst(i,j), countBlackFirst(i,j)));
        }
    }

    cout << result << '\n';

    return 0;
}