// Q1918
// 후위 표기식
// 시간복잡도 - O(n)

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    string answer;
    getline(cin, str);

    stack<char> _operator;

    for(int i=0;i<str.length();i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            answer += str[i];
        }
        else
        {
            if(str[i] == '(')
            {
                _operator.push(str[i]);
                continue;
            }
            else if(str[i] == ')')
            {
                // '('가 나오기 전까지 연산자 추가 
                while(_operator.top() != '(' && !_operator.empty())
                {
                    answer += _operator.top();
                    _operator.pop();
                }
                _operator.pop(); // '(' 제거
                continue;
            }
            else
            {
                if(str[i] == '*' || str[i] == '/')
                {
                    while(!_operator.empty() && (_operator.top() == '*' || _operator.top() == '/'))
                    {
                        answer += _operator.top();
                        _operator.pop();
                    }
                    _operator.push(str[i]);
                    continue;

                }
                else
                {
                    while(!_operator.empty() && _operator.top() != '(')
                    {
                        answer += _operator.top();
                        _operator.pop();
                    }
                    _operator.push(str[i]);
                    continue;
                }
            } 
        }        
    }

    while(!_operator.empty())
    {
        answer += _operator.top();
        _operator.pop();
    }

    cout << answer << '\n';
    
    return 0;
}