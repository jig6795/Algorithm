// Q15654
// N과 M (5)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 10001

int N,M;
int other_arr[MAX];
vector<int> _arr;

void solve(int cnt)
{
    if(M == cnt)
    {
        for(int i=0;i<M;i++)
        {
            cout << other_arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    bool check = true;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            if(other_arr[j] == _arr[i])
            {
                check = false;
                break;
            }
        }

        if(check == true)
        {
            other_arr[cnt] = _arr[i];
            solve(cnt+1);
        }
        check = true;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    int a=0;
    for(int i=0;i<N;i++)
    {
        cin >> a;
        _arr.push_back(a);
    }

    sort(_arr.begin(),_arr.end());

    solve(0);

    return 0;
}