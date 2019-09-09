#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) //내림차순 비교
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > failure; //실패율 저장하기 위한 pair
    double cnt, total; //도달했지만 성공 못한 명수, 총 도달 명수 -> 소수점 계산을 위해 실수형 선언
    int temp;  //스테이지 저장 변수, 전 스테이지 저장
    bool check[500] = {false}; //해당 스테이지에 대한 실패율이 있는지 검사

    sort(stages.begin(),stages.end()); //오름차순으로 정리

    for(int i=0;i<stages.size();i++)
    {
        temp = stages[i];

        if(temp >  N) //최종 스테이지보다 넘어간경우 종료
        {
            break;
        }

        cnt = 1.0; //자기 자신은 이미 포함하기 때문
        total = (double)stages.size() - (double)i;

        for(int j=i+1;j<stages.size();j++)
        {
            if(temp != stages[j]) //스테이지가 넘어간 경우
            {
                break;
            }
            else //스테이지에 도달한 명수 계산
            {
                cnt += 1.0;
                i++;
            }
        }

        check[temp-1] = true;
        failure.push_back(pair<int, double> (temp,(cnt/total)));
    }

    for(int i=0;i<N;i++) //도달하지 못했거나, 실패하지 않은 스테이지의 실패율을 0으로 만들어줌
    {
        if(!check[i])
        {
            failure.push_back(pair<int, double> (i+1, 0.0));
        }
    }

    sort(failure.begin(),failure.end(),compare); //실패율 내림차순으로 정렬
    
    for(int i=0;i<N;i++)
    {
        answer.push_back(failure[i].first);
    }
    
    return answer;
}

int main(void)
{
    int n=2;
    vector<int> v;
    vector<int> output;

    v.push_back(100);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(600);
    v.push_back(7);

    output = solution(n,v);
    
    for(int i=0;i<n;i++)
    {
        cout << output[i] << endl;
    }
    
    return 0;
}