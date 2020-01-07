// Q17298
// 오큰수
// 시간복잡도 - O(n)

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCaseNum;
    cin >> testCaseNum;

    vector<int> v(testCaseNum); // 입력 값을 받는 벡터
    vector<int> ans(testCaseNum); // 정답을 넣을 벡터
    stack<int> st;

    for(int i=0;i<testCaseNum;i++)
    {
        cin >> v[i];
    }

    st.push(0);

    for(int i=1;i<testCaseNum;i++)
    {
        if(st.empty() == 1)
        {
            st.push(i);
            continue;
        }

        while(st.empty() != 1 && v[st.top()] < v[i])
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