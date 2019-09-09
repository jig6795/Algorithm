#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> uniqueId; 
    string state = ""; //Enter, Leave, Change
    string id = ""; //UserId
    string name = ""; //NickName
    int cnt = 0;

    for(int i=0;i<record.size();i++) //Enter, Change를 처리하는 반복문
    {
        if(record[i][0] == 'L')
        {
            continue;
        } //Leave인 경우

        else if(record[i][0] == 'E' || record[i][0] == 'C') //Enter or Change인 경우
        {
            for(int j=0;j<record[i].length();j++)
            {
                if(record[i][j] == ' ')
                {
                    cnt++;
                    continue;
                }

                if(cnt == 1)
                {
                    id += record[i][j];
                }
                else if(cnt == 2)
                {
                    name += record[i][j];
                }
            }
            uniqueId[id] = name;
            //초기화
            id = "";
            name = "";
            cnt = 0;
        }
    }

    for(int i=0;i<record.size();i++) //출력을 위한 반복문
    {
        if(record[i][0] == 'E')
        {
            for(int j=6;record[i][j]!=' ';j++)
            {
                id += record[i][j];
            }
            answer.push_back(uniqueId[id] + "님이 들어왔습니다.");
        }
        else if(record[i][0] == 'L')
        {
            for(int j=6;j<record[i].length();j++)
            {
                id += record[i][j];
            }
            answer.push_back(uniqueId[id] + "님이 나갔습니다.");
        }
        id = "";
    }
    return answer;
}

int main(void)
{
    vector<string> input;
    vector<string> output;

    input.push_back("Enter uid1234 Muzi");
    input.push_back("Enter uid4567 Prodo");
    input.push_back("Leave uid1234");
    input.push_back("Enter uid1234 Prodo");
    input.push_back("Change uid4567 Ryan");

    output = solution(input);

    for(int i=0;i<output.size();i++)
    {
        cout << output[i] << endl;
    }
    
    return 0;
}