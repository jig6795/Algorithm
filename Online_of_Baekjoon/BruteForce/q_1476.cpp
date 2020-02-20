// Q1476
// 날짜 계산

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int E, S, M;
    cin >> E >> S >> M;

    int count_e = 1;
    int count_s = 1;
    int count_m = 1;

    int year = 1;

    while(1)
    {
        if(count_e == E && count_s == S && count_m == M)
        {
            cout << year;
            break;
        }

        count_e += 1;
        count_s += 1;
        count_m += 1;

        year += 1;

        if(count_e > 15)
        {
            count_e = 1;
        }
        
        if(count_s > 28)
        {
            count_s = 1;
        }
        
        if(count_m > 19)
        {
            count_m = 1;
        }
    }

    return 0;
}