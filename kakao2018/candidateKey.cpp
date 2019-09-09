//개같은 문제! 다시 도전

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string> > relation) {
    int answer = 0;
    bool check = false; //후보키인지 아닌지 검사
    map<int, bool> attribute;

    //하나의 속성으로 후보키가 될 수 있는 경우 검사 & 최소성을 만족하므로 다음 검사에서 제외
    for(int i=0;i<relation.size();i++) 
    {
        for(int j=0;j<relation[i].size();j++)
        {
            for(int k=j+1;k<relation[i].size();k++)
            {
                if(relation[i][j] == relation[i][k]) //유일성이 만족하지 않은 경우 바로 다음 속성으로 넘어가서 검사
                {
                    check = true;
                    i++;
                    j = -1;
                    break;
                }
            }
        }

        if(!check) //후보키인 경우 +1
        {
            attribute[i] = true;
            answer++;
            check = false;
        }
    }

    return answer;
}

int main(void)
{
    vector<vector<string> > relation;
    vector<string> tuple1; //학번
    vector<string> tuple2; //이름
    vector<string> tuple3; //전공
    vector<string> tuple4; //학년

    //학번 속성
    tuple1.push_back("100");
    tuple1.push_back("200");
    tuple1.push_back("300");
    tuple1.push_back("400");
    tuple1.push_back("500");
    tuple1.push_back("600");

    //이름 속성
    tuple2.push_back("ryan");
    tuple2.push_back("apeach");
    tuple2.push_back("tube");
    tuple2.push_back("con");
    tuple2.push_back("muzi");
    tuple2.push_back("apeach");

    //전공 속성
    tuple3.push_back("music");
    tuple3.push_back("math");
    tuple3.push_back("computer");
    tuple3.push_back("computer");
    tuple3.push_back("music");
    tuple3.push_back("music");

    //학년 속성
    tuple4.push_back("2");
    tuple4.push_back("2");
    tuple4.push_back("3");
    tuple4.push_back("1");
    tuple4.push_back("3");
    tuple4.push_back("2");

    relation.push_back(tuple1);
    relation.push_back(tuple2);
    relation.push_back(tuple3);
    relation.push_back(tuple4);

    cout << solution(relation);

    return 0;
}