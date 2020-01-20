// Q9613
// GCD 합
// 시간복잡도 - O(n^3)

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> num(100);

    int testCaseNum = 0;
    cin >> testCaseNum;

    int testNum = 0;
    for(int i=0;i<testCaseNum;i++)
    {
        long long sum = 0;
        cin >> testNum;

        for(int j=0;j<testNum;j++)
        {
            cin >> num[j];
        }

        for(int j=0;j<testNum-1;j++)
        {
            for(int k=j+1;k<testNum;k++)
            {
                sum += gcd(num[j],num[k]);
            }
        }

        cout << sum << '\n';
    }

    return 0;
}