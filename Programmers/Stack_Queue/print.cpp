#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 0; //%연산을 위한 변수
    bool check = false;

    while(1)
    {
        //해당 위치의 인쇄물이 출력이 되었을 경우
        if(priorities[location] == 0) 
        {
            return answer;
        }

        //우선 순위가 높은 인쇄물이 있는지 검사
        for(int i=0;i<priorities.size();i++)
        {
            if(cnt == i)
            {
                continue;
            }

            check = true;

            //우선 순위가 높은 인쇄물이 있는 경우, 출력을 하지 않도록 check를 false로 설정
            if(priorities[cnt] < priorities[i])
            {
                check = false;
                break;
            }
        }

        //출력을 하는 경우
        if(check)
        {
            priorities[cnt] = 0;
            answer += 1;
        }
        cnt = (cnt+1)%priorities.size();
    }
}

int main(void)
{
    vector<int> priority;
    priority.push_back(1);
    priority.push_back(1);
    priority.push_back(9);
    priority.push_back(1);
    priority.push_back(1);
    priority.push_back(1);

    int result = solution(priority, 0);

    cout << result << endl;

    return 0;
}