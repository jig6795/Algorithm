// Q1978
// 소수찾기
// 시간복잡도 - O(n^2)

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCaseNum = 0;
    cin >> testCaseNum;

    int countNum = 0;
    int checkNum = 0;
    for(int i=0;i<testCaseNum;i++)
    {
        cin >> checkNum;
        int check = 1;

        if(checkNum == 1)
        {
            continue;
        }

        for(int j=2;j<=checkNum/2;j++)
        {
            if(checkNum%j == 0)
            {
                check = 0;
                break;
            }
        }

        if(check == 1)
        {
            countNum += 1;
        }
    }

    cout << countNum << '\n';
    return 0;
}