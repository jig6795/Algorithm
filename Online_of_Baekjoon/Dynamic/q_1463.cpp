// Q1463
// 1로 만들기
// 시간복잡도 - O(n)

#include <iostream>
#include <algorithm>

using namespace std;

int DP[1000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=2;i<=n;i++)
    {
        DP[i] = DP[i-1] + 1;
        
        if(i%2 == 0)
        {
            DP[i] = min(DP[i], DP[i/2]+1);
        }
        
        if(i%3 == 0)
        {
            DP[i] = min(DP[i], DP[i/3]+1);
        }
    }

    cout << DP[n];

    return 0;
}