// Q1406
// 에디터

#include <iostream>
#include <stack>

using namespace std;

stack<char> cursur_left;
stack<char> cursur_right;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    for(int i=0;i<str.length();i++)
    {
        cursur_left.push(str[i]);
    }

    int n;
    cin >> n;

    char ch;
    char add_ch;
    for(int i=0;i<n;i++)
    {
        cin >> ch;

        if(ch == 'L')
        {
            //cout << "L" << " ";
            if(cursur_left.empty() == 1)
            {
                continue;
            }
            int temp = cursur_left.top();
            cursur_left.pop();
            cursur_right.push(temp);
        }
        else if(ch == 'D')
        {
            //cout << "D" << " ";
            if(cursur_right.empty() == 1)
            {
                continue;
            }
            int temp = cursur_right.top();
            cursur_right.pop();
            cursur_left.push(temp);
        }
        else if(ch == 'P')
        {
            //cout << "P" << " ";
            cin >> add_ch;
            cursur_left.push(add_ch);
        }
        else if(ch == 'B')
        {
            //cout << "B" << " ";
            if(cursur_left.empty() != 1)
            {
                cursur_left.pop();
            }
        }
    }

    while(cursur_left.empty() != 1)
    {
        int temp = cursur_left.top();
        cursur_left.pop();
        cursur_right.push(temp);
    }

    while(cursur_right.empty() != 1)
    {
        cout << cursur_right.top();
        cursur_right.pop();
    }

    return 0;
}