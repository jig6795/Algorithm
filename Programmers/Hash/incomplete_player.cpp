#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    //sort 함수를 통해 오름차순으로 정렬하고, 다를 경우 반환
    //마지막까지 같은 경우에는 participant의 마지막 인원을 반환
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i=0;i<completion.size();i++)
    {
        if(participant[i] != completion[i])
        {
            answer = participant[i];
            return answer;
        }
    }
    answer = participant[participant.size()-1];

    return answer;
}

int main(void)
{
    vector<string> participant; //참가자 명단을 추가할 벡터
    vector<string> completion;  //완주자 명단을 추가할 벡터

    participant.push_back("mislav");
    participant.push_back("stanko");
    participant.push_back("mislav");
    participant.push_back("ana");

    completion.push_back("stanko");
    completion.push_back("ana");
    completion.push_back("mislav");

    cout << solution(participant, completion) << endl;

    return 0;
}