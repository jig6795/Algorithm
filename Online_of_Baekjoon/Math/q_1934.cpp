// Q1934
// 최소공배수
// 시간복잡도 - O(n)

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCaseNum = 0;
    cin >> testCaseNum;

    int a, b;
    for(int i=0;i<testCaseNum;i++)
    {
        cin >> a >> b;
        int res = a * b;
        while(a != 0)
        {
            int r = b % a;
            b = a;
            a = r;
        }
        cout << res / b << '\n';
    }

    return 0;
}