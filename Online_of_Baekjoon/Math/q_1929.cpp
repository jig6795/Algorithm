// Q1929
// 소수 구하기
// 시간복잡도 - O(nlogn)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    cin >> m >> n;

    for(int i=m;i<=n;i++)
    {
        int check = 1;

        if(i == 1)
        {
            continue;
        }

        for(int j=2;j*j<=i;j++)
        {
            if(i%j == 0)
            {
                check = 0;
            }
        }

        if(check == 1)
        {
            cout << i << '\n';
        }
    }

    return 0;
}