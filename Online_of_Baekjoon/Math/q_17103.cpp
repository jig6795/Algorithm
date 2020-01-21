// Q17103
// 골드바흐 파티션
// 시간복잡도 - O(nlogn)
// 실패

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int caseNum = 0;
    cin >> caseNum;

    int n = 0;
    for(int i=0;i<caseNum;i++)
    {
        int cnt = 0;
        cin >> n;

        if(n == 4)
        {
            cout << 1 << '\n';
            continue;
        }

        for(int i=3;i<=n/2;i+=2)
        {
            int check = 0;
            int temp = n - i;

            for(int j=2;j*j<=i;j++)
            {
                if(i%j == 0)
                {
                    check = 1;
                    break;
                }
            }

            for(int j=2;j*j<=temp;j++)
            {
                if(temp%j == 0 || check == 1)
                {
                    check = 1;
                    break;
                }
            }

            if(check == 0)
            {
                cnt += 1;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}