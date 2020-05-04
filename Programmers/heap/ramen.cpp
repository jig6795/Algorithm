#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int j = 0;
    
    priority_queue<int,vector<int>,less<int> > pq; //supplies의 우선순위 큐

    for(int i=0;i<k;i++) //주어진 날짜만큼 반복
    {
        //해당 날짜가 되면 우선 순위 큐에 공급량을 추가
        if(dates[j] == i)
        {
            pq.push(supplies[j]);

            if(j != supplies.size() - 1)
            {
                j += 1;
            }
        }

        //날짜가 하루씩 지나면서 stock을 모두 사용하면 가장 큰 공급량을 추가
        if(stock == 0)
        {
            stock += pq.top();
            pq.pop();
            answer += 1;
        }
        stock -= 1;
    }
    return answer;
}

int main(void)
{
    int stock = 4;

    vector<int> dates;
    dates.push_back(4);
    dates.push_back(10);
    dates.push_back(15);

    vector<int> supplies;
    supplies.push_back(20);
    supplies.push_back(5);
    supplies.push_back(10);

    int k = 30;

    cout << solution(stock,dates,supplies,k);
}