// Q10953
// A+B
// ","가 존재 -> char c로 받는다.

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase, a, b, sum;
    char c;
    cin >> testCase;

    for(int i=0;i<testCase;i++)
    {
        cin >> a >> c >> b;
        sum = a + b;
        cout << sum << '\n';
    }

    return 0;
}