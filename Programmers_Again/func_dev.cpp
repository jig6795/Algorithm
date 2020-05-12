// 기능개발
// 2020.05.12

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> task;
    int total_func = 0;
    int cnt = 0;

    //Queue에 원소들을 넣는다.
    for(int i=0;i<progresses.size();i++)
    {
        task.push(progresses[i]);
    }

    //Queue가 비어있게 되면 모든 일이 종료되었음을 의미한다.
    while(!task.empty())
    {
        //하루가 지나면 해당하는 개발 속도를 더해준다.
        for(int day=0;day<progresses.size();day++)
        {
            if(progresses[day] >= 100)
            {
                continue;
            }
            progresses[day] += speeds[day];
        }

        //개발이 완료된 일이 생긴 경우
        if(progresses[cnt] >= 100)
        {
            task.pop();
            total_func += 1;
            cnt += 1;

            for(int i=cnt;i<progresses.size();i++)
            {
                if(progresses[i] >= 100)
                {
                    task.pop();
                    total_func += 1;
                    cnt += 1;
                }
                else
                {
                    break;
                }
            }
            answer.push_back(total_func);
            total_func = 0;
        }
    }
    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> progresses;
    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);


    vector<int> speeds;
    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);

    vector<int> result = solution(progresses, speeds);

    for(int i=0;i<result.size();i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}