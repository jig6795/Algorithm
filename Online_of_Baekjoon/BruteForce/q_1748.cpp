// Q1748
// 수 이어 쓰기 1
// 시간복잡도 - O(n)

#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    int numLength = n.length();
    long total_length = 0;

    for(int i=1;i<numLength;i++)
    {
        total_length += (9*pow(10,i-1)*i);
    }

    total_length += numLength*(stoi(n)-pow(10, numLength-1)+1);

    cout << total_length;

    return 0;
}