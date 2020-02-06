// Q9095
// 1,2,3 더하기
// 시간복잡도 - O(n)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;

    int DP[11];
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;

    int n;

    for(int i=3;i<11;i++)
    {
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    }

    for(int i=0;i<testCase;i++)
    {
        cin >> n;
        cout << DP[n] << '\n';
    }

    return 0;
}