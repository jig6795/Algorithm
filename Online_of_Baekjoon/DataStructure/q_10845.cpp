// Q10845
// 큐(Queue)

#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> que;

    int n;
    cin >> n;

    string ch;
    int num;
    for(int i=0;i<n;i++)
    {
        cin >> ch;
        if(ch == "push")
        {
            cin >> num;
            que.push(num);
        }
        else if(ch == "pop")
        {
            if(que.empty() == 1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << que.front() << '\n';
                que.pop();
            }
        }
        else if(ch == "size")
        {
            cout << que.size() << '\n';
        }
        else if(ch == "empty")
        {
            if(que.empty() == 1)
            {
                cout << 1 << '\n';
            }
            else if(que.empty() == 0)
            {
                cout << 0 << '\n';
            }
        }
        else if(ch == "front")
        {
            if(que.empty() == 1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << que.front() << '\n';
            }
        }
        else if(ch == "back")
        {
            if(que.empty() == 1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << que.back() << '\n';
            }
        }
    }

    return 0;
}