// Q17413
// 단어뒤집기2
// 시간 복잡도 - O(n)

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> st;
    string str;
    getline(cin, str);

    int flag = 0;
    int cnt = 0;

    while(cnt != str.length()) // 단어 길이만큼 돌린다.
    {
        // "<"가 등장했을 때, 먼저 STACK안을 모두 POP하고 
        // ">"가 등장할 때까지 그대로 출력
        if(str[cnt] == '<')
        {
            while(st.empty() != 1)
            {
                cout << st.top();
                st.pop();
            }

            cout << str[cnt];
            cnt += 1;

            while(str[cnt] != '>')
            {
                cout << str[cnt];
                cnt += 1;
            }

            cout << str[cnt];
            cnt += 1;
        }
        else //글자는 STACK에 넣어주고, 띄어쓰기가 등장하면 모두 POP
        {
            if(str[cnt] == ' ')
            {
                while(st.empty() != 1)
                {
                    cout << st.top();
                    st.pop();
                }
                cout << str[cnt];
                cnt += 1;
            }
            else
            {
                st.push(str[cnt]);
                cnt += 1;
            }
        }
    }

    //마지막 STACK에 남겨져 있는 모든 것을 POP
    while(st.empty() != 1)
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}