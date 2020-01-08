// Q1935
// 후위 표기식 2
// 시간복잡도 - O(n)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCaseNum = 0;
    cin >> testCaseNum;
    cin.ignore();

    string str;
    getline(cin, str);

    stack<double> st;
    vector<double> _number(testCaseNum);

    for(int i=0;i<testCaseNum;i++)
    {
        cin >> _number[i];
    }

    double first, second, third;

    for(int i=0;i<str.length();i++)
    {
        //사칙연산은 STACK에서 두 수를 POP해서 계산 후 PUSH
        if(str[i] == '+')
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();
            third = second+first;
            st.push(third);
        }
        else if(str[i] == '-')
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();
            third = second-first;
            st.push(third);
        }
        else if(str[i] == '*')
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();
            third = second*first;
            st.push(third);
        }
        else if(str[i] == '/')
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();
            third = second/first;
            st.push(third);
        }
        else
        {
            st.push(_number[(int)str[i]-65]);
        }
    }

    //소수점 둘째 자리로 고정하기
    cout << fixed;
    cout.precision(2);
    cout << st.top();

    return 0;
}