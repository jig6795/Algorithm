// Q2523
// 별 찍기 - 13
// 시간복잡도 - O(n^2)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1;i<=2*n-1;i++)
    {
        if(i <= n)
        {
            for(int j=0;j<i;j++)
            {
                cout << '*';
            }
            cout << '\n';
        }
        else
        {
            for(int j=0;j<2*n-i;j++)
            {
                cout << '*';
            }
            cout << '\n';
        }
    }

    return 0;
}