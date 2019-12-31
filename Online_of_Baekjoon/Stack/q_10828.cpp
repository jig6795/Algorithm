// Q10828
// 스택
// 입력에 따라 각 조건을 수행하는 문제

#include <iostream>
#include <cstring>

using namespace std;

int stack[10000];
int _size = 0;
int top = 0;

void push(int num)
{
    if(_size == 10000)
    {
        cout << -1 << '\n';
        return;
    }
    stack[_size] = num;
    _size += 1;
}

void pop(void)
{
    if(_size == 0)
    {
        cout << -1 << '\n';
        return;
    }
    cout << stack[_size-1] << '\n';
    _size -= 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, n;
    cin >> n;

    string str;

    for(int i=0;i<n;i++)
    {
        cin >> str;
        if(str == "push")
        {
            cin >> a;
            push(a);
        }
        else if(str == "pop")
        {
            pop();
        }
        else if(str == "top")
        {
            if(_size == 0)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << stack[_size-1] << '\n';
            }
        }
        else if(str == "size")
        {
            cout << _size << '\n';
        }
        else if(str == "empty")
        {
            if(_size == 0)
            {
                cout <<  1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}