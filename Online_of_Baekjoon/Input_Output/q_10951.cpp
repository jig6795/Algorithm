// Q10951
// A+B

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, sum;

    while(cin >> a >> b) //입력이 있을 때까지 계속 반복
    {
        sum = a + b;
        cout << sum << '\n';
    }

    return 0;
}