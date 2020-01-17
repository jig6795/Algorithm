// Q2609
// 최대공약수와 최소공배수
// 시간복잡도 - O(n)

#include <iostream>
using namespace std;

int gcd(int _a, int _b)
{
    while(_b != 0)
    {
        int r = _a % _b;
        _a = _b;
        _b = r;
    }
    return _a;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << '\n';
    cout << (a*b)/gcd(a,b) << '\n';

    return 0;
}