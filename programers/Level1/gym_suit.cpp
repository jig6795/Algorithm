#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();

    //lost를 해결했을 경우, true
    bool clear[lost.size()];
    for(int i=0;i<lost.size();i++)
    {
        clear[i] = 0;
    }

    //reserve를 사용했을 경우, false
    bool remain[reserve.size()];
    for(int i=0;i<reserve.size();i++)
    {
        remain[i] = 1;
        for(int j=0;j<lost.size();j++)
        {
            if(reserve[i] == lost[j]) //여분을 갖고 있는 학생이 도난을 당한 경우
            {
                answer += 1;
                remain[i] = 0;
                clear[j] = 1;
                break;
            }
        }
    }

    for(int i=0;i<lost.size();i++)
    {
        for(int j=0;j<reserve.size();j++)
        {
            if(lost[i] == reserve[j] + 1 && remain[j] == 1 && clear[i] == 0)
            {
                //cout << lost[i] << " " << reserve[j] + 1 << endl;
                answer += 1;
                remain[j] = 0;
                clear[i] = 1;
                break;
            }
            else if(lost[i] == reserve[j] - 1 && remain[j] == 1 && clear[i] == 0)
            {
                //cout << lost[i] << " " << reserve[j] - 1 << endl;
                answer += 1;
                remain[j] = 0;
                clear[i] = 1;
                break;
            }
        }
    }

    return answer;
}

int main(void)
{
    vector<int> lost;
    lost.push_back(2);
    lost.push_back(3);
    lost.push_back(4);

    vector<int> reserve;
    reserve.push_back(1);
    reserve.push_back(2);
    reserve.push_back(3);
    reserve.push_back(6);

    cout << solution(7,lost,reserve) << endl;

    return 0;
}