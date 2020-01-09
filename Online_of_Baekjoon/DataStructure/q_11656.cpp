// Q11656
// 접미사 배열
// 시간복잡도 - O(n^2)

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);

    vector<string> answer;
    string temp = "";

    for(int i=0;i<str.length();i++)
    {
        for(int j=i;j<str.length();j++)
        {
            temp += str[j];
        }
        answer.push_back(temp);
        temp = "";
    }

    sort(answer.begin(),answer.end());

    for(int i=0;i<answer.size();i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}