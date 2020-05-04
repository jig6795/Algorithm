#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int a,b,c;

    //우선 순위 큐 선언 (오름 차순)
    priority_queue<int,vector<int>,greater<int> > pq;

    //우선 순위 큐에 값을 대입한다.
    for(int i=0;i<scoville.size();i++)
    {
        pq.push(scoville[i]);
    }

    while(1)
    {
        //가장 덜 매운 음식
        a = pq.top();
        pq.pop();

        if(a > K) //덜 매운게 없으면 종료
        {
            return answer;
        }
        else if(pq.empty() && a < K) //모든 요소를 검사했지만, 만족하지 못하면 -1을 반환하고 종료
        {
            return -1;
        }

        //두번째로 덜 매운 음식
        b = pq.top();
        pq.pop();

        //섞은 음식
        c = a + b*2;
        pq.push(c);
        answer += 1;
    }
}

int main(void)
{
    vector<int> scoville;
    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);

    int K = 7;

    cout << solution(scoville,K) << endl;
}