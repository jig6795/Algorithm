// Q10039
// 평균 점수
// 시간복잡도 - O(n)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int sum = 0;

    for(int i=0;i<5;i++)
    {
        cin >> n;

        if(n < 40)
        {
            n = 40;
        }

        sum += n;
    }

    cout << sum / 5 << '\n';

    return 0;
}