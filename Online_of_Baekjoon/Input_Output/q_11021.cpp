// Q11021
// A+B

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;

    int a, b, sum;

    for(int i=0;i<testCase;i++)
    {
        cin >> a >> b;
        sum = a + b;
        cout << "Case #" << i+1 << ": " << sum << '\n';
    }

    return 0;
}