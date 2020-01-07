// Q10866
// 덱(Deque)

#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<int> deq;

    string str;
    int num;
    for(int i=0;i<n;i++)
    {
        cin >> str;

        if(str == "push_front")
        {
            cin >> num;
            deq.push_front(num);
        }
        else if(str == "push_back")
        {
            cin >> num;
            deq.push_back(num);
        }
        else if(str == "pop_front")
        {
            if(deq.empty() == 1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        }
        else if(str == "pop_back")
        {
            if(deq.empty() == 1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        }
        else if(str == "size")
        {
            cout << deq.size() << '\n';
        }
        else if(str == "empty")
        {
            if(deq.empty() == 1)
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if(str == "front")
        {
            if(deq.empty() == 1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << deq.front() << '\n';
            }
        }
        else if(str == "back")
        {
            if(deq.empty() == 1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << deq.back() << '\n';
            }
        }
    }

    return 0;
}