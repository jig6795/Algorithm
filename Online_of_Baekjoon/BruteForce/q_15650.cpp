// Q15650
// N과 M (2)
// BruteForce

#include <iostream>

using namespace  std;

int n, m;
int arr[9];
bool visited[9];

void check(int cnt)
{
    if(cnt == m)
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
        if(!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            if(arr[cnt-1] > arr[cnt])
            {
                visited[i] = false;
            }
            else
            {
                check(cnt+1);
                visited[i] = false;
            }
        }
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