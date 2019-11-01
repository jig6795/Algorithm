#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    vector<int> before;

    for(int i=0;i<arrangement.length();i++)
    {
        //쇠막대기의 왼쪽 끝부분인 경우
        if(arrangement[i] == '(' && arrangement[i+1] == '(')
        {
            before.push_back(0);
        }
        //레이저인 경우
        else if(arrangement[i] == '(' && arrangement[i+1] == ')')
        {
            i += 1;

            //모든 쇠막대기에 해당하는 부분에 +1
            for(int j=0;j<before.size();j++)
            {
                before[j] += 1;
            }
        }
        //쇠막대기의 오른쪽 끝인 경우
        else if(arrangement[i] == ')')
        {
            answer = answer + (before[before.size() - 1] + 1);
            before.pop_back();
        }
    }
    return answer;
}

int main(void)
{
    int result = solution("()(((()())(())()))(())");

    cout << result << endl;

    return 0;
}