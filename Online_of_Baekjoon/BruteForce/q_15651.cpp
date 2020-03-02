// Q15651
// N과 M (3)
// BruteForce

#include <iostream>

using namespace std;

int n, m;
int arr[8];

void check(int cnt)
{
    if(m == cnt)
    {
        for(int i=0;i<m;i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=1;i<=n;i++)
    {
        arr[cnt] = i;
        check(cnt+1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    check(0);

    return 0;
}