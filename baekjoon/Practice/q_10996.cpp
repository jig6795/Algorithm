// Q10996
// 별 찍기 - 21
// 시간복잡도 - O(n^2)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n == 1)
    {
        cout << '*';
        return 0;
    }
    else
    {
        for(int i=1;i<=2*n;i++)
        {
            if(i%2 == 1) // 홀수
            {
                for(int j=1;j<=n;j++)
                {
                    if(j%2 == 1)
                    {
                        cout << '*';
                    }
                    else if(j%2 == 0)
                    {
                        cout << " ";
                    }
                }
                cout << '\n';
            }
            else if(i%2 == 0) // 짝수
            {
                for(int j=1;j<=n;j++)
                {
                    if(j%2 == 0)
                    {
                        cout << '*';
                    }
                    else if(j%2 == 1)
                    {
                        cout << " ";
                    }
                }
                cout << '\n';
            }
        }
    }

    return 0;
}