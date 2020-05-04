#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp; //반복되는 문자열을 받는다.
    int cnt = 1; //몇개 반복이 되는지 확인
    map<string, int> count; //반복되는 것이 몇개인지 세어준다.
    int length = 0; //한번 반복되었을 경우의 만들어진 문자열의 길이
    vector<int> num; //각 만들어진 문자열 길이 저장
    int min = 0; //최소

    for(int i=1;i<=s.length();i++) //i는 자르는 갯수
    {
        temp = s.substr(0,i); //맨 앞부터 일정 수로 자른다.
        cnt = 1;
        length += temp.length();

        for(int j=i;j<s.length();j=j+i)
        {
            if(temp != s.substr(j,i)) //다른 것이 나온 경우
            {
                if(cnt > 1)
                {
                    if((count[temp]/100)>0 && (count[temp]/100)<10)
                    {
                        length += 3;
                    }
                    else if((count[temp]/10)>0 && (count[temp]/10)<10)
                    {
                        length += 2;
                    }
                    else if(count[temp]>1 && count[temp]<10)
                    {
                        //out << 1 << endl;
                        length += 1;
                    }
                }
                temp = s.substr(j,i); //다음 반복 문자열을 만들어준다.
                length += temp.length();
                cnt = 1;
                continue;
            }
            cnt += 1; //같은 경우 +1
            count[temp] = cnt;
        }

        if(cnt>1)
        {
            if((count[temp]/100)>0 && (count[temp]/100)<10)
            {
                length += 3;
            }
            else if((count[temp]/10)>0 && (count[temp]/10)<10)
            {
                length += 2;
            }
            else if(count[temp]>1 && count[temp]<10)
            {
                //cout << 2 << endl;
                length += 1;
            }
            else if(cnt == 1000)
            {
                length += 4;
            }
        }
        //cout << length << endl;
        num.push_back(length);
        length = 0;
    }

    min = num[0];

    for(int i=1;i<num.size();i++)
    {
        if(min>num[i])
        {
            min = num[i];
        }
    }
    
    cout << min << endl;
    answer = min;

    return answer;
}

int main(void)
{
    vector<string> abc;
    
    abc.push_back("aabbaccc");
    abc.push_back("ababcdcdababcdcd");
    abc.push_back("abcabcdede");
    abc.push_back("abcabcabcabcdededededede");
    abc.push_back("xababcdcdababcdcd");
    
    for(int i=0;i<5;i++)
    {
        solution(abc[i]);
    }
    
    //solution(abc[0]);
    solution("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    solution("aa");
    solution("aaccccc");
    return 0;
}