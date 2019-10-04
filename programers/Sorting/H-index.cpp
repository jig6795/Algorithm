#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a,int b) //오름차순으로 정렬
{
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    int cnt = 0; //h보다 크거나 같은 인용 횟수
    
    sort(citations.begin(),citations.end(),compare);

    for(int i=citations[0];i>=0;i--) //최대값에서 하나씩 줄여가면서 h값을 확인
    {
        for(int j=0;j<citations.size();j++) 
        {
            if(i <= citations[j]) //인용 횟수가 h보다 크거나 같을 경우 cnt를 1 증가
            {
                cnt += 1;
            }
        }

        if(cnt >= i)
        {
            return i;
        }
        cnt = 0;
    }

    return answer;
}

int main(void)
{
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    cout << solution(citations) << endl;

    return 0;
}