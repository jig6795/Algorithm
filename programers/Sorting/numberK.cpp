#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector< vector<int> > commands) {
    vector<int> answer;
    vector<int> temp; //임시 범위의 수를 받을 벡터

    for(int i=0;i<commands.size();i++)
    {
        int start = commands[i][0]-1; //i
        int back = commands[i][1]-1; //j

        //임시 벡터에 새로 저장
        for(int i=start;i<=back;i++)
        {
            temp.push_back(array[i]);
        }

        sort(temp.begin(), temp.end());

        answer.push_back(temp[commands[i][2]-1]);
        temp.clear();
    }

    return answer;
}

int main(void)
{
    vector<int> array;
    vector<int> commands_baby;
    vector< vector<int> > commands;
    vector<int> answer;

    array.push_back(1);
    array.push_back(5);
    array.push_back(2);
    array.push_back(6);
    array.push_back(3);
    array.push_back(7);
    array.push_back(4);

    //이중벡터에 값을 대입
    commands_baby.push_back(2);
    commands_baby.push_back(5);
    commands_baby.push_back(3);
    commands.push_back(commands_baby);
    commands_baby.clear();

    commands_baby.push_back(4);
    commands_baby.push_back(4);
    commands_baby.push_back(4);
    commands.push_back(commands_baby);
    commands_baby.clear();

    commands_baby.push_back(1);
    commands_baby.push_back(7);
    commands_baby.push_back(3);
    commands.push_back(commands_baby);
    commands_baby.clear();
    /* ------------- 확인 ---------------
    for(int i=0;i<commands.size();i++)
    {
        for(int j=0;j<commands[i].size();j++)
        {
            cout << commands[i][j] << " ";
        }
        cout << endl;
    }
    */
    answer = solution(array, commands);

    for(int i=0;i<answer.size();i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}