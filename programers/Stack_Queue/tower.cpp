#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> answer_stack; //뒤에서부터 담아오기 위한 stack
    bool check = false;

    //왼쪽으로 돌기 때문에 뒤에서부터 줄여가며 확인
    for(int i=heights.size()-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            //더 높은 탑이 발견이 된다면 stack에 push한다.
            if(heights[i] < heights[j])
            {
                answer_stack.push(j+1);
                check = true;
                break;
            }
        }

        //더 높은 탑이 없는 경우
        if(check == false)
        {
            answer_stack.push(0);
            check = false;
        }

        check = false;
    }

    //stack의 top에서부터 하나씩 pop해서 저장
    while(!answer_stack.empty())
    {
        answer.push_back(answer_stack.top());
        answer_stack.pop();
    }

    return answer;
}

int main(void)
{
    vector<int> height;
    height.push_back(6);
    height.push_back(9);
    height.push_back(5);
    height.push_back(7);
    height.push_back(4);
    
    vector<int> result = solution(height);

    for(int i=0;i<result.size();i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}