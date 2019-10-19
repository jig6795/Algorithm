#include <iostream>
#include <algorithm>

using namespace std;

int t[16], p[16], n, _max;

//
// 재귀함수를 통한 최대값
//
void go(int day, int total)
{
    if(day == n)
    {
        _max = max(_max, total);
        return;
    }

    go(day+1,total);

    if(day + t[day] <= n)
    {
        go(day + t[day], total + p[day]);
    }
}

int main(void)
{
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> t[i];
        cin >> p[i];
    }

    go(0,0);

    cout << _max << endl;
    
    return 0;
}