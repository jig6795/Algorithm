// Q15652
// N과 M (4)

#include <iostream>

using namespace std;

int N,M;
int arr[9];

void solve(int cnt)
{
    if(M == cnt)
    {
        for(int i=0;i<M;i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=1;i<=N;i++)
    {
        if(arr[cnt-1] > i)
        {
            continue;
        }
        arr[cnt] = i;
        solve(cnt+1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    solve(0);

    return 0;
}