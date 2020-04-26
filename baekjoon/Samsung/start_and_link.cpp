// 2020.04.26
// Q14889
// 스타트와 링크
// 실패

#include <iostream>

using namespace std;

#define MAX 21

int soccer_team[MAX][MAX]; // 서로의 시너지 점수를 적는 판
int N; // 총 참가하는 인원의 수


void showSoccerTeam(void)
{
    cout << "This is board of soccer team!" << '\n';
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout << soccer_team[i][j] << " ";
        }
        cout << '\n';
    }
}

void divideSoccerTeam(int numOfMember)
{
    

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> soccer_team[i][j];
        }
    }

    //showSoccerTeam();
    divideSoccerTeam(N);

    return 0;
}