// Q11052
// 카드 구매하기
// 시간복잡도 - O(n^2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> DP(100001);
vector<int> card(1001);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> card[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            DP[i] = max(DP[i], DP[i-j]+card[j]);
        }
    }

    cout << DP[n];

    return 0;
}