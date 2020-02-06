// Q11727
// 2 x n 타일링 2
// 시간복잡도 - O(n)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int DP[1001];
    DP[0] = 1;
    DP[1] = 1;

    for(int i=2;i<=n;i++)
    {
        DP[i] = (DP[i-1] + (2*DP[i-2])) % 10007;
    }

    cout << DP[n];

    return 0;
}