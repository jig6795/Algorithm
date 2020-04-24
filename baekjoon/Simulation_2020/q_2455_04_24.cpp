// Q2455
// 지능형 기차
// 시간 복잡도 - O(n)

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int out, in; // 내린 사람 수, 탄 사람 수
    int sum = 0; // 기차에 현재 타 있는 사람 수
    int max = 0; // 기차에 탄 사람의 최대 수

    for(int i=0;i<4;i++) // 4개 역을 방문하기 때문에
    {
        cin >> out >> in;
        sum -= out; // 기차에서 내림
        sum += in; // 기차에 탐    

        if(max < sum)
        {
            max = sum;
        }
    }

    cout << max << '\n';

    return 0;
}