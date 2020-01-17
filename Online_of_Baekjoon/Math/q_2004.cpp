// Q2004
// 조합 0의 개수
// 시간복잡도 - O(n^2)
// 실패 - 시간초과

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    cin >> n >> m;

    if(n-m > m) //조합 공식
    {
        m = n-m;
    }

    long long countOfUp = 0;
    long long countOfDown = 0;

    for(int i=1;i<=m;i++)
    {
        long long tempDown = i;
        long long tempUp = (n+1) - i;

        if(tempDown%5 == 0)
        {
            while(tempDown%5 == 0)
            {
                tempDown = tempDown/5;
                countOfDown += 1;
            }
        }
     
        if(tempUp%5 == 0)
        {
            while(tempUp%5 == 0)
            {
                tempUp = tempUp/5;
                countOfUp += 1;
            }
        }
    }

    cout << countOfUp - countOfDown << '\n';

    return 0;
}