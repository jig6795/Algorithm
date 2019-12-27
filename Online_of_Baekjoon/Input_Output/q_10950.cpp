// Q10950
// A+B

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase, a, b, sum;
    cin >> testCase;

    while(testCase != 0)
    {
        testCase -= 1;
        cin >> a >> b;

        sum = a + b;
        cout << sum << '\n';
    }

    return 0;
}