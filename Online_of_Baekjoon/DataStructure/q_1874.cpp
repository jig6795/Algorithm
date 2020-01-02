// Q1874
// 스택 수열

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> standard;
vector<char> answer;
stack<int> st;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0;
    cin >> n;

    int _number = 0;
    for(int i=0;i<n;i++)
    {
        cin >> _number;
        standard.push_back(_number);
    }

    // VECTOR의 반복자
    vector<int>::iterator tempNum;
    tempNum = standard.begin();

    for(int c=1;c<=n;c++)
    {
        answer.push_back('+');
        st.push(c);
        while(!st.empty())
        {
            if(st.top() == *tempNum) //반복자 사용
            {
                answer.push_back('-');
                st.pop();
                tempNum += 1;
            }
            else
            {
                break;
            }
        }
    }

    if(st.empty() == 1)
    {
        for(int i=0;i<answer.size();i++)
        {
            cout << answer[i] << '\n';
        }
    }
    else
    {
        cout << "NO" << '\n';
    }
    
    return 0;
}