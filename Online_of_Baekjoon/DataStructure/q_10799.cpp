// Q10799
// 쇠막대기
// 시간복잡도 - O(n)

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);

    stack<int> st;
    int sum = 0;

    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '(')
        {
            if(str[i+1] == ')') // 레이저인 경우
            {
                sum += st.size();
            }
            else // 쇠막대기의 시작인 경우
            {
                st.push(i);
            }
        }
        else if(str[i] == ')')
        {
            if(str[i-1] == '(') // 레이저인 경우는 위에서 처리
            {
                continue;
            }
            else // 쇠막대기의 끝인 경우
            {
                st.pop();
                sum += 1;
            }
        }
    }

    cout << sum;

    return 0;
}