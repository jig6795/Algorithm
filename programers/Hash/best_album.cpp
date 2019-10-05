#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<int> temp; //장르별로 재생 횟수를 담을 vector
    map<string, int> total_cnt; //각 장르별로 총합을 정리
    bool check[100] = {0}; //앨범에 들어갔을 경우 true (재생 횟수가 같은 경우를 방지하기 위해)
    int max = 0;
    string str = "";
    int cnt = 0;

    for(int i=0;i<genres.size();i++) //각 장르별로 총합을 계산하여 정리
    {
        for(auto it=total_cnt.begin();it != total_cnt.end();it++)
        {
            if(it->first == genres[i])
            {
                it->second += plays[i];
            }
        }
        total_cnt.insert(pair<string, int> (genres[i],plays[i]));
    }

    while(1)
    {
        if(total_cnt.empty()) //비어 있는 경우 종료
        {
            break;
        }

        //재생 횟수의 총합이 가장 많은 장르를 선택
        for(auto it=total_cnt.begin();it != total_cnt.end();it++) 
        {
            if(it->second > max)
            {
                max = it->second;
                str = it->first;
            }
        }

        //선택된 장르의 재생 횟수들을 임시 벡터에 넣고 내림차순으로 정렬
        for(int i=0;i<genres.size();i++) 
        {
            if(str == genres[i])
            {
                temp.push_back(plays[i]);
            }
        }
        sort(temp.begin(),temp.end(),cmp);

        //선택된 장르에서 재생 횟수가 많은 것부터 2가지 선택하여 answer에 추가
        for(int i=0;i<temp.size();i++) 
        {
            if(cnt == 2) //한 장르에서 2가지 곡이 선택된 경우 종료
            {
                break;
            }
            
            for(int j=0;j<plays.size();j++)
            {
                //재생 횟수가 같고, 선택되지 않은 곡을 추가
                if(temp[i] == plays[j] && check[j] == 0) 
                {
                    check[j] = true;
                    answer.push_back(j);
                    cnt += 1;
                    break;
                }
            }
        }
        //초기화 & 사용한 장르는 지운다.
        cnt = 0;
        max = 0;
        temp.clear();
        total_cnt.erase(str);
    }
    return answer;
}

int main(void)
{
    vector<string> genres;
    genres.push_back("classic");
    genres.push_back("pop");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");

    vector<int> plays;
    plays.push_back(500);
    plays.push_back(600);
    plays.push_back(150);
    plays.push_back(800);
    plays.push_back(2500);

    vector<int> answer = solution(genres,plays);

    for(int i=0;i<answer.size();i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}