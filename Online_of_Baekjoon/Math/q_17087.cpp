// Q17087
// 숨바꼭질 6
// 시간복잡도 - O(n)

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<int> young(n);
    vector<int> loc(n);

    for(int i=0;i<n;i++)
    {
        cin >> young[i];
    }

    for(int i=0;i<n;i++)
    {
        loc[i] = abs(s - young[i]);
    }

    int ans = loc[0];
    for(int i=1;i<n;i++)
    {
        ans = gcd(ans,loc[i]);
    }

    cout << ans << '\n';
    
    return 0;
}