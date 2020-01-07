// Q1158
// 조세퍼스 문제

#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    queue<int> que;
    for(int i=1;i<=n;i++)
    {
        que.push(i);
    }

    cout << "<";

    while(1)
    {
        if(que.size() == 1) // 마지막 콤마를 생략하기 위해서
        {
            cout << que.front();
            break;
        }

        for(int i=0;i<k-1;i++) // k-1만큼 pop을 한 뒤 다시 push
        {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }

        cout << que.front() << ", ";
        que.pop();
    }
    
    cout << ">";

    return 0;
}