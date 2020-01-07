// Q17299
// 오등큰수
// 시간복잡도 - O(n)

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCaseNum = 0;
    cin >> testCaseNum;

    vector<int> freq(testCaseNum+1);
    vector<int> v(testCaseNum);
    vector<int> ans(testCaseNum);
    stack<int> st;

    for(int i=0;i<testCaseNum;i++)
    {
        cin >> v[i];
        freq[v[i]] += 1;
    }

    st.push(0);
    for(int i=1;i<testCaseNum;i++)
    {
        while(st.empty() != 1 && freq[v[st.top()]] < freq[v[i]])
        {
            ans[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }

    while(st.empty() != 1)
    {
        ans[st.top()] = -1;
        st.pop();
    }

    for(int i=0;i<testCaseNum;i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}