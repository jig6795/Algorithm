// Q14681
// 사분면 고르기
// 시간복잡도 - O(1)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;
    cin >> a >> b;

    if(a > 0 && b > 0)
    {
        cout << 1 << '\n';
        return 0;
    }
    else if(a > 0 && b < 0)
    {
        cout << 4 << '\n';
        return 0;
    }
    else if(a < 0 && b < 0)
    {
        cout << 3 << '\n';
        return 0;
    }
    else
    {
        cout << 2 << '\n';
        return 0;
    }
}