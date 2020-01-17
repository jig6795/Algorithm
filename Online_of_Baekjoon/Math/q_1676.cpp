// Q1676
// 팩토리얼 0의 개수
// 시간복잡도 - O(n)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase = 0;
    cin >> testCase;

    int countOfFive = 0;
    for(int i=2;i<=testCase;i++)
    {
        int temp = i;
        
        if(temp%5 == 0)
        {
            while(temp%5 == 0)
            {
                temp = temp/5;
                countOfFive += 1;
            }
        }
    }

    cout << countOfFive << '\n';

    return 0;
}