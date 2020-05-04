//효율성 문제 1,2,3번 틀림
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    int cnt = 0; //?의 갯수
    int count = 0; //같은 문자열 갯수
    int total = 0;

    for(int i=0;i<queries.size();i++)
    {
        total = 0;
        cnt = 0;
        
        for(int k=0;k<words.size();k++)
        {
            if(queries[i].length()!=words[k].length())
            {
                continue;
            }

            count = 0;
            cnt = 0;

            for(int l=0;l<words[k].length();l++) //문자열 비교
            {
                if(queries[i][l] != words[k][l])
                {
                    if(queries[i][l] == '?')
                    {
                        cnt++;
                        continue;
                    }
                }
                else
                {
                    count++;
                }
            }

            if(queries[i].length()-cnt == count)
            {
                total++;
            }
        }
        answer.push_back(total);
    }
    return answer;
}

int main(void)
{
    vector<string> w;
    vector<string> q;
    vector<int> answer;

    w.push_back("frodo");
    w.push_back("front");
    w.push_back("frost");
    w.push_back("frozen");
    w.push_back("frame");
    w.push_back("kakao");
    
    q.push_back("fro??");
    q.push_back("????o");
    q.push_back("fr???");
    q.push_back("fro???");
    q.push_back("pro?");
    
    answer = solution(w,q);

    for(int i=0;i<q.size();i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}