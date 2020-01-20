// Q2004
// 조합 0의 개수
// 시간복잡도 - O(n)

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    long long num2 = 0;
    long long num5 = 0;

    cin >> m >> n;

    for(long long i=2;i<=m;i*=2)
    {
        num2 += m/i;
    }
    for(long long i=2;i<=(m-n);i*=2)
    {
        num2 -= (m-n)/i;
    }
    for(long long i=2;i<=n;i*=2)
    {
        num2 -= n/i;
    }
    
    for(long long i=5;i<=m;i*=5)
    {
        num5 += m/i;
    }
    for(long long i=5;i<=(m-n);i*=5)
    {
        num5 -= (m-n)/i;
    }
    for(long long i=5;i<=n;i*=5)
    {
        num5 -= n/i;
    }

    if(num5 > num2)
    {
        cout << num2 << '\n';
    }
    else
    {
        cout << num5 << '\n';
    }

    return 0;
}