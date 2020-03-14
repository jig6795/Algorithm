// Q10972
// 다음 순열
// 실패

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> testCase(10001);

void solution(void)
{

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i=1;i<=N;i++)
    {
        cin >> testCase[i];
    }

    bool check = true;
    for(int i=N;i>=1;i--)
    {
        if(testCase[N-i+1] == i)
        {
            check = false;
        }
        else if(testCase[N-i+1] != i)
        {
            check = true;
            break;
        }
    }

    if(check == false)
    {
        cout << -1 << '\n';
        return 0;
    }

    solution();

    return 0;
}