//1026번 - 보물
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main(void)
{
    int n;
    cin >> n;

    int a[n];
    int b[n];
    int c[n];

    int answer = 0;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }

    //a 배열은 오름차순으로 정렬
    //b 배열은 내림차순으로 정렬
    sort(a,a+n);
    sort(b,b+n,compare);

    for(int i=0;i<n;i++)
    {
        c[i] = a[i] * b[i];
        answer += c[i];
    }

    cout << answer << endl;

    return 0;
}