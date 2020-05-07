// 탑
// 2020.05.04

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    bool check = true; // 수신 가능할 경우, False / 수신 불가능인 경우, True
    answer.push_back(0); // 1번째 탑은 수신 가능한 탑이 존재하지 않는다.
    for(int i=1;i<heights.size();i++) // 각 탑 별로 수신 가능한 탑을 확인한다.
    {
        for(int j=i-1;j>=0;j--)
        {
            if(heights[j] > heights[i])
            {
                answer.push_back(j+1);
                check = false;
                break;
            }
        }

        if(check == true)
        {
            answer.push_back(0);
        }
        check = true;
    }

    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> height;
    height.push_back(1);
    height.push_back(5);
    height.push_back(3);
    height.push_back(6);
    height.push_back(7);
    height.push_back(6);
    height.push_back(5);

    vector<int> _answer = solution(height);

    for(int i=0;i<_answer.size();i++)
    {
        cout << _answer[i] << " ";
    }

    return 0;
}