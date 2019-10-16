#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int> > baseball) {
    int answer = 0;
    string num = "";
    string temp = "";
    int strike = 0;
    int ball = 0;
    bool flag = false;

    //가장 작은 수인 123부터 가장 큰 수인 987까지 반복
    for(int i=123;i<=987;i++)
    {
        num = to_string(i);
        //같은 수가 있는 경우 제외
        if(num[0] == num[1] || num[1] == num[2] || num[0] == num[2])
        {
            continue;
        }
        //수가 0인 경우도 제외
        else if(num[0] == '0' || num[1] == '0' || num[2] == '0') 
        {
            continue;
        }
        //가능한 수인 경우 flag는 true
        flag = true; 

        //baseball vector를 돌면서 검사
        for(int j=0;j<baseball.size();j++)
        {
            strike = 0;
            ball = 0;
            temp = to_string(baseball[j][0]);

            //자리수는 3자리로 고정이기 때문
            for(int a=0;a<3;a++)
            {
                for(int b=0;b<3;b++)
                {
                    //자리수가 같고 수가 같은 경우 strike
                    if(a == b && num[a] == temp[b])
                    {
                        strike += 1;
                        continue;
                    }
                    //자리수가 다르고 수가 같은 경우 ball
                    else if(a != b && num[a] == temp[b])
                    {
                        ball += 1;
                        continue;
                    }
                }
            }
            //baseball vector의 어느 하나라도 다를 경우, 다음 수로 넘어간다.
            if(strike != baseball[j][1] || ball != baseball[j][2])
            {
                flag = false;
                break;
            }
        }

        //flag가 여전히 true이면 가능한 수
        if(flag)
        {
            answer += 1;
        }
    }
    return answer;
}

int main(void)
{
    vector<vector<int> > baseball;
    vector<int> score;

    score.push_back(123);
    score.push_back(1);
    score.push_back(1);
    baseball.push_back(score);
    score.clear();

    score.push_back(356);
    score.push_back(1);
    score.push_back(0);
    baseball.push_back(score);
    score.clear();
    
    score.push_back(327);
    score.push_back(2);
    score.push_back(0);
    baseball.push_back(score);
    score.clear();
    
    score.push_back(489);
    score.push_back(0);
    score.push_back(1);
    baseball.push_back(score);
    score.clear();

    int answer = solution(baseball);

    cout << answer << endl;

    return 0;
}