// Q10952
// A+B

#include <iostream>

using namespace  std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, sum;

    while(cin >> a >> b)
    {
        if(a == 0 && b == 0)
        {
            break;
        }
        sum = a + b;
        cout << sum << '\n';
    }

    return 0;
}