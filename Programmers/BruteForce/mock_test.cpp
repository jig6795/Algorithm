#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt[3] = {0}; //맞은 갯수를 저장하기 위한 배열
    int max = 0; //가장 많이 맞은 사람을 비교하기 위한 변수

    //1번 수포자의 찍는 방법
    vector<int> one; 
    for(int i=1;i<=5;i++)
    {
        one.push_back(i);
    }

    //2번 수포자의 찍는 방법
    vector<int> two; 
    for(int i=1;i<=5;i++)
    {
        if(i == 2)
        {
            continue;
        }
        two.push_back(2);
        two.push_back(i);
    }

    //3번 수포자의 찍는 방법
    vector<int> three; 
    three.push_back(3);
    three.push_back(3);
    for(int i=1;i<=5;i++)
    {
        if(i == 3)
        {
            continue;
        }
        three.push_back(i);
        three.push_back(i);
    }

    //1번 수포자의 정답 확인
    for(int i=0;i<answers.size();i++)
    {
        if(one[i%5] == answers[i])
        {
            cnt[0] += 1;
        }
    }

    //2번 수포자의 정답 확인
    for(int i=0;i<answers.size();i++)
    {
        if(two[i%8] == answers[i])
        {
            cnt[1] += 1;
        }
    }

    //3번 수포자의 정답 확인
    for(int i=0;i<answers.size();i++)
    {
        if(three[i%10] == answers[i])
        {
            cnt[2] += 1;
        }
    }

    //가장 많이 맞은 갯수 찾기
    for(int i=0;i<3;i++)
    {
        if(cnt[i] > max)
        {
            max = cnt[i];
        }
    }

    //동점자를 판별
    for(int i=0;i<3;i++)
    {
        if(cnt[i] == max)
        {
            answer.push_back(i+1);
        }
    }

    return answer;
}

int main(void)
{
    vector<int> answer1;
    answer1.push_back(1);
    answer1.push_back(2);
    answer1.push_back(3);
    answer1.push_back(4);
    answer1.push_back(5);

    vector<int> answer2;
    answer2.push_back(1);
    answer2.push_back(3);
    answer2.push_back(2);
    answer2.push_back(4);
    answer2.push_back(2);

    for(int i=0;i<solution(answer1).size();i++)
    {
        cout << solution(answer1)[i] << endl;
    }

    return 0;
}