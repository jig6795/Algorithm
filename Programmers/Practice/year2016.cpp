#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int sum = 0;

    //요일을 담을 벡터 7로 나누었을 때, 1이 금요일인 것을 감안
    vector<string> day; 
    day.push_back("THU");
    day.push_back("FRI");
    day.push_back("SAT");
    day.push_back("SUN");
    day.push_back("MON");
    day.push_back("TUE");
    day.push_back("WED");

    if(a >= 2) //월 계산
    {
        for(int i=2;i<=a;i++)
        {
            if(i <= 8) //8월 이전
            {
                if(i%2 == 0)
                {
                    sum += 31;
                }
                else
                {
                    if(i == 3) //윤달 처리
                    {
                        sum += 29;
                    }
                    else
                    {
                        sum += 30;
                    }
                }
            }
            else //8월 이후
            {
                if(i%2 == 0)
                {
                    sum += 30;
                }
                else
                {
                    sum += 31;
                }
            }
        }
    }
    sum += b; //일 계산
    answer = day[sum%7];

    return answer;
}

int main(void)
{
    int a, b;
    cin >> a >> b;

    string result = solution(a, b);

    cout << result << endl;

    return 0;
}