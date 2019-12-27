// Q11022
// A+B

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase, a, b, sum;
    cin >> testCase;

    for(int i=0;i<testCase;i++)
    {
        cin >> a >> b;
        sum = a + b;
        cout << "Case #" << i+1 << ": " << a << " + " << b << " = " << sum << '\n';
    }

    return 0;
}