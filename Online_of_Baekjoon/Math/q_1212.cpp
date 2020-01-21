// Q1212
// 8진수 2진수
// 시간복잡도 - O(n)

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> que;

    string str;
    getline(cin, str);

    if(str == "0")
    {
        cout << 0;
        return 0;
    }

    for(int i=0;i<str.length();i++)
    {
        switch (str[i])
        {
            case '0':
                que.push(0);
                que.push(0);
                que.push(0);
                break;
            case '1':
                que.push(0);
                que.push(0);
                que.push(1);
                break;
            case '2':
                que.push(0);
                que.push(1);
                que.push(0);
                break;
            case '3':
                que.push(0);
                que.push(1);
                que.push(1);
                break;
            case '4':
                que.push(1);
                que.push(0);
                que.push(0);
                break;
            case '5':
                que.push(1);
                que.push(0);
                que.push(1);
                break;
            case '6':
                que.push(1);
                que.push(1);
                que.push(0);
                break;
            case '7':
                que.push(1);
                que.push(1);
                que.push(1);
                break;
            default:
                break;    
        }
    }

    while(que.front() != 1)
    {
        que.pop();
    }

    while(que.empty() != 1)
    {
        cout << que.front();
        que.pop();
    }
    
    return 0;
}